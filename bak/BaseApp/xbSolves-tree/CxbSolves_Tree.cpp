///////////////////////////////////////////////////////////
//  CxbSolves_Tree.cpp
//  Implementation of the Class CxbSolves_Tree
//  Created on:      21-4��-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbSolves_Tree.h"

#include "CxbDevBase.h"
#include "CxbDev_Tree.h"


int CxbSolves_Tree::GroundType()
{
	return pxbProfile->pxbOrder->GroundType;
}


void CxbSolves_Tree::Init(CPowerProfile* vProfile, CxbHvdcGrid * vGrid) 
{

	pProfile = vProfile;
	pHvdc = vGrid;

	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

}

void CxbSolves_Tree::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case xb_Ground10:
		doNewXbSolvers10(); //�������
		break;
	
	case xb_Ground11:
		doNewXbSolvers11();//������������
		break;
	
	case xb_Ground20:
		doNewXbSolvers20();//˫�����Ե�
		break;
	
	case xb_Ground21:
		doNewXbSolvers21();//˫���������
		break;
	
	default:
		break;
	}//switch
}


void CxbSolves_Tree::doNewXbSolvers10()
{

	//to-do,����
	
	//�������	
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


void CxbSolves_Tree::doNewXbSolvers11()
{

	//to-do,����
	
	//������������	
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


void CxbSolves_Tree::doNewXbSolvers20()
{

	//to-do,����
	
	//˫�����Ե�	
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


void CxbSolves_Tree::doNewXbSolvers21()
{

	//to-do,����
	
	//˫������
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


void CxbSolves_Tree::doSovle()
{
	//�γ�Y
	UpdateY();	
	//
	UpdateI();
	//
	SolveU();

}


void CxbSolves_Tree::SolveU()
{
	pxbProfile->Solve();
}


void CxbSolves_Tree::NewSolves()
{
	//
	for each (pDevTBL_Pair  vPair in  pHvdc->GetDevTBLs())
	{
		doNewItem(vPair.second);
	}//pDevTBL_Pair
}


void CxbSolves_Tree::doNewItem(int vtblType)
{

	CDeviceTBL * vTBL;
	
	vTBL = pHvdc->DeviceTBL(vtblType);
	
	doNewItem( vTBL);
}


void CxbSolves_Tree::doNewItem(CDeviceTBL* vTBL)
{

	for each (CxbDevBase *  vDev in  vTBL->ItemVect())
	{
		if ((vDev->GetPosOrNeg()) == xb_Pos) //�����豸
			NewCal_Tree(vDev);


		if ((vDev->GetPosOrNeg()) == xb_Neg) //�����豸
			switch (GroundType())
			{
			case xb_Ground20: //˫�����Ե�
			case xb_Ground21: //˫������
				NewCal_Tree(vDev);

				break;

			default:
				break;
			}
	}
}


void CxbSolves_Tree::StationSort()
{

	StationMap vStaMap;

	//doStationSort(vStaMap);

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//

	pProfile->StaCount = static_cast<int>(vStaMap.size());
}




void CxbSolves_Tree::Run()
{
	//
	Prepare();
	
	//
	doSovle();

}


void CxbSolves_Tree::NodeID()
{

	int vK = 0;
	
	NodeMap vNodeID, vNodeMap;
	
	//
	pHvdc->ClearNodeID();
	

	for each (CPowerCalculate * vCal in pChildren)
	{
		//�����нڵ��ţ������ӵصĽڵ�
		vCal->NodeSort(vNodeMap);
	}//
	
	 //
	for each (CPowerCalculate * vCal in pChildren)
	{	
		//���ӵصĽڵ�ı����Ϊ-1����ʾ�ӵ�
		vCal->NodeGround(vNodeMap);
	}//
	
	
	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//��ȥ�ӵؽڵ�
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
	
	for each (CPowerCalculate * vCal in pChildren)
	{
		//�����ڵ���
		vCal->NodeID(vNodeID);
	}//
}