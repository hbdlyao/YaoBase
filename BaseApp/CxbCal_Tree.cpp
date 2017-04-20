///////////////////////////////////////////////////////////
//  CxbCal_Composite.cpp
//  Implementation of the Class CxbCal_Tree
//  Created on:      20-4月-2017 22:17:30
///////////////////////////////////////////////////////////

#include "CxbCal_Tree.h"


CxbCal_Tree::~CxbCal_Tree(){

	for each (CxbCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}
	
	pChildren.clear();
}


void CxbCal_Tree::Init(CPowerProfile* vProfile, CPowerGrid* vGrid){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile, vGrid);
	}
}


void CxbCal_Tree::Init(CDeviceBase* vDev){

	//PowerCalculate 不能重载?
	
	//对每一个 CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vDev);
	}
}


void CxbCal_Tree::Add(CxbCalculate* vItem){

	pChildren.push_back(vItem);
}


void CxbCal_Tree::Remove(CxbCalculate* vItem){

	//children.removeElement( component );
}


bool CxbCal_Tree::IsLeaf(){

	return false;
}


void CxbCal_Tree::Prepare(){

	//对每一个CxbCalculate
		for each (CxbCalculate * vCal in pChildren)
		{
	vCal->Prepare();
		}
}


void CxbCal_Tree::StationSort(StationMap& vStaMap){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}
}


void CxbCal_Tree::NodeSort(NodeMap& vNodeMap){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Tree::NodeGround(NodeMap& vNodeMap){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Tree::NodeID(NodeMap& vNodeID){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CxbCal_Tree::UpdateY(){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CxbCal_Tree::UpdateI(){

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}