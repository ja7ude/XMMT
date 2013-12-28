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

// XMMSpecPpg.cpp : CXMMSpecPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMSpecPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMSpecPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMSpecPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMSpecPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CXMMSpecPropPage, "XMMLVL.XMMSpecPropPage.1",
	0xbbd2f13a, 0xbc06, 0x4512, 0xb2, 0xec, 0x51, 0x56, 0xb0, 0xc2, 0x81, 0x54)


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage::CXMMSpecPropPageFactory::UpdateRegistry -
// CXMMSpecPropPage のシステム レジストリのエントリを追加または削除します

BOOL CXMMSpecPropPage::CXMMSpecPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMSPEC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage::CXMMSpecPropPage - コンストラクタ

CXMMSpecPropPage::CXMMSpecPropPage() :
	COlePropertyPage(IDD, IDS_XMMSPEC_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMSpecPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CXMMSpecPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMSpecPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage メッセージ ハンドラ
