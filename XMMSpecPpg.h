#if !defined(AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED_)
#define AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMSpecPpg.h : CXMMSpecPropPage プロパティ ページ クラスの宣言を行います

////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage : このクラスの動作の定義に関しては XMMSpecPpg.cpp.cpp ファイルを参照してください

class CXMMSpecPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMSpecPropPage)
	DECLARE_OLECREATE_EX(CXMMSpecPropPage)

// コンストラクタ
public:
	CXMMSpecPropPage();

// ダイアログ データ
	//{{AFX_DATA(CXMMSpecPropPage)
	enum { IDD = IDD_PROPPAGE_XMMSPEC };
		// メモ - ClassWizard はこの位置にメンバを追加します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA

// インプリメンテーション
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	//{{AFX_MSG(CXMMSpecPropPage)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED)
