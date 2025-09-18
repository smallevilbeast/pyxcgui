# -*- coding: utf8 -*-
from xcgui import XApp, XWindow, XDesigner

app = XApp()
app.enableDPI(True)
XDesigner.loadResource("resources\\qqmusic\\resource.res")


class QQMuiscWindow(XWindow):
    def __init__(self):
        super(QQMuiscWindow, self).__init__()
        self.loadLayout("resources\\qqmusic\\main.xml")


window = QQMuiscWindow()
window.showWindow()
app.run()
app.exit()
