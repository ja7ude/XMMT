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

// XMMXYCtl.cpp : CXMMXYCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMXYCtl.h"
#include "XMMXYPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMXYCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMXYCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMXYCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CXMMXYCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMXYCtrl)
	DISP_PROPERTY_NOTIFY(CXMMXYCtrl, "Invert", m_invert, OnInvertChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CXMMXYCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMXYCtrl, "BackColor", GetBackColor, SetBackColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMXYCtrl, "Color", GetColor, SetColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMXYCtrl, "HighQuality", GetHighQuality, SetHighQuality, VT_BOOL)
	DISP_PROPERTY_EX(CXMMXYCtrl, "DemSampleFreq", GetDemSampleFreq, SetDemSampleFreq, VT_I2)
	DISP_FUNCTION(CXMMXYCtrl, "Draw", Draw, VT_EMPTY, VTS_PI4)
	DISP_FUNCTION(CXMMXYCtrl, "Clear", Clear, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMXYCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMXYCtrl)
	EVENT_CUSTOM("OnLButtonClick", FireOnLButtonClick, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnRButtonClick", FireOnRButtonClick, VTS_I2  VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMXYCtrl, 1)
	PROPPAGEID(CXMMXYPropPage::guid)
END_PROPPAGEIDS(CXMMXYCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMXYCtrl, "XMMT.XMMXYCtrl.1",
	0x964dcb7f, 0xa8e7, 0x407f, 0xa6, 0x89, 0x26, 0x69, 0x6b, 0xc1, 0x84, 0x78)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMXYCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMXY =
		{ 0xbff74b5e, 0xa2d0, 0x4865, { 0x82, 0x3e, 0xf, 0x91, 0xca, 0x52, 0xea, 0x7a } };
const IID BASED_CODE IID_DXMMXYEvents =
		{ 0x15fe58b4, 0x5152, 0x4e06, { 0xb6, 0xe7, 0xb5, 0xc2, 0xd4, 0xa, 0xf8, 0x84 } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMXYOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMXYCtrl, IDS_XMMXY, _dwXMMXYOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::CXMMXYCtrlFactory::UpdateRegistry -
// CXMMXYCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMXYCtrl::CXMMXYCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMXY,
			IDB_XMMXY,
			afxRegApartmentThreading,
			_dwXMMXYOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::CXMMXYCtrl - コンストラクタ

CXMMXYCtrl::CXMMXYCtrl()
{
	InitializeIIDs(&IID_DXMMXY, &IID_DXMMXYEvents);

	m_clBack = RGB(0,0,0);
	m_clXY = RGB(0,255,0);
	m_bmpSize.cx = 0;
	m_bmpSize.cy = 0;
	m_pIX = NULL;
	m_pIY = NULL;
	m_sampfreq = 11025/2;
}
/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::~CXMMXYCtrl - デストラクタ

CXMMXYCtrl::~CXMMXYCtrl()
{
	DeleteIXY();
	m_bmpXY.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::OnDraw - 描画関数

void CXMMXYCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	UpdateSize(rcBounds);
	DrawBitmap(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::DoPropExchange - 永続性のサポート

void CXMMXYCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_Color(pPX, _T("Color"), m_clXY, RGB(0,255,0));
	PX_Color(pPX, _T("BackColor"), m_clBack, RGB(0,0,0));
	PX_Bool(pPX, _T("HighQuality"), m_bHighQuality, FALSE);
	PX_Short(pPX, _T("DemSampleFreq"), m_sampfreq, 11025/2);
	PX_Bool(pPX, _T("Invert"), m_invert, FALSE);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMXYCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}

//---------------------------------------------------------------------------
void CXMMXYCtrl::DeleteIXY(void)
{
	// インターポーレータを削除します。
	if( m_pIX ){
		delete m_pIX;
		delete m_pIY;
		m_pIX = m_pIY = NULL;
	}
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::OpenIXY(void)
{
	if( m_bHighQuality && !m_pIX ){
		m_pIX = new CINTPXY2(m_sampfreq);
		m_pIY = new CINTPXY2(m_sampfreq);
	}
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::InitialUpdate(void)
{
	CRect rc;
	GetClientRect(&rc);
	UpdateSize(&rc);
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::Initialize(void)
{
	if( !m_bmpSize.cx ) InitialUpdate();
	OpenIXY();
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::DrawBitmap(CDC *pDC, const CRect &rc)
{
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpXY);
	pDC->BitBlt(rc.left, rc.top, m_bmpSize.cx, m_bmpSize.cy, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::UpdateSize(const CRect &rc)
{
	m_rcClient = rc;
	if( (rc.Width() != m_bmpSize.cx) || (rc.Height() != m_bmpSize.cy) ){
		m_bmpSize.cx = rc.Width();
		m_bmpSize.cy = rc.Height();
		m_bmpXY.DeleteObject();
		CDC *pDC = GetDC();
		VERIFY(pDC->GetMapMode() == MM_TEXT);
		m_bmpXY.CreateCompatibleBitmap(pDC, m_bmpSize.cx, m_bmpSize.cy);
		ReleaseDC(pDC);
		DrawXY(NULL);
	}
}
//---------------------------------------------------------------------------
void CXMMXYCtrl::DrawXY(LONG *pXY)
{
	Initialize();
	LPLONG bx = pXY;
	LPLONG by = &pXY[512];
	int count = 512;
	int i;
	LPLONG px, py;

	LONG X[1024], Y[1024];
	LONG max = 0;
	if( pXY ){
		if( m_bHighQuality ){
			if( !m_pIX ){
				OpenIXY();
				if( !m_pIX ) return;
			}
			// データをオーバーサンプリングします。
			px = bx; py = by;
			LPLONG ptx = X;
			LPLONG pty = Y;
			m_pIX->Clear(); m_pIY->Clear();
			for( i = 0; i < count; i++ ){
				m_pIX->Do(ptx, *px++); m_pIY->Do(pty, *py++);
			}
			count = 1024;
			bx = X; by = Y;
		}

		px = bx; py = by;
		for( i = 0; i < count; i++, px++, py++ ){
			if( max < *px ) max = *px;
			if( max < *py ) max = *py;
		}
		if( max < 16384 ) max = 16384;
		max = max * 16 / 7;
	}

	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpXY);
	dc.FillSolidRect(&m_rcClient, GetRefColor(m_clBack));
	if( pXY ){
		int x, y;
		int XC = m_bmpSize.cx / 2;
		int YC = m_bmpSize.cy / 2;
		CPen pen(PS_SOLID, 0, GetRefColor(m_clXY));
		CPen *pOldPen = dc.SelectObject(&pen);
		px = bx; py = by;
		if( m_invert ){
			for( i = 0; i < count; i++, px++, py++ ){
				x = XC + (*px * m_bmpSize.cx)/ max;
				y = YC - (*py * m_bmpSize.cy)/ max;
				dc.MoveTo(x, y); dc.LineTo(x+1, y);
			}
		}
		else {
			for( i = 0; i < count; i++, px++, py++ ){
				x = XC + (*px * m_bmpSize.cx)/ max;
				y = YC + (*py * m_bmpSize.cy)/ max;
				dc.MoveTo(x, y); dc.LineTo(x+1, y);
			}
		}
		dc.SelectObject(pOldPen);
		pen.DeleteObject();
	}
	if( m_sBorderStyle ){
		RECT rc;
		rc.left = rc.top = 0;
		rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
		DrawBorderStyle(&dc, rc);
	}
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}

/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl メッセージ ハンドラ

OLE_COLOR CXMMXYCtrl::GetBackColor() 
{
	return m_clBack;
}

void CXMMXYCtrl::SetBackColor(OLE_COLOR nNewValue) 
{
	m_clBack = nNewValue;
	Draw(NULL);
	SetModifiedFlag();
}

void CXMMXYCtrl::Draw(long FAR* pXY) 
{
	if( !IsWindowVisible() ) return;

	DrawXY(pXY);

	CClientDC dc(this);
	DrawBitmap(&dc, m_rcClient);
}

OLE_COLOR CXMMXYCtrl::GetColor() 
{
	return m_clXY;
}

void CXMMXYCtrl::SetColor(OLE_COLOR nNewValue) 
{
	m_clXY = nNewValue;
	Draw(NULL);
	SetModifiedFlag();
}

BOOL CXMMXYCtrl::GetHighQuality() 
{
	return m_bHighQuality;
}

void CXMMXYCtrl::SetHighQuality(BOOL bNewValue) 
{
	if( m_bHighQuality != bNewValue ){
		m_bHighQuality = bNewValue;
		DeleteIXY();
		OpenIXY();
		SetModifiedFlag();
	}
}

short CXMMXYCtrl::GetDemSampleFreq() 
{
	return m_sampfreq;
}

void CXMMXYCtrl::SetDemSampleFreq(short nNewValue) 
{
	if( (nNewValue >= 5000) && (nNewValue < 13000) ){
		if( m_sampfreq != nNewValue ){
			m_sampfreq = nNewValue;
			DeleteIXY();
			OpenIXY();
			SetModifiedFlag();
		}
	}
}

void CXMMXYCtrl::OnInvertChanged() 
{
	SetModifiedFlag();
}

void CXMMXYCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	FireOnLButtonClick(SHORT(point.x), SHORT(point.y));
	COleControl::OnLButtonDown(nFlags, point);
}

void CXMMXYCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	FireOnRButtonClick(SHORT(point.x), SHORT(point.y));
	COleControl::OnRButtonDown(nFlags, point);
}

void CXMMXYCtrl::Clear() 
{
	Draw(NULL);
}

void CXMMXYCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}
