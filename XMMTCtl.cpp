// XMMTCtl.cpp : CXMMTCtrl ActiveX コントロール クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMTCtl.h"
#include "XMMTPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMTCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMTCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMTCtrl)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CXMMTCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMTCtrl)
	DISP_PROPERTY(CXMMTCtrl, "bFftConversion", m_bFftConversion, VT_BOOL)
	DISP_PROPERTY_EX(CXMMTCtrl, "wPortTcp", GetWPortTcp, SetWPortTcp, VT_I2)
	DISP_PROPERTY_EX(CXMMTCtrl, "bActive", GetBActive, SetBActive, VT_BOOL)
	DISP_PROPERTY_EX(CXMMTCtrl, "wMaxCount", GetWMaxCount, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CXMMTCtrl, "wCount", GetWCount, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CXMMTCtrl, "HostName", GetHostName, SetNotSupported, VT_BSTR)
	DISP_FUNCTION(CXMMTCtrl, "Listen", Listen, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CXMMTCtrl, "SendChar", SendChar, VT_BOOL, VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "SendCode", SendCode, VT_BOOL, VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "SetBusy", SetBusy, VT_EMPTY, VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "SendMmttyMessage", SendMmttyMessage, VT_BOOL, VTS_I2 VTS_I4 VTS_I4)
	DISP_FUNCTION(CXMMTCtrl, "PostMmttyMessage", PostMmttyMessage, VT_BOOL, VTS_I2 VTS_I4 VTS_I4)
	DISP_FUNCTION(CXMMTCtrl, "WriteMmttyTxw", WriteMmttyTxw, VT_BOOL, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CXMMTCtrl, "SetNotify", SetNotify, VT_BOOL, VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "IsConnected", IsConnected, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "Disconnect", Disconnect, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "IsBusy", IsBusy, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "SendString", SendString, VT_BOOL, VTS_I2 VTS_BSTR VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "GetAddress", GetAddress, VT_BSTR, VTS_I2)
	DISP_FUNCTION(CXMMTCtrl, "PostMmttyMessageAsString", PostMmttyMessageAsString, VT_BOOL, VTS_I2 VTS_I4 VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// イベント マップ

BEGIN_EVENT_MAP(CXMMTCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMTCtrl)
	EVENT_CUSTOM("OnPttEvent", FireOnPttEvent, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnBusyEvent", FireOnBusyEvent, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnDisconnected", FireOnDisconnected, VTS_I2)
	EVENT_CUSTOM("OnCharRcvd", FireOnCharRcvd, VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnConnected", FireOnConnected, VTS_I2)
	EVENT_CUSTOM("OnMessageResult", FireOnMessageResult, VTS_I2  VTS_I4  VTS_I4  VTS_I4)
	EVENT_CUSTOM("OnNotifyNMMT", FireOnNotifyNMMT, VTS_I2  VTS_PI4)
	EVENT_CUSTOM("OnNotifyXY", FireOnNotifyXY, VTS_I2  VTS_PI4)
	EVENT_CUSTOM("OnNotifyFFT", FireOnNotifyFFT, VTS_I2  VTS_PI2  VTS_I2  VTS_I2)
	EVENT_CUSTOM("OnGetProfileName", FireOnGetProfileName, VTS_I2  VTS_I2  VTS_BSTR)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CXMMTCtrl, 1)
	PROPPAGEID(CXMMTPropPage::guid)
END_PROPPAGEIDS(CXMMTCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CXMMTCtrl, "XMMT.XMMTCtrl.1",
	0x9ae88ac4, 0x3c6d, 0x41ba, 0xb1, 0x16, 0x84, 0x79, 0x25, 0x14, 0xe4, 0x38)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CXMMTCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DXMMT =
		{ 0xd38b08e1, 0xb3a1, 0x4ffd, { 0x9e, 0xc3, 0x81, 0x30, 0xfb, 0xad, 0x35, 0x93 } };
const IID BASED_CODE IID_DXMMTEvents =
		{ 0x39642706, 0xd45b, 0x46a9, { 0x96, 0x85, 0xc7, 0x43, 0x6d, 0xf5, 0x61, 0x38 } };

/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwXMMTOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMTCtrl, IDS_XMMT, _dwXMMTOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::CXMMTCtrlFactory::UpdateRegistry -
// CXMMTCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CXMMTCtrl::CXMMTCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMT,
			IDB_XMMT,
			afxRegApartmentThreading,
			_dwXMMTOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::CXMMTCtrl - コンストラクタ

CXMMTCtrl::CXMMTCtrl()
{
	InitializeIIDs(&IID_DXMMT, &IID_DXMMTEvents);

	m_bFftConversion = FALSE;
	m_pSocket = NULL;
	m_PortTCP = 10301;
	m_ConnectionCount = 0;
	memset(m_pConnection, 0, sizeof(m_pConnection));
	memset(m_bBusy, TRUE, sizeof(m_bBusy));
	memset(m_bNotify, 0, sizeof(m_bNotify));
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::~CXMMTCtrl - デストラクタ

CXMMTCtrl::~CXMMTCtrl()
{
	CloseAll();
}
/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::OnDraw - 描画関数

void CXMMTCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillSolidRect(&rcBounds, RGB(192,192,192));

	int x = rcBounds.left + (rcBounds.Width() - 16)/2;
	int y = rcBounds.top + (rcBounds.Height() - 15)/2;
	CBitmap bmp;
	bmp.LoadBitmap(IDB_XMMT);
	CDC dc;
	dc.CreateCompatibleDC(pdc);
	CBitmap *pOldBmp = dc.SelectObject(&bmp);
	pdc->BitBlt(x, y, 16, 15, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
	bmp.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::DoPropExchange - 永続性のサポート

void CXMMTCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("bFftConversion"), m_bFftConversion, FALSE);
	PX_Short(pPX, _T("wPortTcp"), m_PortTCP, 10301);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::GetControlFlags -
// MFC の ActiveX コントロールのインプリメンテーションのカスタマイズ用フラグ
//
// これらのフラグの使い方については MFC のテクニカル ノート "ActiveX コントロールの最適化"
// を参照してください。
DWORD CXMMTCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// コントロールはウィンドウを作成せずにアクティベート可能です。
	// TODO: コントロールのメッセージ ハンドラを作成する場合、m_hWnd
	//		 メンバ変数の値が NULL 以外であることを最初に確認
	//		してから使用してください。
	dwFlags |= windowlessActivate;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl::OnResetState - コントロールのプロパティ値をリセット

void CXMMTCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	CloseAll();
	m_bFftConversion = FALSE;
	m_PortTCP = 10301;
	m_ConnectionCount = 0;
	memset(m_pConnection, 0, sizeof(m_pConnection));
	memset(m_bBusy, TRUE, sizeof(m_bBusy));
	memset(m_bNotify, 0, sizeof(m_bNotify));
}


//---------------------------------------------------------------------------
void CXMMTCtrl::CloseSocket(CCSocket *pSocket)
{
	ASSERT(pSocket);
	ASSERT(pSocket->IsKindOf(RUNTIME_CLASS(CCSocket)));

	pSocket->EnableEvent(FALSE);
	pSocket->Close();

	for( int i = 0; i < USERMAX; i++ ){
		if( m_pConnection[i] == pSocket ){
			m_pConnection[i] = NULL;
			m_CustomSession[i].Delete();
			m_bBusy[i] = TRUE;
			m_ConnectionCount--;
			FireOnDisconnected(i);
			break;
		}
	}
	delete pSocket;
}
//---------------------------------------------------------------------------
BOOL CXMMTCtrl::SendBuf(CCSocket *pSocket, const void *p, int n)
{
	if( n <= 0 ) return TRUE;
	DWORD dwTimeOut = ::GetTickCount() + STIMEOUT;
	int len;
	do {
		len = pSocket->Send(p, n);
		if( len == n ){
			return TRUE;
		}
		else if( len == SOCKET_ERROR ){
			break;
		}
		else if( len < n ){
			n -= len;
			p = ((const BYTE *)p)+len;
		}
		::Sleep(10);
	} while( dwTimeOut > ::GetTickCount() );
	CloseSocket(pSocket);
	return FALSE;
}
//---------------------------------------------------------------------------
void CXMMTCtrl::OnAccept(int nErrorCode)
{
	ASSERT(m_pSocket);
	if( !m_pSocket ) return;

	for( int i = 0; i < USERMAX; i++ ){
		if( !m_pConnection[i] ){
			CCSocket* pSocket = new CCSocket(this);
			if(m_pSocket->Accept(*pSocket)){
				m_pConnection[i] = pSocket;
				m_CustomSession[i].Delete();
				m_bNotify[i] = 0;
				m_bBusy[i] = 0;
				m_ConnectionCount++;
				FireOnConnected(i);
			}
			else {
				delete pSocket;
			}
			break;
		}
	}
}
//---------------------------------------------------------------------------
void CXMMTCtrl::OnDisconnected(CCSocket *pSocket)
{
	CloseSocket(pSocket);
}
//---------------------------------------------------------------------------
void CXMMTCtrl::OnReceive(CCSocket *pSocket, int nErrorCode)
{
	if( nErrorCode == SOCKET_ERROR ) return;
	ASSERT(pSocket);
	BYTE    bf[8192];
	UINT    n;

	n = pSocket->Receive(bf, sizeof(bf));
	int nIndex = 0;
	for( ; (nIndex < USERMAX) && (pSocket != m_pConnection[nIndex]); nIndex++ );
	if( nIndex >= USERMAX ) return;
	if( n != SOCKET_ERROR ){
		LPBYTE p = bf;
		for( UINT i = 0; i < n; i++, p++ ){
			if( !m_CustomSession[nIndex].IsOpen() ){
				switch(*p){
					case NOTIFY_PTTON:
						FireOnPttEvent(nIndex, TRUE);
						break;
					case NOTIFY_PTTOFF:
						FireOnPttEvent(nIndex, FALSE);
						break;
					case NOTIFY_BUSYON:
						m_bBusy[nIndex] = TRUE;
						FireOnBusyEvent(nIndex, TRUE);
						break;
					case NOTIFY_BUSYOFF:
						m_bBusy[nIndex] = FALSE;
						FireOnBusyEvent(nIndex, FALSE);
						break;
					case CODE_CUSTOMSESSION:
						// サーバーとクライアント間で定義された特別なデータの伝送が
						// 開始されます。
						m_CustomSession[nIndex].OpenSession();
						break;
					default:
						FireOnCharRcvd(nIndex, *p);
						break;
				}
			}
			else if( m_CustomSession[nIndex].PutData(*p) ){
				// サーバーとクライアント間で定義された特別なデータの伝送が終了
				// しました。ここでそのデータの処理を行います。
				CUSTOMSESSION *pCom = m_CustomSession[nIndex].GetData();
				switch(pCom->m_command){
					case COM_NOTIFY:
						// MMTTYからのmmtNotifyがここに通知されます。
						if( m_bNotify[nIndex] & ntNOTIFY ){
							FireOnNotifyNMMT(nIndex, (LONG *)pCom->m_pData);
						}
						break;
					case COM_NOTIFYFFT:
						// MMTTYからのmmtNotifyFFTがここに通知されます。
						if( m_bNotify[nIndex] & ntNOTIFYFFT ){
							COMFFT *pFFT = (COMFFT *)pCom->m_pData;
							if( m_bFftConversion ){
								DoFftConversion(nIndex, pFFT);
							}
							else {
								FireOnNotifyFFT(nIndex, pFFT->m_wdata, pFFT->m_wsize, pFFT->m_wsampfreq);
							}
						}
						break;
					case COM_NOTIFYXY:
						// MMTTYからのmmtNotifyXYがここに通知されます。
						if( m_bNotify[nIndex] & ntNOTIFYXY ){
							FireOnNotifyXY(nIndex, (LONG *)pCom->m_pData);
						}
						break;
					case COM_MESSAGERESULT:
						// COM_MESSAGERESULTでMMTTYに送信したメッセージの返答が
						// ここに通知されます。
						{
							COMMSG *pc = (COMMSG *)pCom->m_pData;
							if( pc->m_wParam == MMTMSG_GETPROFILENAME ){
								LPCSTR pStr = LPCSTR(pCom->m_pData + sizeof(COMMSG));
								if( pCom->m_len <= sizeof(COMMSG) ) pStr = "";
								FireOnGetProfileName(nIndex, short(pc->m_lParam), pStr);
							}
							else {
								FireOnMessageResult(nIndex, pc->m_wParam, pc->m_lParam, pc->m_lResult);
							}
						}
						break;
				}
				m_CustomSession[nIndex].Delete();
			}
		}
	}
}
//---------------------------------------------------------------------------
CCSocket *CXMMTCtrl::GetSocket(int nIndex)
{
	if( nIndex < 0 ) return NULL;
	if( nIndex >= USERMAX ) return NULL;
	return m_pConnection[nIndex];
}
//---------------------------------------------------------------------------
void CXMMTCtrl::DoFftConversion(int nIndex, COMFFT *pCom)
{
	SHORT fft[2048];
	SHORT *ps = fft;
	int sampfreq = (pCom->m_wsampfreq * 2048) / pCom->m_wsize;
	int i, x;
	for( i = 0; i < 2048; i++, ps++ ){
		x = (i * 8000 / sampfreq);
		if( x < 2048 ){
			*ps = pCom->m_wdata[x];
		}
		else {
			for( ; i < 2048; i++ ) *ps++ = 0;
			break;
		}
	}
	FireOnNotifyFFT(nIndex, fft, 2048, 8000);
}
//---------------------------------------------------------------------------
void CXMMTCtrl::CloseAll(void) 
{
	if( m_pSocket ){
		m_pSocket->Close();
		delete m_pSocket;
		m_pSocket = NULL;
	}
	for( int i = 0; i < USERMAX; i++ ){
		if( m_pConnection[i] ){
			CCSocket *pSocket = m_pConnection[i];
			pSocket->EnableEvent(FALSE);
			pSocket->Close();
			delete pSocket;
			m_pConnection[i] = NULL;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl メッセージ ハンドラ

BOOL CXMMTCtrl::Listen() 
{
	CloseAll();
	if( !m_pSocket ){
		m_pSocket = new CLSocket(this);
		if( !m_pSocket->Create(m_PortTCP) || !m_pSocket->Listen() ){
			delete m_pSocket;
			m_pSocket = NULL;
		}
	}
	return m_pSocket != NULL;
}

BOOL CXMMTCtrl::SendString(short nIndex, LPCTSTR pStr, short nLen) 
{
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		if( m_bBusy[nIndex] ) return FALSE;
		if( nLen <= 0 ) nLen = 2048;
		BYTE *pb = new BYTE[nLen];
		LPBYTE p = pb;
		for( short n = 0; *pStr && (n < nLen); n++, pStr++){
			if( BYTE(*pStr) < TNC_PTTON ){
				*p++ = BYTE(*pStr);
			}
		}
		r = SendBuf(pSocket, pb, p - pb);
		delete pb;
	}
	return TRUE;
}

BOOL CXMMTCtrl::SendChar(short nIndex, short bChar) 
{
	if( bChar >= TNC_PTTON ) return FALSE;
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		if( m_bBusy[nIndex] ) return FALSE;
		BYTE b = BYTE(bChar);
		r = SendBuf(pSocket, &b, sizeof(b));
	}
	return r;
}

BOOL CXMMTCtrl::SendCode(short nIndex, short bCode) 
{
	if( bCode == CODE_CUSTOMSESSION ) return FALSE;
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		BYTE b = BYTE(bCode);
		r = SendBuf(pSocket, &b, sizeof(b));
	}
	return r;
}
BOOL CXMMTCtrl::IsBusy(short nIndex) 
{
	if( nIndex < 0 ) return TRUE;
	if( nIndex >= USERMAX ) return TRUE;
	return m_bBusy[nIndex];
}
void CXMMTCtrl::SetBusy(short nIndex, short bBusy) 
{
	if( nIndex < 0 ) return;
	if( nIndex >= USERMAX ) return;
	m_bBusy[nIndex] = bBusy;
}

BOOL CXMMTCtrl::PostMmttyMessage(short nIndex, long wParam, long lParam) 
{
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		COMMSG com;
		com.m_wParam = wParam;
		com.m_lParam = lParam;
		CCustomSession cs(COM_MESSAGE, &com, sizeof(com));
		int size;
		CUSTOMHEAD *pHeader = cs.GetHeader(size);
		r = SendBuf(pSocket, pHeader, size);
	}
	return r;
}

