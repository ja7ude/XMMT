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

// XMMLvlCtl.cpp : CXMMLvlCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMLvlCtl.h"
#include "XMMLvlPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMLvlCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMLvlCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMLvlCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CXMMLvlCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMLvlCtrl)
	DISP_PROPERTY_NOTIFY(CXMMLvlCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMLvlCtrl, "OnColor", GetOnColor, SetOnColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMLvlCtrl, "OffColor", GetOffColor, SetOffColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMLvlCtrl, "BackColor", GetBackColor, SetBackColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMLvlCtrl, "LineColor", GetLineColor, SetLineColor, VT_COLOR)
	DISP_FUNCTION(CXMMLvlCtrl, "Draw", Draw, VT_EMPTY, VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMLvlCtrl, "DrawByNMMT", DrawByNMMT, VT_EMPTY, VTS_PI4)
	DISP_FUNCTION(CXMMLvlCtrl, "Clear", Clear, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CXMMLvlCtrl, "DrawByNMMR", DrawByNMMR, VT_EMPTY, VTS_PI4)
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMLvlCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMLvlCtrl)
	EVENT_CUSTOM("OnLMouseDown", FireOnLMouseDown, VTS_I2)
	EVENT_CUSTOM("OnLMouseUp", FireOnLMouseUp, VTS_I2)
	EVENT_CUSTOM("OnLMouseMove", FireOnLMouseMove, VTS_I2)
	EVENT_CUSTOM("OnRMouseDown", FireOnRMouseDown, VTS_I2)
	EVENT_CUSTOM("OnRMouseUp", FireOnRMouseUp, VTS_I2)
	EVENT_CUSTOM("OnRMouseMove", FireOnRMouseMove, VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMLvlCtrl, 1)
	PROPPAGEID(CXMMLvlPropPage::guid)
END_PROPPAGEIDS(CXMMLvlCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMLvlCtrl, "XMMLVL.XMMLvlCtrl.1",
	0x306b30ad, 0x3abe, 0x4f84, 0xa8, 0xb6, 0x32, 0x30, 0x95, 0x7, 0x6, 0x35)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMLvlCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMLvl =
		{ 0xe05ff165, 0x5785, 0x446e, { 0xb2, 0xe6, 0x6e, 0x9e, 0x7e, 0x32, 0x4d, 0xc1 } };
