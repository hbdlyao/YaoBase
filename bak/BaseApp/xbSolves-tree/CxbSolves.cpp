///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      21-4月-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbSolves.h"

#include "CxbDevBase.h"
#include "CxbDev_Tree.h"


int CxbSolves::GroundType()
{
	return pxbProfile->pxbOrder->GroundType;
}


void CxbSolves::Init(CxbProfile* vProfile, CxbHvdcGrid * vGrid)
{

	pProfile = vProfile;
	pHvdc = vGrid;

	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

}

void CxbSolves::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case xb_Ground10:
		doNewXbSolvers10(); //单极大地
		break;
	
	case xb_Ground11:
		doNewXbSolvers11();//单极金属回线
		break;
	
	case xb_Ground20:
		doNewXbSolvers20();//双极中性点
		break;
	
	case xb_Ground21:
		doNewXbSolvers21();//双极并联大地
		break;
	
	default:
		break;
	}//switch
}


void CxbSolves::doNewXbSolvers10()
{

	//to-do,马俊鹏
	
	//单极大地	
	doNewItem(xb_3pVSrc);
	
	doNewItem(xb_PbDKQ);
	
	doNewItem(xb_DCF);
	
	doNewItem(xb_DcLine);
	doNewItem(xb_GroundLine);
	doNewItem(xb_Ground);
	//doNewItem(xb_MetalLine);
	
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	
	
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);
	
	doNewItem(xb_Trap);
	doNewItem(xb_Monitor);
}


void CxbSolves::doNewXbSolvers11()
{

	//to-do,马俊鹏
	
	//单极金属回线	
	doNewItem(xb_3pVSrc);
	
	doNewItem(xb_PbDKQ);
	
	doNewItem(xb_DCF);
	
	doNewItem(xb_DcLine);
	//doNewItem(xb_GroundLine);
	//doNewItem(xb_Ground);
	doNewItem(xb_MetalLine);
	
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);
	
	doNewItem(xb_Trap);
	doNewItem(xb_Monitor);
}


void CxbSolves::doNewXbSolvers20()
{

	//to-do,马俊鹏
	
	//双极中性点	
	doNewItem(xb_3pVSrc);
	
	doNewItem(xb_PbDKQ);
	
	doNewItem(xb_DCF);
	
	doNewItem(xb_DcLine);
	//doNewItem(xb_GroundLine);
	//doNewItem(xb_Ground);
	//doNewItem(xb_MetalLine);
	
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	
	
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);
	
	
	doNewItem(xb_Trap);
	doNewItem(xb_Monitor);
}


void CxbSolves::doNewXbSolvers21()
{

	//to-do,马俊鹏
	
	//双极并联
	doNewItem(xb_3pVSrc);
	
	doNewItem(xb_PbDKQ);
	
	doNewItem(xb_DCF);
	
	doNewItem(xb_DcLine);
	doNewItem(xb_GroundLine);
	doNewItem(xb_Ground);
	//doNewItem(xb_MetalLine);
	
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	
	
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);
	
	
	doNewItem(xb_Trap);
	doNewItem(xb_Monitor);
}


void CxbSolves::doSovle()
{
	//形成Y
	UpdateY();	
	//
	UpdateI();
	//
	//SolveU();

}


void CxbSolves::SolveU()
{
	pxbProfile->Solve();
}


void CxbSolves::NewSolves()
{
	//
	for each (pDevTBL_Pair  vPair in  pHvdc->GetDevTBLs())
	{
		doNewItem(vPair.second);
	}//pDevTBL_Pair
}


void CxbSolves::doNewItem(int vtblType)
{

	CDeviceTBL * vTBL;
	
	vTBL = pHvdc->DeviceTBL(vtblType);
	
	doNewItem( vTBL);
}


void CxbSolves::doNewItem(CDeviceTBL* vTBL)
{

	for each (CxbDevBase *  vDev in  vTBL->ItemVect())
	{
		if ((vDev->GetPosOrNeg()) == xb_Pos) //正极设备
			NewCal_Tree(vDev);


		if ((vDev->GetPosOrNeg()) == xb_Neg) //负极设备
			switch (GroundType())
			{
			case xb_Ground20: //双极中性点
			case xb_Ground21: //双极并联
				NewCal_Tree(vDev);

				break;

			default:
				break;
			}
	}
}


void CxbSolves::StationSort()
{

	StationMap vStaMap;

	//doStationSort(vStaMap);

	//Children
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//

	pProfile->StaCount = static_cast<int>(vStaMap.size());
}




void CxbSolves::Run()
{
	//
	Prepare();
	
	//
	doSovle();

}


void CxbSolves::NodeID()
{

	int vK = 0;
	
	NodeMap vNodeID, vNodeMap;
	
	//
	pHvdc->ClearNodeID();
	

	for each (CxbCalculate * vCal in pChildren)
	{
		//给所有节点编号，包括接地的节点
		vCal->NodeSort(vNodeMap);
	}//
	
	 //
	for each (CxbCalculate * vCal in pChildren)
	{	
		//将接地的节点的编号置为-1，表示接地
		vCal->NodeGround(vNodeMap);
	}//
	
	
	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//划去接地节点
		if (vPair.second != -1)
		{
			vNodeID[vPair.first] = vK;
	
			vK = vK + 1;
		}
		else
			vNodeID[vPair.first] = -1;
	
	}// for each
	
	 //
	pProfile->NodeCount = vK;
	pHvdc->NodeCount = vK;
	
	for each (CxbCalculate * vCal in pChildren)
	{
		//给定节点编号
		vCal->NodeID(vNodeID);
	}//
}