XMMT
====

XMMT.ocx
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

========================================================================
		ActiveX コントロール DLL : XMMT
========================================================================


ControlWizard はこのプロジェクトを 3 controls を含む
XMMT ActiveX コントロール DLL のために作成します。

このスケルトン プロジェクトは ActiveX コントロールの作成の基本を示すだけでなく
コントロールの特定の機能作成のひな型としてもお使いいただけます。

このファイルには XMMT ActiveX コントロール DLL を構成している各ファイルの
概要説明が含まれています。

XMMT.dsp
    このファイル (プロジェクト ファイル) はプロジェクト レベルの情報を含み、
    シングル プロジェクトまたはサブ プロジェクトのビルドに使用されます。他の
    ユーザーとプロジェクト ファイル (.dsp) を共有できますが、メイク ファイル
    はローカルにエクスポートしてください。

XMMT.h
	このファイルは ActiveX コントロール DLL の中心となるインクルードファイルで
	す。このファイルは resource.h のような他のプロジェクトの固有のインクル
	ードファイルもインクルードします。

XMMT.cpp
	このファイルは DLL 初期化、終了およびその他の定義を含むメイン DLL ソース
	ファイルです。
	
XMMT.rc
	このファイルはプロジェクトで使用している Microsoft Windows リソースをすべて
	記述します。このファイルは Visual C++ リソース エディタで直接編集することが
	できます。

XMMT.def
	このファイルは ActiveX コントロール DLL が Microsoft Windows 上で実行される
	時に必要な情報を含んでいます。

XMMT.clw
	このファイルは ClassWizard  が既存のクラスの編集やクラスを新規作成すると
	きに使う情報を持っています。またこのファイルは、ClassWizard によるメッセ
	ージ マップやダイアログ データ マップの編集や生成、プロトタイプ メンバ関
	数の生成に必要な情報も持っています。

XMMT.odl
	このファイルは controls のタイプ ライブラリ用のオブジェクト記述言語
	ソース コードを含んでいます。

/////////////////////////////////////////////////////////////////////////////
XMMT control:

XMMTCtl.h
	このファイルは CXMMTCtrl C++ クラスの宣言を含んでいます。

XMMTCtl.cpp
	このファイルは CXMMTCtrl C++ クラスのインプリメンテーションを含んでいます。

XMMTPpg.h
	このファイルは CXMMTPropPage C++ クラスの宣言を含んでいます。

XMMTPpg.cpp
	このファイルは CXMMTPropPage C++ クラスのインプリメンテーションを含んでいます。

XMMTCtl.bmp
	このファイルはツール パレットに表示されるときにコンテナが CXMMTCtrl コント
	ロールを表示するために使用するビットマップを含んでいます。このビットマップはメ
	イン リソース ファイル XMMT.rc によってインクルードされます。

/////////////////////////////////////////////////////////////////////////////
XMMXY control:

XMMXYCtl.h
	このファイルは CXMMXYCtrl C++ クラスの宣言を含んでいます。

XMMXYCtl.cpp
	このファイルは CXMMXYCtrl C++ クラスのインプリメンテーションを含んでいます。

XMMXYPpg.h
	このファイルは CXMMXYPropPage C++ クラスの宣言を含んでいます。

XMMXYPpg.cpp
	このファイルは CXMMXYPropPage C++ クラスのインプリメンテーションを含んでいます。

XMMXYCtl.bmp
	このファイルはツール パレットに表示されるときにコンテナが CXMMXYCtrl コント
	ロールを表示するために使用するビットマップを含んでいます。このビットマップはメ
	イン リソース ファイル XMMT.rc によってインクルードされます。

/////////////////////////////////////////////////////////////////////////////
XMMBtn control:

XMMBtnCtl.h
	このファイルは CXMMBtnCtrl C++ クラスの宣言を含んでいます。

XMMBtnCtl.cpp
	このファイルは CXMMBtnCtrl C++ クラスのインプリメンテーションを含んでいます。

XMMBtnPpg.h
	このファイルは CXMMBtnPropPage C++ クラスの宣言を含んでいます。

XMMBtnPpg.cpp
	このファイルは CXMMBtnPropPage C++ クラスのインプリメンテーションを含んでいます。

XMMBtnCtl.bmp
	このファイルはツール パレットに表示されるときにコンテナが CXMMBtnCtrl コント
	ロールを表示するために使用するビットマップを含んでいます。このビットマップはメ
	イン リソース ファイル XMMT.rc によってインクルードされます。

/////////////////////////////////////////////////////////////////////////////
その他の標準ファイル:

stdafx.h, stdafx.cpp
	これらのファイルはプリコンパイル済ヘッダー ファイル stdafx.pch  (PCH) 
	やプリコンパイル済型ファイル (PCT) を構築するために使われるファイルです。

resource.h
	このファイルは新規のリソース ID を定義する標準のヘッダー ファイルです。
	Visual C++ のリソース エディタはこのファイルを読み込み更新します。

/////////////////////////////////////////////////////////////////////////////
その他の注意:

"TODO:" で始まるコメントは、ソースコードの追加やカスタマイズの必要な場所を示
します。

/////////////////////////////////////////////////////////////////////////////
