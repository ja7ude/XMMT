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

// XMMT.cpp : CXMMTApp クラスのインプリメンテーションおよび DLL の登録を行います。

#include "stdafx.h"
#include "XMMT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CXMMTApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x9fae7eb9, 0x98b, 0x4952, { 0xa2, 0x34, 0xcf, 0x46, 0x4, 0x19, 0xd7, 0x52 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 2;


////////////////////////////////////////////////////////////////////////////
// CXMMTApp::InitInstance - DLL の初期化

BOOL CXMMTApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if(bInit){
		if(!AfxSocketInit()){
			AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		}
	}

	return bInit;
}

////////////////////////////////////////////////////////////////////////////
// CXMMTApp::ExitInstance - DLL の終了

int CXMMTApp::ExitInstance()
{
	// TODO: この位置にモジュールの終了処理を追加してください。

	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - システム レジストリのエントリを追加

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - システム レジストリからのエントリを削除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// CFontSelect
CFontSelect::CFontSelect(CDC *pDC, CFont *pFont)
{
	m_pDC = pDC;
	m_pFont = pDC->SelectObject(pFont);
}
void CFontSelect::Release(void)
{
	if( m_pFont ){
		m_pDC->SelectObject(m_pFont);
		m_pFont = NULL;
	}
}
// CPenSelect
CPenSelect::CPenSelect(CDC *pDC, CPen *pPen)
{
	m_pDC = pDC;
	m_pPen = pDC->SelectObject(pPen);
}
void CPenSelect::Release(void)
{
	if( m_pPen ){
		m_pDC->SelectObject(m_pPen);
		m_pPen = NULL;
	}
}
// CBrushSelect
CBrushSelect::CBrushSelect(CDC *pDC, CBrush *pBrush)
{
	m_pDC = pDC;
	m_pBrush = pDC->SelectObject(pBrush);
}
void CBrushSelect::Release(void)
{
	if( m_pBrush ){
		m_pDC->SelectObject(m_pBrush);
		m_pBrush = NULL;
	}
}

void DrawBorderStyle(CDC *pDC, const RECT &rc)
{
	CBrush brush(GetSysColor(COLOR_BTNSHADOW));
	pDC->FrameRect(&rc, &brush);
	brush.DeleteObject();
	CPen pen(PS_SOLID, 0, GetSysColor(COLOR_BTNHILIGHT));
	CPen *pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(rc.top, rc.bottom-1);
	pDC->LineTo(rc.right-1, rc.bottom-1);
	pDC->LineTo(rc.right-1, rc.top);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

COLORREF GetRefColor(COLORREF col)
{
	if( col & 0x80000000 ){
		return ::GetSysColor(col & 0x0000ffff);
	}
	else {
		return col;
	}
}