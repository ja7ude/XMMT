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

#if !defined(AFX_XMMLVLPPG_H__42C7FB03_CAE7_4E96_BC0E_CE532C322B52__INCLUDED_)
#define AFX_XMMLVLPPG_H__42C7FB03_CAE7_4E96_BC0E_CE532C322B52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMLvlPpg.h : CXMMLvlPropPage プロパティ ページ クラスの宣言を行います

////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage : このクラスの動作の定義に関しては XMMLvlPpg.cpp.cpp ファイルを参照してください

class CXMMLvlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMLvlPropPage)
	DECLARE_OLECREATE_EX(CXMMLvlPropPage)

// コンストラクタ
public:
	CXMMLvlPropPage();

// ダイアログ データ
	//{{AFX_DATA(CXMMLvlPropPage)
	enum { IDD = IDD_PROPPAGE_XMMLVL };
		// メモ - ClassWizard はこの位置にメンバを追加します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA

// インプリメンテーション
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	//{{AFX_MSG(CXMMLvlPropPage)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_XMMLVLPPG_H__42C7FB03_CAE7_4E96_BC0E_CE532C322B52__INCLUDED)
