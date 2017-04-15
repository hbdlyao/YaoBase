///////////////////////////////////////////////////////////
//  CxbDevBranch.cpp
//  Implementation of the Class CxbDevBranch
//  Created on:      12-4月-2017 12:00:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBranch.h"
#include "CComplex.h"



/**
 * CDevBranch
 */
void CxbDevBranch::Init(){

	SetDotCount(2);
	
	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;
}


double CxbDevBranch::GetZr(){

	return structBranch.Zr;
}


double CxbDevBranch::GetZ_C(){

	return structBranch.Z_C;
}


double CxbDevBranch::GetZ_L(){

	return structBranch.Z_L;
}


double CxbDevBranch::GetZx_C(){

	return structBranch.Zx_C;
}


double CxbDevBranch::GetZx_L(){

	return structBranch.Zx_L;
}


void CxbDevBranch::SetZr(double vValue){

	structBranch.Zr= vValue;
}


void CxbDevBranch::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CxbDevBranch::SetZ_L(double vValue){

	structBranch.Z_L = vValue;
}


void CxbDevBranch::SetZx_C(double vValue){

	structBranch.Zx_C = vValue;
}


void CxbDevBranch::SetZx_L(double vValue){

	structBranch.Zx_L = vValue;
}


/**
 * 受端换流站名称
 */
string CxbDevBranch::GetStationName1(){

	return StationName1;
}


/**
 * 受端换流站名称
 */
string CxbDevBranch::GetStationName2(){

	return StationName2;
}


/**
 * 受端换流站名称
 */
void CxbDevBranch::SetStationName1(string newVal){

	StationName1 = newVal;
}


/**
 * 受端换流站名称
 */
void CxbDevBranch::SetStationName2(string newVal){

	StationName2 = newVal;
}


double CxbDevBranch::GetY(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CxbDevBranch::GetYg(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CxbDevBranch::GetYb(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


/**
 * 马骏鹏
 */
double CxbDevBranch::GetYg(double vOmega){

	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.real();
}


double CxbDevBranch::GetYb(double vOmega){

	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.image();
}