from xcgui import XApp
from animation_lib.animation.main import AnimationWindow

if __name__ == '__main__':
    app = XApp(True)
    app.enableDPI(True)
    app.setPaintFrequency(10)
    # app.showLayoutFrame(True)
    # app.showSvgFrame(True)
    window = AnimationWindow()
    window.show(True)
    app.run()
    app.exit()