const IID BASED_CODE IID_DXMMLvlEvents =
		{ 0x8973d8d1, 0xd0b0, 0x4e4a, { 0x88, 0xbc, 0x82, 0x7e, 0x38, 0x32, 0x45, 0x58 } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMLvlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMLvlCtrl, IDS_XMMLVL, _dwXMMLvlOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::CXMMLvlCtrlFactory::UpdateRegistry -
// CXMMLvlCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMLvlCtrl::CXMMLvlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: コントロールがアパートメント モデルのスレッド処理の規則に従っていることを
	// 確認してください。詳細については MFC のテクニカル ノート 64 を参照してください。
	// アパートメント モデルのスレッド処理の規則に従わないコントロールの場合は、6 番目
	// のパラメータを以下のように変更してください。
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_XMMLVL,
			IDB_XMMLVL,
			afxRegApartmentThreading,
			_dwXMMLvlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::CXMMLvlCtrl - コンストラクタ

CXMMLvlCtrl::CXMMLvlCtrl()
{
	InitializeIIDs(&IID_DXMMLvl, &IID_DXMMLvlEvents);

	m_clBack = RGB(0,0,0);
	m_clLevelOn = RGB(0,255,0);
	m_clLevelOff = RGB(192,192,192);
	m_clLine = RGB(255,255,0);
	m_bmpSize.cx = 0;
	m_bmpSize.cy = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::~CXMMLvlCtrl - デストラクタ

CXMMLvlCtrl::~CXMMLvlCtrl()
{
	m_bmpLevel.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::OnDraw - 描画関数

void CXMMLvlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	UpdateSize(rcBounds);
	DrawBitmap(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::DoPropExchange - 永続性のサポート

void CXMMLvlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_Color(pPX, _T("OnColor"), m_clLevelOn, RGB(0,255,0));
	PX_Color(pPX, _T("OffColor"), m_clLevelOff, RGB(192,192,192));
	PX_Color(pPX, _T("LineColor"), m_clLine, RGB(255,255,0));
	PX_Color(pPX, _T("BackColor"), m_clBack, RGB(0,0,0));
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMLvlCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}

/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void CXMMLvlCtrl::InitialUpdate(void)
{
	CRect rc;
	GetClientRect(&rc);
	UpdateSize(&rc);
}
//---------------------------------------------------------------------------
void CXMMLvlCtrl::Initialize(void)
{
	if( !m_bmpSize.cx ) InitialUpdate();
}
//---------------------------------------------------------------------------
void CXMMLvlCtrl::DrawBitmap(CDC *pDC, const CRect &rc)
{
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpLevel);
	pDC->BitBlt(rc.left, rc.top, m_bmpSize.cx, m_bmpSize.cy, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}
//---------------------------------------------------------------------------
void CXMMLvlCtrl::UpdateSize(const CRect &rc)
{
	m_rcClient = rc;
	if( (rc.Width() != m_bmpSize.cx) || (rc.Height() != m_bmpSize.cy) ){
		m_bmpSize.cx = rc.Width();
		m_bmpSize.cy = rc.Height();
		m_bmpLevel.DeleteObject();
		CDC *pDC = GetDC();
		VERIFY(pDC->GetMapMode() == MM_TEXT);
		m_bmpLevel.CreateCompatibleBitmap(pDC, m_bmpSize.cx, m_bmpSize.cy);
		ReleaseDC(pDC);
		DrawLevel(-1, -1);
	}
}
//---------------------------------------------------------------------------
void CXMMLvlCtrl::DrawLevel(short sig, short sq)
{
	Initialize();

	if( sig > 1024 ) sig = 1024;
	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpLevel);
	dc.FillSolidRect(&m_rcClient, GetRefColor(m_clBack));

	COLORREF col = GetRefColor((sig < sq) ? m_clLevelOff : m_clLevelOn);
	RECT rc;
	rc.left = rc.top = 0;
	rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
	if( m_bmpSize.cy > m_bmpSize.cx ){
		rc.top = m_bmpSize.cy - (sig * m_bmpSize.cy / 1024);
		dc.FillSolidRect(&rc, col);

		rc.top = m_bmpSize.cy - (sq * m_bmpSize.cy / 1024);
		if( rc.top < m_sBorderStyle ) rc.top = m_sBorderStyle;
		if( rc.top < rc.bottom ){
			CPen penmarker(PS_SOLID, 0, GetRefColor(m_clLine));
			CPen *pOldPen = dc.SelectObject(&penmarker);
			dc.MoveTo(0, rc.top);
			dc.LineTo(m_bmpSize.cx, rc.top);
			dc.SelectObject(pOldPen);
			penmarker.DeleteObject();
		}
	}
	else {
		rc.right = sig * m_bmpSize.cx / 1024;
		dc.FillSolidRect(&rc, col);

		rc.right = sq * m_bmpSize.cx / 1024;
		if( rc.right >= (m_bmpSize.cx - m_sBorderStyle) ) rc.right = (m_bmpSize.cx - m_sBorderStyle - 1);
		if( rc.left < rc.right ){
			CPen penmarker(PS_SOLID, 0, GetRefColor(m_clLine));
			CPen *pOldPen = dc.SelectObject(&penmarker);
			dc.MoveTo(rc.right, 0);
			dc.LineTo(rc.right, m_bmpSize.cy);
			dc.SelectObject(pOldPen);
			penmarker.DeleteObject();
		}
	}
	if( m_sBorderStyle ){
		rc.left = rc.top = 0;
		rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
		DrawBorderStyle(&dc, rc);
	}
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}

//---------------------------------------------------------------------------
SHORT CXMMLvlCtrl::GetLevel(CPoint &point)
{
	int level;
	if( m_bmpSize.cy > m_bmpSize.cx ){
		level = (m_bmpSize.cy - point.y) * 1024/ m_bmpSize.cy; 
	}
	else {
		level = point.x * 1024/ m_bmpSize.cx; 
	}
	if( level < 0 ) level = 0;
	if( level > 1024 ) level = 1024;
	return SHORT(level);
}
/////////////////////////////////////////////////////////////////////////////
// CXMMLvlCtrl メッセージ ハンドラ

void CXMMLvlCtrl::Draw(short sig, short sq) 
{
	if( !IsWindowVisible() ) return;

	DrawLevel(sig, sq);

	CClientDC dc(this);
	DrawBitmap(&dc, m_rcClient);
}

OLE_COLOR CXMMLvlCtrl::GetOnColor() 
{
	return m_clLevelOn;
}

void CXMMLvlCtrl::SetOnColor(OLE_COLOR nNewValue) 
{
	m_clLevelOn = nNewValue;
	Draw(-1, -1);
	SetModifiedFlag();
}

OLE_COLOR CXMMLvlCtrl::GetOffColor() 
{
	return m_clLevelOff;
}

void CXMMLvlCtrl::SetOffColor(OLE_COLOR nNewValue) 
{
	m_clLevelOff = nNewValue;
	Draw(-1, -1);
	SetModifiedFlag();
}

OLE_COLOR CXMMLvlCtrl::GetBackColor() 
{
	return m_clBack;
}

void CXMMLvlCtrl::SetBackColor(OLE_COLOR nNewValue) 
{
	m_clBack = nNewValue;
	Draw(-1, -1);
	SetModifiedFlag();
}

OLE_COLOR CXMMLvlCtrl::GetLineColor() 
{
	return m_clLine;
}

void CXMMLvlCtrl::SetLineColor(OLE_COLOR nNewValue) 
{
	m_clLine = nNewValue;
	Draw(-1, -1);
	SetModifiedFlag();
}

void CXMMLvlCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_LBUTTON ){
		SetCapture();
		FireOnLMouseDown(GetLevel(point));
	}
	COleControl::OnLButtonDown(nFlags, point);
}

void CXMMLvlCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnLMouseUp(GetLevel(point));
	}
	COleControl::OnLButtonUp(nFlags, point);
}

void CXMMLvlCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		short level = GetLevel(point);
		if( nFlags & MK_LBUTTON ){
			FireOnLMouseMove(level);
		}
		else if( nFlags & MK_RBUTTON ){
			FireOnRMouseMove(level);
		}
	}
	COleControl::OnMouseMove(nFlags, point);
}

void CXMMLvlCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_RBUTTON ){
		SetCapture();
		FireOnRMouseDown(GetLevel(point));
	}
	COleControl::OnRButtonDown(nFlags, point);
}

void CXMMLvlCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnRMouseUp(GetLevel(point));
	}
	COleControl::OnRButtonUp(nFlags, point);
}

void CXMMLvlCtrl::DrawByNMMT(long FAR* pNMMT) 
{
	LPNMMT pnmmt = (LPNMMT)pNMMT;
	Draw(SHORT(pnmmt->m_siglevel), pnmmt->m_codeswitch & swSQ ? SHORT(pnmmt->m_sqlevel) : -1);
}

void CXMMLvlCtrl::Clear() 
{
	Draw(-1, -1);
}

void CXMMLvlCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}

void CXMMLvlCtrl::DrawByNMMR(long FAR* pNMMR) 
{
	LPNMMR pnmmr = (LPNMMR)pNMMR;
	Draw(SHORT(pnmmr->m_siglevel), pnmmr->m_codeswitch & swSQ ? SHORT(pnmmr->m_sqlevel) : -1);
}
