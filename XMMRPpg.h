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

#if !defined(AFX_XMMRPPG_H__D34595DB_4B29_427F_9CB1_6F850A5D7861__INCLUDED_)
#define AFX_XMMRPPG_H__D34595DB_4B29_427F_9CB1_6F850A5D7861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMRPpg.h : CXMMRPropPage �v���p�e�B �y�[�W �N���X�̐錾���s���܂�

////////////////////////////////////////////////////////////////////////////
// CXMMRPropPage : ���̃N���X�̓���̒�`�Ɋւ��Ă� XMMRPpg.cpp.cpp �t�@�C�����Q�Ƃ��Ă�������

class CXMMRPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMRPropPage)
	DECLARE_OLECREATE_EX(CXMMRPropPage)

// �R���X�g���N�^
public:
	CXMMRPropPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CXMMRPropPage)
	enum { IDD = IDD_PROPPAGE_XMMR };
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o��ǉ����܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA

// �C���v�������e�[�V����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	//{{AFX_MSG(CXMMRPropPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XMMRPPG_H__D34595DB_4B29_427F_9CB1_6F850A5D7861__INCLUDED)
