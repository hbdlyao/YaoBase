///////////////////////////////////////////////////////////
//  CPowerCalculate.cpp
//  Implementation of the Class CPowerCalculate
//  Created on:      09-4月-2017 21:38:18
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerCalculate.h"


void CPowerCalculate::Init(CDeviceBase * vDev)
{
	pDevice = vDev;
}

void CPowerCalculate::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;

	//pGrid = vGrid;

}

void CPowerCalculate::Prepare()
{

}


void CPowerCalculate::NodeGround(NodeMap& vNodeMap)
{

}


void CPowerCalculate::NodeSort(NodeMap& vNodeMap)
{
	int i, vN,vID,vdotCount;
	string vName;
	
	vdotCount = pDevice->GetDotCount();	
	for (i = 0; i < vdotCount; i++)
	{
		vName = pDevice->GetNodeName(i);
		vN = static_cast<int > (vNodeMap.count(vName));
	
		if (vN == 0)
		{//不存在 vName
			vID = static_cast<int> (vNodeMap.size());
			vNodeMap[vName] = vID;
		}
	
	}//for i
	
}


void CPowerCalculate::NodeID(NodeMap& vNodeID)
{
	int i, vID,vdotCount;
	string vName;
		
	vdotCount = pDevice->GetDotCount();
	for (i = 0; i < vdotCount; i++)
	{
		vName = pDevice->GetNodeName(i);
		vID = vNodeID[vName];
	
		pDevice->SetNodeID(i,vID);
	
	}//for i
	
}


void CPowerCalculate::StationSort(StationMap& vStaMap)
{
	int vN, vID;
	string vName;

	vName = pDevice->GetStationName();
	vN = static_cast<int > (vStaMap.count(vName));

	if (vN == 0)
	{//不存在 vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}

	StationIndex = vStaMap[vName];
}