///////////////////////////////////////////////////////////
//  CxbCal_Composite_N.cpp
//  Implementation of the Class CxbCal_Composite_N
//  Created on:      17-4��-2017 14:35:45
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
	//PowerCalculate ��������?

	//��ÿһ�� CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vDev);
	}
}

void CxbCal_Composite::Init(CPowerProfile* vProfile, CPowerGrid* vGrid)
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile, vGrid);
	}
}



void CxbCal_Composite::Prepare()
{
		//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CxbCal_Composite::StationSort(StationMap& vStaMap)
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}
}


void CxbCal_Composite::NodeSort(NodeMap& vNodeMap)
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Composite::NodeGround(NodeMap& vNodeMap)
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Composite::NodeID(NodeMap& vNodeID)
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CxbCal_Composite::UpdateY()
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CxbCal_Composite::UpdateI()
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}


