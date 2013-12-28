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

// CSocket.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "XMMT.h"
#include "XMMTCtl.h"
#include "XMMTPpg.h"
#include "CSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomSession
CCustomSession::CCustomSession(BYTE command, const void *p, int n)
{
	InitialClear();

	m_len = sizeof(CUSTOMHEAD) + n; 
	BYTE *pb = new BYTE[m_len];
	m_pHead = (CUSTOMHEAD *)pb;
	m_pHead->m_code = CODE_CUSTOMSESSION;
	m_pHead->m_command = command;
	m_pHead->m_len = n;
	if( n ) memcpy(pb + sizeof(CUSTOMHEAD), p, n);
}
void CCustomSession::InitialClear(void)
{
	m_mode = m_count = 0;
	memset(&m_com, 0, sizeof(m_com));
	m_pHead = NULL;
	m_len = 0;
}
CUSTOMHEAD* CCustomSession::GetHeader(int &size)
{
	size = m_len;
	return m_pHead;
}
void CCustomSession::Delete(void)
{
	if( m_com.m_pData ){
		delete m_com.m_pData;
		m_com.m_pData = NULL;
	}
	if( m_pHead != NULL ){
		delete m_pHead;
		m_pHead;
	}
	m_mode = 0;
}
BOOL CCustomSession::PutData(BYTE c)
{
	int r = FALSE;
	switch(m_mode){
	case 1:
		m_com.m_command = c;
		m_mode++;
		break;
	case 2:
		m_com.m_len = c;
		m_mode++;
		break;
	case 3:
		m_com.m_len += (c << 8);
		if( m_com.m_pData ){
			delete m_com.m_pData;
			m_com.m_pData = NULL;
		}
		if( m_com.m_len ){
			m_com.m_pData = new BYTE[m_com.m_len];
			m_count = 0;
			m_mode++;
		}
		else {
			m_mode = 0;
			r = TRUE;
		}
		break;
	case 4:
		m_com.m_pData[m_count] = c;
		m_count++;
		if( m_count >= m_com.m_len ){
			m_mode = 0;
			r = TRUE;
		}
		break;
	default:
		m_mode = 0;
		break;
	}
	return r;
}

/////////////////////////////////////////////////////////////////////////////
// CCSocket
IMPLEMENT_DYNAMIC(CCSocket, CSocket)

CCSocket::CCSocket(CXMMTCtrl *pCtrl)
{
	m_pCtrl = pCtrl;
	m_EnabledEvent = TRUE;
}

CCSocket::~CCSocket()
{
}


// ClassWizard が必要とする以下の行を編集しないでください。
#if 0
BEGIN_MESSAGE_MAP(CCSocket, CSocket)
	//{{AFX_MSG_MAP(CCSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CCSocket メンバ関数

void CCSocket::OnReceive(int nErrorCode) 
{
	if( m_pCtrl ) m_pCtrl->OnReceive(this, nErrorCode);	
	CSocket::OnReceive(nErrorCode);
}

void CCSocket::OnClose(int nErrorCode) 
{
	CSocket::OnClose(nErrorCode);
	if( m_EnabledEvent && m_pCtrl ){
		m_pCtrl->OnDisconnected(this);
	}
}
