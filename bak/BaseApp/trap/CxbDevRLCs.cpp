///////////////////////////////////////////////////////////
//  CxbDevRLCs.cpp
//  Implementation of the Class CxbDevRLCs
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevRLCs.h"

CxbDevRLCs::~CxbDevRLCs()
{

	for each (CxbDevRLCs * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}

void CxbDevRLCs::Add(CxbDevBase * vItem)
{

	pChildren.push_back(vItem);
}


void CxbDevRLCs::Remove(CxbDevBase * vItem)
{

	//children.removeElement( component );

}

int CxbDevRLCs::ChildCount()
{
	return static_cast<int >(pChildren.size());

}

CDeviceBase * CxbDevRLCs::Child(int vIndex)
{

	return dynamic_cast<CDeviceBase * >(pChildren[vIndex]);


}



void CxbDevRLCs::ClearNodeID()
{

	for each (CObjBase * vDev in pChildren)
	{
		
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->ClearNodeID();

	}

}


void CxbDevRLCs::NodeSort(NodeMap& vNodeMap)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeSort(vNodeMap);

	}

}

void CxbDevRLCs::NodeGround(NodeMap & vNodeMap)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeGround(vNodeMap);

	}
}


void CxbDevRLCs::NodeID(NodeMap& vNodeID)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeID(vNodeID);

	}

}
