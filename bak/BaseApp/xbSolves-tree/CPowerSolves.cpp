///////////////////////////////////////////////////////////
//  CPowerSolves.cpp
//  Implementation of the Class CPowerSolves
//  Created on:      09-4月-2017 21:38:12
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



void CPowerSolves::NewSolves()
{
	//
	for each (pDevTBL_Pair  vPair in  pGrid->GetDevTBLs())
	{
		doNewItem(vPair.second);
	}//pDevTBL_Pair

}


void CPowerSolves::doNewItem(int vtblType)
{
	CDeviceTBL * vTBL;

	vTBL = pGrid->DeviceTBL(vtblType);

	doNewItem( vTBL);

}


void CPowerSolves::doNewItem(CDeviceTBL * vTBL)
{
	int vIndex;
	CDeviceBase * vDev;

	vIndex = 0;
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CDeviceBase *>(vPair.second);

		if (vDev->IsLeaf())
			doNewCal(vDev, vIndex);
		else
			doNewCal_Tree(vDev , vIndex);

		vIndex = vIndex + 1;

	}//pObj_Pair

}


void CPowerSolves::doNewCal(CDeviceBase * vDev , int vIndex)
{
/*
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

	vName = vDev->GetDeviceName();//to-do
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;
	vCal->DevIndex = vIndex;
	//
	vCal->Init(vDev);
	vCal->Init(pProfile, pGrid);
	
	//
	pItems[vName] = vCal;

*/

}


void CPowerSolves::doNewCal_Tree(CDeviceBase* vDev, int vIndex)
{
	/*
	int i,vN;

	CDeviceBase * vChild;
	CDevTree * vRLCs;

	if (vDev->IsLeaf())
	{
		doNewCal(vDev, 0);
	}
	else
	{
		vRLCs = dynamic_cast<CDevTree *> (vDev);
		vN = vRLCs->ChildCount();
		for (i = 0; i<vN; i++)
		{
			vChild = vRLCs->Child(i);
			doNewCal_Tree(vChild);
		}//for
	}//else
	*/

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


void CPowerSolves::NodeID()
{
	int vK = 0;

	NodeMap vNodeID, vNodeMap;

	//
	pGrid->ClearNodeID();

	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		//给所有节点编号，包括接地的节点
		vPair.second->NodeSort(vNodeMap);
	}//

	 //
	for each (pPowerCal_Pair vPair in pItems)
	{	//将接地的节点的编号置为-1，表示接地
		vPair.second->NodeGround(vNodeMap);
	}//


	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//划去接地节点
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
	//pGrid->NodeCount = vK;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//给定节点编号
		vPair.second->NodeID(vNodeID);
	}//
}


void CPowerSolves::StationSort()
{
	StationMap vStaMap;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//变电站编号
		vPair.second->StationSort(vStaMap);
	}//

	
	pProfile->StaCount = static_cast<int>(vStaMap.size());


}
