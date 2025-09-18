# -*- coding: utf8 -*-
from xcgui import XApp, XWindow, XDesigner

app = XApp()
app.enableDPI(True)
XDesigner.loadResource("resources\\login\\resource.res")


class LoginWindow(XWindow):
    def __init__(self):
        super(LoginWindow, self).__init__()
        self.loadLayout("resources\\login\\main.xml")


window = LoginWindow()
window.showWindow()
app.run()
app.exit()
