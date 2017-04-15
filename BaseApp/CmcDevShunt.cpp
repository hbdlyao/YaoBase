///////////////////////////////////////////////////////////
//  CmcDevShunt.cpp
//  Implementation of the Class CmcDevShunt
//  Created on:      13-4ÔÂ-2017 13:15:34
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevShunt.h"
#include "CComplex.h"



double CmcDevShunt::GetZr(){

	return structBranch.Zr;
}


double CmcDevShunt::GetZ_C(){

	return structBranch.Z_C;
}


double CmcDevShunt::GetZ_L(){

	return structBranch.Z_L;
}


double CmcDevShunt::GetZx_C(){

	return structBranch.Zx_C;
}


double CmcDevShunt::GetZx_L(){

	return structBranch.Zx_L;
}


void CmcDevShunt::SetZr(double vValue){

	structBranch.Zr= vValue;
}


void CmcDevShunt::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CmcDevShunt::SetZ_L(double vValue){

	structBranch.Z_L = vValue;
}


void CmcDevShunt::SetZx_C(double vValue){

	structBranch.Zx_C = vValue;
}


void CmcDevShunt::SetZx_L(double vValue){

	structBranch.Zx_L = vValue;
}


void CmcDevShunt::Init(){

	SetDotCount(1);
	
	structBranch.Zr  = 0;
	structBranch.Zx_C= 0;
	structBranch.Zx_L= 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;
}


double CmcDevShunt::GetY(){

	double vY = 0;
	
	//to-do
	
	return vY;
}


double CmcDevShunt::GetYg(){

	double vY = 0;
	
	//to-do
	
	return vY;
}


double CmcDevShunt::GetYb(){

	double vY = 0;
	
	//to-do
	
	return vY;
}


/**
 * Âí¿¥Åô
 */
double CmcDevShunt::GetYg(double vOmega){

	//? structBranch.Zx_C
	CComplex vY;
	
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	
	return vY.real();
}


/**
 * Âí¿¥Åô
 */
double CmcDevShunt::GetYb(double vOmega){

	CComplex vY;
	if (structBranch.Zx_C)
		vY = (CComplex(structBranch.Zr, vOmega*structBranch.Zx_L) + CComplex(0, -1.0 / vOmega / structBranch.Zx_C)).inverse();
	else
		vY = CComplex(structBranch.Zr, vOmega*structBranch.Zx_L).inverse();
	return vY.image();
}