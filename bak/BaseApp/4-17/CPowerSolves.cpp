///////////////////////////////////////////////////////////
//  CPowerSolves.cpp
//  Implementation of the Class CPowerSolves
//  Created on:      09-4��-2017 21:38:12
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerSolves.h"
#include "CHvdcFunc.h"


CPowerSolves::~CPowerSolves()
{
	Clear();
}

void CPowerSolves::Clear()
{

	for each (pPowerCal_Pair vPair in pItems)
	{
		delete vPair.second; 
		vPair.second = nullptr;
	}
	
	pItems.clear();
	//
}

void CPowerSolves::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;

	pGrid = vGrid;

}

string CPowerSolves::TypeToName(int vType)
{
	string vName;

	vName = CHvdcFunc::mcTypeToName(vType);
	
	return vName;
}


void CPowerSolves::NodeID()
{
	int vK = 0;
	
	NodeMap vNodeID, vNodeMap;
	
	//
	pGrid->ClearNodeID();
	
	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		//�����нڵ��ţ������ӵصĽڵ�
		vPair.second->NodeSort(vNodeMap);
	}//
	
	//
	for each (pPowerCal_Pair vPair in pItems)
	{	//���ӵصĽڵ�ı����Ϊ-1����ʾ�ӵ�
		vPair.second->NodeGround(vNodeMap);
	}//
	
	
	vK=0;
	for each (pair<string,int> vPair in vNodeMap)
	{
		//��ȥ�ӵؽڵ�
		if (vPair.second != -1)
		{
			vNodeID[vPair.first] = vK;
	
			vK = vK + 1;
		}
		else
			vNodeID[vPair.first] = -1;
	
	}// for each
	
	//
	pProfile->NodeCount = vK;
	pGrid->NodeCount = vK;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//�����ڵ���
		vPair.second->NodeID(vNodeID);
	}//
}


void CPowerSolves::StationSort()
{
	StationMap vStaMap;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//���վ���
		vPair.second->StationSort(vStaMap);
	}//

	pProfile->StaCount = static_cast<int>(vStaMap.size());

}


void CPowerSolves::NewSolves()
{
	int vIndex;
	CDeviceTBL * vTBL;
	CDeviceBase * vDev;

	for each (pDevTBL_Pair  vPair1 in  pGrid->GetItems())
	{
		vIndex = 0;
		vTBL = vPair1.second;
		for each (pObj_Pair  vPair2 in  vTBL->GetItems())
		{
			vDev = dynamic_cast<CDeviceBase *>(vPair2.second);

			doNewCal(vDev,vIndex);

			vIndex = vIndex + 1;

		}//pObj_Pair

	}//pDevTBL_Pair
}

void CPowerSolves::doNewItem(int vtblType)
{
	int vIndex;
	CDeviceTBL * vTBL;
	CDeviceBase * vDev;

	vIndex = 0;
	vTBL = pGrid->DeviceTBL(vtblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CDeviceBase *>(vPair.second);

		doNewCal(vDev, vIndex);

		vIndex = vIndex + 1;

	}//pObj_Pair

}


void CPowerSolves::doNewCal(CDeviceBase * vDev, int vIndex)
{
	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();

	switch (vType)
	{
	case 0:
		break;

	default:
		vCal = new  CPowerCalculate();

		break;

	}//switch

	vName = vDev->GetDeviceID();//to-do
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;
	vCal->DevIndex = vIndex;
	//
	vCal->Init(vDev);
	vCal->Init(pProfile, pGrid);
	
	//
	pItems[vName] = vCal;

}


void CPowerSolves::Run()
{
	//
	doPrepare();

}

void CPowerSolves::doPrepare()
{
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}
}

