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
#ifndef FilterH
#define FilterH

//---------------------------------------------------------------------------
#define	PI	3.1415926535897932384626433832795

#define	IIRMAX	16
class CIIRLPF
{
private:
	double	m_Z[IIRMAX*2];
	double	m_A[IIRMAX*3];
	double	m_B[IIRMAX*2];
	int		m_order;
public:
	CIIRLPF();
	void Create(double fc, double fs, int order);
	LONG Do(LONG d);
	void Clear(void);
};

class CINTPXY2{			// IIR x2 for XY Scope
private:
	CIIRLPF	m_iirlpf;	// 処理を高速にするためにIIRフィルタを使います
public:
	CINTPXY2(LONG sampfreq);
	void Clear(void);
	void Do(LPLONG &p, LONG d);
};
#endif
