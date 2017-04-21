///////////////////////////////////////////////////////////
//  CmcDevBranch.cpp
//  Implementation of the Class CmcDevBranch
//  Created on:      13-4月-2017 13:15:44
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevBranch.h"
#include "CComplex.h"



/**
 * CmcDevBranch
 */
void CmcDevBranch::Init(){

	SetDotCount(2);
	
	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;
}


double CmcDevBranch::GetZr(){

	return structBranch.Zr;
}


double CmcDevBranch::GetZ_C(){

	return structBranch.Z_C;
}


double CmcDevBranch::GetZ_L(){

	return structBranch.Z_L;
}


double CmcDevBranch::GetZx_C(){

	return structBranch.Zx_C;
}


double CmcDevBranch::GetZx_L(){

	return structBranch.Zx_L;
}


void CmcDevBranch::SetZr(double vValue){

	structBranch.Zr= vValue;
}


void CmcDevBranch::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CmcDevBranch::SetZ_L(double vValue){

	structBranch.Z_L = vValue;
}


void CmcDevBranch::SetZx_C(double vValue){

	structBranch.Zx_C = vValue;
}


void CmcDevBranch::SetZx_L(double vValue){

	structBranch.Zx_L = vValue;
}


/**
 * 受端换流站名称
 */
string CmcDevBranch::GetStationName1(){

	return StationName1;
}


/**
 * 受端换流站名称
 */
string CmcDevBranch::GetStationName2(){

	return StationName2;
}


/**
 * 受端换流站名称
 */
void CmcDevBranch::SetStationName1(string newVal){

	StationName1 = newVal;
}


/**
 * 受端换流站名称
 */
void CmcDevBranch::SetStationName2(string newVal){

	StationName2 = newVal;
}


double CmcDevBranch::GetY(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CmcDevBranch::GetYg(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CmcDevBranch::GetYb(){

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
double CmcDevBranch::GetYg(double vOmega){

	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.real();
}


double CmcDevBranch::GetYb(double vOmega){

	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.image();
}


double CmcDevBranch::GetZrN(){

	return structBranch.Zr;
}


void CmcDevBranch::SetZrN(double vValue){

	structBranch.Zr= vValue;
}