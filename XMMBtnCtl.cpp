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

// XMMBtnCtl.cpp : CXMMBtnCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMBtnCtl.h"
#include "XMMBtnPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMBtnCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMBtnCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMBtnCtrl)
	DISP_PROPERTY_NOTIFY(CXMMBtnCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Caption", GetCaption, SetCaption, VT_BSTR)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "TextColor", GetTextColor, SetTextColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Enabled", GetEnabled, SetEnabled, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "State", GetState, SetState, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Toggled", GetToggled, SetToggled, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "FaceColor", GetFaceColor, SetFaceColor, VT_COLOR)
	DISP_STOCKPROP_FONT()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMBtnCtrl)
	EVENT_CUSTOM("OnLButtonClick", FireOnLButtonClick, VTS_NONE)
	EVENT_CUSTOM("OnRButtonClick", FireOnRButtonClick, VTS_NONE)
	EVENT_CUSTOM_ID("DblClick", DISPID_DBLCLICK, FireDblClick, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMBtnCtrl, 1)
	PROPPAGEID(CXMMBtnPropPage::guid)
END_PROPPAGEIDS(CXMMBtnCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMBtnCtrl, "XMMT.XMMBtnCtrl.1",
	0x34104a6c, 0xb355, 0x43e0, 0xbb, 0xd1, 0x9a, 0x77, 0x18, 0xab, 0xd, 0x4c)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMBtnCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMBtn =
		{ 0xf5bf613f, 0xd4bc, 0x4582, { 0x80, 0xe5, 0x2f, 0x5e, 0x5b, 0x31, 0xf8, 0x2e } };
