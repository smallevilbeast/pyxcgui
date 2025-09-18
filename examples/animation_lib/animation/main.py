# -*- coding: utf8 -*-
import time

import xcgui
import win32con

from xcgui import (
    XWindow, XButton, XAnimationGroup, XAnimationSequence, XApp, XSvg, XEvent, XDraw, XButton
)
from ..common.xdg import getResource
from ..animation.custom import FocusLineButtonPanel, FocusLineEditPanel


class AnimationWindow(XWindow):
    def __init__(self):
        super(AnimationWindow, self).__init__()

        # 加载布局
        self.loadLayout(getResource("animation", "main.xml"))
        # self.enableLayout(False)

        # 注册窗口绘制消息
        self.regEvent(xcgui.WM_PAINT, self.onWindowPaint)

        # 全局使用XSvg对象
        self._svgList = []

        self._guiList = []

        self._guiChildList = []

        self._customObjectList = []

        self._layoutMain: xcgui.XLayoutEle = self.findObjectByName("global:layoutMain")

        # 注册两侧主按钮的点击事件
        for i in range(1, 28):
            btn: XButton = self.findObjectByName(f"global:btn{i}")
            btn.setTypeEx(xcgui.button_type_radio)
            btn.setGroupId(1)
            btnCallback = getattr(self, f"onGlobalBtn{i}Click", None)
            if btn and btnCallback:
                btn.regEvent(xcgui.XE_BNCLICK, btnCallback)

    def onWindowPaint(self, event: XEvent, _):
        draw = XDraw.cast(event.wParam)
        self.drawWindow(draw)

        for svg in self._svgList:
            draw.drawSvgSrc(svg)
        return True

    def releaseAllAnimation(self):
        svg: XSvg = None
        for svg in self._svgList:
            svg.releaseAnimation(False)
            svg.destroy()
        self._svgList.clear()

        for child in self._guiChildList:
            child.releaseAnimation(False)
        self._guiChildList.clear()

        for gui in self._guiList:
            gui.releaseAnimation(False)
            gui.destroy()
        self._guiList.clear()

        for obj in self._customObjectList:
            obj.release()

        self.releaseAnimation(False)

    # 下落  缩放 缓动
    def onGlobalBtn1Click(self, event, _):
        self.releaseAllAnimation()

        svg_names = '公益,时间戳,技术服务,底层架构,查验,接口配置'
        self._svgList = [XSvg.loadFile(getResource("svg", f"{name}.svg")) for name in svg_names.split(',')]

        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)

        left = 130
        top = 22
        space = 130
        for i in range(0, len(self._svgList)):
            self._svgList[i].setSize(100, 100)
            self._svgList[i].setPosition(left + i * space, top)
            animaSeq = XAnimationSequence(self._svgList[i])
            animaGroup.addItem(animaSeq)

            animaSeq.move(500, left + i * space, 22, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)
            animaSeq.delay(500)

            animaSeq.delay(100 * i)
            animaSeq.alpha(500, 0, 1)

            animaSeq.delay(500)

            animaSeq.alpha(500, 255, 1)
            animaSeq.delay(1000)

            animaSeq.move(2000, left + i * space, 500, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)
            animaSeq.delay(1000)

            animaSeq.delay(i * 200)
            animaSeq.scale(1200, 2.0, 2.0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in, True)

    # 下落 呼吸SVG
    def onGlobalBtn2Click(self, event, _):
        self.releaseAllAnimation()
        left = 450
        top = 22

        svg: XSvg = XSvg.loadFile(getResource("svg", "公益.svg"))
        svg.setSize(100, 100)
        svg.setPosition(left, top)
        self._svgList.append(svg)

        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)

        animaSeq = XAnimationSequence(svg, 0)
        animaGroup.addItem(animaSeq)
        animaSeq.move(2000, left, 500, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)
        animaSeq.delay(2000)
        animaSeq.move(500, left, 22, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)

        animaSeq = XAnimationSequence(svg, 1)
        animaGroup.addItem(animaSeq)
        animaSeq.delay(2000)
        animaSeq.scale(2000, 2.0, 2.0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in, True)

    # 呼吸SVG
    def onGlobalBtn3Click(self, event, _):
        self.releaseAllAnimation()
        left = 300
        top = 150

        svg: XSvg = XSvg.loadFile(getResource("svg", "公益.svg"))
        svg.setSize(300, 300)
        svg.setPosition(left, top)
        self._svgList.append(svg)

        animaSeq = XAnimationSequence(svg, 1)
        animaSeq.scale(1500, 2.0, 2.0, xcgui.ease_flag_cubic | xcgui.ease_flag_in, True)
        animaSeq.run(self)

    # 不透明度SVG
    def onGlobalBtn4Click(self, event, _):
        self.releaseAllAnimation()
        left = 200
        top = 30

        svg_names = '公益,公益,公益'
        self._svgList = [XSvg.loadFile(getResource("svg", f"{name}.svg")) for name in svg_names.split(',')]
        for i in range(len(self._svgList)):
            self._svgList[i].setSize(100, 100)
            self._svgList[i].setPosition(left + i * 100, top)

            animaSeq = XAnimationSequence(self._svgList[i], 0)
            if i == 0:
                animaSeq.alphaEx(3000, 0, 255, 1, 0, True)
            else:
                animaSeq.alpha(3000, 0, 1, 0, True)
            animaSeq.run(self)

        svg_names = '淘公仔文字,淘公仔文字,淘公仔文字'
        for name in svg_names.split(','):
            self._svgList.append(XSvg.loadFile(getResource("svg", f"{name}.svg")))

        top = 100
        for i in range(3, 6):
            li = i - 3
            self._svgList[i].setPosition(left, top + li * 150)
            animaSeq = XAnimationSequence(self._svgList[i], 0)
            if li == 0:
                animaSeq.alpha(3000, 0, 1, 0, True)
            elif li == 1:
                animaSeq.alphaEx(3000, 255, 50, 1, 0, True)
            else:
                animaSeq.alphaEx(3000, 50, 255, 1, 0, True)
            animaSeq.run(self)

    # 移动
    def onGlobalBtn5Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 30

        svg_names = '公益,时间戳,技术服务'
        self._svgList = [XSvg.loadFile(getResource("svg", f"{name}.svg")) for name in svg_names.split(',')]
        for i in range(len(self._svgList)):
            self._svgList[i].setSize(100, 100)
            self._svgList[i].setPosition(left, top + i * 100)
            animaSeq = XAnimationSequence(self._svgList[i], 1)
            animaSeq.run(self)

            if i == 0:
                # 循环10次
                animaSeq.move(2000, 750, top + i * 100, 10, 0, True)
            elif i == 1:
                # 一次，往返
                animaSeq.move(2000, 750, top + i * 100, 1, 0, True)
            else:
                # 一次，不往返
                animaSeq.move(2000, 750, top + i * 100, 1, 0, False)

    # 移动
    def onGlobalBtn6Click(self, event, _):
        self.releaseAllAnimation()
        left = 140
        top = 100
        space = 60

        names = '循环滚动,往返滚动,移动到末尾'
        colors = ['#ffd20962', '#fff47721', '#ff7ac143']
        for i, name in enumerate(names.split(',')):
            shapeText = xcgui.XShapeText(left, top + i * space, 120, 30, name, self)
            shapeText.setTextColor(xcgui.RGBA(colors[i]))
            shapeText.setFont(xcgui.XFont.createFromName("微软雅黑", 16, xcgui.fontStyle_bold))
            self._guiList.append(shapeText)

            animaSeq = XAnimationSequence(shapeText, 0 if i == 0 else 1)
            animaSeq.run(self)
            animaSeq.move(1500 if i == 2 else 3000, 750, top + i * space, 1,
                          xcgui.ease_flag_cubic | xcgui.ease_flag_in,
                          False if i == 2 else True)

    # 移动
    def onGlobalBtn7Click(self, event, _):
        self.releaseAllAnimation()
        left = 125
        top = 50
        space = 62

        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)

        for i in range(0, 12):
            btn = XButton(left + i * space, top, 60, 30, "透明度", self)
            self._guiList.append(btn)

            animaSeq = XAnimationSequence(btn, 0)
            animaGroup.addItem(animaSeq)

            animaSeq.delay(500)
            animaSeq.delay(100 * i)
            animaSeq.alphaEx(1200, 255, 20, 1, 0, True)

        top = 100
        space = 110
        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)
        for i in range(0, 7):
            btn = XButton(left + i * space, top, 80, 30, "循环滚动", self)
            self._guiList.append(btn)

            animaSeq = XAnimationSequence(btn, 0)
            animaGroup.addItem(animaSeq)
            animaSeq.move(500, left + i * space, top, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)
            animaSeq.delay(500)

            animaSeq.delay(100 * i)
            animaSeq.alphaEx(500, 255, 0, 1)

            animaSeq.delay(500)

            #
            animaSeq.alphaEx(500, 0, 255, 1)
            animaSeq.delay(1000)

            # 下落
            animaSeq.move(2000, left + i * space, 500, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out)
            animaSeq.delay(1000)

            # 放大
            animaSeq.delay(i * 200)
            animaSeq.scale(1200, 1.5, 2.0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in, True)

    def onGlobalZone8MouseStay(self, event: XEvent, index):
        for idx, child in enumerate(self._guiChildList):
            if idx != index:
                child.setAlpha(200)

        animaSeq = XAnimationSequence(event.sender, 1)
        animaSeq.layoutWidth(300, xcgui.layout_size_weight, 200, 1, 0, False)
        animaSeq.run(self)

    def onGlobalZone8MouseLeave(self, event: XEvent, index):
        animaSeq = XAnimationSequence(event.sender, 1)
        animaSeq.layoutWidth(300, xcgui.layout_size_weight, 100, 1, 0, False)
        animaSeq.run(self)

        for child in self._guiChildList:
            child.setAlpha(255)

    # 布局焦点展开
    def onGlobalBtn8Click(self, event, _):
        self.releaseAllAnimation()
        layout = xcgui.XLayoutEle(750, 100, self._layoutMain)
        layout.setSpace(20)
        layout.layoutSetMargin(10, 100, 0, 0)
        self._guiList.append(layout)

        for i in range(0, 3):
            childLayout = xcgui.XLayoutEle(0, 0, 100, 100, layout)
            childLayout.enableMouseThrough(False)
            childLayout.setPadding(10, 0, 10, 0)
            childLayout.layoutSetWidth(xcgui.layout_size_weight, 100)
            childLayout.getBkManager().setInfo("{99:1.9.9;98:16(0);5:2(15)20(1)21(3)26(1)"
                                               "22(-7839744)23(255)9(5,5,5,5);}")
            childLayout.regEvent(xcgui.XE_MOUSESTAY, self.onGlobalZone8MouseStay, i)
            childLayout.regEvent(xcgui.XE_MOUSELEAVE, self.onGlobalZone8MouseLeave, i)
            self._guiChildList.append(childLayout)

            shapeText = xcgui.XShapeText(0, 0, 100, 100, "鼠标移动到上面查看", childLayout)
            shapeText.setTextAlign(xcgui.textAlignFlag_center | xcgui.textAlignFlag_vcenter)
            shapeText.setTextColor(xcgui.RGBA("#ffffffff"))
            shapeText.layoutSetWidth(xcgui.layout_size_fill, 0)

        self.adjustLayout()
        self.redraw(False)

    def onGlobalZone9MouseChange(self, event: XEvent, otherEle: xcgui.XElement):
        ele: xcgui.XElement = event.sender
        # 释放当前对象关联的动画
        ele.releaseAnimation(False)
        otherEle.releaseAnimation(False)

        # 当前隐藏
        animaSeq = XAnimationSequence(ele, 1)
        animaSeq.run(ele)
        animaSeq.alphaEx(1000, 255, 0, 1)
        animaSeq.show(0, False)

        # 显示
        otherEle.setAlpha(0)
        otherEle.show(True)
        animaSeq = XAnimationSequence(otherEle, 1)
        animaSeq.run(otherEle)
        animaSeq.delay(500)
        animaSeq.alphaEx(1000, 0, 255, 1)

    # 图片切换- 两个基础元素透明度切换
    def onGlobalBtn9Click(self, event, _):
        self.releaseAllAnimation()

        left = 150
        top = 50
        for i in range(0, 3):
            image = xcgui.XImage.loadFile(getResource('image', f"img-{i * 2 + 1}.jpg"))
            image.setDrawType(xcgui.image_draw_type_fixed_ratio)
            ele = xcgui.XElement(left, top, 212, 271, self)
            ele.addBkImage(xcgui.element_state_flag_leave, image)

            image2 = xcgui.XImage.loadFile(getResource('image', f"img-{i * 2 + 2}.jpg"))
            image2.setDrawType(xcgui.image_draw_type_fixed_ratio)
            ele2 = xcgui.XElement(left, top, 212, 271, self)
            ele2.addBkImage(xcgui.element_state_flag_leave, image2)
            ele2.show(False)

            ele.regEvent(xcgui.XE_MOUSESTAY, self.onGlobalZone9MouseChange, ele2)
            ele2.regEvent(xcgui.XE_MOUSELEAVE, self.onGlobalZone9MouseChange, ele)

            shapeText = xcgui.XShapeText(left, top + 280, 200, 20, "图片切换\n$66.66", self)
            shapeText.setTextColor(xcgui.RGBA(80, 80, 80, 255))
            self._guiList.append(ele)
            self._guiList.append(ele2)
            self._guiList.append(shapeText)

            left += (212 + 10)

        self.redraw(False)

    def onGlobalZone10MouseStay(self, event: XEvent, _):
        ele: xcgui.XElement = event.sender
        ele.releaseAnimation(False)

        pic = ele.getChildByIndex(0)
        animaSeq = XAnimationSequence(pic, 1)
        animaSeq.run(ele)
        animaSeq.move(500, -(212 + 10), 0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in)

        pic = ele.getChildByIndex(1)
        animaSeq = XAnimationSequence(pic, 1)
        animaSeq.run(ele)
        animaSeq.move(500, 0, 0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in)

    def onGlobalZone10MouseLeave(self, event: XEvent, _):
        ele: xcgui.XElement = event.sender
        ele.releaseAnimation(False)

        # 还原
        pic = ele.getChildByIndex(0)
        animaSeq = XAnimationSequence(pic, 1)
        animaSeq.run(ele)
        animaSeq.move(500, 0, 0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in)

        pic = ele.getChildByIndex(1)
        animaSeq = XAnimationSequence(pic, 1)
        animaSeq.run(ele)
        animaSeq.move(500, 212 + 10, 0, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_in)

    # 图片切换2 - 滚动切换
    def onGlobalBtn10Click(self, event, _):
        self.releaseAllAnimation()

        left = 150
        top = 50

        for i in range(0, 3):
            ele = xcgui.XElement(left, top, 212, 271, self)
            ele.enableDrawBorder(False)
            ele.regEvent(xcgui.XE_MOUSESTAY, self.onGlobalZone10MouseStay)
            ele.regEvent(xcgui.XE_MOUSELEAVE, self.onGlobalZone10MouseLeave)

            image = xcgui.XImage.loadFile(getResource('image', f"img-{i * 2 + 1}.jpg"))
            image.setDrawType(xcgui.image_draw_type_fixed_ratio)
            shapePicture = xcgui.XShapePicture(0, 0, 212, 271, ele)
            shapePicture.setImage(image)

            image2 = xcgui.XImage.loadFile(getResource('image', f"img-{i * 2 + 2}.jpg"))
            image2.setDrawType(xcgui.image_draw_type_fixed_ratio)
            shapePicture2 = xcgui.XShapePicture(212 + 10, 0, 212, 271, ele)
            shapePicture2.setImage(image2)

            shapeText = xcgui.XShapeText(left, top + 280, 200, 20, "图片切换\n$66.66", self)
            shapeText.setTextColor(xcgui.RGBA(80, 80, 80, 255))
            self._guiList.append(ele)
            self._guiList.append(shapeText)

            left += (212 + 10)

        self.redraw(False)

    # 图片切换2 - 滚动切换
    def onGlobalBtn11Click(self, event, _):
        self.releaseAllAnimation()
        left = 160
        top = 80
        svgText1 = '<svg x="0" y="0" width="25" height="25" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#ee6362" /></svg> '
        svgText2 = '<svg x="0" y="0" width="25" height="25" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#2cb0b2" /></svg> '
        svgText3 = '<svg x="0" y="0" width="20" height="20" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#f00" /></svg> '

        # 两个球型交替移动
        svg = xcgui.XSvg.loadString(svgText1)
        svg.setPosition(left, top)
        self._svgList.append(svg)
        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)
        animaSeq = XAnimationSequence(svg, 1)
        animaGroup.addItem(animaSeq)
        animaSeq.move(1000, left + 50, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)
        animaSeq.move(1000, left, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)

        svg = XSvg.loadString(svgText2)
        svg.setPosition(left + 50, top)
        self._svgList.append(svg)
        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)
        animaSeq = XAnimationSequence(svg, 1)
        animaGroup.addItem(animaSeq)
        animaSeq.move(1000, left, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)
        animaSeq.move(1000, left + 50, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)

        # 一排小球 缩放
        left = 350
        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)

        for i in range(0, 10):
            svg = XSvg.loadString(svgText3)
            svg.setPosition(left + i * 50, top)
            self._svgList.append(svg)

            animaSeq = XAnimationSequence(svg, 0)
            animaGroup.addItem(animaSeq)
            animaSeq.delay(i * 200)
            animaSeq.scale(1000, 2.0, 2.0, 1, 0, True)

        # 一排小球 垂直缩放
        top = 150
        animaGroup = XAnimationGroup(0)
        animaGroup.run(self)

        for i in range(0, 10):
            svg = XSvg.loadString(svgText3)
            svg.setPosition(left + i * 50, top)
            self._svgList.append(svg)

            animaSeq = XAnimationSequence(svg, 0)
            animaGroup.addItem(animaSeq)
            animaSeq.delay(i * 200)
            animaSeq.scale(1000, 1.0, 2.0, 1, 0, True)

        # 一排小球上下波浪
        left = 150
        top = 200
        for i in range(0, 10):
            svg = XSvg.loadString(svgText3)
            svg.setPosition(left + i * 35, top)
            self._svgList.append(svg)

            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.run(self)
            animaSeq.delay(i * 100).enableCompleteRelease(True)
            animaSeq.move(1200, left + i * 35, top + 100, 1, 0, True)

        # 一排小球上下波浪
        left = 550
        for i in range(0, 10):
            svg = XSvg.loadString(svgText3)
            svg.setPosition(left + i * 35, top)
            self._svgList.append(svg)

            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.run(self)
            animaSeq.delay(i * 150).enableCompleteRelease(True)
            animaSeq.move(1000, left + i * 35, top + 50, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, True)

        # 一排小球跳动
        left = 150
        top = 350
        for i in range(0, 10):
            svg = XSvg.loadString(svgText3)
            svg.setPosition(left + i * 35, top)
            self._svgList.append(svg)

            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.run(self)
            animaSeq.delay(i * 200).enableCompleteRelease(True)
            animaSeq.move(500, left + i * 35, top + 50, 1, xcgui.ease_flag_quint | xcgui.ease_flag_out, True)
            animaSeq.delay(1700)

        # 一排小球移动
        svgText4 = '<svg x="0" y="0" width="15" height="15" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#f00" /></svg>'
        left = 220
        top = 600
        for i in range(5, -1, -1):
            svg = XSvg.loadString(svgText4)
            svg.setPosition(100 - (i * 25), top)
            svg.setAlpha(0)
            self._svgList.append(svg)

            # 创建两个动画序实现移动和透明度变化并行执行
            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.run(self)
            animaSeq.delay(i * 100).enableCompleteRelease(True)
            animaSeq.move(2000, 500 - (i * 25), top, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False)
            animaSeq.move(2000, 900 - (i * 25), top, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in, False)
            animaSeq.move(0, 100 - (i * 25), top, 1)
            animaSeq.delay(500)

            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.run(self)
            animaSeq.delay(1 * 100).enableCompleteRelease(True)
            animaSeq.alphaEx(2000, 0, 255, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False)
            animaSeq.alphaEx(2000, 255, 0, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in, False)
            animaSeq.delay(500)

    # 旋转
    def onGlobalBtn12Click(self, event, _):
        self.releaseAllAnimation()
        left = 120
        top = 100

        # 移动 360度旋转
        svg = XSvg.loadFile(getResource("svg", "淘公仔文字.svg"))
        svg.setPosition(left, top)
        svg.setRotateAngle(0)
        self._svgList.append(svg)

        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(1700, 360, 1, 0)
        animaSeq.run(self)

        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.move(3000, left + 500, top, 1, 0, True)
        animaSeq.run(self)

        # 移动 往返旋转
        top = 350
        svg = XSvg.loadFile(getResource("svg", "淘公仔文字.svg"))
        svg.setPosition(left, top)
        svg.setRotateAngle(-45)
        svg.setUserFillColor(xcgui.RGBA("#ffff0000"), True)
        self._svgList.append(svg)

        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(1500, 45, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in)
        animaSeq.rotate(1500, -45, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in)
        animaSeq.run(self)

        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.move(3000, left + 500, top, 1, 0, True)
        animaSeq.run(self)

    # 旋转
    def onGlobalBtn13Click(self, event, _):
        self.releaseAllAnimation()
        left = 130
        top = 80

        # 自身 摇摆 往返
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(-45)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(1000, 45, 1, 0, True)
        animaSeq.run(self)

        # 自身 旋转
        left = 500
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(1000, 360, 1, xcgui.ease_flag_expo | xcgui.ease_flag_in, False)
        animaSeq.rotate(0, 0, 1, 0, False)
        animaSeq.run(self)

        # 两个叠加 悬挂摆动
        left = 300
        top = 250
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(45)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(3000, 100, 1, xcgui.ease_flag_quad | xcgui.ease_flag_inOut, True) \
            .rotateSetCenter(left + 10, top + 50, False)
        animaSeq.run(self)

        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(45)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(3000, 100, 1, xcgui.ease_flag_cubic | xcgui.ease_flag_inOut, True) \
            .rotateSetCenter(left + 10, top + 50, False)
        animaSeq.run(self)

        # 砍东西效果
        left = 500
        top = 400
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(-45)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(1500, 0, 1, xcgui.ease_flag_expo | xcgui.ease_flag_in, True) \
            .rotateSetCenter(left, top, False)
        animaSeq.run(self)

    # 旋转
    def onGlobalBtn14Click(self, event, _):
        self.releaseAllAnimation()
        left = 130
        top = 50

        # 自身 摇摆 往返
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setSize(50, 50)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        svg.setPosition(left, top)
        svg.setRotateAngle(0)
        self._svgList.append(svg)

        group = XAnimationGroup(0)

        # 旋转
        animaSeq = XAnimationSequence(svg, 0)
        group.addItem(animaSeq)
        animaSeq.rotate(600, 360, 4, 0, False)

        # 缩放
        animaSeq = XAnimationSequence(svg, 0)
        group.addItem(animaSeq)
        animaSeq.scale(2400, 7.0, 7.0, 1, 0, False)
        animaSeq.delay(1000)
        animaSeq.scale(1000, 1.0 / 7.0, 1.0 / 7.0, 1, 0, False)

        # 移动
        animaSeq = XAnimationSequence(svg, 0)
        group.addItem(animaSeq)
        animaSeq.move(2400, left + 500, top + 300, 1, 0, False)
        animaSeq.delay(1000)
        animaSeq.move(1000, left, top, 1, 0, False)
        group.run(self)

    # 旋转 开合效果
    def onGlobalBtn15Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 200
        height = 0
        width = 0

        # 砍东西效果
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(-45)
        self._svgList.append(svg)
        height = svg.getHeight()
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(2000, 0, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, True) \
            .rotateSetCenter(left, top + height / 2, False)
        animaSeq.run(self)

        top = 300
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(45)
        self._svgList.append(svg)
        height = svg.getHeight()
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(2000, 0, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, True) \
            .rotateSetCenter(left, top + height / 2, False)
        animaSeq.run(self)

        left = 500
        top = 200
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(45)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        self._svgList.append(svg)
        height = svg.getHeight()
        width = svg.getWidth()
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(2000, 0, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, True) \
            .rotateSetCenter(left + width, top + height / 2, False)
        animaSeq.run(self)

        top = 300
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setRotateAngle(-45)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.rotate(2000, 0, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, True) \
            .rotateSetCenter(left + width, top + height / 2, False)
        animaSeq.run(self)

    # 旋转 开合效果
    def onGlobalBtn16Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 50
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setUserFillColor(xcgui.RGBA(255, 0, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.color(1500, xcgui.RGBA(0, 0, 255, 255), 1, 0, True)
        animaSeq.run(self)

        top = 225
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setUserFillColor(xcgui.RGBA(0, 255, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.color(1500, xcgui.RGBA(255, 0, 0, 255), 1, 0, True)
        animaSeq.run(self)

        top = 400
        svg = XSvg.loadFile(getResource('svg', '淘公仔文字.svg'))
        svg.setPosition(left, top)
        svg.setUserFillColor(xcgui.RGBA(255, 255, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.color(1500, xcgui.RGBA(0, 0, 255, 255), 1, 0, True)
        animaSeq.run(self)

        svgText = '<svg viewBox="0 0 200 200"><circle cx="100" cy="100" r="100" fill="#ff0" /></svg>'
        svg = XSvg.loadString(svgText)
        svg.setPosition(500, 300)
        svg.setUserFillColor(xcgui.RGBA(255, 255, 0, 255), True)
        self._svgList.append(svg)
        animaSeq = XAnimationSequence(svg, 0)
        animaSeq.color(1500, xcgui.RGBA(0, 255, 255, 255), 1, 0, True)
        animaSeq.run(self)

        shapeText = xcgui.XShapeText(500, 100, 200, 50, "炫彩界面库", self)
        shapeText.setFont(xcgui.XFont.createFromName("微软雅黑", 36, xcgui.fontStyle_bold))
        shapeText.setTextColor(xcgui.RGBA(255, 0, 0, 255))
        self._guiList.append(shapeText)
        animaSeq = XAnimationSequence(shapeText, 0)
        animaSeq.color(1500, xcgui.RGBA(0, 0, 255, 255), 1, 0, True)
        animaSeq.run(self)

        shapeText = xcgui.XShapeText(500, 200, 100, 20, "炫彩界面库", self)
        self._guiList.append(shapeText)
        animaSeq = XAnimationSequence(shapeText, 0)
        animaSeq.color(1500, xcgui.RGBA(0, 255, 0, 255), 1, 0, True)
        animaSeq.run(self)

    # 旋转 开合效果
    def onGlobalBtn17Click(self, event, _):
        self.releaseAllAnimation()
        left = 0
        top = 50

        positionFlags = [
            'position_flag_leftTop',
            'position_flag_left',
            'position_flag_leftBottom',
            'position_flag_top',
            'position_flag_center',
            'position_flag_bottom',
            'position_flag_rightTop',
            'position_flag_right',
            'position_flag_rightBottom'
        ]

        for i in range(0, len(positionFlags)):
            if i % 3 == 0:
                top = 50
                left += 150
            else:
                top += 150
            svg = XSvg.loadFile(getResource('svg', '查验.svg'))
            svg.setPosition(left, top)
            self._svgList.append(svg)

            shapeText = xcgui.XShapeText(left, top + 65, 150, 20, positionFlags[i], self)
            self._guiList.append(shapeText)
            animaSeq = XAnimationSequence(svg, 0)
            animaSeq.scale(3000, 0.5, 0.5, 1, 0, True).scaleSetPosition(getattr(xcgui, positionFlags[i]))
            animaSeq.run(self)
        self.redraw(False)

    def onGlobalZone18MouseStay(self, event: XEvent, _):
        ele: xcgui.XElement = event.sender
        ele.releaseAnimation(False)

        animaSeq = XAnimationSequence(ele, 1)
        animaSeq.scaleSize(400, 250, 40, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, False) \
            .scaleSetPosition(xcgui.position_flag_left)
        animaSeq.run(self)

    def onGlobalZone18MouseLeave(self, event: XEvent, _):
        ele: xcgui.XElement = event.sender
        ele.releaseAnimation(False)

        animaSeq = XAnimationSequence(ele, 1)
        animaSeq.scaleSize(400, 150, 40, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in, False) \
            .scaleSetPosition(xcgui.position_flag_left)
        animaSeq.run(self)

    # 按钮变宽
    def onGlobalBtn18Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 50
        for i in range(5):
            btn = XButton(left, top, 150, 40, "鼠标 停留 离开", self)
            self._guiList.append(btn)
            btn.setFont(xcgui.XFont(10))
            btn.setTextColor(xcgui.RGBA(255, 255, 255, 255))
            btn.getBkManager().setInfo("{99:1.9.9;98:16(0)32(1)64(2);5:2(15)20(1)21(3)26(1)22(-25024)23(255)9(4,4,4,"
                                       "4);5:2(15)20(1)21(3)26(1)22(-20122)23(255)9(4,4,4,4);5:2(15)20(1)21(3)26("
                                       "1)22(-1667526)23(255)9(4,4,4,4);}")
            btn.regEvent(xcgui.XE_MOUSESTAY, self.onGlobalZone18MouseStay)
            btn.regEvent(xcgui.XE_MOUSELEAVE, self.onGlobalZone18MouseLeave)
            top += 60
        self.redraw(False)

    # 按钮变宽
    def onGlobalBtn19Click(self, event, _):
        self.releaseAllAnimation()
        left = 140
        top = 200
        width = 120
        height = 35
        space = 34
        titles = ['窗口 从上往下', '窗口 从左往右', '窗口 缩放', '窗口 缩放2', '窗口 透明']
        for i in range(len(titles)):
            btn = XButton(left, top, width, height, titles[i], self)
            self._guiList.append(btn)
            callback = getattr(self, f"onZone19Btn{i + 1}Click", None)
            if callback:
                btn.regEvent(xcgui.XE_BNCLICK, callback)
            top += space
        self.redraw(False)

    # 窗口缓动 从上往下
    def onZone19Btn1Click(self, event, _):
        rect = self.getRect()
        left = rect.left + (rect.right - rect.left - 400) / 2
        top = rect.top + (rect.bottom - rect.top - 300) / 2
        modelWindow = xcgui.XModelWindow(400, 300, "窗口缓动", self.getHWND())
        animaSeq = XAnimationSequence(modelWindow, 1)
        animaSeq.moveEx(1000, left, 20, left, top, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, False)
        animaSeq.run(modelWindow)
        modelWindow.doModal()

    # 窗口缓动 从左往右
    def onZone19Btn2Click(self, event, _):
        rect = self.getRect()
        left = rect.left + (rect.right - rect.left - 400) / 2
        top = rect.top + (rect.bottom - rect.top - 300) / 2
        modelWindow = xcgui.XModelWindow(400, 300, "窗口缓动", self.getHWND())
        animaSeq = XAnimationSequence(modelWindow, 1)
        animaSeq.moveEx(1000, 20, top, left, top, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, False)
        animaSeq.run(modelWindow)
        modelWindow.doModal()

    # 窗口缩放
    def onZone19Btn3Click(self, event, _):
        modelWindow = xcgui.XModelWindow(400, 300, "窗口缩放", self.getHWND())
        animaSeq = XAnimationSequence(modelWindow, 1)
        animaSeq.scaleSize(1000, 500, 400, 1, xcgui.ease_flag_quad | xcgui.ease_flag_in, True)
        animaSeq.run(modelWindow)
        modelWindow.doModal()

    # 窗口缩放
    def onZone19Btn4Click(self, event, _):
        modelWindow = xcgui.XModelWindow(int(400 * 0.5), int(300 * 0.5), "窗口缩放2", self.getHWND())
        animaSeq = XAnimationSequence(modelWindow, 1)
        animaSeq.scaleSize(1000, 400, 300, 1, xcgui.ease_flag_back | xcgui.ease_flag_out, False)
        animaSeq.run(modelWindow)
        modelWindow.doModal()

    # 窗口透明
    def onZone19Btn5Click(self, event, _):
        modelWindow = xcgui.XModelWindow(400, 300, "窗口透明", self.getHWND())
        modelWindow.setTransparentAlpha(1)
        modelWindow.setTransparentType(xcgui.window_transparent_shadow)
        animaSeq = XAnimationSequence(modelWindow, 1)
        animaSeq.delay(100)
        animaSeq.alpha(1000, 255, 1, 0, False)
        animaSeq.run(modelWindow)
        modelWindow.doModal()

    # 按钮变宽
    def onGlobalBtn20Click(self, event, _):
        self.releaseAllAnimation()
        top = 200
        left = 140
        width = 150
        height = 35
        space = 34
        titles = ['遮盖层-内嵌子弹窗', '遮盖层-内嵌消息框', '遮盖层-消息框', '遮盖层-等待', '遮盖层-基础元素弹窗']
        for i in range(len(titles)):
            btn = XButton(left, top, width, height, titles[i], self)
            self._guiList.append(btn)
            callback = getattr(self, f"onZone20Btn{i + 1}Click", None)
            if callback:
                btn.regEvent(xcgui.XE_BNCLICK, callback)
            top += space
        self.redraw(False)

    def onZone20WindowDestroy(self, event, eleMask: xcgui.XElement):
        eleMask.destroy()
        self.redraw(False)

    # 遮盖层 内嵌子弹窗
    def onZone20Btn1Click(self, event, _):
        rect = self.getBodyRect()
        eleMask = xcgui.XElement(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, self)
        eleMask.addBkFill(xcgui.window_state_flag_leave, xcgui.RGBA(0, 0, 0, 200))

        window = XWindow(0, win32con.WS_CHILD, "", 0, 0, 300, 200, "遮盖层 内嵌子弹窗",
                         self.getHWND(), xcgui.window_style_default)

        window.regEvent(xcgui.WM_DESTROY, self.onZone20WindowDestroy, eleMask)
        window.show(True)
        window.redraw(False)
        self.redraw(False)

    # 遮盖层 内嵌消息框
    def onZone20Btn2Click(self, event, _):
        rect = self.getBodyRect()
        eleMask = xcgui.XElement(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, self)
        eleMask.addBkFill(xcgui.window_state_flag_leave, xcgui.RGBA(0, 0, 0, 200))

        window = xcgui.XMsgWindow(0, win32con.WS_CHILD, "", "炫彩界面库", "标题",
                                  xcgui.messageBox_flag_ok | xcgui.messageBox_flag_icon_info, self.getHWND())
        window.regEvent(xcgui.WM_DESTROY, self.onZone20WindowDestroy, eleMask)
        window.show(True)
        window.redraw(False)
        self.redraw(False)

    def onZone20Btn3Click(self, event, _):
        rect = self.getBodyRect()
        eleMask = xcgui.XElement(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, self)
        eleMask.addBkFill(xcgui.window_state_flag_leave, xcgui.RGBA(0, 0, 0, 200))

        window = xcgui.XMsgWindow("炫彩界面库", "标题",
                                  xcgui.messageBox_flag_ok | xcgui.messageBox_flag_icon_info, self.getHWND())
        window.regEvent(xcgui.WM_DESTROY, self.onZone20WindowDestroy, eleMask)
        window.show(True)
        window.redraw(False)
        self.redraw(False)

    def onZone20MaskPaint(self, event: XEvent, svgList):
        ele: xcgui.XElement = event.sender

        draw = xcgui.XDraw.cast(event.wParam)
        ele.drawEle(draw)
        for svg in svgList:
            draw.drawSvgSrc(svg)
        return True

    def onZone20MaskBtnDown(self, event, svgList):
        for svg in svgList:
            svg.releaseAnimation()
            svg.destroy()

        ele: xcgui.XElement = event.sender
        ele.destroy()

        self.redraw(False)
        return False

    def onZone20Btn4Click(self, event, _):
        svgText1 = '<svg x="0" y="0" width="25" height="25" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#ee6362" /></svg>'
        svgText2 = '<svg x="0" y="0" width="25" height="25" viewBox="0 0 100 100"><circle cx="50" cy="50" r="50" ' \
                   'fill="#2cb0b2" /></svg>'
        svg1 = XSvg.loadString(svgText1)
        svg2 = XSvg.loadString(svgText2)

        zoneSvgList = [svg1, svg2]

        rect = self.getBodyRect()
        eleMask = xcgui.XElement(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, self)
        eleMask.addBkFill(xcgui.window_state_flag_leave, xcgui.RGBA(0, 0, 0, 200))
        eleMask.regEvent(xcgui.XE_PAINT, self.onZone20MaskPaint, zoneSvgList)
        eleMask.regEvent(xcgui.XE_LBUTTONDOWN, self.onZone20MaskBtnDown, zoneSvgList)

        left = int(rect.left + (rect.right - rect.left - 100) / 2)
        top = int((rect.bottom - rect.top) / 2 - 50)
        shapeText = xcgui.XShapeText(left, top - 25, 100, 20, "正在加载...", eleMask)
        shapeText.setTextColor(xcgui.RGBA("#ffffffff"))
        svg1.setPosition(left, top)

        group = XAnimationGroup(0)
        group.run(self)

        animaSeq = XAnimationSequence(svg1, 1)
        group.addItem(animaSeq)
        animaSeq.move(1000, left + 50, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)
        animaSeq.move(1000, left, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)

        svg2.setPosition(left + 50, top)
        group = XAnimationGroup(0)
        group.run(self)
        animaSeq = XAnimationSequence(svg2, 1)
        group.addItem(animaSeq)
        animaSeq.move(1000, left, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)
        animaSeq.move(1000, left + 50, top, 1, xcgui.ease_flag_sine | xcgui.ease_flag_inOut, False)

        self.redraw(False)

    def onZone20DestroyMask(self, event, mask: xcgui.XElement):
        mask.releaseAnimation(False)
        mask.destroy()
        self.redraw(False)
        return True

    def onZone20Btn5Click(self, event, _):
        rect = self.getBodyRect()
        eleMask = xcgui.XElement(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, self)
        eleMask.addBkFill(xcgui.window_state_flag_leave, xcgui.RGBA(0, 0, 0, 200))

        width = 350
        height = 170
        left = int(rect.left + (rect.right - rect.left - width) / 2)
        top = int((rect.bottom - rect.top) / 2 - height)

        eleDlg = xcgui.XElement(left, 10, width, height, eleMask)
        eleDlg.show(False)
        eleDlg.getBkManager().setInfo("{99:1.9.9;98:1(0);5:2(15)20(1)21(3)26(1)22(-1)23(255)9(10,10,10,10);}")
        shapeText = xcgui.XShapeText(50, 5, 200, 30, "仅作功能演示,没有美化处理", eleDlg)
        shapeText.setTextColor(xcgui.RGBA(80, 80, 80, 255))

        btnClose = XButton(width - 40, 2, 30, 22, "", eleDlg)
        btnClose.getBkManager().setInfo("{99:1.9.9;98:16(0,1)32(0,1)64(0,1);5:2(48)8(45.00)3(2,10,2,10)20(1)21(3)26("
                                        "0)22(-8355712)23(255);5:2(48)8(45.00)3(10,2,100,100)20(1)21(3)26(0)22("
                                        "-8355712)23(255);}")
        shapeText = xcgui.XShapeText(20, 60, 100, 20, "请输入内容(这是一个演示)", eleDlg)
        shapeText.setTextColor(xcgui.RGBA(80, 80, 80, 255))

        bkInfo = "{99:1.9.9;98:16(0)32(1)64(1);5:2(15)20(1)21(3)26(0)22(-1)23(255)10(1)7(1)11(3)16(0)12(-3618616)13(" \
                 "255)9(5,5,5,5);5:2(15)20(1)21(3)26(0)22(-1)23(255)10(1)7(1)11(3)16(0)12(-17897)13(255)9(5,5,5,5);}"
        edit = xcgui.XEdit(20, 82, width - 40, 26, eleDlg)
        edit.setDefaultText("请输入内容...")
        edit.setBorderSize(10, 0, 10, 0)
        edit.getBkManager().setInfo(bkInfo)

        left_ = 190
        top_ = height - 35
        btnOk = XButton(left_, top_, 60, 22, "确定", eleDlg)
        btnOk.getBkManager().setInfo(bkInfo)
        left_ += 80
        btnCancel = XButton(left_, top_, 60, 22, "取消", eleDlg)
        btnCancel.getBkManager().setInfo(bkInfo)

        btnOk.regEvent(xcgui.XE_BNCLICK, self.onZone20DestroyMask, eleMask)
        btnCancel.regEvent(xcgui.XE_BNCLICK, self.onZone20DestroyMask, eleMask)
        btnClose.regEvent(xcgui.XE_BNCLICK, self.onZone20DestroyMask, eleMask)

        animaSeq = XAnimationSequence(eleMask, 1)
        animaSeq.alphaEx(500, 0, 255, 1, 0, False)
        animaSeq.run(eleMask)

        animaSeq = XAnimationSequence(eleDlg, 1)
        animaSeq.show(500, True)
        animaSeq.move(500, left, top, 1, xcgui.ease_flag_bounce | xcgui.ease_flag_out, False)
        animaSeq.run(eleMask)

        self.redraw(False)

    # 消息通知
    def onGlobalBtn21Click(self, event, _):
        self.releaseAllAnimation()
        top = 200
        left = 140
        width = 150
        height = 35
        space = 34
        titles = ['top-成功', 'top-警告消息', 'top-消息', 'top-错误消息',
                  'top-没有关闭按钮', 'top-手动关闭消息', 'top-不带标题', 'top-自定义大小']
        for i in range(len(titles)):
            btn = XButton(left, top, width, height, titles[i], self)
            self._guiList.append(btn)
            callback = getattr(self, f"onZone21Btn{i + 1}Click", None)
            if callback:
                btn.regEvent(xcgui.XE_BNCLICK, callback)
            top += space

        left += 160
        top = 200
        titles = ['right-成功', 'right-警告消息', 'right-消息', 'right-错误消息',
                  'right-没有关闭按钮', 'right-手动关闭消息', 'right-不带标题']
        for i in range(len(titles)):
            btn = XButton(left, top, width, height, titles[i], self)
            self._guiList.append(btn)
            callback = getattr(self, f"onZone21BtnRight{i + 1}Click", None)
            if callback:
                btn.regEvent(xcgui.XE_BNCLICK, callback)
            top += space
        self.redraw(False)

    def notifyMsgPopup(self, svgName, title, content, skin, position=xcgui.position_flag_top,
                       btnClose=True, autoClose=True, width=-1, height=-1):
        svg = XSvg.loadFile(getResource('svg', f"{svgName}.svg"))
        svg.setSize(16, 16)
        self.notifyMsgWindowPopupEx(position, title, content,
                                    xcgui.XImage.loadSvg(svg), skin, btnClose, autoClose, width, height)

    def onZone21Btn1Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息", xcgui.notifyMsg_skin_success)

    def onZone21Btn2Click(self, event, _):
        self.notifyMsgPopup('警告', "警告", "这是一条警告的提示消息", xcgui.notifyMsg_skin_warning)

    def onZone21Btn3Click(self, event, _):
        self.notifyMsgPopup('消息', "消息", "这是一条消息的提示消息", xcgui.notifyMsg_skin_message)

    def onZone21Btn4Click(self, event, _):
        self.notifyMsgPopup('错误', "错误", "这是一条错误的提示消息", xcgui.notifyMsg_skin_error)

    def onZone21Btn5Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息,没有关闭按钮", xcgui.notifyMsg_skin_success, btnClose=False)

    def onZone21Btn6Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息,手动关闭,这是一个自动换行文本",
                            xcgui.notifyMsg_skin_success, btnClose=True, autoClose=False)

    def onZone21Btn7Click(self, event, _):
        self.notifyMsgPopup('成功', "", "这是一条成功的提示消息,没有标题", xcgui.notifyMsg_skin_success)

    def onZone21Btn8Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息,\n自定义大小",
                            xcgui.notifyMsg_skin_success, width=300, height=200)

    def onZone21BtnRight1Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息", xcgui.notifyMsg_skin_success, xcgui.position_flag_right)

    def onZone21BtnRight2Click(self, event, _):
        self.notifyMsgPopup('警告', "警告", "这是一条警告的提示消息", xcgui.notifyMsg_skin_warning, xcgui.position_flag_right)

    def onZone21BtnRight3Click(self, event, _):
        self.notifyMsgPopup('消息', "消息", "这是一条消息的提示消息", xcgui.notifyMsg_skin_message, xcgui.position_flag_right)

    def onZone21BtnRight4Click(self, event, _):
        self.notifyMsgPopup('错误', "错误", "这是一条错误的提示消息", xcgui.notifyMsg_skin_error, xcgui.position_flag_right)

    def onZone21BtnRight5Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息,没有关闭按钮", xcgui.notifyMsg_skin_success,
                            xcgui.position_flag_right, btnClose=False)

    def onZone21BtnRight6Click(self, event, _):
        self.notifyMsgPopup('成功', "成功", "这是一条成功的提示消息,手动关闭,这是一个自动换行文本", xcgui.notifyMsg_skin_success,
                            xcgui.position_flag_right, autoClose=False)

    def onZone21BtnRight7Click(self, event, _):
        self.notifyMsgPopup('成功', "", "这是一条成功的提示消息,没有标题", xcgui.notifyMsg_skin_success, xcgui.position_flag_right)

    # 进度条
    def onGlobalBtn22Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 100
        width = 500
        bkInfo = "{99:1.9.9;98:16(0);5:2(37)3(0,8,0,0)20(1)21(3)26(1)22(-3618616)23(255)9(3,3,3,3);}"
        btnInfos = [
            "{99:1.9.9;98:16(0)32(0)64(0);6:2(15)20(1)21(3)26(1)22(-25024)23(255);}",
            "{99:1.9.9;98:16(0)32(0)64(0);6:2(15)20(1)21(3)26(1)22(-25024)23(255);}",
            "{99:1.9.9;98:16(0)32(0)64(0);6:2(15)20(1)21(3)26(0)22(-1)23(255)10(1)7(2)11(3)16(1)12(-25024)13(255);}"
        ]

        image = xcgui.XImage.loadFile(getResource('image', 'sliderBar.png'))
        image.setDrawTypeAdaptive(5, 5, 5, 5)
        self.sliderList = []
        for i in range(3):
            slider = xcgui.XSliderBar(left, top + i * 50, width, 20, self)
            self._guiList.append(slider)
            slider.setBkInfo(bkInfo)
            slider.setButtonWidth(20)
            slider.getButton().setBkInfo(btnInfos[i])
            if i < 2:
                slider.setImageLoad(image)
            self.sliderList.append(slider)

        progImage = xcgui.XImage.loadFile(getResource('image', 'progressBar.png'))
        progImage.setDrawTypeAdaptive(10, 0, 10, 0)
        self.progList = []
        for i in range(3):
            progress = xcgui.XProgressBar(left, top + (i + 3) * 50, width, 20, self)
            self._guiList.append(progress)
            self.progList.append(progress)
            if i < 2:
                progress.setBkInfo("{99:1.9.9;98:16(0);5:2(15)20(1)21(3)26(1)22(-3618616)23(255)9(10,10,10,10);}")
                progress.setImageLoad(progImage)
                progress.setTextColor(xcgui.RGBA("#ffffffff"))

        animaSeq = XAnimationSequence(None, 0)
        animaSeq.delayEx(2000, 1, xcgui.ease_flag_quad | xcgui.ease_flag_out, True) \
            .setCallback(self.onZone22AnimationCallback)
        animaSeq.run(self)
        self.redraw(False)

    def onZone22AnimationCallback(self, sender, pos):
        for index, slider in enumerate(self.sliderList):
            if index == 0 and slider.isValid():
                slider.setPos(int(100.0 * pos + 0.5))
                self.progList[index].setPos(int(100.0 * pos + 0.5))
            elif index == 1 and slider.isValid():
                slider.setPos(int(80.0 * pos + 0.5))
                self.progList[index].setPos(int(80.0 * pos + 0.5))
            elif index == 2 and slider.isValid():
                slider.setPos(int(50.0 * pos + 0.5))
                self.progList[index].setPos(int(50.0 * pos + 0.5))

    # 焦点追踪
    def onGlobalBtn23Click(self, event, _):
        self.releaseAllAnimation()
        left = 150
        top = 80
        width = 100
        height = 60

        # 图标按钮 切换
        whiteFocusLinePanel = FocusLineButtonPanel(True, focusOffset=20)
        self._customObjectList.append(whiteFocusLinePanel)

        whiteFocusLinePanel.createGrayBorderPanel(left, top - 20, 600, height + 40, self)
        left += 50
        whiteFocusLinePanel.createFoucsLine(left, top + height - 2, width, 2, xcgui.RGBA(171, 72, 188, 255), self)
        whiteFocusLinePanel.createWhiteButton(left, top, width, height, "Button",
                                              XSvg.loadFile(getResource('svg', '公益.svg')),
                                              xcgui.RGBA(171, 72, 188, 255),
                                              xcgui.RGBA(247, 238, 248, 255), self)
        whiteFocusLinePanel.createWhiteButton(left + width, top, width, height, "Button",
                                              XSvg.loadFile(getResource('svg', '时间戳.svg')),
                                              xcgui.RGBA(254, 167, 38, 255),
                                              xcgui.RGBA(253, 244, 232, 255), self)

        whiteFocusLinePanel.createWhiteButton(left + width * 2, top, width, height, "Button",
                                              XSvg.loadFile(getResource('svg', '技术服务.svg')),
                                              xcgui.RGBA(38, 166, 154, 255),
                                              xcgui.RGBA(236, 246, 245, 255), self)

        # 图标按钮 切换2 导航条
        left = 150
        top += 100
        width = 90
        height = 40
        purpleFocusLinePanel = FocusLineButtonPanel(False)
        self._customObjectList.append(purpleFocusLinePanel)
        purpleFocusLinePanel.createPurpleFillPanel(left, top, 600, height, self)
        purpleFocusLinePanel.createFoucsLine(left, top + height - 3, width, 3, xcgui.RGBA(0, 162, 232, 255), self)
        purpleFocusLinePanel.createPurpleButton(left, top, width, height, "Button",
                                                XSvg.loadFile(getResource('svg', '公益.svg')), self)
        purpleFocusLinePanel.createPurpleButton(left + width, top, width, height, "Button",
                                                XSvg.loadFile(getResource('svg', '时间戳.svg')), self)
        purpleFocusLinePanel.createPurpleButton(left + width * 2, top, width, height, "Button",
                                                XSvg.loadFile(getResource('svg', '技术服务.svg')), self)

        # 编辑框 焦点边
        left = 150
        top += 80
        width = 150
        height = 30
        focusEditPanel = FocusLineEditPanel()
        self._customObjectList.append(focusEditPanel)
        focusEditPanel.createGrayBorderPanel(left, top, 600, height+40, self)
        left += 50
        top += 20
        for i in range(3):
            focusEditPanel.createEdit(left + i*(width+20), top, width, height, self)

        self.redraw(False)


if __name__ == '__main__':
    app = XApp(True)
    app.setPaintFrequency(10)
    # app.showLayoutFrame(True)
    # app.showSvgFrame(True)
    window = AnimationWindow()
    window.show(True)
    app.run()
    app.exit()
