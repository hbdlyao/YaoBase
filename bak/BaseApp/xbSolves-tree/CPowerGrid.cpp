///////////////////////////////////////////////////////////
//  CPowerGrid.cpp
//  Implementation of the Class CPowerGrid
//  Created on:      23-3ÔÂ-2017 7:40:43
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerGrid.h"
#include "CHvdcFunc.h"


CPowerGrid::~CPowerGrid()
{
	
	Release();

}


string CPowerGrid::TypeToName(int vType)
{
	
	return "CPowerGrid.TypeToName";

}



CDeviceBase * CPowerGrid::Device(int vType, string vName)
{

	return DeviceTBL(vType)->Device(vName);
}



void CPowerGrid::DeviceAdd(int vType,string vID, CDeviceBase * vDev) 
{
	DeviceTBL(vType)->DeviceAdd(vID,vDev);
}


void CPowerGrid::Clear()
{
	//ItemsVect
	for each (pDevTBL_Pair vPair in pItems)
	{
		//
		delete vPair.second;
		vPair.second = nullptr;

	}

	pItems.clear();


}

void CPowerGrid::Release()
{
	
	Clear();

}


void CPowerGrid::ClearNodeID()
{
	CDeviceTBL * vTBL;

	//NodeCount = 0;

	for each (pDevTBL_Pair  vPair in  pItems)
	{
		vTBL = vPair.second;
		vTBL->ClearNodeID();
	}

}

CDeviceTBL * CPowerGrid::DeviceTBL(int vType)
{
	return pItems[vType];
}

