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

// XMMLvlPpg.cpp : CXMMLvlPropPage �v���p�e�B �y�[�W �N���X�̃C���v�������e�[�V����

#include "stdafx.h"
#include "XMMT.h"
#include "XMMLvlPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMLvlPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CXMMLvlPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMLvlPropPage)
	// ���� - ClassWizard �͂��̈ʒu�Ƀ��b�Z�[�W �}�b�v�̃G���g����ǉ��܂��͍폜���܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g�� �� guid �̏�����

IMPLEMENT_OLECREATE_EX(CXMMLvlPropPage, "XMMLVL.XMMLvlPropPage.1",
	0xe194c02e, 0x2752, 0x4759, 0x9e, 0x59, 0x60, 0x96, 0x4, 0xa0, 0xf3, 0xb6)


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::CXMMLvlPropPageFactory::UpdateRegistry -
// CXMMLvlPropPage �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂�

BOOL CXMMLvlPropPage::CXMMLvlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMLVL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::CXMMLvlPropPage - �R���X�g���N�^

CXMMLvlPropPage::CXMMLvlPropPage() :
	COlePropertyPage(IDD, IDS_XMMLVL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMLvlPropPage)
	// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage::DoDataExchange - �y�[�W�ƃv���p�e�B�̊ԂŃf�[�^�̌������s���܂�

void CXMMLvlPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMLvlPropPage)
	// ����: ClassWizard �͂��̈ʒu�� DDP�ADDX�ADDV �̌Ăяo���R�[�h��ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMLvlPropPage ���b�Z�[�W �n���h��
