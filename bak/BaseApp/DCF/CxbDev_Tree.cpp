///////////////////////////////////////////////////////////
//  CxbDev_Tree.cpp
//  Implementation of the Class CxbDev_Tree
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev_Tree.h"

CxbDev_Tree::~CxbDev_Tree()
{

	for each (CxbDev_Tree * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}



bool CxbDev_Tree::IsLeaf()
{
	return false;
}
void CxbDev_Tree::Add(CDeviceBase * vItem)
{

	pChildren.push_back(vItem);
}


void CxbDev_Tree::Remove(CDeviceBase * vItem)
{

	//children.removeElement( component );

}

int CxbDev_Tree::ChildCount()
{
	return static_cast<int >(pChildren.size());

}

CDeviceBase * CxbDev_Tree::Child(int vIndex)
{

	return dynamic_cast<CDeviceBase * >(pChildren[vIndex]);


}

pObjVector CxbDev_Tree::Children()
{
	return pChildren;
}



void CxbDev_Tree::ClearNodeID()
{

	for each (CObjBase * vDev in pChildren)
	{
		
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->ClearNodeID();

	}

}


void CxbDev_Tree::NodeSort(NodeMap& vNodeMap)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeSort(vNodeMap);

	}

}

void CxbDev_Tree::NodeGround(NodeMap & vNodeMap)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeGround(vNodeMap);

	}
}


void CxbDev_Tree::NodeID(NodeMap& vNodeID)
{

	for each (CObjBase * vDev in pChildren)
	{
		//CDeviceBase 
		dynamic_cast<CDeviceBase *> (vDev)->NodeID(vNodeID);

	}

}
