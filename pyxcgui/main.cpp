#pragma once
#include "pch.h"
#include "binding/XDefine.hpp"
#include "binding/XEnum.hpp"
#include "binding/XStruct.hpp"
#include "binding/XStructAuto.hpp"
#include "binding/XObject.hpp"
#include "binding/bkmanager/XBkManager.hpp"
#include "binding/bkmanager/XBkObject.hpp"
#include "binding/XObjectUI.hpp"
#include "binding/XApp.hpp"
#include "binding/XWidget.hpp"
#include "binding/XFont.hpp"
#include "binding/XSvg.hpp"
#include "binding/XDraw.hpp"
#include "binding/XImage.hpp"
#include "binding/XImageSrc.hpp"
#include "binding/XGlobal.hpp"
#include "binding/XElement.hpp"
#include "binding/XLayoutBox.hpp"
#include "binding/element/XButton.hpp"
#include "binding/XResource.hpp"
#include "binding/menu/XMenu.hpp"
#include "binding/XDesigner.hpp"
#include "binding/window/XWindow.hpp"
#include "binding/window/XFrameWindow.hpp"
#include "binding/window/XModelWindow.hpp"
#include "binding/window/XMsgWindow.hpp"
#include "binding/adapter/XAdapter.hpp"
#include "binding/adapter/XAdapterTree.hpp"
#include "binding/adapter/XAdapterTable.hpp"
#include "binding/adapter/XAdapterMap.hpp"
#include "binding/adapter/XAdapterListView.hpp"
#include "binding/element/XTextLink.hpp"
#include "binding/element/XDateTime.hpp"
#include "binding/element/XMonthCal.hpp"
#include "binding/element/XLayoutEle.hpp"
#include "binding/element/XMenuBar.hpp"
#include "binding/element/XPane.hpp"
#include "binding/element/XProgressBar.hpp"
#include "binding/element/XScrollBar.hpp"
#include "binding/element/XSliderBar.hpp"
#include "binding/element/XTabBar.hpp"
#include "binding/element/XToolBar.hpp"
#include "binding/element/XScrollView.hpp"
#include "binding/element/XEdit.hpp"
#include "binding/element/XLayoutFrame.hpp"
#include "binding/template/XTemplate.hpp"
#include "binding/element/XListBox.hpp"
#include "binding/element/XList.hpp"
#include "binding/element/XListView.hpp"
#include "binding/element/XTree.hpp"
#include "binding/ease/XEase.hpp"
#include "binding/shape/XShape.hpp"
#include "binding/shape/XShapeEllipse.hpp"
#include "binding/shape/XShapeGif.hpp"
#include "binding/shape/XShapePicture.hpp"
#include "binding/shape/XShapeGroupBox.hpp"	   
#include "binding/shape/XShapeLine.hpp"
#include "binding/shape/XShapeText.hpp"
#include "binding/shape/XShapeRect.hpp"
#include "binding/shape/XShapeTable.hpp"

// animation
#include "binding/animation/XAnimationItem.hpp"


						 
namespace xcgui {

	PYBIND11_MODULE(xcgui, m) {
		m.doc() = "xcgui for python";

		// define
		declareDefine(m);

		// 所有枚举类型
		declareEnum(m);

		// base
		declareBase(m);

		// designer
		declareDesigner(m);

		// layoutBox
		declareLayoutBox(m);

		// 所有struct
		declareStruct(m);

		// auto struct
		declareStructAuto(m);

		// xfont
		declareFont(m);

		// svg
		declareSvg(m);

		// image src
		declareImageSrc(m);

		// image
		declareImage(m);

		// draw
		declareDraw(m);

		// bkObject
		declareBkObject(m);

		// bkManager
		declareBkManager(m);

		// resource
		declareResource(m);

		// ObjectUI
		declareObjectUI(m);

		// global
		declareGlobal(m);

		// app
		declareApp(m);

		// widget
		declareWidget(m);

		// element
		declareElement(m);

		// menu
		declareMenu(m);

		// button
		declareButton(m);

		// window
		declareWindow(m);

		// frameWindow
		declareFrameWindow(m);

		// modelWindow
		declareModelWindow(m);

		// msgWindow
		declareMsgWindow(m);

		// adapter
		declareAdapter(m);

		// adapterTree
		declareAdapterTree(m);

		// adapterTable
		declareAdapterTable(m);

		// adapterMap
		declareAdapterMap(m);

		// adapterListView
		declareAdapterListView(m);

		// textlink
		declareTextLink(m);

		// datetime
		declareDateTime(m);

		// monthCal
		declareMonthCal(m);
		
		// layoutEle
		declareLayoutEle(m);

		// menubar
		declareMenuBar(m);

		// panel
		declarePanel(m);

		// progressBar
		declareProgressBar(m);

		// scrollbar
		declareScrollBar(m);
	
		// sliderBar
		declareSliderBar(m);

		// tabBar
		declareTabBar(m);

		// Toolbar
		declareToolbar(m);

		// scrollView
		declareScrollView(m);

		// edit
		declareEdit(m);

		// layoutFrame
		declareLayoutFrame(m);

		// template
		declareTemplate(m);

		// listBox
		declareListBox(m);

		// list
		declareList(m);

		// listView
		declareListView(m);

		// tree
		declareTree(m);

		// ease 
		declareEase(m);

		// shape
		declareShape(m);

		// shapeEllipse
		declareShapeEllipse(m);

		// shapeGif
		declareShapeGif(m);

		// shapePicture
		declareShapePicture(m);

		// shapeGroupBox
		declareShapeGroupBox(m);

		// shapeLine
		declareShapeLine(m);

		// shapeText
		declareShapeText(m);

		// shapeRect
		declareShapeRect(m);

		// shapeTable
		declareShapeTable(m);

		// animationItem
		declareAnimationItem(m);
	}
}