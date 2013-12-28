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

#if !defined(AFX_XMMRCTL_H__B370EA1E_2334_4106_9C27_CCBE23140D62__INCLUDED_)
#define AFX_XMMRCTL_H__B370EA1E_2334_4106_9C27_CCBE23140D62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMRCtl.h : CXMMRCtrl ActiveX コントロール クラスの宣言

//---------------------------------------------------------------------------
enum {
	RXM_HANDLE=0x0000,	// APP -> MMTTY
	RXM_REQHANDLE,
	RXM_EXIT,
	RXM_PTT,
	RXM_CHAR,

	RXM_WINPOS,
	RXM_WIDTH,
	RXM_REQPARA,
	RXM_SETBAUD,
	RXM_SETMARK,

	RXM_SETSPACE,
	RXM_SETSWITCH,
	RXM_SETHAM,
	RXM_SHOWSETUP,
	RXM_SETVIEW,

	RXM_SETSQLVL,
	RXM_SHOW,
	RXM_SETFIG,
	RXM_SETRESO,
	RXM_SETLPF,

	RXM_SETTXDELAY,
	RXM_UPDATECOM,
	RXM_SUSPEND,
	RXM_NOTCH,
	RXM_PROFILE,

    RXM_TIMER,
    RXM_ENBFOCUS,	// added on Ver1.63A
    RXM_SETDEFFREQ,	// added on Ver1.63B
    RXM_SETLENGTH,	// added on Ver1.63B
	RXM_ENBSHARED,	// added on Ver1.64

	RXM_PTTFSK,		// added on Ver1.67B
//--------------------------------------
	TXM_HANDLE=0x8000,	// MMTTY -> APP
	TXM_REQHANDLE,
	TXM_START,
	TXM_CHAR,
	TXM_PTTEVENT,

	TXM_HEIGHT,
	TXM_BAUD,
	TXM_MARK,
	TXM_SPACE,
	TXM_SWITCH,

	TXM_VIEW,
	TXM_LEVEL,
	TXM_FIGEVENT,
	TXM_RESO,
	TXM_LPF,

	TXM_THREAD,
	TXM_PROFILE,
    TXM_NOTCH,
    TXM_DEFSHIFT,
    TXM_RADIOFREQ,	// added on Ver1.63
};
#pragma pack(push, 1)
typedef struct {
	LONG	smpFreq;	// MMTTY->APP
	CHAR	title[128];	// APP->MMTTY
	CHAR	comName[16];// APP->MMTTY
	LONG	smpFFT;		// APP->MMTTY 0-11025, 1-8000

	LONG	flagFFT;
	LONG	arrayFFT[2048];
	LONG	flagXY;
	LONG	arrayX[512];
	LONG	arrayY[512];

	CHAR	verMMTTY[16];
	CHAR	comRadio[16];
	LONG	LostSound;
    LONG	OverFlow;
	LONG	ErrorClock;		// ppm
	LONG	smpDemFreq;		// デモジュレータのサンプリング周波数
    LONG	TxBuffCount;	// 送信バッファの未送信文字数
	CHAR	ProfileName[16][64];
    LONG	dummy[2048];
}COMARRAY;
#pragma pack(pop)

#define	swAFC	0x00000004	// b2 AFC
#define	swNET	0x00000008	// b3 NET
#define	swATC	0x00000010	// b4 ATC
#define	swBPF	0x00000020	// b5 BPF
#define	swLMS	0x00000040	// b6 LMS/Notch
#define	swSQ	0x00000080	// b7 SQ
#define	swREV	0x00000100	// b8 Rev
#define	swUOS	0x00000200	// b9 UOS
#define	swNOT	0x00002000	// b13	Notch/LMS
#define	swTWO	0x00004000	// b14

/////////////////////////////////////////////////////////////////////////////
// CXMMRCtrl : このクラスの動作の定義に関しては XMMRCtl.cpp を参照してください

class CXMMRCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMRCtrl)

private:
	CString			m_InvokeCommand;
	BOOL			m_bConnected;
	UINT			m_nTimerID;
	int				m_TimerMode;
	int				m_TimerCount;
	int				m_Timeup;
private:
	NMMR			m_NMMR;
	HWND			m_hMMWnd;
	HANDLE			m_hComFile;
	COMARRAY		*m_pCom;
	COMARRAY		m_InternalArray;
