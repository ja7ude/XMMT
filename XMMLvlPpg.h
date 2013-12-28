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

// XMMLvlPpg.h : CXMMLvlPropPage �v���p�e�B �y�[�W �N���X�̐錾���s���܂�

////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage : ���̃N���X�̓���̒�`�Ɋւ��Ă� XMMLvlPpg.cpp.cpp �t�@�C�����Q�Ƃ��Ă�������

class CXMMLvlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMLvlPropPage)
	DECLARE_OLECREATE_EX(CXMMLvlPropPage)

// �R���X�g���N�^
public:
	CXMMLvlPropPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CXMMLvlPropPage)
	enum { IDD = IDD_PROPPAGE_XMMLVL };
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o��ǉ����܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA

// �C���v�������e�[�V����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	//{{AFX_MSG(CXMMLvlPropPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XMMLVLPPG_H__42C7FB03_CAE7_4E96_BC0E_CE532C322B52__INCLUDED)
