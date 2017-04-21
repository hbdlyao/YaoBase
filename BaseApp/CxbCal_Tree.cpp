///////////////////////////////////////////////////////////
//  CxbCal_Tree.cpp
//  Implementation of the Class CxbCal_Tree
//  Created on:      21-4月-2017 20:03:35
///////////////////////////////////////////////////////////

#include "CxbCal_Tree.h"
#include "CHvdcFunc.h"
#include "CxbDevBase.h"
#include "CxbDev_Tree.h"

#include "gbHead_xbCal.h"


CxbCal_Tree::~CxbCal_Tree()
{
	for each (CxbCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}

void CxbCal_Tree::Clear()
{
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Clear();
	}

}


void CxbCal_Tree::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile);
	}
}


void CxbCal_Tree::Init(CDeviceBase* vDev)
{
	pDevice = vDev;
}


void CxbCal_Tree::Add(CxbCalculate * vItem)
{
	pChildren.push_back(vItem);
}



void CxbCal_Tree::Remove(CxbCalculate* vItem)
{

	//children.removeElement( component );
}


bool CxbCal_Tree::IsLeaf()
{
	return false;
}



int CxbCal_Tree::ChildCount()
{

	return static_cast<int >(pChildren.size());
}

CxbCalculate * CxbCal_Tree::Child(int vIndex){

	return dynamic_cast<CxbCalculate * >(pChildren[vIndex]);
}


pxbCalVector CxbCal_Tree::Children()
{

	return pChildren;
}


void CxbCal_Tree::Prepare()
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CxbCal_Tree::NodeID(NodeMap& vNodeID)
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}



void CxbCal_Tree::NodeSort(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Tree::NodeGround(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Tree::StationSort(StationMap& vStaMap)
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//
}


CxbCalculate * CxbCal_Tree::doNewCal(CDeviceBase* vDev)
{
	int vType;
	string vName;
	CxbCalculate * vCal = nullptr;
	
	vType = vDev->GetDeviceType();
	
	switch (vType)
	{
	case xb_3pVSrc:
		vCal = new CxbCal3pVSrc();
		break;
	
	case xb_PbDKQ:
		vCal = new CxbCalPbDkq();
		break;
	
	case xb_DCF:
		vCal = new CxbCalDCF();
		break;
	
	case xb_DCF_RLC:
		vCal = new CxbCalDCF_RLC();
		break;
	
	case xb_DcLine:
		vCal = new CxbCalDcLine();
		break;
	
	case xb_GroundLine:
		vCal = new CxbCalGroundLine();
		break;
	
	case xb_Ground:
		vCal = new CxbCalGround();
		break;
	
	
	case xb_MetalLine:
		vCal = new CxbCalMetalLine();
		break;
	
	case xb_XfC:
		vCal = new CxbCalXf_C();
		break;
	
	case xb_CoupleC:
		vCal = new CxbCalCouple_C();
		break;
	
	case xb_PulseC:
		vCal = new CxbCalCouple_C();
		break;
	
	case xb_Shunt:
		vCal = new CxbCalShunt();
		break;
	
	case xb_Branch:
		vCal = new CxbCalBranch();
		break;
	
	case xb_Monitor:
		vCal = new CxbCal_Tree();
		break;
	
	case xb_Trap:
		vCal = new CxbCal_Tree();
		break;
	
	
	default:
		break;
	
	}//switch
	
	vName = vDev->GetDeviceName();//to-do
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;	
	//
	vCal->Init(vDev);
	vCal->Init(pxbProfile);
	
	//
	Add(vCal);
	
	//
	cout << "doNewCal---" << CHvdcFunc::xbTypeToName(vType) << "----" << vName;
	cout << "  ChildCount  " << ChildCount() << endl;

	//
	return vCal;

}



void CxbCal_Tree::UpdateY()
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}
void CxbCal_Tree::UpdateI() 
{

	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}



void CxbCal_Tree::NewCal_Tree(CDeviceBase* vDev){

	CPowerCalculate * vCal;
	CxbDev_Tree * vNode;
	
	//
	vCal=doNewCal(vDev);
	
	//
	if (!vDev->IsLeaf())
	{
		vNode = dynamic_cast<CxbDev_Tree * >(vDev);
		for each (CDeviceBase* vDev in vNode->Children())
		{
			vCal->NewCal_Tree(vDev);
		}//for 
	
	}//else
}