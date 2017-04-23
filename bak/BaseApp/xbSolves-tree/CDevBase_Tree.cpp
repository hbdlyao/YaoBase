///////////////////////////////////////////////////////////
//  CDevBase_Tree.cpp
//  Implementation of the Class CDevBase_Tree
//  Created on:      21-4ÔÂ-2017 19:40:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevBase_Tree.h"


CDevBase_Tree::~CDevBase_Tree()
{

	for each (CDeviceBase * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}
	
	pChildren.clear();
}


void CDevBase_Tree::Add(CDeviceBase* vItem)
{

	pChildren.push_back(vItem);
}


void CDevBase_Tree::Remove(CDeviceBase* vItem)
{

	//children.removeElement( component );
}


bool CDevBase_Tree::IsLeaf()
{
	return false;
}


int CDevBase_Tree::ChildCount()
{

	return static_cast<int >(pChildren.size());
}


CDeviceBase * CDevBase_Tree::Child(int vIndex)
{

	return dynamic_cast<CDeviceBase * >(pChildren[vIndex]);
}


pObjVector CDevBase_Tree::Children()
{
	return pChildren;
}


void CDevBase_Tree::ClearNodeID()
{

	for each (CDeviceBase * vDev in pChildren)
	{
		vDev->ClearNodeID();	
	}
}


void CDevBase_Tree::NodeSort(NodeMap& vNodeMap)
{

	for each (CDeviceBase * vDev in pChildren)
	{
		vDev->NodeSort(vNodeMap);
	
	}
}


void CDevBase_Tree::NodeGround(NodeMap& vNodeMap)
{

	for each (CDeviceBase * vDev in pChildren)
	{
		vDev->NodeGround(vNodeMap);	
	}
}

void CDevBase_Tree::NodeID(NodeMap& vNodeID)
{
	for each (CDeviceBase * vDev in pChildren)
	{
		vDev->NodeID(vNodeID);	
	}
}