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

// XMMSpecCtl.cpp : CXMMSpecCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMSpecCtl.h"
#include "XMMSpecPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMSpecCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMSpecCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMSpecCtrl)
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

BEGIN_DISPATCH_MAP(CXMMSpecCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMSpecCtrl)
	DISP_PROPERTY_NOTIFY(CXMMSpecCtrl, "bShowValue", m_bShowValue, OnBShowValueChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CXMMSpecCtrl, "bShowLimiter", m_bShowLimiter, OnBShowLimiterChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CXMMSpecCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "Notch1", GetNotch1, SetNotch1, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "Notch2", GetNotch2, SetNotch2, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "BaseFreq", GetBaseFreq, SetBaseFreq, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "WidthFreq", GetWidthFreq, SetWidthFreq, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "MarkFreq", GetMarkFreq, SetMarkFreq, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "SpaceFreq", GetSpaceFreq, SetSpaceFreq, VT_I2)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "BackColor", GetBackColor, SetBackColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "MarkerColor", GetMarkerColor, SetMarkerColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "SpectramColor", GetSpectramColor, SetSpectramColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMSpecCtrl, "LimiterColor", GetLimiterColor, SetLimiterColor, VT_COLOR)
	DISP_FUNCTION(CXMMSpecCtrl, "Draw", Draw, VT_EMPTY, VTS_PI2 VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMSpecCtrl, "Clear", Clear, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CXMMSpecCtrl, "UpdateByNMMT", UpdateByNMMT, VT_EMPTY, VTS_PI4)
	DISP_FUNCTION(CXMMSpecCtrl, "UpdateByNMMR", UpdateByNMMR, VT_EMPTY, VTS_PI4)
	DISP_STOCKPROP_FONT()
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMSpecCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMSpecCtrl)
	EVENT_CUSTOM("OnLMouseDown", FireOnLMouseDown, VTS_I2)
	EVENT_CUSTOM("OnLMouseMove", FireOnLMouseMove, VTS_I2)
	EVENT_CUSTOM("OnLMouseUp", FireOnLMouseUp, VTS_I2)
	EVENT_CUSTOM("OnRMouseDown", FireOnRMouseDown, VTS_I2)
	EVENT_CUSTOM("OnRMouseUp", FireOnRMouseUp, VTS_I2)
	EVENT_CUSTOM("OnRMouseMove", FireOnRMouseMove, VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMSpecCtrl, 1)
	PROPPAGEID(CXMMSpecPropPage::guid)
END_PROPPAGEIDS(CXMMSpecCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMSpecCtrl, "XMMLVL.XMMSpecCtrl.1",
	0x9614c387, 0x73aa, 0x4a07, 0x8f, 0xc6, 0x7c, 0x40, 0x7d, 0xab, 0x1, 0x7c)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMSpecCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMSpec =
		{ 0x825b17e6, 0xdc7b, 0x40c4, { 0xb0, 0x3b, 0x39, 0x79, 0x3c, 0xa9, 0xdf, 0x6 } };