BOOL CXMMTCtrl::SendMmttyMessage(short nIndex, long wParam, long lParam) 
{
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		COMMSG com;
		com.m_wParam = wParam;
		com.m_lParam = lParam;
		CCustomSession cs(COM_MESSAGERESULT, &com, sizeof(com));
		int size;
		CUSTOMHEAD *pHeader = cs.GetHeader(size);
		r = SendBuf(pSocket, pHeader, size);
	}
	return r;
}

BOOL CXMMTCtrl::WriteMmttyTxw(short nIndex, LPCTSTR pStr) 
{
	return PostMmttyMessageAsString(nIndex, MMTMSG_WRITETXW, pStr);
}

BOOL CXMMTCtrl::SetNotify(short nIndex, short bNotify) 
{
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		BYTE b = BYTE(bNotify);
		m_bNotify[nIndex] = b;
		CCustomSession cs(COM_SETNOTIFY, &b, sizeof(b));
		int size;
		CUSTOMHEAD *pHeader = cs.GetHeader(size);
		r = SendBuf(pSocket, pHeader, size);
	}
	return r;
}

BOOL CXMMTCtrl::IsConnected(short nIndex) 
{
	return GetSocket(nIndex) != NULL;
}

void CXMMTCtrl::Disconnect(short nIndex) 
{
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		CloseSocket(pSocket);
	}
}

