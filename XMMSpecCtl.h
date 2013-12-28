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
#if !defined(AFX_XMMSPECCTL_H__9D9E0524_0189_4180_A154_7370E9793064__INCLUDED_)
#define AFX_XMMSPECCTL_H__9D9E0524_0189_4180_A154_7370E9793064__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMSpecCtl.h : CXMMSpecCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl : このクラスの動作の定義に関しては XMMSpecCtl.cpp を参照してください

class CXMMSpecCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMSpecCtrl)
private:
	COLORREF	m_clBack;
	COLORREF	m_clMarker;
	COLORREF	m_clLimiter;
	COLORREF	m_clLine;
	CRect		m_rcClient;
	CSize		m_bmpSize;
	CBitmap		m_bmpSpectram;
	short		m_markfreq;
	short		m_spacefreq;
	short		m_notch1;
	short		m_notch2;
	short		m_basefreq;
	short		m_widthfreq;
private:
	void InitialUpdate(void);
	void Initialize(void);
	void DrawBitmap(CDC *pDC, const CRect &rc);
	void UpdateSize(const CRect &rc);
	void DrawSpectram(short *pFFT, short size, short sampfreq);
	SHORT GetMouseFreq(const CPoint &point);

// コンストラクタ
public:
	CXMMSpecCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMSpecCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMSpecCtrl();

	DECLARE_OLECREATE_EX(CXMMSpecCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMSpecCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMSpecCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMSpecCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMSpecCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMSpecCtrl)
	BOOL m_bShowValue;
	afx_msg void OnBShowValueChanged();
	BOOL m_bShowLimiter;
	afx_msg void OnBShowLimiterChanged();
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg short GetNotch1();
	afx_msg void SetNotch1(short nNewValue);
	afx_msg short GetNotch2();
	afx_msg void SetNotch2(short nNewValue);
	afx_msg short GetBaseFreq();
	afx_msg void SetBaseFreq(short nNewValue);
	afx_msg short GetWidthFreq();
	afx_msg void SetWidthFreq(short nNewValue);
	afx_msg short GetMarkFreq();
	afx_msg void SetMarkFreq(short nNewValue);
	afx_msg short GetSpaceFreq();
	afx_msg void SetSpaceFreq(short nNewValue);
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetMarkerColor();
	afx_msg void SetMarkerColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetSpectramColor();
	afx_msg void SetSpectramColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetLimiterColor();
	afx_msg void SetLimiterColor(OLE_COLOR nNewValue);
	afx_msg void Draw(short FAR* pFFT, short size, short sampfreq);
	afx_msg void Clear();
	afx_msg void UpdateByNMMT(long FAR* pNMMT);
	afx_msg void UpdateByNMMR(long FAR* pNMMR);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMSpecCtrl)
	void FireOnLMouseDown(short freq)
		{FireEvent(eventidOnLMouseDown,EVENT_PARAM(VTS_I2), freq);}
	void FireOnLMouseMove(short freq)
		{FireEvent(eventidOnLMouseMove,EVENT_PARAM(VTS_I2), freq);}
	void FireOnLMouseUp(short freq)
		{FireEvent(eventidOnLMouseUp,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseDown(short freq)
		{FireEvent(eventidOnRMouseDown,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseUp(short freq)
		{FireEvent(eventidOnRMouseUp,EVENT_PARAM(VTS_I2), freq);}
	void FireOnRMouseMove(short freq)
		{FireEvent(eventidOnRMouseMove,EVENT_PARAM(VTS_I2), freq);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMSpecCtrl)
	dispidNotch1 = 4L,
	dispidNotch2 = 5L,
	dispidBShowValue = 1L,
	dispidBaseFreq = 6L,
	dispidWidthFreq = 7L,
	dispidMarkFreq = 8L,
	dispidSpaceFreq = 9L,
	dispidBShowLimiter = 2L,
	dispidBackColor = 10L,
	dispidMarkerColor = 11L,
	dispidSpectramColor = 12L,
	dispidLimiterColor = 13L,
	dispidVisible = 3L,
	dispidDraw = 14L,
	dispidClear = 15L,
	dispidUpdateByNMMT = 16L,
	dispidUpdateByNMMR = 17L,
	eventidOnLMouseDown = 1L,
	eventidOnLMouseMove = 2L,
	eventidOnLMouseUp = 3L,
	eventidOnRMouseDown = 4L,
	eventidOnRMouseUp = 5L,
	eventidOnRMouseMove = 6L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMSPECCTL_H__9D9E0524_0189_4180_A154_7370E9793064__INCLUDED)