const IID BASED_CODE IID_DXMMSpecEvents =
		{ 0x7ae508f5, 0xe62, 0x491e, { 0xb0, 0x23, 0x21, 0x4c, 0x1b, 0, 0x65, 0xe0 } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMSpecOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMSpecCtrl, IDS_XMMSPEC, _dwXMMSpecOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::CXMMSpecCtrlFactory::UpdateRegistry -
// CXMMSpecCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMSpecCtrl::CXMMSpecCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMSPEC,
			IDB_XMMSPEC,
			afxRegApartmentThreading,
			_dwXMMSpecOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::CXMMSpecCtrl - コンストラクタ

CXMMSpecCtrl::CXMMSpecCtrl()
{
	InitializeIIDs(&IID_DXMMSpec, &IID_DXMMSpecEvents);

	m_clBack = RGB(0,0,0);
	m_clMarker = RGB(255, 255, 0);
	m_clLimiter = RGB(192,192,192);
	m_clLine = RGB(255,255,255);
	m_bmpSize.cx = 0; m_bmpSize.cy = 0;
	m_markfreq = 2125;
	m_spacefreq = 2125 + 170;
	m_notch1 = 0;
	m_notch2 = 0;
	m_basefreq = 0;
	m_widthfreq = 3000;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::~CXMMSpecCtrl - デストラクタ

CXMMSpecCtrl::~CXMMSpecCtrl()
{
	m_bmpSpectram.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::OnDraw - 描画関数

void CXMMSpecCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	UpdateSize(rcBounds);
	DrawBitmap(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::DoPropExchange - 永続性のサポート

void CXMMSpecCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("bShowValue"), m_bShowValue, TRUE);
	PX_Bool(pPX, _T("bShowLimiter"), m_bShowLimiter, TRUE);
	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_Short(pPX, _T("MarkFreq"), m_markfreq, 2125);
	PX_Short(pPX, _T("SpaceFreq"), m_spacefreq, 2125+170);
	PX_Short(pPX, _T("Notch1"), m_notch1, 0);
	PX_Short(pPX, _T("Notch2"), m_notch2, 0);
	PX_Short(pPX, _T("BaseFreq"), m_basefreq, 0);
	PX_Short(pPX, _T("WidthFreq"), m_widthfreq, 3000);
	PX_Color(pPX, _T("SpectramColor"), m_clLine, RGB(255,255,255));
	PX_Color(pPX, _T("BackColor"), m_clBack, RGB(0,0,0));
	PX_Color(pPX, _T("MarkerColor"), m_clMarker, RGB(255,255,0));
	PX_Color(pPX, _T("LimiterColor"), m_clLimiter, RGB(192,192,192));
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMSpecCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}

/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void CXMMSpecCtrl::InitialUpdate(void)
{
	CRect rc;
	GetClientRect(&rc);
	UpdateSize(&rc);
}
//---------------------------------------------------------------------------
void CXMMSpecCtrl::Initialize(void)
{
	if( !m_bmpSize.cx ) InitialUpdate();
}
//---------------------------------------------------------------------------
void CXMMSpecCtrl::DrawBitmap(CDC *pDC, const CRect &rc)
{
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpSpectram);
	pDC->BitBlt(rc.left, rc.top, m_bmpSize.cx, m_bmpSize.cy, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}
//---------------------------------------------------------------------------
void CXMMSpecCtrl::UpdateSize(const CRect &rc)
{
	m_rcClient = rc;
	if( (rc.Width() != m_bmpSize.cx) || (rc.Height() != m_bmpSize.cy) ){
		m_bmpSize.cx = rc.Width();
		m_bmpSize.cy = rc.Height();
		m_bmpSpectram.DeleteObject();
		CDC *pDC = GetDC();
		VERIFY(pDC->GetMapMode() == MM_TEXT);
		m_bmpSpectram.CreateCompatibleBitmap(pDC, m_bmpSize.cx, m_bmpSize.cy);
		ReleaseDC(pDC);
		DrawSpectram(NULL, 2048, 11025);
	}
}
//---------------------------------------------------------------------------
void CXMMSpecCtrl::DrawSpectram(short *pFFT, short size, short sampfreq)
{
	Initialize();

	RECT rc;
	rc.left = rc.top = 0;
	rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpSpectram);
	dc.FillSolidRect(&rc, GetRefColor(m_clBack));

	int x;
	if( m_bShowLimiter ){
		// 300Hz, 2700Hzゲージを描画します。
		CPen penlimit(PS_DOT, 0, GetRefColor(m_clLimiter));
		CPenSelect pslimit(&dc, &penlimit);
		x = (300 - m_basefreq) * m_bmpSize.cx / m_widthfreq;
		dc.MoveTo(x, 0);
		dc.LineTo(x, m_bmpSize.cy);
		x = (2700 - m_basefreq) * m_bmpSize.cx / m_widthfreq;
		dc.MoveTo(x, 0);
		dc.LineTo(x, m_bmpSize.cy);
		pslimit.Release();
		penlimit.DeleteObject();
	}

	// マーク/スペース周波数ゲージを描画します。
	CPen penmarker(PS_DOT, 0, GetRefColor(m_clMarker));
	CPenSelect ps(&dc, &penmarker);
	x = (m_markfreq - m_basefreq) * m_bmpSize.cx / m_widthfreq;
	dc.MoveTo(x, 0);
	dc.LineTo(x, m_bmpSize.cy);
	x = (m_spacefreq - m_basefreq) * m_bmpSize.cx / m_widthfreq;
	dc.MoveTo(x, 0);
	dc.LineTo(x, m_bmpSize.cy);
	ps.Release();
	penmarker.DeleteObject();

	if( pFFT ){
		// スペクトラムを描画します。
		CPen pen(PS_SOLID, 0, GetRefColor(m_clLine));
		CPenSelect ps(&dc, &pen);
		int off = m_basefreq * size / sampfreq;
		double k = double(m_widthfreq) * double(size)/(double(m_bmpSize.cx) * double(sampfreq));
		int y;
		int max = 256;
		for( x = 0; x < m_bmpSize.cx; x++ ){
			y = pFFT[int(x * k) + off];
			if( y < 0 ) y = 0;
			if( y > max ) y = max;
			y = m_bmpSize.cy - (y * m_bmpSize.cy / max);
			if( x ){
				dc.LineTo(x, y);
			}
			else {
				dc.MoveTo(x, y);
			}
		}
		ps.Release();
		pen.DeleteObject();
	}
	if( m_notch1 || m_notch2 ){
		// ノッチフィルタのマーカーを描画します。
		x = (m_notch1 - m_basefreq) * m_bmpSize.cx / m_widthfreq;
		POINT	ary[3];
		ary[0].x = x; ary[0].y = m_bmpSize.cy - 1;
		ary[1].x = x - 3; ary[1].y = m_bmpSize.cy - 6;
		ary[2].x = x + 3; ary[2].y = m_bmpSize.cy - 6;
		CPen pen(PS_SOLID, 0, RGB(255,255,0));
		CPenSelect ps(&dc, &pen);
		CBrush brushR(RGB(255,0,0));
		CBrushSelect bs(&dc, &brushR);
		dc.Polygon(ary, 3);
		bs.Release();
		brushR.DeleteObject();
		if( m_notch2 ){
			x = (m_notch2 - m_basefreq) * m_bmpSize.cx / m_widthfreq;
			ary[0].x = x; ary[1].x = x - 3; ary[2].x = x + 3;
			CBrush brushB(RGB(0,0,255));
			CBrushSelect bs(&dc, &brushB);
			dc.Polygon(ary, 3);
			bs.Release();
			brushB.DeleteObject();
		}
		ps.Release();
		pen.DeleteObject();
	}
	// マーク周波数とシフト幅の数値を描画します。
	if( m_bShowValue ){
		TCHAR bf[32];
		wsprintf(bf, _T("%d"), m_markfreq);
		CFont *pOldFont = SelectStockFont(&dc);
		CSize funit = dc.GetTextExtent(bf);
		dc.SetTextColor(RGB(255,255,0));
		int bm = dc.SetBkMode(TRANSPARENT);
		dc.TextOut(4, 1, bf);
		wsprintf(bf, _T("%d"), m_spacefreq - m_markfreq);
		dc.TextOut(4, funit.cy + 1, bf);
		dc.SelectObject(pOldFont);
		dc.SetBkMode(bm);
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
SHORT CXMMSpecCtrl::GetMouseFreq(const CPoint &point)
{
	LONG freq = m_basefreq + point.x * m_widthfreq/ m_bmpSize.cx;
	if( freq < 0 ) freq = 0;
	if( freq > 3000 ) freq = 3000;
	return SHORT(freq);
}
/////////////////////////////////////////////////////////////////////////////
// CXMMSpecCtrl メッセージ ハンドラ

void CXMMSpecCtrl::Draw(short FAR* pFFT, short size, short sampfreq) 
{
	if( !IsWindowVisible() ) return;

	DrawSpectram(pFFT, size, sampfreq);

	CClientDC dc(this);
	DrawBitmap(&dc, m_rcClient);
}

void CXMMSpecCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_LBUTTON ){
		SetCapture();
		FireOnLMouseDown(GetMouseFreq(point));
	}
	COleControl::OnLButtonDown(nFlags, point);
}

void CXMMSpecCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnLMouseUp(GetMouseFreq(point));
	}
	COleControl::OnLButtonUp(nFlags, point);
}

void CXMMSpecCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		short fq = GetMouseFreq(point);
		if( nFlags & MK_LBUTTON ){
			FireOnLMouseMove(fq);
		}
		else if( nFlags & MK_RBUTTON ){
			FireOnRMouseMove(fq);
		}
	}
	COleControl::OnMouseMove(nFlags, point);
}

void CXMMSpecCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_RBUTTON ){
		SetCapture();
		FireOnRMouseDown(GetMouseFreq(point));
	}
	COleControl::OnRButtonDown(nFlags, point);
}

void CXMMSpecCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnRMouseUp(GetMouseFreq(point));
	}
	COleControl::OnRButtonUp(nFlags, point);
}

short CXMMSpecCtrl::GetNotch1() 
{
	return m_notch1;
}

void CXMMSpecCtrl::SetNotch1(short nNewValue) 
{
	m_notch1 = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

short CXMMSpecCtrl::GetNotch2() 
{
	return m_notch2;
}

void CXMMSpecCtrl::SetNotch2(short nNewValue) 
{
	m_notch2 = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

void CXMMSpecCtrl::OnBShowValueChanged() 
{
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

void CXMMSpecCtrl::OnBShowLimiterChanged() 
{
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

short CXMMSpecCtrl::GetBaseFreq() 
{
	return m_basefreq;
}

void CXMMSpecCtrl::SetBaseFreq(short nNewValue) 
{
	if( nNewValue >= 4000 ) return;
	m_basefreq = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

short CXMMSpecCtrl::GetWidthFreq() 
{
	return m_widthfreq;
}

void CXMMSpecCtrl::SetWidthFreq(short nNewValue) 
{
	if( nNewValue <= 0 ) return;
	m_widthfreq = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}


void CXMMSpecCtrl::Clear() 
{
	Draw(NULL, 2048, 11025);
}

short CXMMSpecCtrl::GetMarkFreq() 
{
	return m_markfreq;
}

void CXMMSpecCtrl::SetMarkFreq(short nNewValue) 
{
	m_markfreq = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

short CXMMSpecCtrl::GetSpaceFreq() 
{
	return m_spacefreq;
}

void CXMMSpecCtrl::SetSpaceFreq(short nNewValue) 
{
	m_spacefreq = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}


OLE_COLOR CXMMSpecCtrl::GetBackColor() 
{
	return m_clBack;
}

void CXMMSpecCtrl::SetBackColor(OLE_COLOR nNewValue) 
{
	m_clBack = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

OLE_COLOR CXMMSpecCtrl::GetMarkerColor() 
{
	return m_clMarker;
}

void CXMMSpecCtrl::SetMarkerColor(OLE_COLOR nNewValue) 
{
	m_clMarker = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

OLE_COLOR CXMMSpecCtrl::GetSpectramColor() 
{
	return m_clLine;
}

void CXMMSpecCtrl::SetSpectramColor(OLE_COLOR nNewValue) 
{
	m_clLine = nNewValue;
	SetModifiedFlag();
}

OLE_COLOR CXMMSpecCtrl::GetLimiterColor() 
{
	return m_clLimiter;
}

void CXMMSpecCtrl::SetLimiterColor(OLE_COLOR nNewValue) 
{
	m_clLimiter = nNewValue;
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

void CXMMSpecCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}

void CXMMSpecCtrl::UpdateByNMMT(long FAR* pNMMT) 
{
	LPNMMT pnmmt = (LPNMMT)pNMMT;

	m_markfreq = SHORT(pnmmt->m_markfreq);
	m_spacefreq = SHORT(pnmmt->m_spacefreq);
	m_notch1 = m_notch2 = 0;
	if( (pnmmt->m_codeswitch & (swLMS|swNOT)) == (swLMS|swNOT) ){
		m_notch1 = SHORT(pnmmt->m_notch1);
		if( (pnmmt->m_codeswitch & swTWO) && pnmmt->m_notch2 ){
			m_notch2 = SHORT(pnmmt->m_notch2);
		}
	}
}

void CXMMSpecCtrl::UpdateByNMMR(long FAR* pNMMR) 
{
	LPNMMR pnmmr = (LPNMMR)pNMMR;

	m_markfreq = SHORT(pnmmr->m_markfreq);
	m_spacefreq = SHORT(pnmmr->m_spacefreq);
	m_notch1 = m_notch2 = 0;
	if( (pnmmr->m_codeswitch & (swLMS|swNOT)) == (swLMS|swNOT) ){
		m_notch1 = SHORT(pnmmr->m_notch1);
		if( (pnmmr->m_codeswitch & swTWO) && pnmmr->m_notch2 ){
			m_notch2 = SHORT(pnmmr->m_notch2);
		}
	}
}
