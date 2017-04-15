///////////////////////////////////////////////////////////
//  CxbDevBranch.cpp
//  Implementation of the Class CxbDevBranch
//  Created on:      12-4月-2017 12:00:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBranch.h"
#include "CComplex.h"



/**
* CmcDevBranch
*/
void CxbDevBranch::Init() {

	SetDotCount(2);

	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;
}


double CxbDevBranch::GetZr() {

	return structBranch.Zr;
}


double CxbDevBranch::GetZ_C() {

	return structBranch.Z_C;
}


double CxbDevBranch::GetZ_L() {

	return structBranch.Z_L;
}


double CxbDevBranch::GetZx_C() {

	return structBranch.Zx_C;
}


double CxbDevBranch::GetZx_L() {

	return structBranch.Zx_L;
}


void CxbDevBranch::SetZr(double vValue) {

	structBranch.Zr = vValue;
}


void CxbDevBranch::SetZ_C(double vValue) {

	structBranch.Z_C = vValue;
}


void CxbDevBranch::SetZ_L(double vValue) {

	structBranch.Z_L = vValue;
}


void CxbDevBranch::SetZx_C(double vValue) {

	structBranch.Zx_C = vValue;
}


void CxbDevBranch::SetZx_L(double vValue) {

	structBranch.Zx_L = vValue;
}


/**
* 受端换流站名称
*/
string CxbDevBranch::GetStationName1() {

	return StationName1;
}


/**
* 受端换流站名称
*/
string CxbDevBranch::GetStationName2() {

	return StationName2;
}


/**
* 受端换流站名称
*/
void CxbDevBranch::SetStationName1(string newVal) {

	StationName1 = newVal;
}


/**
* 受端换流站名称
*/
void CxbDevBranch::SetStationName2(string newVal) {

	StationName2 = newVal;
}


void CxbDevBranch::InitY(double vFre)
{
	CComplex vY;
	double vOmega;
	if (Yg == nullptr)
		delete Yg;
	if (Yb == nullptr)
		delete Yg;
	Yg = new double[H_CAL_NUM];
	Yb = new double[H_CAL_NUM];

	for (int i = 0; i < H_CAL_NUM; i++)
	{
		vOmega = vFre * 2 * PI;
		if (structBranch.Zx_C)
			vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
		else
			vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
		Yg[i] = vY.real();
		Yb[i] = vY.image();
	}
}


double CxbDevBranch::GetYg(int vhOrder)
{
	return Yg[vhOrder - 1];
}


double CxbDevBranch::GetYb(int vhOrder)
{
	return Yb[vhOrder - 1];
}


