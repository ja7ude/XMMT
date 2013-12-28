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

#if !defined(AFX_XMMTCTL_H__7B97DA68_FA24_4879_8855_C25FC1ADD416__INCLUDED_)
#define AFX_XMMTCTL_H__7B97DA68_FA24_4879_8855_C25FC1ADD416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMTCtl.h : CXMMTCtrl ActiveX コントロール クラスの宣言

#include "CSocket.h"
#include "LSocket.h"
/////////////////////////////////////////////////////////////////////////////
// CXMMTCtrl : このクラスの動作の定義に関しては XMMTCtl.cpp を参照してください

#define	STIMEOUT	3000
#define	USERMAX		8

class CXMMTCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMTCtrl)

private:
	SHORT			m_PortTCP;
	CLSocket		*m_pSocket;
	int				m_ConnectionCount;
	CCSocket		*m_pConnection[USERMAX];
	CCustomSession	m_CustomSession[USERMAX];
	BOOL			m_bBusy[USERMAX];
	BYTE			m_bNotify[USERMAX];
	BOOL			m_bActive;
private:
	void CloseSocket(CCSocket *pSocket);
	BOOL SendBuf(CCSocket *pSocket, const void *p, int n);
	CCSocket *GetSocket(int nIndex);
	void DoFftConversion(int nIndex, COMFFT *pCom);
	void CloseAll(void);

public:
	void OnAccept(int nErrorCode);
	void OnDisconnected(CCSocket *pSocket);
	void OnReceive(CCSocket *pSocket, int nErrorCode);

// コンストラクタ
public:
	CXMMTCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CXMMTCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	~CXMMTCtrl();

	DECLARE_OLECREATE_EX(CXMMTCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CXMMTCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMTCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CXMMTCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CXMMTCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CXMMTCtrl)
	BOOL m_bFftConversion;
	afx_msg short GetWPortTcp();
	afx_msg void SetWPortTcp(short nNewValue);
	afx_msg BOOL GetBActive();
	afx_msg void SetBActive(BOOL bNewValue);
	afx_msg short GetWMaxCount();
	afx_msg short GetWCount();
	afx_msg BSTR GetHostName();
	afx_msg BOOL Listen();
	afx_msg BOOL SendChar(short nIndex, short bChar);
	afx_msg BOOL SendCode(short nIndex, short bCode);
	afx_msg void SetBusy(short nIndex, short bBusy);
	afx_msg BOOL SendMmttyMessage(short nIndex, long wParam, long lParam);
	afx_msg BOOL PostMmttyMessage(short nIndex, long wParam, long lParam);
	afx_msg BOOL WriteMmttyTxw(short nIndex, LPCTSTR pStr);
	afx_msg BOOL SetNotify(short nIndex, short bNotify);
	afx_msg BOOL IsConnected(short nIndex);
	afx_msg void Disconnect(short nIndex);
	afx_msg BOOL IsBusy(short nIndex);
	afx_msg BOOL SendString(short nIndex, LPCTSTR pStr, short nLen);
	afx_msg BSTR GetAddress(short nIndex);
	afx_msg BOOL PostMmttyMessageAsString(short nIndex, long wParam, LPCTSTR pStr);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CXMMTCtrl)
	void FireOnPttEvent(short nIndex, short btx)
		{FireEvent(eventidOnPttEvent,EVENT_PARAM(VTS_I2  VTS_I2), nIndex, btx);}
	void FireOnBusyEvent(short nIndex, short bBusy)
		{FireEvent(eventidOnBusyEvent,EVENT_PARAM(VTS_I2  VTS_I2), nIndex, bBusy);}
	void FireOnDisconnected(short nIndex)
		{FireEvent(eventidOnDisconnected,EVENT_PARAM(VTS_I2), nIndex);}
	void FireOnCharRcvd(short nIndex, short bChar)
		{FireEvent(eventidOnCharRcvd,EVENT_PARAM(VTS_I2  VTS_I2), nIndex, bChar);}
	void FireOnConnected(short nIndex)
		{FireEvent(eventidOnConnected,EVENT_PARAM(VTS_I2), nIndex);}
	void FireOnMessageResult(short nIndex, long wParam, long lParam, long lResult)
		{FireEvent(eventidOnMessageResult,EVENT_PARAM(VTS_I2  VTS_I4  VTS_I4  VTS_I4), nIndex, wParam, lParam, lResult);}
	void FireOnNotifyNMMT(short nIndex, long FAR* pNMMT)
		{FireEvent(eventidOnNotifyNMMT,EVENT_PARAM(VTS_I2  VTS_PI4), nIndex, pNMMT);}
	void FireOnNotifyXY(short nIndex, long FAR* pXY)
		{FireEvent(eventidOnNotifyXY,EVENT_PARAM(VTS_I2  VTS_PI4), nIndex, pXY);}
	void FireOnNotifyFFT(short nIndex, short FAR* pFFT, short size, short sampfreq)
		{FireEvent(eventidOnNotifyFFT,EVENT_PARAM(VTS_I2  VTS_PI2  VTS_I2  VTS_I2), nIndex, pFFT, size, sampfreq);}
	void FireOnGetProfileName(short nIndex, short nProfile, LPCTSTR pStr)
		{FireEvent(eventidOnGetProfileName,EVENT_PARAM(VTS_I2  VTS_I2  VTS_BSTR), nIndex, nProfile, pStr);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMTCtrl)
	dispidWPortTcp = 2L,
	dispidBActive = 3L,
	dispidWMaxCount = 4L,
	dispidWCount = 5L,
	dispidHostName = 6L,
	dispidBFftConversion = 1L,
	dispidListen = 7L,
	dispidSendChar = 8L,
	dispidSendCode = 9L,
	dispidSetBusy = 10L,
	dispidSendMmttyMessage = 11L,
	dispidPostMmttyMessage = 12L,
	dispidWriteMmttyTxw = 13L,
	dispidSetNotify = 14L,
	dispidIsConnected = 15L,
	dispidDisconnect = 16L,
	dispidIsBusy = 17L,
	dispidSendString = 18L,
	dispidGetAddress = 19L,
	dispidPostMmttyMessageAsString = 20L,
	eventidOnPttEvent = 1L,
	eventidOnBusyEvent = 2L,
	eventidOnDisconnected = 3L,
	eventidOnCharRcvd = 4L,
	eventidOnConnected = 5L,
	eventidOnMessageResult = 6L,
	eventidOnNotifyNMMT = 7L,
	eventidOnNotifyXY = 8L,
	eventidOnNotifyFFT = 9L,
	eventidOnGetProfileName = 10L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMTCTL_H__7B97DA68_FA24_4879_8855_C25FC1ADD416__INCLUDED)
