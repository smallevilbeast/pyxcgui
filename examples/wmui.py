# -*- coding: utf8 -*-
import xcgui
from xcgui import XApp, XWindow, XDesigner


def loadLightTheme():
    XDesigner.loadResource("resources\\WmUi\\Light\\WmUi.res")
    XDesigner.loadStyle("resources\\WmUi\\Light\\WmUi.css")

def loadDarkTheme():
    XDesigner.loadResource("resources\\WmUi\\Dark\\WmUi.res")
    XDesigner.loadStyle("resources\\WmUi\\Dark\\WmUi.css")


def to_xrect(rect: xcgui.RECT, left: int = 0, top: int = 0, right: int = 0, bottom: int = 0):
    rect.left += left
    rect.top += top
    rect.right += right
    rect.bottom += bottom
    return xcgui.XRect(rect.left, rect.top, rect.right, rect.bottom)


class ProgressBarStyle:
    # 覆盖
    STYLE_OVERLAY = 1
    # 内嵌
    STYLE_INLAY = 2
    # 偏移
    STYLE_OFFSET = 3



def drawProgressBar(progressBar: xcgui.XProgressBar, 
                    draw: xcgui.XDraw, 
                    style: int,  
                    draw_horiontal: bool, 
                    draw_tips: bool, 
                    color_name: str,
                    bg_color_name: str,
                    text_color_name: str,
                    progress_height: int,
                    radius: int):
    total = progressBar.getRange()
    pos = progressBar.getPos()
    progress = pos / total
    size = progressBar.getSize()

    if style == ProgressBarStyle.STYLE_OVERLAY or style == ProgressBarStyle.STYLE_INLAY:
        if draw_horiontal:
            top = (size.height - progress_height) // 2
            rect = xcgui.XRect(0, top, size.width, top + progress_height)
        else:
            left = (size.width - progress_height) // 2
            rect = xcgui.XRect(left, 0, left + progress_height, size.height)
    elif style == ProgressBarStyle.STYLE_OFFSET:
        if draw_horiontal:
            top = (size.height - progress_height) // 2
            rect = xcgui.XRect(4, top, size.width, top + progress_height)
        else:
            left = (size.width - progress_height) // 2
            rect = xcgui.XRect(left, 0, left + progress_height, size.height - 4)
    else:
        raise Exception("不支持的进度条样式")

    color = xcgui.XResource.getColor(bg_color_name)
    draw.setBrushColor(color)
    draw.fillRoundRect(rect, radius, radius)

    if style == ProgressBarStyle.STYLE_OVERLAY:
        if draw_horiontal:
            rect.right = int(rect.right * progress)
        else:
            rect.top += int(rect.bottom - rect.bottom * progress)
    elif style == ProgressBarStyle.STYLE_INLAY:
        radius -= 3
        if draw_horiontal:
            rect = xcgui.XRect(3, rect.top + 3, rect.right - 3, rect.bottom - 3)
            rect.right = int(rect.right * progress)
        else:
            rect = xcgui.XRect(rect.left + 3, rect.top + 3, rect.right - 3, rect.bottom - 3)
            rect.top += int(rect.bottom - rect.bottom * progress)
    elif style == ProgressBarStyle.STYLE_OFFSET:
        if draw_horiontal:
            rect = xcgui.XRect(0, rect.top - 4, rect.right - 4, rect.bottom - 4)
            rect.right = int(rect.right * progress)
        else:
            rect = xcgui.XRect(rect.left - 4, 4, rect.right - 4, rect.bottom)
            rect.top += int(rect.bottom - rect.bottom * progress)
    draw.setBrushColor(xcgui.XResource.getColor(color_name))
    draw.fillRoundRect(rect, radius, radius)


    if draw_tips:
        if style == ProgressBarStyle.STYLE_OVERLAY or style == ProgressBarStyle.STYLE_INLAY:
            if draw_horiontal:
                rect = xcgui.XRect(rect.right - 40, (size.height - 18) // 2, size.width, size.height)
            else:
                rect = xcgui.XRect((size.width - 28) // 2, rect.top + 5, size.width, size.height)
        elif style == ProgressBarStyle.STYLE_OFFSET:
            if draw_horiontal:
                rect = xcgui.XRect(rect.right - 40, (size.height - 18) // 2 - 2, size.width, size.height)
            else:
                rect = xcgui.XRect((size.width - 28) // 2 - 2, rect.top + 5, size.width, size.height)
        draw.setBrushColor(xcgui.XResource.getColor(text_color_name))
        draw.drawText(f'{int(progress * 100)}%', rect)




class WmUI(XWindow):
    def __init__(self):
        super().__init__()
        self.loadLayout("resources\\WmUi\\main.xml")
        btn: xcgui.XButton =  self.findObjectByName('切换')
        btn.regEvent(xcgui.XE_BUTTON_CHECK, self._onThemeSwitch)

        self._initInputSection()
        self._initViewSection()
        self._initOtherSection()

    
    def _onThemeSwitch(self, event: xcgui.XEvent, userdata):
        if event.wParam == 1:
            loadDarkTheme()
        else:
            loadLightTheme()
        self.redraw(True)


    def _initInputSection(self):
        for i in range(3):
            combo1: xcgui.XComboBox = self.findObjectByName(f'下拉组合框{i+1}')
            combo1.regEvent(xcgui.XE_COMBOBOX_POPUP_LIST, self._onComboBoxPopupList)
            combo1.createAdapter()
            for j in range(10):
                combo1.addItemText(f"组合框项 {j+1}")


    def _initViewSection(self):

        # 列表框1
        listbox1: xcgui.XListBox = self.findObjectByName('列表框1')
        listbox1.setItemTemplateXML("resources\\WmUi\\列表框项模板.xml")
        listbox1.createAdapter()
        for i in range(10):
            listbox1.addItemText(f"列表框项 {i+1}")

        # 列表1
        list1: xcgui.XList = self.findObjectByName('列表1')
        list1.setItemTemplateXML("resources\\WmUi\\列表项模板.xml")
        list1.createAdapter(4)
        list1.createAdapterHeader()

        list1.addColumnText(100, "name1", "列1")
        list1.addColumnText(100, "name2", "列2")
        list1.addColumnText(100, "name3", "列3")
        list1.addColumnText(160, "name4", "列4")
        for i in range(10):
            idx = list1.addRowTextEx("name1", f"列表项 {i+1} - 1")
            list1.setItemTextEx(idx, "name2", f"列表项 {i+1} - 2")
            list1.setItemTextEx(idx, "name3", f"列表项 {i+1} - 3")
            list1.setItemTextEx(idx, "name4", f"列表项 {i+1} - 4")

        # 树视图1
        tree1: xcgui.XTree = self.findObjectByName('列表树1')
        tree1.setItemTemplateXML("resources\\WmUi\\列表树项模板.xml")
        tree1.createAdapter()
        for i in range(10):
            idx = tree1.insertItemText(f'父项 {i+1}')
            for j in range(3):
                tree1.insertItemText(f'子项 {i+1}-{j+1}', idx)

        # 列表视图1
        listview1: xcgui.XListView = self.findObjectByName('列表视图1')
        listview1.setItemTemplateXML("resources\\WmUi\\列表视图项模板.xml")
        listview1.createAdapter()
        for i in range(5):
            group_idx = listview1.groupAddItemText(f'组 {i+1}')
            for j in range(3):
                child_idx = listview1.itemAddItemTextEx(group_idx, 'name3', f'组 {i+1} - 子项 {j+1}')
                listview1.itemSetImageEx(group_idx, child_idx, "name2", xcgui.XResource.getImage("呲牙"))

    def _initOtherSection(self):
        # _工具条1
        toolbar1: xcgui.XToolBar = self.findObjectByName('工具条1')
        btn1 = xcgui.XButton(0, 0, 60, 30, "Button1")
        btn1.setCssName('三态按钮_主要_填充_R4')
        
        btn2 = xcgui.XButton(0, 0, 60, 30, "Button2")
        btn2.setCssName('三态按钮_次要_填充_R4')

        btn3 = xcgui.XButton(0, 0, 60, 30, "Button3")
        btn3.setCssName('三态按钮_警告_填充_R4')

        btn4 = xcgui.XButton(0, 0, 60, 30, "Button4")
        btn4.setCssName('三态按钮_明亮_填充_R4')

        btn5 = xcgui.XButton(0, 0, 60, 30, "Button5")
        btn5.setCssName('三态按钮_主要_链接')
        toolbar1.insertEle(btn1, -1)
        toolbar1.insertEle(btn2, -1)
        toolbar1.insertEle(btn3, -1)
        toolbar1.insertEle(btn4, -1)
        toolbar1.insertEle(btn5, -1)

        
        # _菜单条1
        menubar1: xcgui.XMenuBar = self.findObjectByName('菜单条1')
        menubar1.regEvent(xcgui.XE_MENU_POPUP_WND, self._onMenuBarPopupWnd)
        menubar1.regEvent(xcgui.XE_MENU_DRAW_BACKGROUND, self._onMenuBarDrawBackground)
        menubar1.regEvent(xcgui.XE_MENU_DRAWITEM, self._onMenuBarDrawItem)
        menubar1.addButton("文件")
        menubar1.addButton("编辑")
        menubar1.addButton("查看")
        menubar1.addButton("帮助")
        for i in range(4):
            btn = menubar1.getButton(i)
            btn.enableBkTransparent(True)
            btn.enableCss(True)
            btn.setCssName("菜单条按钮_普通")

        menu: xcgui.XMenu = menubar1.getMenu(0)
        menu.enableDrawItem(True)
        menu.enableDrawBackground(True)
        menu.setItemHeight(35)
        menu.addItem(101, "新建")
        menu.addItem(102, "打开")
        menu.addItem(103, "保存")

        menu = menubar1.getMenu(1)
        menu.enableDrawItem(True)
        menu.enableDrawBackground(True)
        menu.setItemHeight(35)
        menu.addItem(201, "撤销")
        menu.addItem(202, "重做")
        menu.addItem(203, "剪切")

        menu = menubar1.getMenu(2)
        menu.enableDrawItem(True)
        menu.enableDrawBackground(True)
        menu.setItemHeight(35)
        menu.addItem(301, "放大")
        menu.addItem(302, "缩小")
        menu.addItem(303, "重置")

        menu = menubar1.getMenu(3)
        menu.enableDrawItem(True)
        menu.enableDrawBackground(True)
        menu.setItemHeight(35)
        menu.addItem(401, "帮助主题")
        menu.addItem(402, "关于")
        menu.addItem(403, "检查更新")

        
        # _tab条1
        tab1: xcgui.XTabBar = self.findObjectByName('tab条1')
        for i in range(10):
            tab1.addLabel(f"标签 {i+1}")
        font = xcgui.XResource.getFont('图标字体_s10')
        for i in range(10):
            label: xcgui.XButton = tab1.getLabel(i)
            label.setCssName("六态按钮_高亮_全_R8")
            label.setPadding(10, 0, 0, 0)
            close_btn: xcgui.XButton = tab1.getLabelClose(i)
            if (close_btn.getType() == xcgui.XC_BUTTON):
                close_btn.setCssName("三态按钮_警告_链接")
                close_btn.setFont(font)
                close_btn.setText("")
            else:
                close_btn.setPadding(10, 0, 10, 0)
        btn_left: xcgui.XButton = tab1.getButtonLeft()
        btn_left.setCssName("三态按钮_次要_链接")
        btn_left.setFont(font)
        btn_left.setText("")

        btn_right: xcgui.XButton = tab1.getButtonRight()
        btn_right.setCssName("三态按钮_次要_链接")
        btn_right.setFont(font)
        btn_right.setText("")

        # _滑动条1
        slider1: xcgui.XSliderBar = self.findObjectByName('滑动条1')
        slider1.getButton().setCssName("三态按钮_白色_填充_R8")

        # _滑动条2
        slider2: xcgui.XSliderBar = self.findObjectByName('滑动条2')
        slider2.getButton().setCssName("三态按钮_明亮_填充_R8")

        # _滑动条3
        slider3: xcgui.XSliderBar = self.findObjectByName('滑动条3')
        slider3.getButton().setCssName("三态按钮_白色_边框_R8")

        # 进度条1
        progress1: xcgui.XProgressBar = self.findObjectByName('进度条1')
        progress1.enableBkTransparent(True)
        progress1.regEvent(xcgui.XE_PAINT, self._onProgressBar1Paint)

        # 进度条2
        progress2: xcgui.XProgressBar = self.findObjectByName('进度条2')
        progress1.enableBkTransparent(True)
        progress2.regEvent(xcgui.XE_PAINT, self._onProgressBar2Paint)

        # 进度条3
        progress3: xcgui.XProgressBar = self.findObjectByName('进度条3')
        progress1.enableBkTransparent(True)
        progress3.regEvent(xcgui.XE_PAINT, self._onProgressBar3Paint)

        # 进度条4
        progress4: xcgui.XProgressBar = self.findObjectByName('进度条4')
        progress1.enableBkTransparent(True)
        progress4.regEvent(xcgui.XE_PAINT, self._onProgressBar4Paint)

        # 进度条5
        progress5: xcgui.XProgressBar = self.findObjectByName('进度条5')
        progress1.enableBkTransparent(True)
        progress5.regEvent(xcgui.XE_PAINT, self._onProgressBar5Paint)

        # 进度条6
        progress6: xcgui.XProgressBar = self.findObjectByName('进度条6')
        progress1.enableBkTransparent(True)
        progress6.regEvent(xcgui.XE_PAINT, self._onProgressBar6Paint)



    def _onComboBoxPopupList(self, event: xcgui.XEvent, userdata):
        window: xcgui.XWindow = xcgui.Cast(event.wParam)
        listbox: xcgui.XListBox = xcgui.Cast(event.lParam)
        listbox.setItemTemplateXML("resources\\WmUi\\列表框项模板.xml")
        listbox.setItemHeightDefault(30, 30)

        if window.getType() == xcgui.XC_COMBOBOXWINDOW or window.getType() == xcgui.XC_LISTBOX:
            window.setTransparentAlpha(255)
            window.setTransparentType(xcgui.window_transparent_shadow)
            window.setCssName("基础窗口_填充1_R8")
            window.setShadowInfo(10, 128, 8, False, 0)

            rect = window.getRect()
            rect.left -= 10
            rect.top -= 10
            rect.right += 10
            rect.bottom += 10
            window.setRect(rect)

            listbox.setCssName("列表框_普通")
            rect1 = listbox.getRect()
            rect1.left += 15
            rect1.right += 15
            rect1.top += 5
            rect1.bottom += 5
            listbox.setRect(rect1)


    def _onMenuBarPopupWnd(self, event: xcgui.XEvent, userdata):
        menu: xcgui.XMenu = xcgui.Cast(event.wParam)
        popup_wnd = xcgui.menu_popupWnd_.cast(event.lParam)
        window: xcgui.XWindow = xcgui.Cast(popup_wnd.hWindow)
        window.setTransparentAlpha(255)
        window.setTransparentType(xcgui.window_transparent_shadow)
        window.setCssName("基础窗口_填充2_R8")
        window.setShadowInfo(10, 128, 8, False, 0)
        window.setPadding(15, 15, 15, 15)

    def _onMenuBarDrawBackground(self, event: xcgui.XEvent, userdata):
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        draw_bg = xcgui.menu_drawBackground_.cast(event.lParam)
        draw.setBrushColor(xcgui.XResource.getColor("中性色2"))
        window = xcgui.Cast(draw_bg.hWindow)
        rect = window.getClientRect()
        draw.fillRoundRect(rect, 8, 8)
        draw.setBrushColor(xcgui.XResource.getColor("中性色3"))
        draw.drawRoundRect(rect, 8, 8)

    def _onMenuBarDrawItem(self, event: xcgui.XEvent, userdata):
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        draw_item = xcgui.menu_drawItem_.cast(event.lParam)
        if (draw_item.nState & xcgui.menu_item_flag_.menu_item_flag_select) != 0:
            draw.setBrushColor(xcgui.XResource.getColor("中性色4"))
            rect = to_xrect(draw_item.rcItem, 3, 3, -3, -3)
            draw.fillRoundRect(rect, 6, 6)
        draw.setBrushColor(xcgui.XResource.getColor("主文本色"))
        draw.setTextAlign(xcgui.textAlignFlag_vcenter | xcgui.textFormatFlag_DisplayFormatControl)
        rect = to_xrect(draw_item.rcItem, 20, 0, 0, 0)
        draw.drawText(draw_item.pText, rect)

    def _onProgressBar1Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_OVERLAY, 
                        True, 
                        True, 
                        "雾霾蓝", 
                        "中性色2", 
                        "主文本色", 
                        10, 
                        4)
        return True
        

    def _onProgressBar2Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_INLAY, 
                        True, 
                        True, 
                        "黑色", 
                        "黄色", 
                        "白色", 
                        20, 
                        10)
        return True

    def _onProgressBar3Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_OFFSET, 
                        True, 
                        True, 
                        "雾霾蓝", 
                        "主文本色", 
                        "主文本色", 
                        30, 
                        8)
        return True

    def _onProgressBar4Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_OVERLAY, 
                        False, 
                        False, 
                        "雾霾蓝", 
                        "中性色2", 
                        "主文本色", 
                        10, 
                        4)
        return True
    
    def _onProgressBar5Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_INLAY, 
                        False, 
                        True, 
                        "深红", 
                        "卡其黄", 
                        "米白色", 
                        30, 
                        15)
        return True

    def _onProgressBar6Paint(self, event: xcgui.XEvent, userdata):
        progressBar: xcgui.XProgressBar = event.sender
        draw: xcgui.XDraw = xcgui.Cast(event.wParam)
        drawProgressBar(progressBar, draw, 
                        ProgressBarStyle.STYLE_OFFSET, 
                        False, 
                        True, 
                        "灰豆绿", 
                        "主文本色", 
                        "深蓝", 
                        30, 
                        10)
        return True


if __name__ == '__main__':
    app = XApp()
    app.enableDPI(True)
    app.enableAutoRedrawUI(True)
    XDesigner.loadResource("resources\\WmUi\\resource.res")
    XDesigner.loadResource("resources\\WmUi\\WmUi_Base.res")
    loadLightTheme()
    window = WmUI()
    window.showWindow()
    app.run()
    app.exit()
