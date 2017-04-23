///////////////////////////////////////////////////////////
//  CxbDevBranch.cpp
//  Implementation of the Class CxbDevBranch
//  Created on:      19-4��-2017 23:19:31
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBranch.h"

CxbDevBranch::~CxbDevBranch()
{
	delete[] Yg;
	delete[] Yb;
}

void CxbDevBranch::Clear()
{
	delete[] Yg;
	delete[] Yb;
}

void CxbDevBranch::InitData()
{
	Yg = new double[hMax()];
	Yb = new double[hMax()];
}

void CxbDevBranch::Init()
{
	SetDotCount(2);

	InitData();
}


void CxbDevBranch::Prepare_hRLC()
{
	//
	CComplex vY;
	double vZg, vZb;

	//
	for (int vh = 1; vh <= hMax(); vh++)
	{
		vZg = GetZr();
		vZb = vh * Omega() * GetZ_L();

		if (GetZ_C() != 0)
			vZb = vZb + -1.0 / (vh * Omega() * GetZ_C());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vh - 1] = vY.real();
		Yb[vh - 1] = vY.image();

	}

}

double CxbDevBranch::GetZr()
{

	return structBranch.Zr;
}


double CxbDevBranch::GetZ_C()
{
	return structBranch.Z_C*1E-6;
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
 * ����
 */
double CxbDevBranch::GetYg(int vhOrder){

	//г��������1��ʼ
	return Yg[vhOrder - 1];
}


double CxbDevBranch::GetYb(int vhOrder){

	//г��������1��ʼ
	return Yb[vhOrder - 1];
}


