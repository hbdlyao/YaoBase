///////////////////////////////////////////////////////////
//  CxbCal_Composite_N.cpp
//  Implementation of the Class CxbCal_Composite_N
//  Created on:      17-4月-2017 14:35:45
///////////////////////////////////////////////////////////

#include "CxbCal_Composite.h"
#include "CxbDevBranch.h"


CxbCal_Composite::~CxbCal_Composite()
{

	for each (CxbCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();

}


void CxbCal_Composite::Add(CxbCalculate * vItem)
{
	pChildren.push_back(vItem);
}


void CxbCal_Composite::Remove(CxbCalculate * vItem)
{
	//children.removeElement( component );
}

bool CxbCal_Composite::IsLeaf()
{
	return false;
}


void CxbCal_Composite::Init(CDeviceBase* vDev)
{
	//PowerCalculate 不能重载?

	//对每一个 CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vDev);
	}
}

void CxbCal_Composite::Init(CPowerProfile* vProfile, CPowerGrid* vGrid)
{
	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile, vGrid);
	}
}



void CxbCal_Composite::Prepare()
{
		//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CxbCal_Composite::StationSort(StationMap& vStaMap)
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}
}


void CxbCal_Composite::NodeSort(NodeMap& vNodeMap)
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Composite::NodeGround(NodeMap& vNodeMap)
{
	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Composite::NodeID(NodeMap& vNodeID)
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CxbCal_Composite::UpdateY()
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CxbCal_Composite::UpdateI()
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}


