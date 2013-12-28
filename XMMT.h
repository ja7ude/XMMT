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

#if !defined(AFX_XMMT_H__7BC5FA40_6A91_4769_AAFC_2CEF07B14A97__INCLUDED_)
#define AFX_XMMT_H__7BC5FA40_6A91_4769_AAFC_2CEF07B14A97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMT.h : XMMT.DLL のメイン ヘッダー ファイルです

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CXMMTApp : このクラスの動作の定義に関しては XMMT.cpp ファイルを参照してください

class CXMMTApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

/////////////////////////////////////////////////////////////////////////////
// CFontSelect
class CFontSelect
{
	CDC		*m_pDC;
	CFont	*m_pFont;
public:
	CFontSelect(CDC *pDC, CFont *pFont);
	inline ~CFontSelect(){Release();};
	void Release(void);
};
// CPenSelect
class CPenSelect
{
	CDC		*m_pDC;
	CPen	*m_pPen;
public:
	CPenSelect(CDC *pDC, CPen *pPen);
	inline ~CPenSelect(){Release();};
	void Release(void);
};
// CBrushSelect
class CBrushSelect
{
	CDC		*m_pDC;
	CBrush	*m_pBrush;
public:
	CBrushSelect(CDC *pDC, CBrush *pBrush);
	inline ~CBrushSelect(){Release();};
	void Release(void);
};

void DrawBorderStyle(CDC *pDC, const RECT &rc);

/////////////////////////////////////////////////////////////////////////////
enum {		// クライアントからの通知
	NOTIFY_PTTON=0x00f0,
	NOTIFY_PTTOFF,
	NOTIFY_BUSYON,
	NOTIFY_BUSYOFF,
};
enum {		// クライアントへのコマンド
	TNC_PTTON = 0x00f0,
	TNC_PTTOFF,
	TNC_PTTFLUSH,
	TNC_CLEARBUF,
	TNC_AFCON,
	TNC_AFCOFF,
	TNC_NETON,
	TNC_NETOFF,
	TNC_REVON,
	TNC_REVOFF,
	TNC_HAM,
    TNC_ECHOON,
    TNC_ECHOOFF,
	TNC_CANCELPTTFLUSH,
};
enum {		// MMTTYへのメッセージ
	MMTMSG_NULL,
	MMTMSG_CHAR,
	MMTMSG_PTT,
	MMTMSG_COMMON,
	MMTMSG_CLEARFIFO,
	MMTMSG_SETSWITCH,
	MMTMSG_SETVIEW,
	MMTMSG_CHARTXW,
	MMTMSG_WRITETXW,
	MMTMSG_SETFREQ,
	MMTMSG_SETBAUD,
	MMTMSG_SETSQ,
	MMTMSG_SETNOTCH,
	MMTMSG_SETDEFFREQ,
	MMTMSG_SETPTTTIMER,
    MMTMSG_SETTNCTYPE,
	MMTMSG_SETPRIORITY,
	MMTMSG_SETLENGTH,
	MMTMSG_SETRESO,
	MMTMSG_SETLPF,
    MMTMSG_GETPROFILENAME,
	MMTMSG_LOADPROFILE,
	MMTMSG_SAVEPROFILE,
};
#pragma pack(push, 1)
typedef struct {
	DWORD	m_markfreq;
	DWORD	m_spacefreq;
	DWORD	m_siglevel;
	DWORD	m_sqlevel;
	DWORD	m_txbuflen;
	DWORD	m_codeswitch;
	DWORD	m_codeview;
	DWORD	m_notch1;
	DWORD	m_notch2;
	DWORD	m_baud;
	DWORD	m_bitlength;
	DWORD	m_txwlen;
	DWORD	m_sampfreq;
	DWORD	m_demfreq;
	DWORD	m_radiofreq;
	DWORD	m_modetnc;
    DWORD	m_fig;
    DWORD	m_defmark;
    DWORD	m_defshift;
	DWORD	m_Reserved[45];
}NMMT;
#pragma pack(pop)
typedef NMMT* LPNMMT;

#pragma pack(push, 1)
typedef struct {
	DWORD	m_markfreq;
	DWORD	m_spacefreq;
	DWORD	m_siglevel;
	DWORD	m_sqlevel;
	DWORD	m_codeswitch;
	DWORD	m_codeview;
	DWORD	m_notch1;
	DWORD	m_notch2;
	DWORD	m_baud;
    DWORD	m_fig;
	DWORD	m_radiofreq;
	DWORD	m_Reserved[53];
}NMMR;
#pragma pack(pop)
typedef NMMR* LPNMMR;

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

COLORREF GetRefColor(COLORREF col);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMT_H__7BC5FA40_6A91_4769_AAFC_2CEF07B14A97__INCLUDED)
