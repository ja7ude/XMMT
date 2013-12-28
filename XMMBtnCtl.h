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

#if !defined(AFX_XMMBTNCTL_H__913833FF_DF33_4CD3_85D2_32FA88EFA798__INCLUDED_)
#define AFX_XMMBTNCTL_H__913833FF_DF33_4CD3_85D2_32FA88EFA798__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMBtnCtl.h : CXMMBtnCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl : このクラスの動作の定義に関しては XMMBtnCtl.cpp を参照してください

class CXMMBtnCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMBtnCtrl)

private:
	BOOL		m_Toggled;
	BOOL		m_fState;
	COLORREF	m_clEdge[3];
	COLORREF	m_clFace;
	COLORREF	m_clPush;
	COLORREF	m_clText;
	COLORREF	m_clGrayText;
	RECT		m_rcClient;
	CString		m_Text;
	BOOL		m_Enabled;
private:
	void Initialize(void);
	void Draw(void);
	void OnDrawInternal(CDC *pDC);

public:
	void InitialUpdate(void);
	void SetWindowText(LPCTSTR lpszString);
	void EnableWindow(BOOL bEnable);
	inline void EnableToggle(BOOL bEnable){m_Toggled = bEnable;};
	inline BOOL IsWindowEnabled(void){return m_Enabled;};
	void GetWindowText(CString& rString) const;

// コンストラクタ
public:
	CXMMBtnCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMBtnCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMBtnCtrl();

	DECLARE_OLECREATE_EX(CXMMBtnCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMBtnCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMBtnCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMBtnCtrl)     // タイプ名とその他のステータス

	// サブクラス化されたコントロールのサポート
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// メッセージ マップ
	//{{AFX_MSG(CXMMBtnCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMBtnCtrl)
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg BSTR GetCaption();
	afx_msg void SetCaption(LPCTSTR lpszNewValue);
	afx_msg OLE_COLOR GetTextColor();
	afx_msg void SetTextColor(OLE_COLOR nNewValue);
	afx_msg BOOL GetEnabled();
	afx_msg void SetEnabled(BOOL bNewValue);
	afx_msg BOOL GetState();
	afx_msg void SetState(BOOL bNewValue);
	afx_msg BOOL GetToggled();
	afx_msg void SetToggled(BOOL bNewValue);
	afx_msg OLE_COLOR GetFaceColor();
	afx_msg void SetFaceColor(OLE_COLOR nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMBtnCtrl)
	void FireOnLButtonClick()
		{FireEvent(eventidOnLButtonClick,EVENT_PARAM(VTS_NONE));}
	void FireOnRButtonClick()
		{FireEvent(eventidOnRButtonClick,EVENT_PARAM(VTS_NONE));}
	void FireDblClick()
		{FireEvent(DISPID_DBLCLICK,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMBtnCtrl)
	dispidCaption = 2L,
	dispidTextColor = 3L,
	dispidEnabled = 4L,
	dispidState = 5L,
	dispidToggled = 6L,
	dispidFaceColor = 7L,
	dispidVisible = 1L,
	eventidOnLButtonClick = 1L,
	eventidOnRButtonClick = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMBTNCTL_H__913833FF_DF33_4CD3_85D2_32FA88EFA798__INCLUDED)
