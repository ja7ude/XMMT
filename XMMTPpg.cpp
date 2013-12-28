// XMMTPpg.cpp : CXMMTPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "XMMT.h"
#include "XMMTPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMTPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CXMMTPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMTPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CXMMTPropPage, "XMMT.XMMTPropPage.1",
	0xa269042d, 0xaf35, 0x40e9, 0xa9, 0x18, 0xc0, 0x2b, 0x56, 0xda, 0x2f, 0xed)


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::CXMMTPropPageFactory::UpdateRegistry -
// CXMMTPropPage のシステム レジストリのエントリを追加または削除します

BOOL CXMMTPropPage::CXMMTPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::CXMMTPropPage - コンストラクタ

CXMMTPropPage::CXMMTPropPage() :
	COlePropertyPage(IDD, IDS_XMMT_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMTPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CXMMTPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMTPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage メッセージ ハンドラ
