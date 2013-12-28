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

#if !defined(AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED_)
#define AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Filter.h"
// XMMXYCtl.h : CXMMXYCtrl ActiveX �R���g���[�� �N���X�̐錾

/////////////////////////////////////////////////////////////////////////////
// CXMMXYCtrl : ���̃N���X�̓���̒�`�Ɋւ��Ă� XMMXYCtl.cpp ���Q�Ƃ��Ă�������

class CXMMXYCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXMMXYCtrl)

private:
	COLORREF	m_clBack;
	COLORREF	m_clXY;
	CRect		m_rcClient;
	CSize		m_bmpSize;
	CBitmap		m_bmpXY;
	CINTPXY2	*m_pIX;
	CINTPXY2	*m_pIY;
	short		m_sampfreq;
	BOOL		m_bHighQuality;
private:
	void DeleteIXY(void);
	void OpenIXY(void);
	void InitialUpdate(void);
	void Initialize(void);
	void DrawBitmap(CDC *pDC, const CRect &rc);
	void UpdateSize(const CRect &rc);
	void DrawXY(LONG *pXY);

// �R���X�g���N�^
public:
	CXMMXYCtrl();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CXMMXYCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	~CXMMXYCtrl();

	DECLARE_OLECREATE_EX(CXMMXYCtrl)   // �N���X �t�@�N�g�� �� guid
	DECLARE_OLETYPELIB(CXMMXYCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXMMXYCtrl)    // �v���p�e�B �y�[�W ID
	DECLARE_OLECTLTYPE(CXMMXYCtrl)     // �^�C�v���Ƃ��̑��̃X�e�[�^�X

// ���b�Z�[�W �}�b�v
	//{{AFX_MSG(CXMMXYCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// �f�B�X�p�b�` �}�b�v
	//{{AFX_DISPATCH(CXMMXYCtrl)
	BOOL m_invert;
	afx_msg void OnInvertChanged();
	BOOL m_visible;
	afx_msg void OnVisibleChanged();
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetColor();
	afx_msg void SetColor(OLE_COLOR nNewValue);
	afx_msg BOOL GetHighQuality();
	afx_msg void SetHighQuality(BOOL bNewValue);
	afx_msg short GetDemSampleFreq();
	afx_msg void SetDemSampleFreq(short nNewValue);
	afx_msg void Draw(long FAR* pXY);
	afx_msg void Clear();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// �C�x���g �}�b�v
	//{{AFX_EVENT(CXMMXYCtrl)
	void FireOnLButtonClick(short X, short Y)
		{FireEvent(eventidOnLButtonClick,EVENT_PARAM(VTS_I2  VTS_I2), X, Y);}
	void FireOnRButtonClick(short X, short Y)
		{FireEvent(eventidOnRButtonClick,EVENT_PARAM(VTS_I2  VTS_I2), X, Y);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// �f�B�X�p�b�` �� �C�x���g ID
public:
	enum {
	//{{AFX_DISP_ID(CXMMXYCtrl)
	dispidBackColor = 3L,
	dispidColor = 4L,
	dispidHighQuality = 5L,
	dispidDemSampleFreq = 6L,
	dispidInvert = 1L,
	dispidVisible = 2L,
	dispidDraw = 7L,
	dispidClear = 8L,
	eventidOnLButtonClick = 1L,
	eventidOnRButtonClick = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_XMMXYCTL_H__BC982388_1FF3_43E6_BA82_4283EB41D797__INCLUDED)
