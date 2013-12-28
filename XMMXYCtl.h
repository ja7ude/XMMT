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

#if !defined(AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED_)
#define AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Filter.h"
// XMMXYCtl.h : CXMMXYCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl : このクラスの動作の定義に関しては XMMXYCtl.cpp を参照してください

class CXMMXYCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMXYCtrl)

private:
	COLORREF	m_clBack;
	COLORREF	m_clXY;
	CRect		m_rcClient;
	CSize		m_bmpSize;
	CBitmap		m_bmpXY;
	CINTPXY2	*m_pIX;
	CINTPXY2	*m_pIY;
	short		m_sampfreq;
	BOOL		m_bHighQuality;
private:
	void DeleteIXY(void);
	void OpenIXY(void);
	void InitialUpdate(void);
	void Initialize(void);
	void DrawBitmap(CDC *pDC, const CRect &rc);
	void UpdateSize(const CRect &rc);
	void DrawXY(LONG *pXY);

// コンストラクタ
public:
	CXMMXYCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMXYCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMXYCtrl();

	DECLARE_OLECREATE_EX(CXMMXYCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMXYCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMXYCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMXYCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMXYCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMXYCtrl)
	BOOL m_invert;
	afx_msg void OnInvertChanged();
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetColor();
	afx_msg void SetColor(OLE_COLOR nNewValue);
	afx_msg BOOL GetHighQuality();
	afx_msg void SetHighQuality(BOOL bNewValue);
	afx_msg short GetDemSampleFreq();
	afx_msg void SetDemSampleFreq(short nNewValue);
	afx_msg void Draw(long FAR* pXY);
	afx_msg void Clear();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMXYCtrl)
	void FireOnLButtonClick(short X, short Y)
		{FireEvent(eventidOnLButtonClick,EVENT_PARAM(VTS_I2  VTS_I2), X, Y);}
	void FireOnRButtonClick(short X, short Y)
		{FireEvent(eventidOnRButtonClick,EVENT_PARAM(VTS_I2  VTS_I2), X, Y);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMXYCtrl)
	dispidBackColor = 3L,
	dispidColor = 4L,
	dispidHighQuality = 5L,
	dispidDemSampleFreq = 6L,
	dispidInvert = 1L,
	dispidVisible = 2L,
	dispidDraw = 7L,
	dispidClear = 8L,
	eventidOnLButtonClick = 1L,
	eventidOnRButtonClick = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED)
