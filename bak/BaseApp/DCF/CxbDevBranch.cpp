///////////////////////////////////////////////////////////
//  CxbDevBranch.cpp
//  Implementation of the Class CxbDevBranch
//  Created on:      19-4月-2017 23:19:31
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBranch.h"


void CxbDevBranch::Init()
{
	SetDotCount(2);

	Yg = new double[hMax()];
	Yb = new double[hMax()];
}

double CxbDevBranch::GetZr()
{

	return structBranch.Zr;
}


double CxbDevBranch::GetZ_C()
{

	return structBranch.Z_C;
}


double CxbDevBranch::GetZ_L()
{

	return structBranch.Z_L;
}


double CxbDevBranch::GetZx_C(){

	return structBranch.Zx_C;
}


double CxbDevBranch::GetZx_L()
{

	return structBranch.Zx_L;
}


void CxbDevBranch::SetZr(double vValue)
{

	structBranch.Zr = vValue;
}


void CxbDevBranch::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CxbDevBranch::SetZ_L(double vValue)
{

	structBranch.Z_L = vValue;
}


void CxbDevBranch::SetZx_C(double vValue)
{

	structBranch.Zx_C = vValue;
}


void CxbDevBranch::SetZx_L(double vValue)
{

	structBranch.Zx_L = vValue;
}


/**
 * 马骏鹏
 */
double CxbDevBranch::GetYg(int vhOrder){

	//谐波次数从1开始
	return Yg[vhOrder - 1];
}


double CxbDevBranch::GetYb(int vhOrder){

	//谐波次数从1开始
	return Yb[vhOrder - 1];
}


void CxbDevBranch::Prepare_hRLC(){

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
		//马俊鹏:to-do
		//RLC串联
	
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

