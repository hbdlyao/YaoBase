///////////////////////////////////////////////////////////
//  CHvdcDeviceBase.cpp
//  Implementation of the Class CHvdcDeviceBase
//  Created on:      04-4月-2017 7:25:12
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDeviceBase.h"



void CDevOneDot::Init()
{

	SetDotCount(1);
}




void CDevTwoDot::Init(){

	SetDotCount(2);
}


void CDevShunt::Init()
{
	SetDotCount(1);

	structBranch.Zr  = 0;
	structBranch.Zx_C= 0;
	structBranch.Zx_L= 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;

}


double CDevShunt::GetZr()
{

	return structBranch.Zr;
}


double CDevShunt::GetZ_C()
{

	return structBranch.Z_C;
}


double CDevShunt::GetZ_L()
{

	return structBranch.Z_L;
}


double CDevShunt::GetZx_C()
{

	return structBranch.Zx_C;
}


double CDevShunt::GetZx_L()
{

	return structBranch.Zx_L;
}


void CDevShunt::SetZr(double vValue)
{

	structBranch.Zr= vValue;
}


void CDevShunt::SetZ_C(double vValue)
{

	structBranch.Z_C = vValue;
}


void CDevShunt::SetZ_L(double vValue)
{

	structBranch.Z_L = vValue;
}


void CDevShunt::SetZx_C(double vValue)
{

	structBranch.Zx_C = vValue;
}


void CDevShunt::SetZx_L(double vValue)
{

	structBranch.Zx_L = vValue;
}



double CDevShunt::GetY()
{

	double vY = 0;

	//to-do

	return vY;
}

double CDevShunt::GetYg()
{

	double vY = 0;

	//to-do

	return vY;

}


double CDevShunt::GetYb()
{

	double vY = 0;

	//to-do

	return vY;
}


//马骏鹏
double CDevShunt::GetYg(double vOmega) 
{
	//? structBranch.Zx_C
	CComplex vY;

	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();

	return vY.real();

}

//马骏鹏
double CDevShunt::GetYb(double vOmega) 
{
	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.image();
}


//CDevBranch
void CDevBranch::Init()
{
	SetDotCount(2);

	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;

}

double CDevBranch::GetZr()
{

	return structBranch.Zr;
}


double CDevBranch::GetZ_C()
{

	return structBranch.Z_C;
}


double CDevBranch::GetZ_L()
{

	return structBranch.Z_L;
}


double CDevBranch::GetZx_C()
{

	return structBranch.Zx_C;
}


double CDevBranch::GetZx_L()
{

	return structBranch.Zx_L;
}


void CDevBranch::SetZr(double vValue)
{

	structBranch.Zr= vValue;
}


void CDevBranch::SetZ_C(double vValue)
{

	structBranch.Z_C = vValue;
}


void CDevBranch::SetZ_L(double vValue)
{

	structBranch.Z_L = vValue;
}


void CDevBranch::SetZx_C(double vValue)
{

	structBranch.Zx_C = vValue;
}


void CDevBranch::SetZx_L(double vValue) 
{

	structBranch.Zx_L = vValue;
}

/**
* 受端换流站名称
*/
string CDevBranch::GetStationName1() {

	return StationName1;
}


/**
* 受端换流站名称
*/
string CDevBranch::GetStationName2() {

	return StationName2;
}


/**
* 受端换流站名称
*/
void CDevBranch::SetStationName1(string newVal) 
{

	StationName1 = newVal;
}


/**
* 受端换流站名称
*/
void CDevBranch::SetStationName2(string newVal) 
{

	StationName2 = newVal;
}




double CDevBranch::GetY(){

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CDevBranch::GetYg()
{

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}


double CDevBranch::GetYb()
{

	double vY = 0;
	
	if (structBranch.Zr != 0)
		vY = (1 / structBranch.Zr);
	else
		vY = 0;
	
	return vY;
}

//马骏鹏
double CDevBranch::GetYg(double vOmega) 
{
	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.real();
}
double CDevBranch::GetYb(double vOmega) 
{
	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.image();
}
//
