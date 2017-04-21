///////////////////////////////////////////////////////////
//  CxbCalculate.cpp
//  Implementation of the Class CxbCalculate
//  Created on:      05-4ÔÂ-2017 18:31:46
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalculate.h"
/**
 * void Init(CPowerProfile * vProfile, CPowerGrid * vGrid) override;
 */
void CxbCalculate::UpdateY()
{
//
}



void CxbCalculate::UpdateI()
{
//
}


void CxbCalculate::Add(CxbCalculate * vItem)
{

}


void CxbCalculate::Remove(CxbCalculate * vItem)
{

}

void CxbCalculate::Init(CDeviceBase* vDev)
{
	pDevice = vDev;
}

void CxbCalculate::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);
}

