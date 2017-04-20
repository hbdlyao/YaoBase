///////////////////////////////////////////////////////////
//  CxbDevShunt.cpp
//  Implementation of the Class CxbDevShunt
//  Created on:      12-4��-2017 12:00:41
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevShunt.h"
#include "CComplex.h"


void CxbDevShunt::Init()
{
	SetDotCount(1);

	Yg = new double[hMax()];
	Yb = new double[hMax()];
}


double CxbDevShunt::GetZr() {

	return structBranch.Zr;
}


double CxbDevShunt::GetZ_C() {

	return structBranch.Z_C;
}


double CxbDevShunt::GetZ_L() {

	return structBranch.Z_L;
}


double CxbDevShunt::GetZx_C() {

	return structBranch.Zx_C;
}


double CxbDevShunt::GetZx_L() {

	return structBranch.Zx_L;
}


void CxbDevShunt::SetZr(double vValue) {

	structBranch.Zr = vValue;
}


void CxbDevShunt::SetZ_C(double vValue) {

	structBranch.Z_C = vValue;
}


void CxbDevShunt::SetZ_L(double vValue) {

	structBranch.Z_L = vValue;
}


void CxbDevShunt::SetZx_C(double vValue) {

	structBranch.Zx_C = vValue;
}


void CxbDevShunt::SetZx_L(double vValue) 
{
	structBranch.Zx_L = vValue;
}


/**
 * ����
 */
double CxbDevShunt::GetYg(int vhOrder)
{
	//г��������1��ʼ
	return Yg[vhOrder - 1];
}


double CxbDevShunt::GetYb(int vhOrder)
{
	//г��������1��ʼ
	return Yb[vhOrder - 1];
}

void CxbDevShunt::Prepare_hRLC() 
{
	CComplex vY;

	double vOmega;

	if (Yg != nullptr)
		delete Yg;
	if (Yb != nullptr)
		delete Yg;

	Yg = new double[hMax()];
	Yb = new double[hMax()];

	double vFre = FreqRef();

	for (int i = 0; i < hMax(); i++)
	{
		//����:to-do
		//RLC����

		vOmega = vFre * 2 * PI;
		if (structBranch.Zx_C)
			vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
		else
			vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
		
	///////////////////////
		Yg[i] = vY.real();
		Yb[i] = vY.image();

	}
}




