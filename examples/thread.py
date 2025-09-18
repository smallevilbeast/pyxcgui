# -*- coding: utf8 -*-
import xcgui
import functools
import threading
import requests
from xcgui import XApp, XWindow, XEvent, XButton, XEdit, RunUiThread


def threaded(f):
    @functools.wraps(f)
    def wrapper(*args, **kwargs):
        t = threading.Thread(target=f, args=args, kwargs=kwargs)
        t.daemon = True
        t.start()

    return wrapper


class MenuDemo(XWindow):
    def __init__(self):
        super(MenuDemo, self).__init__(400, 300, "XCGUI界面库 for python")
        self.enableLayout(True)
        self.setAlignV(xcgui.layout_align_center)
        self.setAlignH(xcgui.layout_align_center)
        self.enableHorizon(False)
        self.setSpace(20)
        self.btn = XButton(300, 30, "主线程执行测试", self)
        self.btn.regEvent(34, self.onBtnClick)
        self.edit = XEdit(300, 30, self)

    # 通过线程获取ip
    @threaded
    def asyncGetIpInfo(self):
        text = requests.get('http://myip.ipip.net/').text
        self.updateBtnTextOnUiThread(text)

    def onBtnClick(self, event: XEvent, _) -> bool:
        self.asyncGetIpInfo()

    # 通过装饰器，在ui线程执行更改
    @RunUiThread()
    def updateBtnTextOnUiThread(self, text):
        self.edit.setText(text)
        self.edit.redraw(True)


def main():
    app = XApp()
    app.enableDPI(True)
    window = MenuDemo()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
