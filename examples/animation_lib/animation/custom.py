# -*- coding: utf8 -*-
import xcgui
import random


class FocusLineButtonPanel:
    def __init__(self, changeColor=True, focusOffset=-1):
        self._guiList = []
        self._panel: xcgui.XShapeRect = None
        self._focusLine: xcgui.XElement = None
        self._changeColor = changeColor
        self._focusOffset = focusOffset

    def release(self):
        for obj in self._guiList:
            obj.releaseAnimation()
            obj.destroy()
        self._guiList.clear()

    # 创建紫色面板
    def createPurpleFillPanel(self, x, y, width, height, parent):
        self._panel= xcgui.XShapeRect(x, y, width, height, parent)
        self._guiList.append(self._panel)
        self._panel.setFillColor(xcgui.RGBA("#ff9c27b0"))  # 紫色
        self._panel.enableBorder(False)

    # 创建紫色按钮
    def createPurpleButton(self, x, y, width, height, name, svg: xcgui.XSvg, parent):
        btn = xcgui.XButton(x, y, width, height, name, parent)
        self._guiList.append(btn)
        bkInfo = "{99:1.9.9;98:16(0)32(1)64(2);5:2(15)20(1)21(3)26(1)22(-5232740)23(255);5:2(15)20(1)21(3)26(1)22(" \
                 "-4702042)23(255);5:2(15)20(1)21(3)26(1)22(-4303953)23(255);}"
        btn.setBkInfo(bkInfo)
        btn.setTextColor(xcgui.RGBA(255, 255, 255, 255))
        svg.setSize(24, 24)
        svg.setUserFillColor(xcgui.RGBA(255, 255, 255, 255), True)
        btn.setIcon(xcgui.XImage.loadSvg(svg))
        btn.regEvent(xcgui.XE_BNCLICK, self.onPanelButtonClick)

    # 创建灰色面板
    def createGrayBorderPanel(self, x, y, width, height, parent):
        self._panel = xcgui.XShapeRect(x, y, width, height, parent)
        self._guiList.append(self._panel)
        self._panel.setBorderColor(xcgui.RGBA("#ffc8c8c8"))
        self._panel.enableFill(False)

    # 创建按钮
    def createWhiteButton(self, x, y, width, height, name, svg: xcgui.XSvg, color, bkColor, parent):
        btn = xcgui.XButton(x, y, width, height, name, parent)
        self._guiList.append(btn)
        btn.setIconAlign(xcgui.button_icon_align_top)
        btn.setTextColor(color)
        btn.addBkFill(xcgui.element_state_flag_stay, bkColor)
        btn.addBkFill(xcgui.element_state_flag_down, bkColor)
        btn.addBkFill(xcgui.element_state_flag_leave, xcgui.RGBA("#ffffffff"))

        svg.setUserFillColor(color, True)
        svg.setSize(32, 32)
        btn.setIcon(xcgui.XImage.loadSvg(svg))

        btn.regEvent(xcgui.XE_BNCLICK, self.onPanelButtonClick)

    # 当点击按钮时
    def onPanelButtonClick(self, event: xcgui.XEvent, _):
        sender: xcgui.XButton = event.sender
        if self._changeColor:
            # 取按钮颜色改变焦点线的颜色
            self._focusLine.clearBkInfo()
            self._focusLine.addBkFill(xcgui.element_state_flag_leave, sender.getTextColor())

        # 焦点线动画
        rect = sender.getRect()
        animaSeq = xcgui.XAnimationSequence(self._focusLine, 1)
        animaSeq.run(self._panel)
        if self._focusOffset == -1:
            self._focusLine.setWidth(rect.right - rect.left)
            animaSeq.move(400, rect.left, 0, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False)\
                .moveSetFlag(xcgui.animation_move_x)
        else:
            self._focusLine.setWidth(rect.right - rect.left - self._focusOffset * 2)
            animaSeq.move(400, rect.left + self._focusOffset, 0, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False)\
                .moveSetFlag(xcgui.animation_move_x)

        # 按钮上的图标变化
        btnSvg = sender.getIcon(0).getSvg()
        btnSvg.releaseAnimation(True)

        animaSvg = xcgui.XAnimationSequence(btnSvg, 1)
        animaSvg.run(sender)
        index = random.randint(0, 0xFFFFFFFF) % 3
        if index == 0:
            # 放大
            animaSvg.scale(600, 1.5, 1.5, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in, True)
        elif index == 1:
            # 360旋转
            animaSvg.rotate(600, 360, 1, 0, False)
        elif index == 2:
            # 连接旋转
            animaSvg.rotate(200, -45, 1, 0, False)
            animaSvg.rotate(300, 45, 1, 0, True)
            animaSvg.rotate(200, 0, 1, 0, False)

    def createFoucsLine(self, x, y, width, height, color, parent):
        self._focusLine = xcgui.XElement(x, y, width, height, parent)
        self._guiList.append(self._focusLine)
        self._focusLine.enableTopmost(True)
        self._focusLine.addBkFill(xcgui.element_state_flag_leave, color)


class FocusLineEditPanel:
    def __init__(self):
        self._guiList = []
        self._panel: xcgui.XShapeRect = None

    def release(self):
        for obj in self._guiList:
            obj.releaseAnimation()
            obj.destroy()
        self._guiList.clear()

    def createGrayBorderPanel(self, x, y, width, height, parent):
        self._panel = xcgui.XShapeRect(x, y, width, height, parent)
        self._guiList.append(self._panel)
        self._panel.setBorderColor(xcgui.RGBA(200, 200, 200, 255))
        self._panel.enableFill(False)

    def createEdit(self, x, y, width, height, parent):
        edit = xcgui.XEdit(x, y, width, height, parent)
        self._guiList.append(edit)
        edit.enableDrawFocus(False)

        edit.addBkFill(xcgui.element_state_flag_leave, xcgui.RGBA(235, 235, 235, 255))
        edit.addBkFill(xcgui.element_state_flag_stay, xcgui.RGBA(235, 235, 235, 255))
        edit.regEvent(xcgui.XE_SETFOCUS, self.onEditSetFocus)
        edit.regEvent(xcgui.XE_KILLFOCUS, self.onEditKillFocus)

    def onEditSetFocus(self, event: xcgui.XEvent, _):
        edit: xcgui.XEdit = event.sender
        rect = edit.getRect()
        focusEle = xcgui.XElement(int(rect.left + (rect.right - rect.left) / 2), rect.bottom - 2, 1, 2, edit.getParent())
        colors = ["#ffab48bc", "#fffea726", "#ff26a69a", "#ffc80000"]
        index = random.randint(0, 0xFFFFFFFF) % 4
        color = xcgui.RGBA(colors[index])
        focusEle.addBkFill(xcgui.element_state_flag_leave, color)
        edit.setUserData(focusEle)

        animaSeq = xcgui.XAnimationSequence(focusEle, 1)
        animaSeq.scaleSize(400, rect.right-rect.left, 2, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False)
        animaSeq.run(self._panel)

    def onEditKillFocus(self, event: xcgui.XEvent, _):
        edit: xcgui.XEdit = event.sender
        focusEle: xcgui.XElement = edit.getUserData()
        if focusEle.isValid():
            animaSeq = xcgui.XAnimationSequence(focusEle, 1)
            animaSeq.scaleSize(400, 0, 2, 1, xcgui.ease_flag_circ|xcgui.ease_flag_out, False)
            animaSeq.destroyObjectUI(0)
            animaSeq.run(self._panel)
