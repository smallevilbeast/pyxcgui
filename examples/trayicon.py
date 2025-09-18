#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
XCGUI 托盘图标示例
展示面向对象的XTrayIcon类的使用方法
"""


import xcgui
from xcgui import XApp, XWindow, XButton, XEdit, XTrayIcon, XImage


class DemoWindow(XWindow):
    def __init__(self):
        super(DemoWindow, self).__init__(400, 300, "XCGUI界面库 for python")
        self.enableLayout(True)
        self.setAlignV(xcgui.layout_align_center)
        self.setAlignH(xcgui.layout_align_center)
        self.enableHorizon(False)
        self.setSpace(20)
        self.btn = XButton(100, 30, "测试", self)
        self.btn.regEvent(xcgui.XE_BNCLICK, self.onBtnClick)
        self.edit = XEdit(200, 30, self)

        self.setupTrayIcon()

    def onBtnClick(self, event, userdata):
        self.edit.setText("你好，世界！")
        self.edit.redraw(True)

    def setupTrayIcon(self):
        self.tray = XTrayIcon(self, 100);
        self.tray.setIcon(xcgui.LoadIcon("resources\\exe.ico"))
        self.tray.setTips("XCGUI托盘图标测试")
        self.tray.add()


def main():
    app = XApp()
    app.enableDPI(True)
    window = DemoWindow()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
