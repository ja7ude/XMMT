// XMMTPpg.cpp : CXMMTPropPage �v���p�e�B �y�[�W �N���X�̃C���v�������e�[�V����

#include "stdafx.h"
#include "XMMT.h"
#include "XMMTPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMTPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CXMMTPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXMMTPropPage)
	// ���� - ClassWizard �͂��̈ʒu�Ƀ��b�Z�[�W �}�b�v�̃G���g����ǉ��܂��͍폜���܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g�� �� guid �̏�����

IMPLEMENT_OLECREATE_EX(CXMMTPropPage, "XMMT.XMMTPropPage.1",
	0xa269042d, 0xaf35, 0x40e9, 0xa9, 0x18, 0xc0, 0x2b, 0x56, 0xda, 0x2f, 0xed)


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::CXMMTPropPageFactory::UpdateRegistry -
// CXMMTPropPage �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂�

BOOL CXMMTPropPage::CXMMTPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XMMT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::CXMMTPropPage - �R���X�g���N�^

CXMMTPropPage::CXMMTPropPage() :
	COlePropertyPage(IDD, IDS_XMMT_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXMMTPropPage)
	// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage::DoDataExchange - �y�[�W�ƃv���p�e�B�̊ԂŃf�[�^�̌������s���܂�

void CXMMTPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXMMTPropPage)
	// ����: ClassWizard �͂��̈ʒu�� DDP�ADDX�ADDV �̌Ăяo���R�[�h��ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMTPropPage ���b�Z�[�W �n���h��
