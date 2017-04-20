///////////////////////////////////////////////////////////
//  CxbCal_Composite.cpp
//  Implementation of the Class CxbCal_Tree
//  Created on:      20-4��-2017 22:17:30
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

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile, vGrid);
	}
}


void CxbCal_Tree::Init(CDeviceBase* vDev){

	//PowerCalculate ��������?
	
	//��ÿһ�� CxbCalculate
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

	//��ÿһ��CxbCalculate
		for each (CxbCalculate * vCal in pChildren)
		{
	vCal->Prepare();
		}
}


void CxbCal_Tree::StationSort(StationMap& vStaMap){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}
}


void CxbCal_Tree::NodeSort(NodeMap& vNodeMap){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Tree::NodeGround(NodeMap& vNodeMap){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Tree::NodeID(NodeMap& vNodeID){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CxbCal_Tree::UpdateY(){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CxbCal_Tree::UpdateI(){

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}