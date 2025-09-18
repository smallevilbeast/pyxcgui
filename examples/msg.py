# -*- coding: utf8 -*-
import xcgui
from xcgui import XApp, XWindow, XEvent, XButton, XMsgWindow


class MsgDemo(XWindow):
    def __init__(self):
        super(MsgDemo, self).__init__(400, 300, "XCGUI界面库 for python")
        self.enableLayout(True)
        self.setAlignV(xcgui.layout_align_center)
        self.setAlignH(xcgui.layout_align_center)
        self.btn = XButton(80, 30, "弹出消息框", self)
        self.btn.regEvent(xcgui.XE_BNCLICK, self.onBtnClick2)

    def onBtnClick(self, event: XEvent, _) -> bool:
        msg = XMsgWindow("炫彩界面库", "标题",
                         xcgui.messageBox_flag_ok | xcgui.messageBox_flag_icon_info,
                         self.getHWND(),
                         xcgui.window_style_modal)
        flag = msg.doModal()
        print(flag)

    def onBtnClick2(self, event, _):
        flag = xcgui.MessageBox("消息提示", "Python库将发布",
                                xcgui.messageBox_flag_ok |
                                xcgui.messageBox_flag_cancel |
                                xcgui.messageBox_flag_icon_qustion,
                                self.getHWND())
        if flag == xcgui.messageBox_flag_ok:
            xcgui.Alert("提示", "你点击了确定")
        elif flag == xcgui.messageBox_flag_cancel:
            xcgui.Alert("提示", "你点击了取消")


def main():
    app = XApp()
    app.enableDPI(True)
    window = MsgDemo()
    window.showWindow()
    app.run()
    app.exit()


if __name__ == '__main__':
    main()
