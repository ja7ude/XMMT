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

#if !defined(AFX_XMMBTNPPG_H__F5FF84E6_B6E5_4F64_B35E_402817FEC18B__INCLUDED_)
#define AFX_XMMBTNPPG_H__F5FF84E6_B6E5_4F64_B35E_402817FEC18B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMBtnPpg.h : CXMMBtnPropPage �v���p�e�B �y�[�W �N���X�̐錾���s���܂�

////////////////////////////////////////////////////////////////////////////
// CXMMBtnPropPage : ���̃N���X�̓���̒�`�Ɋւ��Ă� XMMBtnPpg.cpp.cpp �t�@�C�����Q�Ƃ��Ă�������

class CXMMBtnPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMBtnPropPage)
	DECLARE_OLECREATE_EX(CXMMBtnPropPage)

// �R���X�g���N�^
public:
	CXMMBtnPropPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CXMMBtnPropPage)
	enum { IDD = IDD_PROPPAGE_XMMBTN };
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o��ǉ����܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA

// �C���v�������e�[�V����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	//{{AFX_MSG(CXMMBtnPropPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XMMBTNPPG_H__F5FF84E6_B6E5_4F64_B35E_402817FEC18B__INCLUDED)
