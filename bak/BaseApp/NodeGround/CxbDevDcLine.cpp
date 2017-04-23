///////////////////////////////////////////////////////////
//  CxbDevDcLine.cpp
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4ÔÂ-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDcLine.h"

CxbDevDcLine::~CxbDevDcLine()
{
	delete[] pLineParam;
}

void CxbDevDcLine::Clear()
{
	delete[] pLineParam;
}

void CxbDevDcLine::InitData()
{
	pLineParam = new struct_LineParam[hMax()];
}

void CxbDevDcLine::Init()
{
	SetDotCount(4);

	InitData();

}


void CxbDevDcLine::Prepare_hRLC()
{

}

/**
 * ·µ»ØYÕó
 */
CMatrix CxbDevDcLine::GetYMatrix(int hOrder) 
{
	//??
/*		 0		  1		  1		  2
	0	Ys11	Ys12	Ym11	Ym12
	1	Ys12	Ys11	Ym12	Ym11
	2	Ym11	Ym12	Ys11	Ys12
	3	Ym12	Ym11	Ys12	Ys11
*/

	CMatrix vY(4);
	CComplex vC;

	vC = CComplex(GetYs11re(hOrder), GetYs11im(hOrder));
	vY._mat[0][0] = vC;
	vY._mat[1][1] = vC;
	vY._mat[2][2] = vC;
	vY._mat[3][3] = vC;

	vC = CComplex(GetYs12re(hOrder), GetYs12im(hOrder));
	vY._mat[0][1] = vC;
	vY._mat[1][0] = vC;
	vY._mat[2][3] = vC;
	vY._mat[3][2] = vC;

	vC = CComplex(GetYm11re(hOrder), GetYm11im(hOrder));
	vY._mat[0][2] = vC;
	vY._mat[1][3] = vC;
	vY._mat[2][0] = vC;
	vY._mat[3][1] = vC;

	vC = CComplex(GetYm12re(hOrder), GetYm12im(hOrder));
	vY._mat[0][3] = vC;
	vY._mat[1][2] = vC;
	vY._mat[2][1] = vC;
	vY._mat[3][0] = vC;
	
	//
	return vY;

}

double CxbDevDcLine::GetYs11re(int vhOrder)
{
	return pLineParam[vhOrder-1].Ys11re;

}

double CxbDevDcLine::GetYs12re(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ys12re;

}


double CxbDevDcLine::GetYs11im(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ys11im;

}

double CxbDevDcLine::GetYs12im(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ym11im;
}

double CxbDevDcLine::GetYm11re(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ym11re;
}

double CxbDevDcLine::GetYm12re(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ym12re;
}


double CxbDevDcLine::GetYm11im(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ym11im;
}

double CxbDevDcLine::GetYm12im(int vhOrder)
{
	return pLineParam[vhOrder - 1].Ym12im;
}


void CxbDevDcLine::SetYs11re(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ys11re = vY;
}

void CxbDevDcLine::SetYs12re(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ys12re = vY;
}


void CxbDevDcLine::SetYs11im(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ys11im = vY;
}

void CxbDevDcLine::SetYs12im(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ys12im = vY;
}


void CxbDevDcLine::SetYm11re(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ym11re = vY;

}

void CxbDevDcLine::SetYm12re(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ym12re = vY;

}


void CxbDevDcLine::SetYm11im(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ym11im = vY;

}

void CxbDevDcLine::SetYm12im(int vhOrder, double vY)
{
	pLineParam[vhOrder - 1].Ym12im = vY;

}



string CxbDevDcLine::BusName(int vIndex)
{

	string vBus;
	
	switch (vIndex)
	{
	case 0:
	case 1:
		vBus = GetStationName1() +"---"+ GetNodeName(vIndex);
		break;
	case 2:
	case 3:
		vBus = GetStationName2() + "---" + GetNodeName(vIndex);
		break;

	default:
		break;
	}

	if (GetNodeName(vIndex) == "-1")
		vBus = "-1";

	return vBus;

}