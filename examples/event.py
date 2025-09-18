import xcgui
from xcgui import XApp, XWindow, XEvent, XPoint


class EventParamDemo(XWindow):
    def __init__(self):
        super(EventParamDemo, self).__init__(400, 300, "XCGUI界面库 for python")

        # 注册窗口鼠标按下事件
        self.regEvent(xcgui.WM_LBUTTONDOWN, self.onWinButtonDown)

    def onWinButtonDown(self, event: XEvent, _):
        flags = event.wParam

        # 指针转python对象
        pt = XPoint.cast(event.lParam)
        print(f"flags: {flags}, pt.x: {pt.x}, pt.y: {pt.y}")
        return False


def main():
    app = XApp()
    app.enableDPI(True)
    window = EventParamDemo()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
