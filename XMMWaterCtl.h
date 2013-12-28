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

#if !defined(AFX_XMMWATERCTL_H__8365F640_554A_439D_BFA2_61D037FF87E9__INCLUDED_)
#define AFX_XMMWATERCTL_H__8365F640_554A_439D_BFA2_61D037FF87E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMWaterCtl.h : CXMMWaterCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl : このクラスの動作の定義に関しては XMMWaterCtl.cpp を参照してください

class CXMMWaterCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMWaterCtrl)

private:
	COLORREF	m_clBack;
	COLORREF	m_clSpectram;
	CRect		m_rcClient;
	CSize		m_bmpSize;
	CBitmap		m_bmpWater;
	short		m_basefreq;
	short		m_widthfreq;
private:
	COLORREF	m_clTable[256];
	int			m_Max;
	int			m_Min;
	int			m_SumMax;
private:
	void InitialUpdate(void);
	void Initialize(void);
	void DrawBitmap(CDC *pDC, const CRect &rc);
	void UpdateSize(const CRect &rc);
	void DrawWater(short *pFFT, short size, short sampfreq);
	void CreateTable(void);
	SHORT GetMouseFreq(const CPoint &point);

// コンストラクタ
public:
	CXMMWaterCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMWaterCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMWaterCtrl();

	DECLARE_OLECREATE_EX(CXMMWaterCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMWaterCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMWaterCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMWaterCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMWaterCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMWaterCtrl)
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetSpectramColor();
	afx_msg void SetSpectramColor(OLE_COLOR nNewValue);
	afx_msg short GetBaseFreq();
	afx_msg void SetBaseFreq(short nNewValue);
	afx_msg short GetWidthFreq();
	afx_msg void SetWidthFreq(short nNewValue);
	afx_msg void Draw(short FAR* pFFT, short size, short sampfreq);
	afx_msg void Clear();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMWaterCtrl)
	void FireOnLMouseDown(short freq)
		{FireEvent(eventidOnLMouseDown,EVENT_PARAM(VTS_I2), freq);}
	void FireOnLMouseUp(short freq)
		{FireEvent(eventidOnLMouseUp,EVENT_PARAM(VTS_I2), freq);}
	void FireOnLMouseMove(short freq)
		{FireEvent(eventidOnLMouseMove,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseDown(short freq)
		{FireEvent(eventidOnRMouseDown,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseMove(short freq)
		{FireEvent(eventidOnRMouseMove,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseUp(short freq)
		{FireEvent(eventidOnRMouseUp,EVENT_PARAM(VTS_I2), freq);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMWaterCtrl)
	dispidBackColor = 2L,
	dispidSpectramColor = 3L,
	dispidBaseFreq = 4L,
	dispidWidthFreq = 5L,
	dispidVisible = 1L,
	dispidDraw = 6L,
	dispidClear = 7L,
	eventidOnLMouseDown = 1L,
	eventidOnLMouseUp = 2L,
	eventidOnLMouseMove = 3L,
	eventidOnRMouseDown = 4L,
	eventidOnRMouseMove = 5L,
	eventidOnRMouseUp = 6L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMWATERCTL_H__8365F640_554A_439D_BFA2_61D037FF87E9__INCLUDED)
