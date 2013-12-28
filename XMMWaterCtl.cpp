// XMMWaterCtl.cpp : CXMMWaterCtrl ActiveX �R���g���[�� �N���X�̃C���v�������e�[�V����

#include "stdafx.h"
#include "XMMT.h"
#include "XMMWaterCtl.h"
#include "XMMWaterPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXMMWaterCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CXMMWaterCtrl, COleControl)
	//{{AFX_MSG_MAP(CXMMWaterCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �f�B�X�p�b�` �}�b�v

BEGIN_DISPATCH_MAP(CXMMWaterCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXMMWaterCtrl)
	DISP_PROPERTY_NOTIFY(CXMMWaterCtrl, "Visible", m_visible, OnVisibleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CXMMWaterCtrl, "BackColor", GetBackColor, SetBackColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMWaterCtrl, "SpectramColor", GetSpectramColor, SetSpectramColor, VT_COLOR)
	DISP_PROPERTY_EX(CXMMWaterCtrl, "BaseFreq", GetBaseFreq, SetBaseFreq, VT_I2)
	DISP_PROPERTY_EX(CXMMWaterCtrl, "WidthFreq", GetWidthFreq, SetWidthFreq, VT_I2)
	DISP_FUNCTION(CXMMWaterCtrl, "Draw", Draw, VT_EMPTY, VTS_PI2 VTS_I2 VTS_I2)
	DISP_FUNCTION(CXMMWaterCtrl, "Clear", Clear, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_HWND()
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// �C�x���g �}�b�v

BEGIN_EVENT_MAP(CXMMWaterCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXMMWaterCtrl)
	EVENT_CUSTOM("OnLMouseDown", FireOnLMouseDown, VTS_I2)
	EVENT_CUSTOM("OnLMouseUp", FireOnLMouseUp, VTS_I2)
	EVENT_CUSTOM("OnLMouseMove", FireOnLMouseMove, VTS_I2)
	EVENT_CUSTOM("OnRMouseDown", FireOnRMouseDown, VTS_I2)
	EVENT_CUSTOM("OnRMouseMove", FireOnRMouseMove, VTS_I2)
	EVENT_CUSTOM("OnRMouseUp", FireOnRMouseUp, VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// �v���p�e�B �y�[�W

// TODO: �v���p�e�B �y�[�W��ǉ����āABEGIN �s�̍Ō�ɂ���J�E���g�𑝂₵�Ă��������B
BEGIN_PROPPAGEIDS(CXMMWaterCtrl, 1)
	PROPPAGEID(CXMMWaterPropPage::guid)
END_PROPPAGEIDS(CXMMWaterCtrl)


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g���� guid �����������܂�

IMPLEMENT_OLECREATE_EX(CXMMWaterCtrl, "XMMLVL.XMMWaterCtrl.1",
	0x68ed648d, 0xff56, 0x43fb, 0xbe, 0xe9, 0xee, 0x90, 0x83, 0x5, 0x8b, 0x8a)


/////////////////////////////////////////////////////////////////////////////
// �^�C�v ���C�u���� ID �ƃo�[�W����

IMPLEMENT_OLETYPELIB(CXMMWaterCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// �C���^�[�t�F�C�X ID

const IID BASED_CODE IID_DXMMWater =
		{ 0xeebeee03, 0x7b8c, 0x4817, { 0xa2, 0x8b, 0x60, 0x85, 0x44, 0x5f, 0x80, 0xb0 } };
const IID BASED_CODE IID_DXMMWaterEvents =
		{ 0x7fe82f53, 0x2389, 0x4078, { 0xa4, 0xdf, 0xda, 0x9e, 0x85, 0x33, 0x93, 0xbe } };


/////////////////////////////////////////////////////////////////////////////
// �R���g���[���̌^���̐���

static const DWORD BASED_CODE _dwXMMWaterOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXMMWaterCtrl, IDS_XMMWATER, _dwXMMWaterOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::CXMMWaterCtrlFactory::UpdateRegistry -
// CXMMWaterCtrl �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂� 

BOOL CXMMWaterCtrl::CXMMWaterCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_XMMWATER,
			IDB_XMMWATER,
			afxRegApartmentThreading,
			_dwXMMWaterOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::CXMMWaterCtrl - �R���X�g���N�^

CXMMWaterCtrl::CXMMWaterCtrl()
{
	InitializeIIDs(&IID_DXMMWater, &IID_DXMMWaterEvents);

	m_clBack = RGB(0,0,0);
	m_clSpectram = RGB(255,255,255);
	m_bmpSize.cx = 0; m_bmpSize.cy = 0;
	m_basefreq = 0;
	m_widthfreq = 3000;
	CreateTable();
	m_Max = 256;
	m_SumMax = 256*8;
	m_Min = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::~CXMMWaterCtrl - �f�X�g���N�^

CXMMWaterCtrl::~CXMMWaterCtrl()
{
	m_bmpWater.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::OnDraw - �`��֐�

void CXMMWaterCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	UpdateSize(rcBounds);
	DrawBitmap(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::DoPropExchange - �i�����̃T�|�[�g

void CXMMWaterCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Visible"), m_visible, TRUE);
	PX_Short(pPX, _T("BaseFreq"), m_basefreq, 0);
	PX_Short(pPX, _T("WidthFreq"), m_widthfreq, 3000);
	PX_Color(pPX, _T("SpectramColor"), m_clSpectram, RGB(255,255,255));
	PX_Color(pPX, _T("BackColor"), m_clBack, RGB(0,0,0));
	CreateTable();
}


/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl::OnResetState - �R���g���[���̃v���p�e�B�l�����Z�b�g

void CXMMWaterCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange ���Ăяo���ăf�t�H���g�l�Ƀ��Z�b�g

	// ���̈ʒu�ɃR���g���[���̏�Ԃ����Z�b�g���鏈����ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void CXMMWaterCtrl::InitialUpdate(void)
{
	CRect rc;
	GetClientRect(&rc);
	UpdateSize(&rc);
}
//---------------------------------------------------------------------------
void CXMMWaterCtrl::Initialize(void)
{
	if( !m_bmpSize.cx ) InitialUpdate();
}
//---------------------------------------------------------------------------
void CXMMWaterCtrl::DrawBitmap(CDC *pDC, const CRect &rc)
{
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpWater);
	pDC->BitBlt(rc.left, rc.top, m_bmpSize.cx, m_bmpSize.cy, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}
//---------------------------------------------------------------------------
void CXMMWaterCtrl::UpdateSize(const CRect &rc)
{
	m_rcClient = rc;
	if( (rc.Width() != m_bmpSize.cx) || (rc.Height() != m_bmpSize.cy) ){
		m_bmpSize.cx = rc.Width();
		m_bmpSize.cy = rc.Height();
		m_bmpWater.DeleteObject();
		CDC *pDC = GetDC();
		VERIFY(pDC->GetMapMode() == MM_TEXT);
		m_bmpWater.CreateCompatibleBitmap(pDC, m_bmpSize.cx, m_bmpSize.cy);
		ReleaseDC(pDC);
		DrawWater(NULL, 2048, 11025);
	}
}
//---------------------------------------------------------------------------
void CXMMWaterCtrl::DrawWater(short *pFFT, short size, short sampfreq)
{
	Initialize();

	RECT rc;
	rc.left = rc.top = 0;
	rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap *pOldBmp = dc.SelectObject(&m_bmpWater);

	if( pFFT ){
		// �X�N���[�����܂��B
		if( m_sBorderStyle ){
			dc.StretchBlt(0, 2, m_bmpSize.cx, m_bmpSize.cy - 2, &dc, 0, 1, m_bmpSize.cx, m_bmpSize.cy - 2, SRCCOPY);
		}
		else {
			dc.StretchBlt(0, 1, m_bmpSize.cx, m_bmpSize.cy - 1, &dc, 0, 0, m_bmpSize.cx, m_bmpSize.cy - 1, SRCCOPY);
		}
//		dc.BitBlt(0, 1, m_bmpSize.cx, 0, &dc, 0, 1, SRCCOPY);

		// �X�y�N�g������`�悵�܂��B
		int off = m_basefreq * size / sampfreq;
		double k = double(m_widthfreq) * double(size)/(double(m_bmpSize.cx) * double(sampfreq));
		int x, c;
		int y = m_sBorderStyle ? 1 : 0;
		int max = -32767;
		int avg = 0;
		int avgcnt = 0;
		double kl = 256.0/double(m_Max - m_Min);
		for( x = 0; x < m_bmpSize.cx; x++ ){
			c = pFFT[int(x * k) + off];
			if( max < c ) max = c;
			avg += c;
			avgcnt++;

			c -= m_Min;
			c = int(double(c) * kl);
			if( c < 0 ) c = 0;
			if( c > 255 ) c = 255;
			dc.SetPixel(x, y, m_clTable[c]);
		}
		m_SumMax -= m_Max;
		m_SumMax += max;
		if( m_SumMax < (256*2) ) m_SumMax = (256*2);
		m_Max = m_SumMax / 8;
		if( avgcnt ) m_Min = avg/avgcnt;
		if( m_Min >= (m_Max - 32) ) m_Max = m_Min + 32;
	}
	else {
		dc.FillSolidRect(&rc, GetRefColor(m_clBack));
	}
	if( m_sBorderStyle ){
		rc.left = rc.top = 0;
		rc.right = m_bmpSize.cx; rc.bottom = m_bmpSize.cy;
		DrawBorderStyle(&dc, rc);
	}
	dc.SelectObject(pOldBmp);
	dc.DeleteDC();
}
//---------------------------------------------------------------------------
void CXMMWaterCtrl::CreateTable(void)
{
	typedef union {
		struct {
			BYTE	r;
			BYTE	g;
			BYTE	b;
			BYTE	c;
		}b;
		COLORREF	col;
	}COL;
	COL clLow, clHigh;
	clLow.col = GetRefColor(m_clBack);
	clHigh.col = GetRefColor(m_clSpectram);
	COL cl;
	for( int i = 0; i < 256; i++ ){
		cl.b.r = clLow.b.r + (clHigh.b.r - clLow.b.r) * i / 256;
		cl.b.g = clLow.b.g + (clHigh.b.g - clLow.b.g) * i / 256;
		cl.b.b = clLow.b.b + (clHigh.b.b - clLow.b.b) * i / 256;
		m_clTable[i] = cl.col;
	}
}
//---------------------------------------------------------------------------
SHORT CXMMWaterCtrl::GetMouseFreq(const CPoint &point)
{
	LONG freq = m_basefreq + point.x * m_widthfreq/ m_bmpSize.cx;
	if( freq < 0 ) freq = 0;
	if( freq > 3000 ) freq = 3000;
	return SHORT(freq);
}
/////////////////////////////////////////////////////////////////////////////
// CXMMWaterCtrl ���b�Z�[�W �n���h��

void CXMMWaterCtrl::Draw(short FAR* pFFT, short size, short sampfreq) 
{
	DrawWater(pFFT, size, sampfreq);

	if( !IsWindowVisible() ) return;
	CClientDC dc(this);
	DrawBitmap(&dc, m_rcClient);
}

OLE_COLOR CXMMWaterCtrl::GetBackColor() 
{
	return m_clBack;
}

void CXMMWaterCtrl::SetBackColor(OLE_COLOR nNewValue) 
{
	m_clBack = nNewValue;
	CreateTable();
	Draw(NULL, 2048, 11025);
	SetModifiedFlag();
}

OLE_COLOR CXMMWaterCtrl::GetSpectramColor() 
{
	return m_clSpectram;
}

void CXMMWaterCtrl::SetSpectramColor(OLE_COLOR nNewValue) 
{
	m_clSpectram = nNewValue;
	CreateTable();
	SetModifiedFlag();
}


short CXMMWaterCtrl::GetBaseFreq() 
{
	return m_basefreq;
}

void CXMMWaterCtrl::SetBaseFreq(short nNewValue) 
{
	if( nNewValue >= 4000 ) return;
	m_basefreq = nNewValue;
	SetModifiedFlag();
}

short CXMMWaterCtrl::GetWidthFreq() 
{
	return m_widthfreq;
}

void CXMMWaterCtrl::SetWidthFreq(short nNewValue) 
{
	if( nNewValue <= 0 ) return;
	m_widthfreq = nNewValue;
	SetModifiedFlag();
}

void CXMMWaterCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_LBUTTON ){
		SetCapture();
		FireOnLMouseDown(GetMouseFreq(point));
	}
	COleControl::OnLButtonDown(nFlags, point);
}

void CXMMWaterCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnLMouseUp(GetMouseFreq(point));
	}
	COleControl::OnLButtonUp(nFlags, point);
}

void CXMMWaterCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		short fq = GetMouseFreq(point);
		if( nFlags & MK_LBUTTON ){
			FireOnLMouseMove(fq);
		}
		else if( nFlags & MK_RBUTTON ){
			FireOnRMouseMove(fq);
		}
	}
	COleControl::OnMouseMove(nFlags, point);
}

void CXMMWaterCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if( nFlags == MK_RBUTTON ){
		SetCapture();
		FireOnRMouseDown(GetMouseFreq(point));
	}
	COleControl::OnRButtonDown(nFlags, point);
}

void CXMMWaterCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() == this ){
		ReleaseCapture();
		FireOnRMouseUp(GetMouseFreq(point));
	}
	COleControl::OnRButtonUp(nFlags, point);
}

void CXMMWaterCtrl::Clear() 
{
	m_Max = 256;
	m_SumMax = 256*8;
	m_Min = 0;
	Draw(NULL, 2048, 11025);
}

void CXMMWaterCtrl::OnVisibleChanged() 
{
	ShowWindow(m_visible ? SW_SHOW : SW_HIDE);
	SetModifiedFlag();
}
