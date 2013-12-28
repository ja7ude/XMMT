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

#if !defined(AFX_CSOCKET_H__CBD2F8CF_7475_4B87_B7DD_957963631EB9__INCLUDED_)
#define AFX_CSOCKET_H__CBD2F8CF_7475_4B87_B7DD_957963631EB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSocket.h : ヘッダー ファイル
//
#define	WM_SOCKETEVENT	WM_USER+402
enum {
	MMSO_STATUS,
	MMSO_CLOSE,
	MMSO_CONNECT,
	MMSO_MONICLOSE,
};

/////////////////////////////////////////////////////////////////////////////
// CCustomSession class
//---------------------------------------------------------------------------
#define	CODE_CUSTOMSESSION	0x00ff		// サーバークライアント間の通信で定義された特別なコード
enum {
	COM_SETNOTIFY,				// Server -> Client
	COM_MESSAGE,				// Server -> Client
	COM_MESSAGERESULT = 0x0040,	// Server <-> Client
	COM_NOTIFY = 0x0080,		// Client -> Server
	COM_NOTIFYFFT,				// Client -> Server
	COM_NOTIFYXY,				// Client -> Server
};
#define	ntNOTIFY		1
#define	ntNOTIFYFFT		2
#define	ntNOTIFYXY		4

#pragma pack(push, 1)
typedef struct {
	BYTE	m_code;
	BYTE	m_command;
	WORD	m_len;
	LPBYTE	m_pData;
}CUSTOMSESSION;
typedef struct {
	BYTE	m_code;
	BYTE	m_command;
	WORD	m_len;
}CUSTOMHEAD;
typedef struct {
	WORD	m_wsize;
	WORD	m_wsampfreq;
	SHORT	m_wdata[2048];
}COMFFT;
typedef struct {
	LONG	m_x[512];
	LONG	m_y[512];
}COMXY;
typedef struct {
	DWORD	m_wParam;
	DWORD	m_lParam;
	DWORD	m_lResult;
}COMMSG;
#pragma pack(pop)
//---------------------------------------------------------------------------
class CCustomSession
{
private:
	int		m_mode;
	int		m_count;
	CUSTOMSESSION	m_com;
private:
	int			m_len;
	CUSTOMHEAD	*m_pHead;
private:
	void InitialClear(void);
public:
	inline CCustomSession(void){InitialClear();};
	CCustomSession(BYTE command, const void *p, int n);
	inline ~CCustomSession(){Delete();};
	CUSTOMHEAD *GetHeader(int &size);
	void Delete(void);
	inline void OpenSession(void){m_mode = 1;};
	inline BOOL IsOpen(void){ return m_mode; };
	BOOL PutData(BYTE c);
	inline CUSTOMSESSION *GetData(void){return &m_com;};
};

class CXMMTCtrl;

/////////////////////////////////////////////////////////////////////////////
// CCSocket コマンド ターゲット

class CCSocket : public CSocket
{
	DECLARE_DYNAMIC(CCSocket);

private:
	CXMMTCtrl		*m_pCtrl;
	BOOL			m_EnabledEvent;
public:
	inline void EnableEvent(BOOL enabled){m_EnabledEvent = enabled;};
// アトリビュート
public:

// オペレーション
public:
	CCSocket(CXMMTCtrl *pCtrl);
	virtual ~CCSocket();

// オーバーライド
public:
	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CCSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CCSocket)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG

// インプリメンテーション
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CSOCKET_H__CBD2F8CF_7475_4B87_B7DD_957963631EB9__INCLUDED_)
