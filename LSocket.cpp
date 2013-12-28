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

// LSocket.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "XMMT.h"
#include "XMMTCtl.h"
#include "XMMTPpg.h"
#include "LSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLSocket
IMPLEMENT_DYNAMIC(CLSocket, CSocket)

CLSocket::CLSocket(CXMMTCtrl *pCtrl)
{
	m_pCtrl = pCtrl;
}

CLSocket::~CLSocket()
{
}


// ClassWizard が必要とする以下の行を編集しないでください。
#if 0
BEGIN_MESSAGE_MAP(CLSocket, CSocket)
	//{{AFX_MSG_MAP(CLSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CLSocket メンバ関数

void CLSocket::OnAccept(int nErrorCode) 
{
	m_pCtrl->OnAccept(nErrorCode);
	CSocket::OnAccept(nErrorCode);
}
