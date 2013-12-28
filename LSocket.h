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
// LSocket.h : �w�b�_�[ �t�@�C��
//

class CXMMTCtrl;

/////////////////////////////////////////////////////////////////////////////
// CLSocket �R�}���h �^�[�Q�b�g

class CLSocket : public CSocket
{
	DECLARE_DYNAMIC(CLSocket);

private:
	CXMMTCtrl	*m_pCtrl;

// �A�g���r���[�g
public:

// �I�y���[�V����
public:
	CLSocket(CXMMTCtrl *pCtrl);
	virtual ~CLSocket();

// �I�[�o�[���C�h
public:
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CLSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CLSocket)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG

// �C���v�������e�[�V����
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_LSOCKET_H__0DA9064D_A4C6_4B91_B08B_342C52B451E6__INCLUDED_)