const IID BASED_CODE IID_DXMMBtnEvents =
		{ 0xc3decf69, 0xc3bc, 0x427c, { 0x9c, 0xf3, 0x4b, 0xe6, 0x1a, 0xae, 0x9e, 0xff } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMBtnOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMBtnCtrl, IDS_XMMBTN, _dwXMMBtnOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::CXMMBtnCtrlFactory::UpdateRegistry -
// CXMMBtnCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMBtnCtrl::CXMMBtnCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMBTN,
			IDB_XMMBTN,
			afxRegApartmentThreading,
			_dwXMMBtnOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::CXMMBtnCtrl - コンストラクタ

CXMMBtnCtrl::CXMMBtnCtrl()
{
	InitializeIIDs(&IID_DXMMBtn, &IID_DXMMBtnEvents);

	m_Enabled = TRUE;
	m_Toggled = TRUE;
	m_clEdge[0] = GetSysColor(COLOR_BTNHILIGHT);
	m_clEdge[1] = GetSysColor(COLOR_BTNSHADOW);
	m_clEdge[2] = GetSysColor(COLOR_3DDKSHADOW);
	m_clFace = 0x80000000 + COLOR_BTNFACE;
	m_clPush = RGB(255,255,255);
	m_fState = FALSE;
	m_clText = RGB(0,0,0);
	m_clGrayText = GetSysColor(COLOR_GRAYTEXT);
	memset(&m_rcClient, 0, sizeof(m_rcClient));
	m_visible = TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::~CXMMBtnCtrl - デストラクタ

CXMMBtnCtrl::~CXMMBtnCtrl()
{
	// TODO: この位置にコントロールのインスタンス データの後処理用のコードを追加してください
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnDraw - 描画関数

void CXMMBtnCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
//	DoSuperclassPaint(pdc, rcBounds);
	m_rcClient = rcBounds;
	OnDrawInternal(pdc);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::DoPropExchange - 永続性のサポート

void CXMMBtnCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Enabled"), m_Enabled, TRUE);
	PX_Bool(pPX, _T("State"), m_fState, FALSE);
	PX_Bool(pPX, _T("Toggled"), m_Toggled, TRUE);
	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_String(pPX, _T("Caption"), m_Text, _T(""));
	PX_Color(pPX, _T("TextColor"), m_clText, RGB(0,0,0));
	PX_Color(pPX, _T("FaceColor"), m_clFace);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMBtnCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::PreCreateWindow - CreateWindowEx のパラメータを修正

BOOL CXMMBtnCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::IsSubclassedControl - サブクラス化されたコントロール

BOOL CXMMBtnCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnOcmCommand - コマンド メッセージのハンドル

LRESULT CXMMBtnCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: この位置にスイッチ ステートメントで wNotifyCode を処理するコードを追加してください

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void CXMMBtnCtrl::InitialUpdate(void)
{
	GetClientRect(&m_rcClient);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::Initialize(void)
{
	if( !m_rcClient.right ) InitialUpdate();
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::Draw(void)
{
	if( !IsWindowVisible() ) return;
	CClientDC dc(this);
	OnDrawInternal(&dc);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::SetWindowText(LPCTSTR lpszString)
{
	Initialize();
	if( lstrcmp(m_Text, lpszString) ){
		m_Text = lpszString;
		Draw();
	}
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::GetWindowText(CString& rString) const
{
	rString = m_Text;
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::EnableWindow(BOOL bEnable)
{
	Initialize();
	if( bEnable != m_Enabled ){
		m_Enabled = bEnable;
		Draw();
	}
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnDrawInternal(CDC *pDC)
{
	Initialize();

	RECT rc = m_rcClient;
	pDC->FillSolidRect(&rc, m_clEdge[2]);
	if( m_fState ){		// push button
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, m_clEdge[1]);
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, m_clEdge[0]);
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clPush);
	}
	else {				// pop button
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clEdge[1]);
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clEdge[0]);
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, GetRefColor(m_clFace));
	}
	CFont *pOldFont = SelectStockFont(pDC);
	pDC->SetTextColor(GetRefColor(m_Enabled ? m_clText : m_clGrayText));
	pDC->DrawText(m_Text, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	pDC->SelectObject(pOldFont);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( !m_Enabled ) return;
	if( m_Toggled ){
		SetState(!GetState());
	}
	else {
		SetState(TRUE);
		::Sleep(100);
		SetState(FALSE);
	}
	FireOnLButtonClick();
}
void CXMMBtnCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
}
void CXMMBtnCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if( !m_Enabled ) return;
	FireDblClick();
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if( m_Enabled ) FireOnRButtonClick();
	COleControl::OnRButtonDown(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl メッセージ ハンドラ



BSTR CXMMBtnCtrl::GetCaption() 
{
	CString strResult;
	strResult = m_Text;
	return strResult.AllocSysString();
}

void CXMMBtnCtrl::SetCaption(LPCTSTR lpszNewValue) 
{
	m_Text = lpszNewValue;
	Draw();
	SetModifiedFlag();
}

OLE_COLOR CXMMBtnCtrl::GetTextColor() 
{
	return m_clText;
}

void CXMMBtnCtrl::SetTextColor(OLE_COLOR nNewValue) 
{
	m_clText = nNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetEnabled() 
{
	return m_Enabled;
}

void CXMMBtnCtrl::SetEnabled(BOOL bNewValue) 
{
	m_Enabled = bNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetState() 
{
	return m_fState;
}

void CXMMBtnCtrl::SetState(BOOL bNewValue) 
{
	Initialize();
	if( m_fState == bNewValue ) return;
	m_fState = bNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetToggled() 
{
	return m_Toggled;
}

void CXMMBtnCtrl::SetToggled(BOOL bNewValue) 
{
	m_Toggled = bNewValue;
	if( !m_Toggled && GetState() ) SetState(FALSE);
	SetModifiedFlag();
}


OLE_COLOR CXMMBtnCtrl::GetFaceColor() 
{
	return m_clFace;
}

void CXMMBtnCtrl::SetFaceColor(OLE_COLOR nNewValue) 
{
	m_clFace = nNewValue;
	Draw();
	SetModifiedFlag();
}

void CXMMBtnCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}