private:
	BOOL			m_ptt;
private:
	CString			m_Title;
	CString			m_ComName;
	CString			m_RadioName;
	CString			m_CommonMemory;
	LONG			m_smpFFT;
	SHORT			m_fft[2048];
	LONG			m_xy[1024];
private:
	void CreateCommonMemory(void);
	void CloseCommonMemory(void);
	void ChangeCommonMemory(LPCSTR pCommonMemory);
	void DecodeOptions(void);

	void InternalPostMmttyMessage(DWORD wParam, DWORD lParam);
	void RemoveUselessMessage(void);
	void DeleteTimer(void);
	void OpenMmtty(void);
	void CloseMmtty(BOOL bWait);

// コンストラクタ
public:
	CXMMRCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMRCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMRCtrl();

	DECLARE_OLECREATE_EX(CXMMRCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMRCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMRCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMRCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMRCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg LRESULT OnMmttyMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMRCtrl)
	BOOL m_bRemoveUselessMessage;
	BOOL m_bTranslateAllMessages;
	BOOL m_bInitialClose;
	long m_delayInvoke;
	BOOL m_bNotifyComChange;
	BOOL m_bConfirmClose;
	BOOL m_bNotifyXY;
	BOOL m_bNotifyFFT;
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg BOOL GetBActive();
	afx_msg void SetBActive(BOOL bNewValue);
	afx_msg BSTR GetInvokeCommand();
	afx_msg void SetInvokeCommand(LPCTSTR lpszNewValue);
	afx_msg long GetTxBufLen();
	afx_msg void SetTxBufLen(long nNewValue);
	afx_msg BSTR GetComName();
	afx_msg void SetComName(LPCTSTR lpszNewValue);
	afx_msg BSTR GetTitle();
	afx_msg void SetTitle(LPCTSTR lpszNewValue);
	afx_msg BSTR GetRadioName();
	afx_msg void SetRadioName(LPCTSTR lpszNewValue);
	afx_msg long GetSmpFreq();
	afx_msg long GetSmpFFT();
	afx_msg void SetSmpFFT(long nNewValue);
	afx_msg BSTR GetVerMMTTY();
	afx_msg long GetLostSound();
	afx_msg void SetLostSound(long nNewValue);
	afx_msg long GetOverFlow();
	afx_msg void SetOverFlow(long nNewValue);
	afx_msg long GetErrorClock();
	afx_msg long GetSmpDemFreq();
	afx_msg BOOL GetPTT();
	afx_msg void SetPTT(BOOL bNewValue);
	afx_msg OLE_HANDLE GetHWndMmtty();
	afx_msg BOOL GetBInvoking();
	afx_msg long GetSharedPointer();
	afx_msg BOOL GetVisibleMmtty();
	afx_msg void SetVisibleMmtty(BOOL bNewValue);
	afx_msg BOOL PostMmttyMessage(long wParam, long lParam);
	afx_msg BOOL SetMmttySwitch(long codeswitch);
	afx_msg BOOL SetMmttyView(long codeview);
	afx_msg BOOL SetMmttyPTT(short ptt);
	afx_msg BOOL SendChar(short bChar);
	afx_msg BOOL SendString(LPCTSTR pStr);
	afx_msg void ReadNMMR(long FAR* pNMMR);
	afx_msg BSTR GetProfiles(short nIndex);
	afx_msg void SetProfiles(short nIndex, LPCTSTR lpszNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMRCtrl)
	void FireOnConnected()
		{FireEvent(eventidOnConnected,EVENT_PARAM(VTS_NONE));}
	void FireOnCharRcvd(short bChar)
		{FireEvent(eventidOnCharRcvd,EVENT_PARAM(VTS_I2), bChar);}
	void FireOnPttEvent(short btx)
		{FireEvent(eventidOnPttEvent,EVENT_PARAM(VTS_I2), btx);}
	void FireOnDisconnected(short status)
		{FireEvent(eventidOnDisconnected,EVENT_PARAM(VTS_I2), status);}
	void FireOnNotifyNMMR(long FAR* pNMMR)
		{FireEvent(eventidOnNotifyNMMR,EVENT_PARAM(VTS_PI4), pNMMR);}
	void FireOnNotchChanged(short notch1, short notch2)
		{FireEvent(eventidOnNotchChanged,EVENT_PARAM(VTS_I2  VTS_I2), notch1, notch2);}
	void FireOnViewChanged(long codeview)
		{FireEvent(eventidOnViewChanged,EVENT_PARAM(VTS_I4), codeview);}
	void FireOnSwitchChanged(long codeswitch)
		{FireEvent(eventidOnSwitchChanged,EVENT_PARAM(VTS_I4), codeswitch);}
	void FireOnFreqChanged(short markfreq, short spacefreq)
		{FireEvent(eventidOnFreqChanged,EVENT_PARAM(VTS_I2  VTS_I2), markfreq, spacefreq);}
	void FireOnBaudChanged(short baud)
		{FireEvent(eventidOnBaudChanged,EVENT_PARAM(VTS_I2), baud);}
	void FireOnNotifyFFT(short FAR* pFFT, short size, short sampfreq)
		{FireEvent(eventidOnNotifyFFT,EVENT_PARAM(VTS_PI2  VTS_I2  VTS_I2), pFFT, size, sampfreq);}
	void FireOnNotifyXY(long FAR* pXY)
		{FireEvent(eventidOnNotifyXY,EVENT_PARAM(VTS_PI4), pXY);}
	void FireOnRadioFreqChanged(long freq)
		{FireEvent(eventidOnRadioFreqChanged,EVENT_PARAM(VTS_I4), freq);}
	void FireOnRadioNameChanged(LPCTSTR pStrRadio)
		{FireEvent(eventidOnRadioNameChanged,EVENT_PARAM(VTS_BSTR), pStrRadio);}
	void FireOnComNameChanged(LPCTSTR pStrCom)
		{FireEvent(eventidOnComNameChanged,EVENT_PARAM(VTS_BSTR), pStrCom);}
	void FireOnFigChanged(short bFig)
		{FireEvent(eventidOnFigChanged,EVENT_PARAM(VTS_I2), bFig);}
	void FireOnTranslateMessage(long wParam, long lParam)
		{FireEvent(eventidOnTranslateMessage,EVENT_PARAM(VTS_I4  VTS_I4), wParam, lParam);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMRCtrl)
	dispidBActive = 10L,
	dispidInvokeCommand = 11L,
	dispidTxBufLen = 12L,
	dispidComName = 13L,
	dispidTitle = 14L,
	dispidRadioName = 15L,
	dispidSmpFreq = 16L,
	dispidSmpFFT = 17L,
	dispidVerMMTTY = 18L,
	dispidLostSound = 19L,
	dispidOverFlow = 20L,
	dispidErrorClock = 21L,
	dispidSmpDemFreq = 22L,
	dispidPTT = 23L,
	dispidVisible = 9L,
	dispidHWndMmtty = 24L,
	dispidBInvoking = 25L,
	dispidSharedPointer = 26L,
	dispidVisibleMmtty = 27L,
	dispidBRemoveUselessMessage = 1L,
	dispidBTranslateAllMessages = 2L,
	dispidBInitialClose = 3L,
	dispidDelayInvoke = 4L,
	dispidBNotifyComChange = 5L,
	dispidBConfirmClose = 6L,
	dispidBNotifyXY = 7L,
	dispidBNotifyFFT = 8L,
	dispidPostMmttyMessage = 28L,
	dispidSetMmttySwitch = 29L,
	dispidSetMmttyView = 30L,
	dispidSetMmttyPTT = 31L,
	dispidSendChar = 32L,
	dispidSendString = 33L,
	dispidProfiles = 35L,
	dispidReadNMMR = 34L,
	eventidOnConnected = 1L,
	eventidOnCharRcvd = 2L,
	eventidOnPttEvent = 3L,
	eventidOnDisconnected = 4L,
	eventidOnNotifyNMMR = 5L,
	eventidOnNotchChanged = 6L,
	eventidOnViewChanged = 7L,
	eventidOnSwitchChanged = 8L,
	eventidOnFreqChanged = 9L,
	eventidOnBaudChanged = 10L,
	eventidOnNotifyFFT = 11L,
	eventidOnNotifyXY = 12L,
	eventidOnRadioFreqChanged = 13L,
	eventidOnRadioNameChanged = 14L,
	eventidOnComNameChanged = 15L,
	eventidOnFigChanged = 16L,
	eventidOnTranslateMessage = 17L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMRCTL_H__B370EA1E_2334_4106_9C27_CCBE23140D62__INCLUDED)
