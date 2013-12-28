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

// XMMLvlPpg.cpp : CXMMLvlPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMLvlPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMLvlPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMLvlPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMLvlPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CXMMLvlPropPage, "XMMLVL.XMMLvlPropPage.1",
	0xe194c02e, 0x2752, 0x4759, 0x9e, 0x59, 0x60, 0x96, 0x4, 0xa0, 0xf3, 0xb6)


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::CXMMLvlPropPageFactory::UpdateRegistry -
// CXMMLvlPropPage のシステム レジストリのエントリを追加または削除します

BOOL CXMMLvlPropPage::CXMMLvlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMLVL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::CXMMLvlPropPage - コンストラクタ

CXMMLvlPropPage::CXMMLvlPropPage() :
	COlePropertyPage(IDD, IDS_XMMLVL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMLvlPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CXMMLvlPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMLvlPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage メッセージ ハンドラ
