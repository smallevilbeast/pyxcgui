# -*- coding: utf8 -*-
import xcgui as xc


class DemoWindow(xc.XWindow):
    def __init__(self):
        super(DemoWindow, self).__init__(600, 400, "测试")
        btn = xc.XButton(150, 120, 80, 30, "打开", self)
        btn.regEvent(xc.XE_BNCLICK, self.onBtnClick)

    def onBtnClick(self, event, _):
        dlg = xc.XModelWindow(400, 300, "提示", self.getHWND())
        okBtn = xc.XButton(200, 250, 80, 30, "确定", dlg)
        okBtn.regEvent(xc.XE_BNCLICK, lambda e, _: dlg.endModal(xc.messageBox_flag_ok))
        cancelBtn = xc.XButton(290, 250, 80, 30, "取消", dlg)
        cancelBtn.regEvent(xc.XE_BNCLICK, lambda e, _: dlg.endModal(xc.messageBox_flag_cancel))

        flag = dlg.doModal()
        if flag == xc.messageBox_flag_ok:
            xc.Alert("提示", "你点了确定")


if __name__ == '__main__':
    app = xc.XApp()
    app.enableDPI(True)
    window = DemoWindow()
    window.show(True)
    app.run()
    app.exit()
