<h1 align="center">XCGUI for Python</h1>
<p align="center">
    <a href="https://github.com/twgh/xcgui/releases"><img src="https://img.shields.io/badge/release-0.1.1-blue.svg?" alt="release"></a>
    <a href="http://www.xcgui.com"><img src="https://img.shields.io/badge/XCGUI-3.3.4-blue.svg?" alt="XCGUI"></a>
    <a href="https://opensource.org/licenses/MIT"><img src="https://img.shields.io/badge/License-MIT-brightgreen.svg?" alt="License"></a>
    <br><br>
    <a href="https://github.com/smallevilbeast/pyxcgui-example">程序示例</a>&nbsp;&nbsp;
    <a href="http://www.xcgui.com/doc-ui/">官方文档</a>&nbsp;&nbsp;
	<a href="http://mall.xcgui.com">官方资源</a>
</p>




## 介绍

- 本库封装自炫彩界面库，功能丰富(1000多个API接口)，简单易用，轻量级，高度DIY自定义，支持一键换肤。
- 炫彩界面库是由C/C++语言开发：软件运行效率高，不需要第三方库的支持，不依赖MFC，ATL，WINDOWS标准控件等。
- DirectUI设计思想：在窗口内没有子窗口，界面元素都是逻辑上的区域(无HWND句柄，安全，灵活)，所有UI元素都是自主开发(不受系统限制)，更加灵活的实现各种程序界面，满足不同用户的需求。
- 拥有免费的UI设计器：快速开发工具，所见即所得，高度自定义系统(DIY)，让UI开发变的更加简单。
- 支持Direct2D，硬件加速，能更大程度的发挥硬件特性，创建高性能，高质量的2D图形。
- 有完善的中文官方文档：[中文官方文档](http://www.xcgui.com/doc-ui/)

## 获取

```
pip install xcgui
```

## 可视化UI设计器

使用UI设计器可以快速设计界面，节省大量代码。

[![uidesigner](https://z3.ax1x.com/2021/09/15/4Vmh9S.png)](https://github.com/twgh/xcgui-example/tree/main/uidesigner)

[设计器使用例子]只有这么多代码：

```python
from xcgui import XApp, XWindow, XDesigner

app = XApp()
XDesigner.loadResource("baidu\\resource.res")


class BaiduWindow(XWindow):
    def __init__(self):
        super(BaiduWindow, self).__init__()
        self.loadLayout("baidu\\main.xml")
        
        
window = BaiduWindow()
window.showWindow()
app.run()
app.exit()
```


## 简单窗口（纯代码）



```python
# -*- coding: utf8 -*-
import xcgui
from xcgui import XApp, XWindow, XButton, XEdit


class DemoWindow(XWindow):
    def __init__(self):
        super(DemoWindow, self).__init__(400, 300, "XCGUI界面库 for python")
        self.enableLayout(True)
        self.setAlignV(xcgui.layout_align_center)
        self.setAlignH(xcgui.layout_align_center)
        self.enableHorizon(False)
        self.setSpace(20)
        self.btn = XButton(100, 30, "测试", self)
        self.btn.regEvent(34, self.onBtnClick)
        self.edit = XEdit(200, 30, self)

    def onBtnClick(self, event, userdata):
        self.edit.setText("你好，世界！")
        self.edit.redraw(True)


def main():
    app = XApp()
    window = DemoWindow()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()

```

帮助&支持
-------------------------
点击链接加入群聊 [PyXCGUI交流群](https://jq.qq.com/?_wv=1027&k=oIXzbTbI)
