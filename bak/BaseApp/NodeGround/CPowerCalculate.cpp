///////////////////////////////////////////////////////////
//  CPowerCalculate.cpp
//  Implementation of the Class CPowerCalculate
//  Created on:      09-4ÔÂ-2017 21:38:18
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerCalculate.h"

CPowerCalculate::~CPowerCalculate() 
{
	Clear();
}

void CPowerCalculate::Clear() 
{

}

void CPowerCalculate::Init(CDeviceBase * vDev)
{
	pDevice = vDev;
}

void CPowerCalculate::Init(CPowerProfile * vProfile)
{
	pProfile = vProfile;
}


void CPowerCalculate::Add(CPowerCalculate* vItem)
{

}


void CPowerCalculate::Remove(CPowerCalculate* vItem){

}


bool CPowerCalculate::IsLeaf(){

	return true;
}


void CPowerCalculate::NewCal_Tree(CDeviceBase * vDev)
{

}

void CPowerCalculate::Prepare()
{

}

void CPowerCalculate::NodeGround(NodeMap& vNodeMap)
{
	pDevice->NodeGround(vNodeMap);
}


void CPowerCalculate::NodeSort(NodeMap& vNodeMap)
{
	pDevice->NodeSort(vNodeMap);
}


void CPowerCalculate::NodeID(NodeMap& vNodeID)
{
	pDevice->NodeID(vNodeID);

}


void CPowerCalculate::StationSort(StationMap& vStaMap)
{
	doStationSort(vStaMap);
}


void CPowerCalculate::doStationSort(StationMap& vStaMap)
{
	int vN, vID;
	string vName;

	vName = pDevice->GetStationName();
	vN = static_cast<int > (vStaMap.count(vName));

	if (vN == 0)
	{//²»´æÔÚ vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}

	StationIndex = vStaMap[vName];
}
