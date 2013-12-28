// XMMWaterPpg.cpp : CXMMWaterPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMWaterPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMWaterPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMWaterPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMWaterPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CXMMWaterPropPage, "XMMLVL.XMMWaterPropPage.1",
	0x80062348, 0x4e3d, 0x4f3a, 0x88, 0xfb, 0x36, 0x1d, 0xca, 0xe9, 0xd2, 0x13)


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterPropPage::CXMMWaterPropPageFactory::UpdateRegistry -
// CXMMWaterPropPage のシステム レジストリのエントリを追加または削除します

BOOL CXMMWaterPropPage::CXMMWaterPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMWATER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterPropPage::CXMMWaterPropPage - コンストラクタ

CXMMWaterPropPage::CXMMWaterPropPage() :
	COlePropertyPage(IDD, IDS_XMMWATER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMWaterPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CXMMWaterPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMWaterPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterPropPage メッセージ ハンドラ
