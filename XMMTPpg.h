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

#if !defined(AFX_XMMTPPG_H__88A2A8AA_4401_41D5_9217_C4BDBEAB2788__INCLUDED_)
#define AFX_XMMTPPG_H__88A2A8AA_4401_41D5_9217_C4BDBEAB2788__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMTPpg.h : CXMMTPropPage プロパティ ページ クラスの宣言を行います

////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage : このクラスの動作の定義に関しては XMMTPpg.cpp.cpp ファイルを参照してください

class CXMMTPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMTPropPage)
	DECLARE_OLECREATE_EX(CXMMTPropPage)

// コンストラクタ
public:
	CXMMTPropPage();

// ダイアログ データ
	//{{AFX_DATA(CXMMTPropPage)
	enum { IDD = IDD_PROPPAGE_XMMT };
		// メモ - ClassWizard はこの位置にメンバを追加します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA

// インプリメンテーション
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	//{{AFX_MSG(CXMMTPropPage)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMTPPG_H__88A2A8AA_4401_41D5_9217_C4BDBEAB2788__INCLUDED)
