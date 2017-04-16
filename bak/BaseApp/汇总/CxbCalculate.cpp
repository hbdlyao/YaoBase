///////////////////////////////////////////////////////////
//  CxbCalculate.cpp
//  Implementation of the Class CxbCalculate
//  Created on:      05-4ÔÂ-2017 18:31:46
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalculate.h"

void CxbCalculate::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	//pGrid = vGrid;

	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);
	//pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);
}

void CxbCalculate::Prepare()
{

}
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


void CxbCalculate::StationSort(StationMap& vStaMap){

}