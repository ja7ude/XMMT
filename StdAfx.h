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

#if !defined(AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_)
#define AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//            �܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//            �v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B

#define VC_EXTRALEAN	// Windows �w�b�_�[����g�p����Ă��Ȃ����������O 

#include <afxctl.h>	// MFC �� ActiveX  �R���g���[��
#include <afxext.h>	// MFC �̊g������
#include <afxdtctl.h>	// MFC �� Internet Explorer 4 �R���� �R���g���[�� �T�|�[�g
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>	// MFC �� Windows �R���� �R���g���[�� �T�|�[�g
#endif // _AFX_NO_AFXCMN_SUPPORT

// MFC �̃f�[�^�x�[�X �N���X���g�p���Ȃ��ꍇ�́A�ȉ��� 2 �s�̃C���N���[�h
// �t�@�C���̋L�q���폜���Ă��������B
#include <afxdb.h>	// MFC �̃f�[�^�x�[�X �N���X
#include <afxdao.h>	// MFC �� DAO �f�[�^�x�[�X �N���X

#include <afxsock.h>		// MFC �̃\�P�b�g�g���@�\

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__5C28F09F_DE8E_45CD_B323_2439709669FF__INCLUDED_)