short CXMMTCtrl::GetWPortTcp() 
{
	return m_PortTCP;
}

void CXMMTCtrl::SetWPortTcp(short nNewValue) 
{
	m_PortTCP = nNewValue;
	if( m_pSocket ){
		m_pSocket->Close();
		delete m_pSocket;
		m_pSocket = NULL;
		Listen();
	}
	SetModifiedFlag();
}

BOOL CXMMTCtrl::GetBActive() 
{
	return m_pSocket != NULL;
}

void CXMMTCtrl::SetBActive(BOOL bNewValue) 
{
	if( GetBActive() != bNewValue ){
		if( bNewValue ){
			Listen();
			SetModifiedFlag();
		}
		else {
			CloseAll();
			SetModifiedFlag();
		}
	}
}

short CXMMTCtrl::GetWMaxCount() 
{
	return USERMAX;
}

short CXMMTCtrl::GetWCount() 
{
	return m_ConnectionCount;
}

BSTR CXMMTCtrl::GetAddress(short nIndex) 
{
	CString strResult;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		UINT PeerPort;
		pSocket->GetPeerName(strResult, PeerPort);
	}
	else {
		strResult = _T("Unknown");
	}
	return strResult.AllocSysString();
}

BSTR CXMMTCtrl::GetHostName() 
{
	CString strResult;
	char host[256];
	gethostname(host, sizeof(host));
	strResult = host;
	return strResult.AllocSysString();
}

BOOL CXMMTCtrl::PostMmttyMessageAsString(short nIndex, long wParam, LPCTSTR pStr) 
{
	int r = FALSE;
	CCSocket *pSocket = GetSocket(nIndex);
	if( pSocket ){
		int len = sizeof(COMMSG) + lstrlen(pStr) + 1;
		LPBYTE pb = new BYTE[len];
		COMMSG *pCom = (COMMSG *)pb;
		pCom->m_wParam = wParam;
		pCom->m_lParam = 0;
		// 文字列の実体をCOMMSGのすぐ後ろにコピーします。
#ifdef _UNICODE
		LPSTR p = LPSTR(pb + sizeof(COMMSG));
		while(*pStr){
			*p++ = BYTE(*pStr++);
		}
		*p = 0;
#else
		lstrcpy(LPTSTR(pb + sizeof(COMMSG)), pStr);
#endif

		CCustomSession cs(COM_MESSAGE, pb, len);
		delete pb;
		int size;
		CUSTOMHEAD *pHeader = cs.GetHeader(size);
		r = SendBuf(pSocket, pHeader, size);
	}
	return r;
}
