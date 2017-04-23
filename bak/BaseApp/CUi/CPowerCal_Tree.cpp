///////////////////////////////////////////////////////////
//  CPowerCal_Tree.cpp
//  Implementation of the Class CPowerCal_Tree
//  Created on:      21-4ÔÂ-2017 18:10:14
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CPowerCal_Tree.h"
#include "CDevBase_tree.h"



CPowerCal_Tree::~CPowerCal_Tree()
{
	for each (CPowerCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
	//
}


void CPowerCal_Tree::Clear()
{
	for each (CPowerCal_Tree * vCal in pChildren)
	{
		vCal->Clear();
	}

}

void CPowerCal_Tree::Init(CDeviceBase* vDev)
{
	pDevice = vDev;

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Init(vDev);
	}
}



void CPowerCal_Tree::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;	

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile);
	}

}


bool CPowerCal_Tree::IsLeaf()
{
	return false;
}


void CPowerCal_Tree::Add(CPowerCalculate * vItem)
{

	pChildren.push_back(vItem);
}


void CPowerCal_Tree::Remove(CPowerCalculate * vItem)
{

	//children.removeElement( component );
}


int CPowerCal_Tree::ChildCount()
{
	return static_cast<int >(pChildren.size());
}


CPowerCalculate * CPowerCal_Tree::Child(int vIndex)
{
	return dynamic_cast<CPowerCalculate * >(pChildren[vIndex]);
}


pPowerCalVector CPowerCal_Tree::Children()
{
	return pChildren;
}


void CPowerCal_Tree::NewSolves()
{
	//
	for each (pDevTBL_Pair  vPair in  pGrid->GetDevTBLs())
	{
		doNewItem(vPair.second);
	}//pDevTBL_Pair
}


void CPowerCal_Tree::doNewItem(int vtblType)
{
	CDeviceTBL * vTBL;
	
	vTBL = pGrid->DeviceTBL(vtblType);
	
	doNewItem( vTBL);

}


void CPowerCal_Tree::doNewItem(CDeviceTBL* vTBL)
{
	for each (CDeviceBase *  vDev in  vTBL->ItemVect())
	{
		NewCal_Tree(vDev);
	}
}

void CPowerCal_Tree::NewCal_Tree(CDeviceBase* vDev)
{
	CPowerCalculate * vCal;
	CDevBase_Tree * vNode;

	//
	vCal=doNewCal(vDev);

	//
	if (!vDev->IsLeaf())
	{
		vNode = dynamic_cast<CDevBase_Tree * >(vDev);
		for each (CDeviceBase* vDev in vNode->Children())
		{
			vCal->NewCal_Tree(vDev);
		}//for 

	}//else

}


CPowerCalculate *  CPowerCal_Tree::doNewCal(CDeviceBase* vDev)
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

	//
	vName = vDev->GetDeviceName();//to-do
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;
	//
	vCal->Init(vDev);
	vCal->Init(pProfile);

	//
	Add(vCal);

	//
	return vCal;

}



void CPowerCal_Tree::Prepare()
{
	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CPowerCal_Tree::NodeSort(NodeMap& vNodeMap)
{
	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CPowerCal_Tree::NodeGround(NodeMap& vNodeMap)
{
	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CPowerCal_Tree::NodeID(NodeMap& vNodeID)
{
	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CPowerCal_Tree::StationSort()
{
	StationMap vStaMap;

	//doStationSort(vStaMap);

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//

	pProfile->StaCount = static_cast<int>(vStaMap.size());

}

void CPowerCal_Tree::StationSort(StationMap& vStaMap)
{
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//
}
