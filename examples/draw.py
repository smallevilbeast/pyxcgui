import xcgui
from xcgui import XApp, XWindow, XDraw, XEvent

WM_PAINT = 0xF


class DemoWindow(XWindow):
    def __init__(self):
        super(DemoWindow, self).__init__(400, 300, "demo")

        self.enableDragWindow(True)
        self.adjustLayout()

        self.regEvent(WM_PAINT, self.on_window_paint)

        self.image = xcgui.XImage.loadFile("resources\\image\\logo.png")
        self.image.setDrawType(xcgui.image_draw_type_fixed_ratio)
        self.shapePicture = xcgui.XShapePicture(50, 50, self)
        self.shapePicture.setImage(self.image)


    def on_window_paint(self, event: XEvent, _) -> bool:
        draw = XDraw.cast(event.wParam)
        rect = self.getClientRect()

        self.shapePicture.setAlpha(100)
        #draw.imageEx(self.image, 0, 0, rect.right - rect.left, rect.bottom - rect.top)
        #self.drawWindow(draw)

        draw.setBrushColor(xcgui.RGBA("#ffffffff"))
        rect.left += 20
        rect.top += 50
        rect.right -= 20
        rect.bottom -= 20
        draw.drawRect(rect)

        draw.setTextAlign(xcgui.textAlignFlag_center | xcgui.textAlignFlag_vcenter)
        draw.drawText("窗口自绘示例", rect)

        return True


def main():
    app = XApp(False)
    app.enableDPI(True)
    window = DemoWindow()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
