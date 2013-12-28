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

//---------------------------------------------------------------------------
#include "stdafx.h"

#include <math.h>
#include "Filter.h"

//---------------------------------------------------------------------------
CIIRLPF::CIIRLPF()
{
	m_order = 0;
	memset(m_A, 0, sizeof(double[IIRMAX*3]));
	memset(m_B, 0, sizeof(double[IIRMAX*2]));
	memset(m_Z, 0, sizeof(double[IIRMAX*2]));
}

void CIIRLPF::Clear(void)
{
	memset(m_Z, 0, sizeof(double[IIRMAX*2]));
}

//---------------------------------------------------------------------------
// ÉoÉ^Å[ÉèÅ[ÉX
void CIIRLPF::Create(double fc, double fs, int order)
{
	ASSERT(order);
	ASSERT(order <= IIRMAX*2);
	ASSERT(fc < fs/2);

	m_order = order;
	double	w0, wa, zt;
	int		j, n;

	wa = tan(PI*fc/fs);
	w0 = 1.0;
	n = (order & 1) + 1;
	double *pA = m_A;
	double *pB = m_B;
	for( j = 1; j <= order/2; j++, pA+=3, pB+=2 ){
		w0 = 1.0;
		zt = cos(n*PI/(2*order));
		pA[0] = 1 + wa*w0*2*zt + wa*w0*wa*w0;
		pA[1] = -2 * (wa*w0*wa*w0 - 1)/pA[0];
		pA[2] = -(1.0 - wa*w0*2*zt + wa*w0*wa*w0)/pA[0];
		pB[0] = wa*w0*wa*w0 / pA[0];
		pB[1] = 2*pB[0];
		n += 2;
	}
	if( order & 1 ){
		j = (order / 2);
		pA = m_A + (j*3);
		pB = m_B + (j*2);
		pA[0] = 1 + wa*w0;
		pA[1] = -(wa*w0 - 1)/pA[0];
		pB[0] = wa*w0/pA[0];
		pB[1] = pB[0];
	}
}

LONG CIIRLPF::Do(LONG dd)
{
	double *pA = m_A;
	double *pB = m_B;
	double *pZ = m_Z;
	double o;
	double d = dd;
	for( int i = 0; i < m_order/2; i++, pA+=3, pB+=2, pZ+=2 ){
		d += pZ[0] * pA[1] + pZ[1] * pA[2];
		o = d * pB[0] + pZ[0] * pB[1] + pZ[1] * pB[0];
		pZ[1] = pZ[0];
		if( fabs(d) < 1e-37 ) d = 0.0;	// î≠êUÇÃñhé~
		pZ[0] = d;
		d = o;
	}
	if( m_order & 1 ){
		d += pZ[0] * pA[1];
		o = d * pB[0] + pZ[0] * pB[0];
		if( fabs(d) < 1e-37 ) d = 0.0;	// î≠êUÇÃñhé~
		pZ[0] = d;
		d = o;
	}
	return (LONG)d;
}

//*********************************************************************
// CINTPXY	XYScope óp Å~2ÉCÉìÉ^É|Å[ÉåÅ[É^èàóùÉNÉâÉX
//
CINTPXY2::CINTPXY2(LONG sampfreq)
{
	m_iirlpf.Create(2700.0, sampfreq * 2, 14);
}

void CINTPXY2::Clear(void)
{
	m_iirlpf.Clear();
}

void CINTPXY2::Do(LPLONG &p, LONG d)
{
	*p++ = LONG(m_iirlpf.Do(d) * 1.15);
	*p++ = LONG(m_iirlpf.Do(d) * 1.15);
}
