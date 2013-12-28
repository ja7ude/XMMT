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

#if !defined(AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_)
#define AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : 標準のシステム インクルード ファイル、
//            または参照回数が多く、かつあまり変更されない
//            プロジェクト専用のインクルード ファイルを記述します。

#define VC_EXTRALEAN	// Windows ヘッダーから使用されていない部分を除外 

#include <afxctl.h>	// MFC の ActiveX  コントロール
#include <afxext.h>	// MFC の拡張部分
#include <afxdtctl.h>	// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>	// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT

// MFC のデータベース クラスを使用しない場合は、以下の 2 行のインクルード
// ファイルの記述を削除してください。
#include <afxdb.h>	// MFC のデータベース クラス
#include <afxdao.h>	// MFC の DAO データベース クラス

#include <afxsock.h>		// MFC のソケット拡張機能

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_)
