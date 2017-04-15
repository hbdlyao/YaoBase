///////////////////////////////////////////////////////////
//  CPowerGrid.cpp
//  Implementation of the Class CPowerGrid
//  Created on:      23-3ÔÂ-2017 7:40:43
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerGrid.h"
#include "CHvdcFunc.h"

void CPowerGrid::MyFree()
{
}

CPowerGrid::~CPowerGrid(){
	
	MyFree();

	Release();

}


string CPowerGrid::TypeToName(int vType){
	
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
	int i, vdotCount;

	CDeviceTBL * vTBL;
	CDeviceBase * vDev;

	NodeCount = 0;

	for each (pDevTBL_Pair  vPair1 in  pItems)
	{
		vTBL = vPair1.second;
		for each (pObj_Pair  vPair2 in  vTBL->GetItems())
		{
			vDev = dynamic_cast<CDeviceBase *>(vPair2.second);
			vdotCount = vDev->GetDotCount();

			for (i = 0; i < vdotCount; i++)
			{
				vDev->SetNodeID(i, -2);
			}//for i

		}//for each
	}

}

CDeviceTBL * CPowerGrid::DeviceTBL(int vType){

	return pItems[vType];
}

