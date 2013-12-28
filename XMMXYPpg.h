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

#if !defined(AFX_XMMXYPPG_H__C6EE697C_AD77_41A6_B5C3_7DDBA8D44A38__INCLUDED_)
#define AFX_XMMXYPPG_H__C6EE697C_AD77_41A6_B5C3_7DDBA8D44A38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMXYPpg.h : CXMMXYPropPage プロパティ ページ クラスの宣言を行います

////////////////////////////////////////////////////////////////////////////
// CXMMXYPropPage : このクラスの動作の定義に関しては XMMXYPpg.cpp.cpp ファイルを参照してください

class CXMMXYPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMXYPropPage)
	DECLARE_OLECREATE_EX(CXMMXYPropPage)

// コンストラクタ
public:
	CXMMXYPropPage();

// ダイアログ データ
	//{{AFX_DATA(CXMMXYPropPage)
	enum { IDD = IDD_PROPPAGE_XMMXY };
		// メモ - ClassWizard はこの位置にメンバを追加します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA

// インプリメンテーション
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	//{{AFX_MSG(CXMMXYPropPage)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMXYPPG_H__C6EE697C_AD77_41A6_B5C3_7DDBA8D44A38__INCLUDED)
