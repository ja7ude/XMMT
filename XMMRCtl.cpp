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

// XMMRCtl.cpp : CXMMRCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMRCtl.h"
#include "XMMRPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void STRNCPY(LPSTR pDest, LPCTSTR pSrc, int len)
{
	len--;
	for( int i = 0; *pSrc && (i < len); i++ ){
		*pDest++ = BYTE(*pSrc++);
	}
	*pDest = 0;
}

IMPLEMENT_DYNCREATE(CXMMRCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ
const UINT gMsgMmtty=::RegisterWindowMessage(_T("MMTTY"));

BEGIN_MESSAGE_MAP(CXMMRCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMRCtrl)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_REGISTERED_MESSAGE(gMsgMmtty, OnMmttyMessage )
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CXMMRCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMRCtrl)
	DISP_PROPERTY(CXMMRCtrl, "bRemoveUselessMessage", m_bRemoveUselessMessage, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "bTranslateAllMessages", m_bTranslateAllMessages, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "bInitialClose", m_bInitialClose, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "DelayInvoke", m_delayInvoke, VT_I4)
	DISP_PROPERTY(CXMMRCtrl, "bNotifyComChange", m_bNotifyComChange, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "bConfirmClose", m_bConfirmClose, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "bNotifyXY", m_bNotifyXY, VT_BOOL)
	DISP_PROPERTY(CXMMRCtrl, "bNotifyFFT", m_bNotifyFFT, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CXMMRCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMRCtrl, "bActive", GetBActive, SetBActive, VT_BOOL)
	DISP_PROPERTY_EX(CXMMRCtrl, "InvokeCommand", GetInvokeCommand, SetInvokeCommand, VT_BSTR)
	DISP_PROPERTY_EX(CXMMRCtrl, "TxBufLen", GetTxBufLen, SetTxBufLen, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "ComName", GetComName, SetComName, VT_BSTR)
	DISP_PROPERTY_EX(CXMMRCtrl, "Title", GetTitle, SetTitle, VT_BSTR)
	DISP_PROPERTY_EX(CXMMRCtrl, "RadioName", GetRadioName, SetRadioName, VT_BSTR)
	DISP_PROPERTY_EX(CXMMRCtrl, "smpFreq", GetSmpFreq, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "smpFFT", GetSmpFFT, SetSmpFFT, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "verMMTTY", GetVerMMTTY, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CXMMRCtrl, "LostSound", GetLostSound, SetLostSound, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "OverFlow", GetOverFlow, SetOverFlow, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "ErrorClock", GetErrorClock, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "smpDemFreq", GetSmpDemFreq, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "PTT", GetPTT, SetPTT, VT_BOOL)
	DISP_PROPERTY_EX(CXMMRCtrl, "hWndMmtty", GetHWndMmtty, SetNotSupported, VT_HANDLE)
	DISP_PROPERTY_EX(CXMMRCtrl, "bInvoking", GetBInvoking, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX(CXMMRCtrl, "SharedPointer", GetSharedPointer, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CXMMRCtrl, "VisibleMmtty", GetVisibleMmtty, SetVisibleMmtty, VT_BOOL)
	DISP_FUNCTION(CXMMRCtrl, "PostMmttyMessage", PostMmttyMessage, VT_BOOL, VTS_I4 VTS_I4)
	DISP_FUNCTION(CXMMRCtrl, "SetMmttySwitch", SetMmttySwitch, VT_BOOL, VTS_I4)
	DISP_FUNCTION(CXMMRCtrl, "SetMmttyView", SetMmttyView, VT_BOOL, VTS_I4)
	DISP_FUNCTION(CXMMRCtrl, "SetMmttyPTT", SetMmttyPTT, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CXMMRCtrl, "SendChar", SendChar, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CXMMRCtrl, "SendString", SendString, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CXMMRCtrl, "ReadNMMR", ReadNMMR, VT_EMPTY, VTS_PI4)
	DISP_PROPERTY_PARAM(CXMMRCtrl, "Profiles", GetProfiles, SetProfiles, VT_BSTR, VTS_I2)
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMRCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMRCtrl)
	EVENT_CUSTOM("OnConnected", FireOnConnected, VTS_NONE)
	EVENT_CUSTOM("OnCharRcvd", FireOnCharRcvd, VTS_I2)
	EVENT_CUSTOM("OnPttEvent", FireOnPttEvent, VTS_I2)
	EVENT_CUSTOM("OnDisconnected", FireOnDisconnected, VTS_I2)
	EVENT_CUSTOM("OnNotifyNMMR", FireOnNotifyNMMR, VTS_PI4)
	EVENT_CUSTOM("OnNotchChanged", FireOnNotchChanged, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnViewChanged", FireOnViewChanged, VTS_I4)
	EVENT_CUSTOM("OnSwitchChanged", FireOnSwitchChanged, VTS_I4)
	EVENT_CUSTOM("OnFreqChanged", FireOnFreqChanged, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnBaudChanged", FireOnBaudChanged, VTS_I2)
	EVENT_CUSTOM("OnNotifyFFT", FireOnNotifyFFT, VTS_PI2  VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnNotifyXY", FireOnNotifyXY, VTS_PI4)
	EVENT_CUSTOM("OnRadioFreqChanged", FireOnRadioFreqChanged, VTS_I4)
	EVENT_CUSTOM("OnRadioNameChanged", FireOnRadioNameChanged, VTS_BSTR)
	EVENT_CUSTOM("OnComNameChanged", FireOnComNameChanged, VTS_BSTR)
	EVENT_CUSTOM("OnFigChanged", FireOnFigChanged, VTS_I2)
	EVENT_CUSTOM("OnTranslateMessage", FireOnTranslateMessage, VTS_I4  VTS_I4)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMRCtrl, 1)
	PROPPAGEID(CXMMRPropPage::guid)
END_PROPPAGEIDS(CXMMRCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMRCtrl, "XMMR.XMMRCtrl.1",
	0xdc25fbe7, 0x50ba, 0x469e, 0x8a, 0x5d, 0x4f, 0xa3, 0x48, 0x8d, 0x6e, 0xc)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMRCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMR =
		{ 0xd721e49e, 0x6eb1, 0x4a51, { 0xad, 0x84, 0x61, 0x15, 0x5f, 0xce, 0x29, 0xb4 } };
const IID BASED_CODE IID_DXMMREvents =
		{ 0x527a76c5, 0x3c2d, 0x4d68, { 0x99, 0xec, 0xb4, 0xd2, 0xf5, 0x3c, 0xae, 0x74 } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMROleMisc =
//	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMRCtrl, IDS_XMMR, _dwXMMROleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::CXMMRCtrlFactory::UpdateRegistry -
// CXMMRCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMRCtrl::CXMMRCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMR,
			IDB_XMMR,
			afxRegApartmentThreading,
			_dwXMMROleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::CXMMRCtrl - コンストラクタ

CXMMRCtrl::CXMMRCtrl()
{
	InitializeIIDs(&IID_DXMMR, &IID_DXMMREvents);

	memset(&m_InternalArray, 0, sizeof(m_InternalArray));
	memset(&m_NMMR, 0, sizeof(m_NMMR));
	m_InvokeCommand = "MMTTY.EXE -m";
	m_bConnected = FALSE;
	m_hMMWnd = HWND_BROADCAST;
	m_hComFile = NULL;
	m_pCom = &m_InternalArray;
	m_ptt = FALSE;
	m_visible = TRUE;
	m_nTimerID = 0;
	m_bConfirmClose = TRUE;
	m_bInitialClose = TRUE;
	m_bNotifyFFT = TRUE;
	m_bNotifyXY = TRUE;
	m_bNotifyComChange = TRUE;
	m_bTranslateAllMessages = FALSE;
	m_bRemoveUselessMessage = TRUE;
	m_delayInvoke = 0;
	m_CommonMemory = _T("MMTTY");
	m_Timeup = 150;
}
/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::~CXMMRCtrl - デストラクタ
CXMMRCtrl::~CXMMRCtrl()
{
	CloseMmtty(FALSE);
	CloseCommonMemory();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::OnDraw - 描画関数

void CXMMRCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillSolidRect(&rcBounds, RGB(192,192,192));

	int x = rcBounds.left + (rcBounds.Width() - 16)/2;
	int y = rcBounds.top + (rcBounds.Height() - 15)/2;
	CBitmap bmp;
	bmp.LoadBitmap(IDB_XMMR);
	CDC dc;
	dc.CreateCompatibleDC(pdc);
	CBitmap *pOldBmp = dc.SelectObject(&bmp);
	pdc->BitBlt(x, y, 16, 15, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
	bmp.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::DoPropExchange - 永続性のサポート

void CXMMRCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("bInitialClose"), m_bInitialClose, TRUE);
	PX_Bool(pPX, _T("bConfirmClose"), m_bConfirmClose, TRUE);
	PX_Bool(pPX, _T("bNotifyFFT"), m_bNotifyFFT, TRUE);
	PX_Bool(pPX, _T("bNotifyXY"), m_bNotifyXY, TRUE);
	PX_Bool(pPX, _T("bNotifyComChange"), m_bNotifyComChange, TRUE);
	PX_Bool(pPX, _T("bTranslateAllMessages"), m_bTranslateAllMessages, FALSE);
	PX_Bool(pPX, _T("bRemoveUselessMessage"), m_bRemoveUselessMessage, TRUE);
#ifdef _DEBUG
	PX_String(pPX, _T("InvokeCommand"), m_InvokeCommand, _T("D:\\MMTTY\\MMTTY.EXE -r"));
#else
	PX_String(pPX, _T("InvokeCommand"), m_InvokeCommand, _T("MMTTY.EXE -m"));
#endif
	PX_String(pPX, _T("ComName"), m_ComName, _T(""));
	PX_String(pPX, _T("RadioName"), m_RadioName, _T(""));
	PX_String(pPX, _T("Title"), m_Title, _T(""));
	PX_Long(pPX, _T("smpFFT"), m_smpFFT, FALSE);
	PX_Long(pPX, _T("DelayInvoke"), m_delayInvoke, 0);

#if 0
	if( pPX->IsLoading() ){
		DecodeOptions();
	}
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMRCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}

/////////////////////////////////////////////////////////////////////////////
void CXMMRCtrl::CreateCommonMemory(void)
{
	// 共有メモリアクセスのファイルマッピングを作成します。
	m_hComFile = (HANDLE)::CreateFileMapping(HANDLE(0xffffffff), NULL, PAGE_READWRITE, 0, sizeof(COMARRAY), m_CommonMemory);
	if( m_hComFile && (m_pCom = (COMARRAY *)::MapViewOfFile(m_hComFile, FILE_MAP_WRITE, 0, 0, 0))!=NULL ){
		// 共有メモリを初期化します。
		memset(m_pCom, 0, sizeof(COMARRAY));
	}
	else {
		if( m_hComFile ){
			CloseHandle(m_hComFile);
			m_hComFile = NULL;
		}
	}
}

void CXMMRCtrl::CloseCommonMemory(void)
{
	if( m_hComFile ){
		if( m_pCom != &m_InternalArray ){
			::UnmapViewOfFile(m_pCom);
			m_pCom = NULL;
		}
		CloseHandle(m_hComFile);
		m_hComFile = NULL;
	}
}

void CXMMRCtrl::ChangeCommonMemory(LPCSTR pCommonMemory)
{
	if( (m_pCom == &m_InternalArray) || strcmp(pCommonMemory, m_CommonMemory) ){
		if( m_pCom && (m_pCom != &m_InternalArray) ){
			memcpy(&m_InternalArray, m_pCom, sizeof(COMARRAY));
		}
		CloseCommonMemory();
		m_CommonMemory = pCommonMemory;
		CreateCommonMemory();
		if( m_pCom ){
			memcpy(m_pCom, &m_InternalArray, sizeof(COMARRAY));
		}
	}
}

void __fastcall SetStr(CString &cs, LPCSTR p)
{
	cs = "";
	for( ; *p && *p != ' '; p++ ) cs += *p;
}

void CXMMRCtrl::DecodeOptions(void)
{
	CString cs;
	LPCSTR s = m_InvokeCommand;
	while(*s){
		if( !strncmp(s, " -C", 3) ){
			SetStr(cs, s + 3);
			ChangeCommonMemory(cs);
		}
		else if( !strncmp(s, " -T", 3) ){
			SetStr(cs, s + 3);
			m_Timeup = (atoi(cs) * 10) + 30;
		}
		s++;
	}
}

void CXMMRCtrl::InternalPostMmttyMessage(DWORD wParam, DWORD lParam)
{
	// MMTTYにメッセージを送ります。
	::PostMessage(m_hMMWnd, gMsgMmtty, wParam, lParam);
}
//---------------------------------------------------------------------------
void CXMMRCtrl::RemoveUselessMessage(void)
{
	MSG msg;
	while( ::PeekMessage(&msg, m_hWnd, gMsgMmtty, gMsgMmtty, PM_NOREMOVE) ){
		if( msg.wParam == TXM_LEVEL ){
			::PeekMessage(&msg, m_hWnd, gMsgMmtty, gMsgMmtty, PM_REMOVE);
		}
		else {
			break;
		}
	}
}
//---------------------------------------------------------------------------
LRESULT CXMMRCtrl::OnMmttyMessage(WPARAM wParam, LPARAM lParam)
{
	switch(wParam){
		case TXM_HANDLE:
			m_hMMWnd = (HWND)lParam;
			InternalPostMmttyMessage(RXM_HANDLE, (DWORD)m_hWnd);
			if( !m_bConnected ){
				DeleteTimer();
				InternalPostMmttyMessage(RXM_ENBFOCUS, FALSE);
				m_bConnected = TRUE;
				FireOnConnected();
			}
			break;
		case TXM_REQHANDLE:
			InternalPostMmttyMessage(RXM_HANDLE, (DWORD)m_hWnd);
			break;
		case TXM_START:
			VERIFY(m_hMMWnd != HWND_BROADCAST);
			break;
		case TXM_PTTEVENT:
			m_ptt = lParam;
			if( !m_bTranslateAllMessages ) FireOnPttEvent(SHORT(lParam));
			break;
		case TXM_CHAR:
			if( !m_bTranslateAllMessages ) FireOnCharRcvd(SHORT(lParam));
			break;
		case TXM_BAUD:
			m_NMMR.m_baud = lParam;
			if( !m_bTranslateAllMessages ) FireOnBaudChanged(SHORT(lParam));
			break;
		case TXM_MARK:
			m_NMMR.m_markfreq = lParam;
			break;
		case TXM_SPACE:
			m_NMMR.m_spacefreq = lParam;
			if( !m_bTranslateAllMessages ) FireOnFreqChanged(SHORT(m_NMMR.m_markfreq), SHORT(m_NMMR.m_spacefreq));
			break;
		case TXM_SWITCH:
			m_NMMR.m_codeswitch = lParam;
			if( !m_bTranslateAllMessages ) FireOnSwitchChanged(lParam);
			break;
		case TXM_VIEW:
			m_NMMR.m_codeview = lParam;
			if( !m_bTranslateAllMessages ) FireOnViewChanged(lParam);
			break;
		case TXM_LEVEL:
			if( m_bRemoveUselessMessage ) RemoveUselessMessage();
			m_NMMR.m_siglevel = LOWORD(lParam);
			m_NMMR.m_sqlevel = HIWORD(lParam);
			if( !m_bTranslateAllMessages ) FireOnNotifyNMMR((LONG *)&m_NMMR);
			if( m_pCom ){
				if( m_bNotifyFFT && m_pCom->flagFFT ){
					SHORT *pw = m_fft;
					LPLONG pl = m_pCom->arrayFFT;
					int size = (m_pCom->smpFreq >= 10000) ? 2048 : 1024;
					if( m_pCom->smpFFT ) size = 2048;
					for( int i = 0; i < size; i++ ) *pw++ = SHORT(*pl++);
					m_pCom->flagFFT = 0;
					FireOnNotifyFFT(m_fft, SHORT(size), SHORT(m_pCom->smpFreq));
				}
				if( m_bNotifyXY && m_pCom->flagXY ){
					memcpy(m_xy, m_pCom->arrayX, sizeof(m_xy));
					m_pCom->flagXY = 0;
					FireOnNotifyXY(m_xy);
				}
#ifndef _UNICODE
				if( m_bNotifyComChange && strcmp(m_pCom->comName, m_ComName) ){
					m_ComName = m_pCom->comName;
					FireOnComNameChanged(m_ComName);
				}
				if( m_bNotifyComChange && strcmp(m_pCom->comRadio, m_RadioName) ){
					m_RadioName = m_pCom->comRadio;
					FireOnComNameChanged(m_RadioName);
				}
#endif
			}
			break;
		case TXM_FIGEVENT:
			m_NMMR.m_fig = lParam;
			if( !m_bTranslateAllMessages ) FireOnFigChanged(SHORT(lParam));
			break;
		case TXM_NOTCH:
			m_NMMR.m_notch1 = LOWORD(lParam);
			m_NMMR.m_notch2 = HIWORD(lParam);
			if( !m_bTranslateAllMessages ) FireOnNotchChanged(SHORT(m_NMMR.m_notch1), SHORT(m_NMMR.m_notch2));
			break;
		case TXM_RADIOFREQ:
			m_NMMR.m_radiofreq = lParam;
			if( !m_bTranslateAllMessages ) FireOnRadioFreqChanged(lParam);
			break;
		default:
			if( !m_bTranslateAllMessages ) FireOnTranslateMessage(wParam, lParam);
			break;
	}
	if( m_bTranslateAllMessages ) FireOnTranslateMessage(wParam, lParam);
	return FALSE;
}
//---------------------------------------------------------------------------
void CXMMRCtrl::OnTimer(UINT nIDEvent) 
{
	if( nIDEvent == m_nTimerID ){
		switch(m_TimerMode){
			case 0:
				if( m_TimerCount ){
					m_TimerCount--;
					break;
				}
				if( m_pCom ){
					m_pCom->smpFFT = m_smpFFT;
					STRNCPY(m_pCom->title, m_Title, sizeof(m_pCom->title));
					if( m_ComName.IsEmpty() ){
						m_ComName = m_pCom->comName;
					}
					else {
						STRNCPY(m_pCom->comName, m_ComName, sizeof(m_pCom->comName));
					}
					if( m_RadioName.IsEmpty() ){
						m_RadioName = m_pCom->comRadio;
					}
					else {
						STRNCPY(m_pCom->comRadio, m_RadioName, sizeof(m_pCom->comRadio));
					}
				}
				VERIFY(m_hWnd == (HWND)GetHwnd());
				if( !m_hWnd ){
					AfxMessageBox(IDS_XMMR_NO_WINDOW);
					return;
				}
				{
					TCHAR bf[512];
					wsprintf(bf, _T("%s -h%X"), m_InvokeCommand, (DWORD)m_hWnd);
#ifdef _UNICODE
					char bbf[512];
					STRNCPY(bbf, bf, sizeof(bbf));
					UINT r = ::WinExec(bbf, SW_SHOW);
#else
					UINT r = ::WinExec(bf, SW_SHOW);
#endif
					m_TimerMode++;
					m_TimerCount = (r > 31) ? m_Timeup : 1;
				}
				//break;
			case 1:
				m_TimerCount--;
				if( !m_TimerCount ){
					DeleteTimer();
					FireOnDisconnected(2);
				}
				else if( !m_bConnected && m_bInitialClose && (m_TimerCount < (m_Timeup-50)) ){
					// For insurance
					HWND hWnd = ::FindWindow(_T("TMmttyWd"), NULL);
					if( hWnd ){
						::PostMessage(hWnd, gMsgMmtty, RXM_HANDLE, (DWORD)m_hWnd);
						::PostMessage(hWnd, gMsgMmtty, RXM_REQHANDLE, 0);
					}
				}
				break;
		}
	}
	else {	
		COleControl::OnTimer(nIDEvent);
	}
}
//---------------------------------------------------------------------------
void CXMMRCtrl::DeleteTimer(void)
{
	if( m_nTimerID ){
		KillTimer(m_nTimerID);
		m_nTimerID = NULL;
	}
}
//---------------------------------------------------------------------------
void CXMMRCtrl::OpenMmtty(void)
{
	CloseMmtty(TRUE);
	m_hMMWnd = HWND_BROADCAST;

	DecodeOptions();
	if( m_pCom == &m_InternalArray ){
		ChangeCommonMemory(m_CommonMemory);
	}
	// アプリケーションを起動/監視するためのタイマーを起動します。
	m_TimerMode = 0;
	m_nTimerID = SetTimer(1, 100, NULL);
	m_TimerCount = m_delayInvoke / 100;
}
//---------------------------------------------------------------------------
void CXMMRCtrl::CloseMmtty(BOOL bWait)
{
	DeleteTimer();
	HWND hWnd = NULL;
	if( m_bInitialClose ){
		hWnd = (m_hMMWnd != HWND_BROADCAST) ? m_hMMWnd : ::FindWindow(_T("TMmttyWd"), NULL);
	}
	else {
		hWnd = (m_hMMWnd != HWND_BROADCAST) ? m_hMMWnd : NULL;
	}
	m_hMMWnd = HWND_BROADCAST;
	m_bConnected = FALSE;
	m_ptt = FALSE;
	if( hWnd ){
		// スタンドアローンで起動されているかもしれないので、
		// WM_CLOSEを送って終了させます。
		::SendMessage(hWnd, WM_CLOSE, 0, 0);

		if( bWait ){
			int i = 0;
			if( m_bConfirmClose ){
				// MMTTYが完全に終了するまで待ちます。
				for( i = 0; (i < 500) && IsWindow(hWnd); i++ ){
					::Sleep(10);
				}
			}
			FireOnDisconnected(i >= 500 ? 0 : 1);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl メッセージ ハンドラ

BOOL CXMMRCtrl::GetBActive() 
{
	return m_bConnected;
}

void CXMMRCtrl::SetBActive(BOOL bNewValue) 
{
	if( bNewValue ){
		if( !m_bConnected ){
			OpenMmtty();
		}
	}
	else {
		CloseMmtty(TRUE);
	}
	SetModifiedFlag();
}


BSTR CXMMRCtrl::GetInvokeCommand() 
{
	CString strResult;
	strResult = m_InvokeCommand;
	return strResult.AllocSysString();
}

void CXMMRCtrl::SetInvokeCommand(LPCTSTR lpszNewValue) 
{
	if( lstrcmp(m_InvokeCommand, lpszNewValue) ){
		m_InvokeCommand = lpszNewValue;
		if( m_bConnected ) DecodeOptions();
		SetModifiedFlag();
	}
}


long CXMMRCtrl::GetTxBufLen() 
{
	return m_pCom ? m_pCom->TxBuffCount : 0;
}

void CXMMRCtrl::SetTxBufLen(long nNewValue) 
{
	if( m_pCom ){
		m_pCom->TxBuffCount = nNewValue;
		SetModifiedFlag();
	}
}

BSTR CXMMRCtrl::GetComName() 
{
	CString strResult;
	if( m_bConnected && m_pCom ) m_ComName = m_pCom->comName;
	strResult = m_ComName;
	return strResult.AllocSysString();
}

void CXMMRCtrl::SetComName(LPCTSTR lpszNewValue) 
{
	m_ComName = lpszNewValue;
	if( m_pCom ){
		STRNCPY(m_pCom->comName, m_ComName, sizeof(m_pCom->comName));
		PostMmttyMessage(RXM_UPDATECOM, 0);
	}
	SetModifiedFlag();
}

BSTR CXMMRCtrl::GetTitle() 
{
	CString strResult;
	strResult = m_Title;
	return strResult.AllocSysString();
}

void CXMMRCtrl::SetTitle(LPCTSTR lpszNewValue) 
{
	m_Title = lpszNewValue;
	if( m_pCom ){
		STRNCPY(m_pCom->title, m_Title, sizeof(m_pCom->title));
		PostMmttyMessage(RXM_UPDATECOM, 0);
	}
	SetModifiedFlag();
}

BSTR CXMMRCtrl::GetRadioName() 
{
	CString strResult;
	if( m_bConnected && m_pCom ) m_RadioName = m_pCom->comRadio;
	strResult = m_RadioName;
	return strResult.AllocSysString();
}

void CXMMRCtrl::SetRadioName(LPCTSTR lpszNewValue) 
{
	m_RadioName = lpszNewValue;
	if( m_pCom ){
		STRNCPY(m_pCom->comRadio, m_RadioName, sizeof(m_pCom->comRadio));
		PostMmttyMessage(RXM_UPDATECOM, 0);
	}
	SetModifiedFlag();
}

long CXMMRCtrl::GetSmpFreq() 
{
	return m_pCom ? m_pCom->smpFreq : 0;
}

long CXMMRCtrl::GetSmpFFT() 
{
	return m_smpFFT;
}

void CXMMRCtrl::SetSmpFFT(long nNewValue) 
{
	m_smpFFT = nNewValue;
	if( m_pCom ){
		m_pCom->smpFFT = nNewValue;
	}
	SetModifiedFlag();
}

BSTR CXMMRCtrl::GetVerMMTTY() 
{
	CString strResult;
	strResult = m_pCom ? m_pCom->verMMTTY : "Unknown";
	return strResult.AllocSysString();
}

long CXMMRCtrl::GetLostSound() 
{
	return m_pCom ? m_pCom->LostSound : 0;
}

void CXMMRCtrl::SetLostSound(long nNewValue) 
{
	if( m_pCom ){
		m_pCom->LostSound = nNewValue;
		SetModifiedFlag();
	}
}

long CXMMRCtrl::GetOverFlow() 
{
	return m_pCom ? m_pCom->OverFlow : 0;
}

void CXMMRCtrl::SetOverFlow(long nNewValue) 
{
	if( m_pCom ){
		m_pCom->OverFlow = nNewValue;
		SetModifiedFlag();
	}
}

long CXMMRCtrl::GetErrorClock() 
{
	return m_pCom ? m_pCom->ErrorClock : 0;
}

long CXMMRCtrl::GetSmpDemFreq() 
{
	return m_pCom ? m_pCom->smpDemFreq : 0;
}

BOOL CXMMRCtrl::GetPTT() 
{
	return m_ptt;
}

void CXMMRCtrl::SetPTT(BOOL bNewValue) 
{
	if( m_bConnected ){
		m_ptt = bNewValue;
		PostMmttyMessage(RXM_PTT, bNewValue ? 2 : 0);
	}
	SetModifiedFlag();
}

void CXMMRCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}

BOOL CXMMRCtrl::PostMmttyMessage(long wParam, long lParam) 
{
	if( !m_bConnected ) return FALSE;
	::PostMessage(m_hMMWnd, gMsgMmtty, wParam, lParam);
	return TRUE;
}

BOOL CXMMRCtrl::SetMmttySwitch(long codeswitch) 
{
	return PostMmttyMessage(RXM_SETSWITCH, codeswitch);
}

BOOL CXMMRCtrl::SetMmttyView(long codeview) 
{
	return PostMmttyMessage(RXM_SETVIEW, codeview);
}

BOOL CXMMRCtrl::SetMmttyPTT(short ptt) 
{
	return PostMmttyMessage(RXM_PTT, ptt);
}

BOOL CXMMRCtrl::SendChar(short bChar) 
{
	if( !m_bConnected ) return FALSE;
	if( !m_ptt ) SetMmttyPTT(2);
	return PostMmttyMessage(RXM_CHAR, bChar);
}

BOOL CXMMRCtrl::SendString(LPCTSTR pStr) 
{
	if( !m_bConnected ) return FALSE;
	if( !m_ptt ) SetMmttyPTT(2);
	while( *pStr ){
		if( !SendChar(*pStr++) ) return FALSE;
	}
	return TRUE;
}

OLE_HANDLE CXMMRCtrl::GetHWndMmtty() 
{
	return (OLE_HANDLE)m_hMMWnd;
}

BSTR CXMMRCtrl::GetProfiles(short nIndex) 
{
	CString strResult;
	if( (nIndex >= 0) && (nIndex < 16) && m_pCom ){
		strResult = m_pCom->ProfileName[nIndex];
	}
	return strResult.AllocSysString();
}

void CXMMRCtrl::SetProfiles(short nIndex, LPCTSTR lpszNewValue) 
{
	if( (nIndex >= 0) && (nIndex < 16) && m_pCom ){
		STRNCPY(m_pCom->ProfileName[nIndex], lpszNewValue, 64);
		SetModifiedFlag();
	}
}

BOOL CXMMRCtrl::GetBInvoking() 
{
	return m_nTimerID != NULL;
}

long CXMMRCtrl::GetSharedPointer() 
{
	return (long)m_pCom;
}

BOOL CXMMRCtrl::GetVisibleMmtty() 
{
	if( !m_bConnected ) return FALSE;
	return ::IsWindowVisible(m_hMMWnd);
}

void CXMMRCtrl::SetVisibleMmtty(BOOL bNewValue) 
{
	if( !m_bConnected ) return;
	PostMmttyMessage(RXM_SHOW, bNewValue);
}

void CXMMRCtrl::ReadNMMR(long FAR* pNMMR) 
{
	memcpy(pNMMR, &m_NMMR, sizeof(m_NMMR));
}
