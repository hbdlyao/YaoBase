///////////////////////////////////////////////////////////
//  CxbCalRLC_N.cpp
//  Implementation of the Class CxbCalRLC_N
//  Created on:      17-4月-2017 14:35:45
///////////////////////////////////////////////////////////

#include "CxbCalRLC_N.h"
#include "CxbDevBranch.h"


CxbCalRLC_N::~CxbCalRLC_N()
{
	Clear();
}

void CxbCalRLC_N::Clear()
{

	for each (CxbCalRLC * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
	//
}

void CxbCalRLC_N::Add(CxbCalRLC * vItem)
{
	pChildren.push_back(vItem);
}


void CxbCalRLC_N::Remove(CxbCalRLC * vItem)
{

	//children.removeElement( component );

}


void CxbCalRLC_N::UpdateY()
{
	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->UpdateY();
	}
	
}


void CxbCalRLC_N::UpdateI()
{
	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->UpdateI();
	}

}


void CxbCalRLC_N::Prepare()
{
	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CxbCalRLC_N::StationSort(StationMap& vStaMap)
{

	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}

}


void CxbCalRLC_N::NodeSort(NodeMap& vNodeMap)
{

	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCalRLC_N::NodeGround(NodeMap& vNodeMap)
{
	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCalRLC_N::NodeID(NodeMap& vNodeID)
{

	//对每一个CxbCalculate
	for each (CxbCalRLC * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}

}


void CxbCalRLC_N::Init(CPowerProfile* vProfile, CPowerGrid* vGrid){

	pProfile = vProfile;
	//pGrid = vGrid;
	
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);
	//pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);
}