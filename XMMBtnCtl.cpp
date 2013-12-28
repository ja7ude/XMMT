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

// XMMBtnCtl.cpp : CXMMBtnCtrl ActiveX �R���g���[�� �N���X�̃C���v�������e�[�V����

#include "stdafx.h"
#include "XMMT.h"
#include "XMMBtnCtl.h"
#include "XMMBtnPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMBtnCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMBtnCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �f�B�X�p�b�` �}�b�v

BEGIN_DISPATCH_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMBtnCtrl)
	DISP_PROPERTY_NOTIFY(CXMMBtnCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Caption", GetCaption, SetCaption, VT_BSTR)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "TextColor", GetTextColor, SetTextColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Enabled", GetEnabled, SetEnabled, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "State", GetState, SetState, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "Toggled", GetToggled, SetToggled, VT_BOOL)
	DISP_PROPERTY_EX(CXMMBtnCtrl, "FaceColor", GetFaceColor, SetFaceColor, VT_COLOR)
	DISP_STOCKPROP_FONT()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// �C�x���g �}�b�v

BEGIN_EVENT_MAP(CXMMBtnCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMBtnCtrl)
	EVENT_CUSTOM("OnLButtonClick", FireOnLButtonClick, VTS_NONE)
	EVENT_CUSTOM("OnRButtonClick", FireOnRButtonClick, VTS_NONE)
	EVENT_CUSTOM_ID("DblClick", DISPID_DBLCLICK, FireDblClick, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// �v���p�e�B �y�[�W

// TODO: �v���p�e�B �y�[�W��ǉ����āABEGIN �s�̍Ō�ɂ���J�E���g�𑝂₵�Ă��������B
BEGIN_PROPPAGEIDS(CXMMBtnCtrl, 1)
	PROPPAGEID(CXMMBtnPropPage::guid)
END_PROPPAGEIDS(CXMMBtnCtrl)


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g���� guid �����������܂�

IMPLEMENT_OLECREATE_EX(CXMMBtnCtrl, "XMMT.XMMBtnCtrl.1",
	0x34104a6c, 0xb355, 0x43e0, 0xbb, 0xd1, 0x9a, 0x77, 0x18, 0xab, 0xd, 0x4c)


/////////////////////////////////////////////////////////////////////////////
// �^�C�v ���C�u���� ID �ƃo�[�W����

IMPLEMENT_OLETYPELIB(CXMMBtnCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// �C���^�[�t�F�C�X ID

const IID BASED_CODE IID_DXMMBtn =
		{ 0xf5bf613f, 0xd4bc, 0x4582, { 0x80, 0xe5, 0x2f, 0x5e, 0x5b, 0x31, 0xf8, 0x2e } };
const IID BASED_CODE IID_DXMMBtnEvents =
		{ 0xc3decf69, 0xc3bc, 0x427c, { 0x9c, 0xf3, 0x4b, 0xe6, 0x1a, 0xae, 0x9e, 0xff } };


/////////////////////////////////////////////////////////////////////////////
// �R���g���[���̌^���̐���

static const DWORD BASED_CODE _dwXMMBtnOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMBtnCtrl, IDS_XMMBTN, _dwXMMBtnOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::CXMMBtnCtrlFactory::UpdateRegistry -
// CXMMBtnCtrl �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂� 

BOOL CXMMBtnCtrl::CXMMBtnCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: �R���g���[�����A�p�[�g�����g ���f���̃X���b�h�����̋K���ɏ]���Ă��邱�Ƃ�
	// �m�F���Ă��������B�ڍׂɂ��Ă� MFC �̃e�N�j�J�� �m�[�g 64 ���Q�Ƃ��Ă��������B
	// �A�p�[�g�����g ���f���̃X���b�h�����̋K���ɏ]��Ȃ��R���g���[���̏ꍇ�́A6 �Ԗ�
	// �̃p�����[�^���ȉ��̂悤�ɕύX���Ă��������B
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_XMMBTN,
			IDB_XMMBTN,
			afxRegApartmentThreading,
			_dwXMMBtnOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::CXMMBtnCtrl - �R���X�g���N�^

CXMMBtnCtrl::CXMMBtnCtrl()
{
	InitializeIIDs(&IID_DXMMBtn, &IID_DXMMBtnEvents);

	m_Enabled = TRUE;
	m_Toggled = TRUE;
	m_clEdge[0] = GetSysColor(COLOR_BTNHILIGHT);
	m_clEdge[1] = GetSysColor(COLOR_BTNSHADOW);
	m_clEdge[2] = GetSysColor(COLOR_3DDKSHADOW);
	m_clFace = 0x80000000 + COLOR_BTNFACE;
	m_clPush = RGB(255,255,255);
	m_fState = FALSE;
	m_clText = RGB(0,0,0);
	m_clGrayText = GetSysColor(COLOR_GRAYTEXT);
	memset(&m_rcClient, 0, sizeof(m_rcClient));
	m_visible = TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::~CXMMBtnCtrl - �f�X�g���N�^

CXMMBtnCtrl::~CXMMBtnCtrl()
{
	// TODO: ���̈ʒu�ɃR���g���[���̃C���X�^���X �f�[�^�̌㏈���p�̃R�[�h��ǉ����Ă�������
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnDraw - �`��֐�

void CXMMBtnCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
//	DoSuperclassPaint(pdc, rcBounds);
	m_rcClient = rcBounds;
	OnDrawInternal(pdc);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::DoPropExchange - �i�����̃T�|�[�g

void CXMMBtnCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Enabled"), m_Enabled, TRUE);
	PX_Bool(pPX, _T("State"), m_fState, FALSE);
	PX_Bool(pPX, _T("Toggled"), m_Toggled, TRUE);
	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_String(pPX, _T("Caption"), m_Text, _T(""));
	PX_Color(pPX, _T("TextColor"), m_clText, RGB(0,0,0));
	PX_Color(pPX, _T("FaceColor"), m_clFace);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnResetState - �R���g���[���̃v���p�e�B�l�����Z�b�g

void CXMMBtnCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange ���Ăяo���ăf�t�H���g�l�Ƀ��Z�b�g

	// ���̈ʒu�ɃR���g���[���̏�Ԃ����Z�b�g���鏈����ǉ����Ă�������
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::PreCreateWindow - CreateWindowEx �̃p�����[�^���C��

BOOL CXMMBtnCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::IsSubclassedControl - �T�u�N���X�����ꂽ�R���g���[��

BOOL CXMMBtnCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl::OnOcmCommand - �R�}���h ���b�Z�[�W�̃n���h��

LRESULT CXMMBtnCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: ���̈ʒu�ɃX�C�b�` �X�e�[�g�����g�� wNotifyCode ����������R�[�h��ǉ����Ă�������

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void CXMMBtnCtrl::InitialUpdate(void)
{
	GetClientRect(&m_rcClient);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::Initialize(void)
{
	if( !m_rcClient.right ) InitialUpdate();
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::Draw(void)
{
	if( !IsWindowVisible() ) return;
	CClientDC dc(this);
	OnDrawInternal(&dc);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::SetWindowText(LPCTSTR lpszString)
{
	Initialize();
	if( lstrcmp(m_Text, lpszString) ){
		m_Text = lpszString;
		Draw();
	}
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::GetWindowText(CString& rString) const
{
	rString = m_Text;
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::EnableWindow(BOOL bEnable)
{
	Initialize();
	if( bEnable != m_Enabled ){
		m_Enabled = bEnable;
		Draw();
	}
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnDrawInternal(CDC *pDC)
{
	Initialize();

	RECT rc = m_rcClient;
	pDC->FillSolidRect(&rc, m_clEdge[2]);
	if( m_fState ){		// push button
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, m_clEdge[1]);
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, m_clEdge[0]);
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clPush);
	}
	else {				// pop button
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clEdge[1]);
		rc.bottom--; rc.right--;
		pDC->FillSolidRect(&rc, m_clEdge[0]);
		rc.top++; rc.left++;
		pDC->FillSolidRect(&rc, GetRefColor(m_clFace));
	}
	CFont *pOldFont = SelectStockFont(pDC);
	pDC->SetTextColor(GetRefColor(m_Enabled ? m_clText : m_clGrayText));
	pDC->DrawText(m_Text, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	pDC->SelectObject(pOldFont);
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( !m_Enabled ) return;
	if( m_Toggled ){
		SetState(!GetState());
	}
	else {
		SetState(TRUE);
		::Sleep(100);
		SetState(FALSE);
	}
	FireOnLButtonClick();
}
void CXMMBtnCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
}
void CXMMBtnCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if( !m_Enabled ) return;
	FireDblClick();
}
//---------------------------------------------------------------------------
void CXMMBtnCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if( m_Enabled ) FireOnRButtonClick();
	COleControl::OnRButtonDown(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
// CXMMBtnCtrl ���b�Z�[�W �n���h��



BSTR CXMMBtnCtrl::GetCaption() 
{
	CString strResult;
	strResult = m_Text;
	return strResult.AllocSysString();
}

void CXMMBtnCtrl::SetCaption(LPCTSTR lpszNewValue) 
{
	m_Text = lpszNewValue;
	Draw();
	SetModifiedFlag();
}

OLE_COLOR CXMMBtnCtrl::GetTextColor() 
{
	return m_clText;
}

void CXMMBtnCtrl::SetTextColor(OLE_COLOR nNewValue) 
{
	m_clText = nNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetEnabled() 
{
	return m_Enabled;
}

void CXMMBtnCtrl::SetEnabled(BOOL bNewValue) 
{
	m_Enabled = bNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetState() 
{
	return m_fState;
}

void CXMMBtnCtrl::SetState(BOOL bNewValue) 
{
	Initialize();
	if( m_fState == bNewValue ) return;
	m_fState = bNewValue;
	Draw();
	SetModifiedFlag();
}

BOOL CXMMBtnCtrl::GetToggled() 
{
	return m_Toggled;
}

void CXMMBtnCtrl::SetToggled(BOOL bNewValue) 
{
	m_Toggled = bNewValue;
	if( !m_Toggled && GetState() ) SetState(FALSE);
	SetModifiedFlag();
}


OLE_COLOR CXMMBtnCtrl::GetFaceColor() 
{
	return m_clFace;
}

void CXMMBtnCtrl::SetFaceColor(OLE_COLOR nNewValue) 
{
	m_clFace = nNewValue;
	Draw();
	SetModifiedFlag();
}

void CXMMBtnCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}
