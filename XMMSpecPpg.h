#if !defined(AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED_)
#define AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// XMMSpecPpg.h : CXMMSpecPropPage �v���p�e�B �y�[�W �N���X�̐錾���s���܂�

////////////////////////////////////////////////////////////////////////////
// CXMMSpecPropPage : ���̃N���X�̓���̒�`�Ɋւ��Ă� XMMSpecPpg.cpp.cpp �t�@�C�����Q�Ƃ��Ă�������

class CXMMSpecPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXMMSpecPropPage)
	DECLARE_OLECREATE_EX(CXMMSpecPropPage)

// �R���X�g���N�^
public:
	CXMMSpecPropPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CXMMSpecPropPage)
	enum { IDD = IDD_PROPPAGE_XMMSPEC };
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o��ǉ����܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA

// �C���v�������e�[�V����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	//{{AFX_MSG(CXMMSpecPropPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XMMSPECPPG_H__F866431C_4DD5_4FAF_BE30_DD1F84A71732__INCLUDED)
