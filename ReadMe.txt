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

========================================================================
		ActiveX �R���g���[�� DLL : XMMT
========================================================================


ControlWizard �͂��̃v���W�F�N�g�� 3 controls ���܂�
XMMT ActiveX �R���g���[�� DLL �̂��߂ɍ쐬���܂��B

���̃X�P���g�� �v���W�F�N�g�� ActiveX �R���g���[���̍쐬�̊�{�����������łȂ�
�R���g���[���̓���̋@�\�쐬�̂ЂȌ^�Ƃ��Ă����g�����������܂��B

���̃t�@�C���ɂ� XMMT ActiveX �R���g���[�� DLL ���\�����Ă���e�t�@�C����
�T�v�������܂܂�Ă��܂��B

XMMT.dsp
    ���̃t�@�C�� (�v���W�F�N�g �t�@�C��) �̓v���W�F�N�g ���x���̏����܂݁A
    �V���O�� �v���W�F�N�g�܂��̓T�u �v���W�F�N�g�̃r���h�Ɏg�p����܂��B����
    ���[�U�[�ƃv���W�F�N�g �t�@�C�� (.dsp) �����L�ł��܂����A���C�N �t�@�C��
    �̓��[�J���ɃG�N�X�|�[�g���Ă��������B

XMMT.h
	���̃t�@�C���� ActiveX �R���g���[�� DLL �̒��S�ƂȂ�C���N���[�h�t�@�C����
	���B���̃t�@�C���� resource.h �̂悤�ȑ��̃v���W�F�N�g�̌ŗL�̃C���N��
	�[�h�t�@�C�����C���N���[�h���܂��B

XMMT.cpp
	���̃t�@�C���� DLL �������A�I������т��̑��̒�`���܂ރ��C�� DLL �\�[�X
	�t�@�C���ł��B
	
XMMT.rc
	���̃t�@�C���̓v���W�F�N�g�Ŏg�p���Ă��� Microsoft Windows ���\�[�X�����ׂ�
	�L�q���܂��B���̃t�@�C���� Visual C++ ���\�[�X �G�f�B�^�Œ��ڕҏW���邱�Ƃ�
	�ł��܂��B

XMMT.def
	���̃t�@�C���� ActiveX �R���g���[�� DLL �� Microsoft Windows ��Ŏ��s�����
	���ɕK�v�ȏ����܂�ł��܂��B

XMMT.clw
	���̃t�@�C���� ClassWizard  �������̃N���X�̕ҏW��N���X��V�K�쐬�����
	���Ɏg�����������Ă��܂��B�܂����̃t�@�C���́AClassWizard �ɂ�郁�b�Z
	�[�W �}�b�v��_�C�A���O �f�[�^ �}�b�v�̕ҏW�␶���A�v���g�^�C�v �����o��
	���̐����ɕK�v�ȏ��������Ă��܂��B

XMMT.odl
	���̃t�@�C���� controls �̃^�C�v ���C�u�����p�̃I�u�W�F�N�g�L�q����
	�\�[�X �R�[�h���܂�ł��܂��B

/////////////////////////////////////////////////////////////////////////////
XMMT control:

XMMTCtl.h
	���̃t�@�C���� CXMMTCtrl C++ �N���X�̐錾���܂�ł��܂��B

XMMTCtl.cpp
	���̃t�@�C���� CXMMTCtrl C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMTPpg.h
	���̃t�@�C���� CXMMTPropPage C++ �N���X�̐錾���܂�ł��܂��B

XMMTPpg.cpp
	���̃t�@�C���� CXMMTPropPage C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMTCtl.bmp
	���̃t�@�C���̓c�[�� �p���b�g�ɕ\�������Ƃ��ɃR���e�i�� CXMMTCtrl �R���g
	���[����\�����邽�߂Ɏg�p����r�b�g�}�b�v���܂�ł��܂��B���̃r�b�g�}�b�v�̓�
	�C�� ���\�[�X �t�@�C�� XMMT.rc �ɂ���ăC���N���[�h����܂��B

/////////////////////////////////////////////////////////////////////////////
XMMXY control:

XMMXYCtl.h
	���̃t�@�C���� CXMMXYCtrl C++ �N���X�̐錾���܂�ł��܂��B

XMMXYCtl.cpp
	���̃t�@�C���� CXMMXYCtrl C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMXYPpg.h
	���̃t�@�C���� CXMMXYPropPage C++ �N���X�̐錾���܂�ł��܂��B

XMMXYPpg.cpp
	���̃t�@�C���� CXMMXYPropPage C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMXYCtl.bmp
	���̃t�@�C���̓c�[�� �p���b�g�ɕ\�������Ƃ��ɃR���e�i�� CXMMXYCtrl �R���g
	���[����\�����邽�߂Ɏg�p����r�b�g�}�b�v���܂�ł��܂��B���̃r�b�g�}�b�v�̓�
	�C�� ���\�[�X �t�@�C�� XMMT.rc �ɂ���ăC���N���[�h����܂��B

/////////////////////////////////////////////////////////////////////////////
XMMBtn control:

XMMBtnCtl.h
	���̃t�@�C���� CXMMBtnCtrl C++ �N���X�̐錾���܂�ł��܂��B

XMMBtnCtl.cpp
	���̃t�@�C���� CXMMBtnCtrl C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMBtnPpg.h
	���̃t�@�C���� CXMMBtnPropPage C++ �N���X�̐錾���܂�ł��܂��B

XMMBtnPpg.cpp
	���̃t�@�C���� CXMMBtnPropPage C++ �N���X�̃C���v�������e�[�V�������܂�ł��܂��B

XMMBtnCtl.bmp
	���̃t�@�C���̓c�[�� �p���b�g�ɕ\�������Ƃ��ɃR���e�i�� CXMMBtnCtrl �R���g
	���[����\�����邽�߂Ɏg�p����r�b�g�}�b�v���܂�ł��܂��B���̃r�b�g�}�b�v�̓�
	�C�� ���\�[�X �t�@�C�� XMMT.rc �ɂ���ăC���N���[�h����܂��B

/////////////////////////////////////////////////////////////////////////////
���̑��̕W���t�@�C��:

stdafx.h, stdafx.cpp
	�����̃t�@�C���̓v���R���p�C���σw�b�_�[ �t�@�C�� stdafx.pch  (PCH) 
	��v���R���p�C���ό^�t�@�C�� (PCT) ���\�z���邽�߂Ɏg����t�@�C���ł��B

resource.h
	���̃t�@�C���͐V�K�̃��\�[�X ID ���`����W���̃w�b�_�[ �t�@�C���ł��B
	Visual C++ �̃��\�[�X �G�f�B�^�͂��̃t�@�C����ǂݍ��ݍX�V���܂��B

/////////////////////////////////////////////////////////////////////////////
���̑��̒���:

"TODO:" �Ŏn�܂�R�����g�́A�\�[�X�R�[�h�̒ǉ���J�X�^�}�C�Y�̕K�v�ȏꏊ����
���܂��B

/////////////////////////////////////////////////////////////////////////////
