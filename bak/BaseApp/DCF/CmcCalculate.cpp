///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4ÔÂ-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"


void CmcCalculate::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	//pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	//pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}


void CmcCalculate::SaveNormal()
{

}
void CmcCalculate::CalConvertor_DC()
{

}
void CmcCalculate::CalConvertor_AC()
{

}
void CmcCalculate::CalConvertor_Port()
{

}

void CmcCalculate::CalXf2_l()
{

}
void CmcCalculate::CalXf2_v()
{

}
void CmcCalculate::CalXf2_Port()
{

}
void CmcCalculate::CalXf2_UpShift()
{

}
void CmcCalculate::CalXf2_DownShift()
{

}

void CmcCalculate::CalACSide()
{

}

bool CmcCalculate::IsFixed_I()
{	
	return false;
}


void CmcCalculate::InitX()
{


}


void CmcCalculate::UpdateY() {

}


void CmcCalculate::Prepare()
{

}


void CmcCalculate::UpdateJ() {

	//
}


void CmcCalculate::UpdateF_J() {

	//
}




void CmcCalculate::PrepareNormal() {

}