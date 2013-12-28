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

// XMMXYPpg.cpp : CXMMXYPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMXYPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMXYPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMXYPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMXYPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CXMMXYPropPage, "XMMT.XMMXYPropPage.1",
	0xabf4907f, 0xa789, 0x47ea, 0xb5, 0xf1, 0x71, 0x27, 0x48, 0x32, 0xbc, 0xa8)


/////////////////////////////////////////////////////////////////////////////
// CXMMXYPropPage::CXMMXYPropPageFactory::UpdateRegistry -
// CXMMXYPropPage のシステム レジストリのエントリを追加または削除します

BOOL CXMMXYPropPage::CXMMXYPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMXY_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYPropPage::CXMMXYPropPage - コンストラクタ

CXMMXYPropPage::CXMMXYPropPage() :
	COlePropertyPage(IDD, IDS_XMMXY_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMXYPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CXMMXYPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMXYPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMXYPropPage メッセージ ハンドラ
