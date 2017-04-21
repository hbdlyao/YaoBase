///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      21-4��-2017 20:29:55
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


void CxbSolves::doNewXbSolvers10()
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


void CxbSolves::doNewXbSolvers11()
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


void CxbSolves::doNewXbSolvers20()
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


void CxbSolves::doNewXbSolvers21()
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


void CxbSolves::doSovle()
{
	//�γ�Y
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
		//�����нڵ��ţ������ӵصĽڵ�
		vCal->NodeSort(vNodeMap);
	}//
	
	 //
	for each (CxbCalculate * vCal in pChildren)
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
	
	for each (CxbCalculate * vCal in pChildren)
	{
		//�����ڵ���
		vCal->NodeID(vNodeID);
	}//
}