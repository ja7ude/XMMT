//Copyright+LGPL

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Copyright 2000-2013 Makoto Mori, Nobuyuki Oba
//-----------------------------------------------------------------------------------------------------------------------------------------------
// This file is part of MMTTY.

// MMTTY is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// MMTTY is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License along with MMTTY.  If not, see 
// <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------------------------------------------------------------------------

#if !defined(AFX_XMMLVLCTL_H__838ED5F3_E9AE_4CC4_8829_472CF162CF02__INCLUDED_)
#define AFX_XMMLVLCTL_H__838ED5F3_E9AE_4CC4_8829_472CF162CF02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMLvlCtl.h : CXMMLvlCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl : このクラスの動作の定義に関しては XMMLvlCtl.cpp を参照してください

class CXMMLvlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMLvlCtrl)
private:
	COLORREF	m_clBack;
	COLORREF	m_clLevelOn;
	COLORREF	m_clLevelOff;
	COLORREF	m_clLine;
	CRect		m_rcClient;
	CSize		m_bmpSize;
	CBitmap		m_bmpLevel;
private:
	void InitialUpdate(void);
	void Initialize(void);
	void DrawBitmap(CDC *pDC, const CRect &rc);
	void UpdateSize(const CRect &rc);
	void DrawLevel(short sig, short sq);
	SHORT GetLevel(CPoint &point);

// コンストラクタ
public:
	CXMMLvlCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMLvlCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMLvlCtrl();

	DECLARE_OLECREATE_EX(CXMMLvlCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMLvlCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMLvlCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMLvlCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMLvlCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMLvlCtrl)
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg OLE_COLOR GetOnColor();
	afx_msg void SetOnColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetOffColor();
	afx_msg void SetOffColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetLineColor();
	afx_msg void SetLineColor(OLE_COLOR nNewValue);
	afx_msg void Draw(short sig, short sq);
	afx_msg void DrawByNMMT(long FAR* pNMMT);
	afx_msg void Clear();
	afx_msg void DrawByNMMR(long FAR* pNMMR);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMLvlCtrl)
	void FireOnLMouseDown(short level)
		{FireEvent(eventidOnLMouseDown,EVENT_PARAM(VTS_I2), level);}
	void FireOnLMouseUp(short level)
		{FireEvent(eventidOnLMouseUp,EVENT_PARAM(VTS_I2), level);}
	void FireOnLMouseMove(short level)
		{FireEvent(eventidOnLMouseMove,EVENT_PARAM(VTS_I2), level);}
	void FireOnRMouseDown(short level)
		{FireEvent(eventidOnRMouseDown,EVENT_PARAM(VTS_I2), level);}
	void FireOnRMouseUp(short level)
		{FireEvent(eventidOnRMouseUp,EVENT_PARAM(VTS_I2), level);}
	void FireOnRMouseMove(short level)
		{FireEvent(eventidOnRMouseMove,EVENT_PARAM(VTS_I2), level);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMLvlCtrl)
	dispidOnColor = 2L,
	dispidOffColor = 3L,
	dispidBackColor = 4L,
	dispidLineColor = 5L,
	dispidVisible = 1L,
	dispidDraw = 6L,
	dispidDrawByNMMT = 7L,
	dispidClear = 8L,
	dispidDrawByNMMR = 9L,
	eventidOnLMouseDown = 1L,
	eventidOnLMouseUp = 2L,
	eventidOnLMouseMove = 3L,
	eventidOnRMouseDown = 4L,
	eventidOnRMouseUp = 5L,
	eventidOnRMouseMove = 6L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMLVLCTL_H__838ED5F3_E9AE_4CC4_8829_472CF162CF02__INCLUDED)
