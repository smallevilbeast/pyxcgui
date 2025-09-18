# -*- coding: utf8 -*-
from xcgui import XApp, XWindow, XDesigner

app = XApp()
app.enableDPI(True)
XDesigner.loadResource("resources\\baidu\\resource.res")


class BaiduWindow(XWindow):
    def __init__(self):
        super(BaiduWindow, self).__init__()
        self.loadLayout("resources\\baidu\\main.xml")


window = BaiduWindow()
window.showWindow()
app.run()
app.exit()
