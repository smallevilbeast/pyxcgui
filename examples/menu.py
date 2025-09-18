# -*- coding: utf8 -*-
import xcgui
from xcgui import XApp, XWindow, XEvent, XMenu, XButton, XImage, XSvg


class MenuDemo(XWindow):
    def __init__(self):
        super(MenuDemo, self).__init__(400, 300, "XCGUI界面库 for python")
        self.enableLayout(True)
        self.setAlignV(xcgui.layout_align_center)
        self.setAlignH(xcgui.layout_align_center)
        self.btn = XButton(80, 30, "弹出菜单", self)
        self.btn.regEvent(xcgui.XE_BNCLICK, self.onBtnClick)

        self.menu = XMenu()
        self.menu.setAutoDestroy(False)
        self.createMenu()

    def createMenu(self):
        self.menu.addItem(101, "复制")
        self.menu.addItem(102, "粘贴")
        self.menu.addItem(0, "", 0, xcgui.menu_item_flag_separator)
        self.menu.addItem(103, "最近文件")
        self.menu.addItemIcon(1031, "东京热.mp4", 103, XImage.loadFile('resources\\dianshangzhibo.ico'), 0)

    def onBtnClick(self, event: XEvent, userdata) -> bool:
        pt = self.btn.pointClientToScreen(xcgui.position_flag_leftBottom)
        self.menu.popup(self.getHWND(), pt.x, pt.y, self.btn)


def main():
    app = XApp()
    app.enableDPI(True)
    window = MenuDemo()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
