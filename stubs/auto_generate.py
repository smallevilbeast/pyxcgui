# -*- encoding: utf8 -*-
import CppHeaderParser

types = {
    '*': 'uintptr_t',
}

g_enum_names = set()
g_types = set()


def to_py_types(typename):
    if '*' in typename:
        return 'uintptr_t'
    if typename[0] == 'H':
        return 'uintptr_t'
    if typename in g_enum_names:
        return 'int'

def get_enum_pybind11(enum):
    name = enum["name"]
    out_list = []
    out_list.append(f'py::enum_<{name}>(m, "{name}", py::arithmetic())')
    for val in  enum['values']:
        item_name = val['name']
        out_list.append(f'	.value("{item_name}", {item_name})')
    out_list.append('	.export_values();')
    return '\n'.join(out_list)


def generate_enumNames(header: CppHeaderParser.CppHeader):
    enums = header.enums
    for enum in enums:
        print(get_enum_pybind11(enum))
        print()



def generate_Types(header: CppHeaderParser.CppHeader):
    functions = header.functions
    for func in functions:
        retType = func['rtnType']
        if 'XC_API' not in retType:
            continue
        g_types.add(get_realRetType(retType))
        paramTypes = get_function_pararms(func)
        for pType in paramTypes:
            g_types.add(pType)


def get_realParamType(paramType):
    ret_list = paramType.split()
    if 'in_' in ret_list:
        ret_list.remove('in_')
    if 'out_' in ret_list:
        ret_list.remove('out_')
    if 'in_out_' in ret_list:
        ret_list.remove('in_out_')
    if 'in_buffer_' in ret_list:
        ret_list.remove('in_buffer_')
    if 'out_buffer_' in ret_list:
        ret_list.remove('out_buffer_')
    return ' '.join(ret_list)


def get_realRetType(retType):
    ret_list = retType.split()
    if len(ret_list) >= 3:
        return ' '.join(ret_list[1:-1])
    return retType


def get_function_pararms(func):
    parameters = func['parameters']
    types = set()
    for param in parameters:
        types.add(get_realParamType(param['type']))
    return types


def generate_structs(header: CppHeaderParser):
    classes = header.classes
    clazz_map = {
        "BOOL": 'bool',
        "HXCGUI": "uintptr_t",
        "HTEMP": "uintptr_t",
        "HWINDOW": "uintptr_t",
        "HMENUX": "uintptr_t",
        "HIMAGE": "uintptr_t",
        "UINT*": "uintptr_t"
    }

    for clazz in classes.values():
        declaration_method = clazz['declaration_method']
        if declaration_method == 'class':
            continue
        name = clazz['name']
        if 'event' in name:
            continue

        ret_list = []
        ret_list.append(f'py::class_<{name}>(m, "{name}")')
        ret_list.append(f'    PYCAST({name})')
        ret_list.append(f'	.def(py::init<>())')
        for prop in clazz['properties']["public"]:
            prop_name = prop['name']
            type_name = prop["type"]
            new_type_name = clazz_map.get(type_name, None)
            if new_type_name:
                out = '''
    .def_property("%s", [](%s self) -> %s {
        return (%s)self.%s;
    }, 
    [](%s self, %s %s) {
        self.%s = (%s)%s;
    
    })
''' % (
                prop_name, name, new_type_name, new_type_name, prop_name, name, new_type_name, prop_name, prop_name, type_name,
                prop_name)
                ret_list.append(out)
            else:
                ret_list.append(f'	.def_readwrite("{prop_name}", &{name}::{prop_name})')
        ret_list[-1] = ret_list[-1] + ';'
        print('\n'.join(ret_list))
        print()

def generate_defines(header):
    include_names = ["XE_", "XC_", "XWM_", "WM_", "WINDOW"]
    exclude_names = ["(", "XC_API", "MARK"]
    include_wm_messages = '''
    - @ref WM_PAINT 窗口绘制消息
    - @ref WM_CLOSE 窗口关闭消息.
    - @ref WM_DESTROY 窗口销毁消息.
    - @ref WM_NCDESTROY 窗口非客户区销毁消息.
    - @ref WM_LBUTTONDOWN 窗口鼠标左键按下消息
    - @ref WM_LBUTTONUP 窗口鼠标左键弹起消息.
    - @ref WM_RBUTTONDOWN 窗口鼠标右键按下消息.
    - @ref WM_RBUTTONUP 窗口鼠标右键弹起消息.
    - @ref WM_LBUTTONDBLCLK 窗口鼠标左键双击消息.
    - @ref WM_RBUTTONDBLCLK 窗口鼠标右键双击消息.
    - @ref WM_MOUSEMOVE 窗口鼠标移动消息.
    - @ref WM_MOUSEHOVER 窗口鼠标悬停消息
    - @ref WM_MOUSELEAVE 窗口鼠标离开消息.
    - @ref WM_MOUSEWHEEL 窗口鼠标滚轮滚动消息.
    - @ref WM_CAPTURECHANGED 窗口鼠标捕获改变消息.
    - @ref WM_KEYDOWN 窗口键盘按键消息.
    - @ref WM_KEYUP 窗口键盘弹起消息.
    - @ref WM_CHAR       窗口字符消息.
    - @ref WM_SIZE 窗口大小改变消息.
    - @ref WM_EXITSIZEMOVE 窗口退出移动或调整大小模式循环改，详情参见MSDN.
    - @ref WM_TIMER 窗口定时器消息.
    - @ref WM_SETFOCUS 窗口获得焦点.
    - @ref WM_KILLFOCUS 窗口失去焦点.
    - @ref WM_SETCURSOR  窗口设置鼠标光标.
    - @ref WM_DROPFILES  拖动文件到窗口.
        '''

    def isInclude(name):
        for patt in include_names:
            if patt in name:
                return True
        return False

    def isExclude(name):
        for patt in exclude_names:
            if patt in name:
                return True
        return False

    out_list = []
    for itemStr in include_wm_messages.split("."):
        try:
            wm = itemStr.split()[2]
            out_list.append(f'm.attr("{wm}") = {wm};')
        except IndexError:
            pass

    for define in header.defines:
        name = define.split()[0]
        if isInclude(name) and not isExclude(name):
            out_list.append(f'm.attr("{name}") = {name};')

    print("\n".join(out_list))

def parse_function(header: CppHeaderParser.CppHeader):
    generate_enumNames(header)
    #generate_structs(header)



def main():
    header = CppHeaderParser.CppHeader('xcgui.h')
    generate_enumNames(header)





if __name__ == '__main__':
    main()
