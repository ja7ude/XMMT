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

#if !defined(AFX_LSOCKET_H__0DA9064D_A4C6_4B91_B08B_342C52B451E6__INCLUDED_)
#define AFX_LSOCKET_H__0DA9064D_A4C6_4B91_B08B_342C52B451E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LSocket.h : ヘッダー ファイル
//

class CXMMTCtrl;

/////////////////////////////////////////////////////////////////////////////
// CLSocket コマンド ターゲット

class CLSocket : public CSocket
{
	DECLARE_DYNAMIC(CLSocket);

private:
	CXMMTCtrl	*m_pCtrl;

// アトリビュート
public:

// オペレーション
public:
	CLSocket(CXMMTCtrl *pCtrl);
	virtual ~CLSocket();

// オーバーライド
public:
	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CLSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CLSocket)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG

// インプリメンテーション
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_LSOCKET_H__0DA9064D_A4C6_4B91_B08B_342C52B451E6__INCLUDED_)
