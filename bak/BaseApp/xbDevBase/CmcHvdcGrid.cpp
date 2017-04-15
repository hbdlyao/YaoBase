///////////////////////////////////////////////////////////
//  CmcHvdcGrid.cpp
//  Implementation of the Class CmcHvdcGrid
//  Created on:      08-4ÔÂ-2017 10:32:17
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcHvdcGrid.h"
#include "CHvdcFunc.h"

void CmcHvdcGrid::Init(){

	int i;
	CDeviceTBL * vTBL;
	
	for (i = mc_AcSys; i <= mc_MetalLine; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);
	
	}
}


string CmcHvdcGrid::TypeToName(int vType){

	string vName;
	vName = CHvdcFunc::mcTypeToName(vType);
	
	return vName;
}


CDeviceTBL * CmcHvdcGrid::NewDeviceTBL(int vType)
{

	string vName;
	CHvdcDeviceTBL * vSet;
	
	vName = TypeToName(vType);
	
	//
	vSet = new CHvdcDeviceTBL();
	vSet->SetTblType(vType);
	vSet->SetTblName(vName);
	
	//
	pItems[vType] = vSet;
	
	return pItems[vType];
}