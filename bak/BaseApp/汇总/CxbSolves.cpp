///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      05-4��-2017 18:22:30
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolves.h"
#include "CHvdcFunc.h"
#include "CxbDevBase.h"

#include "gbHead_xbCal.h"

string CxbSolves::TypeToName(int vType)
{

	string vName;
	vName = CHvdcFunc::xbTypeToName(vType);
	
	return vName;
}


void CxbSolves::Init(CPowerProfile* vProfile, CPowerGrid* vGrid)
{

	pProfile = vProfile;
	pGrid = vGrid;

	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);
	pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);

}

void CxbSolves::doPrepare()
{
	//
	pxbProfile->ReSetData();

	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}


}


void CxbSolves::NewSolves(int vGndType)
{
	GroundType = vGndType;
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
	//�������	
	doNewItem(xb_3pVSrc);
	doNewItem(xb_PbDKQ);
	doNewItem(xb_DcF);
	doNewItem(xb_DcLine);
	doNewItem(xb_GroundLine);
	//doNewItem(xb_Ground);
	//doNewItem(xb_MetalLine);
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);

}


void CxbSolves::doNewXbSolvers11()
{
	//������������	
	doNewItem(xb_3pVSrc);
	doNewItem(xb_PbDKQ);
	doNewItem(xb_DcF);
	doNewItem(xb_DcLine);
	//doNewItem(xb_GroundLine);
	//doNewItem(xb_Ground);
	doNewItem(xb_MetalLine);
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);

}


void CxbSolves::doNewXbSolvers20()
{
	//˫�����Ե�	
	doNewItem(xb_3pVSrc);

	doNewItem(xb_PbDKQ);
	doNewItem(xb_DcF);
	doNewItem(xb_DcLine);
	//doNewItem(xb_Ground);
	//doNewItem(xb_GroundLine);
	//doNewItem(xb_MetalLine);
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);
}


void CxbSolves::doNewXbSolvers21()
{
	//˫������

	doNewItem(xb_3pVSrc);

	doNewItem(xb_PbDKQ);
	doNewItem(xb_DcF);
	doNewItem(xb_DcLine);
	//doNewItem(xb_GroundLine);
	//doNewItem(xb_Ground);
	//doNewItem(xb_MetalLine);
	doNewItem(xb_XfC);
	doNewItem(xb_CoupleC);
	doNewItem(xb_PulseC);
	doNewItem(xb_Shunt);
	doNewItem(xb_Branch);

}


void CxbSolves::doNewItem(int vtblType)
{
	int vIndex;
	CDeviceTBL * vTBL;
	CxbDevBase * vDev;

	vIndex = 0;
	vTBL = pGrid->DeviceTBL(vtblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevBase *>(vPair.second);

		if ((vDev->GetPosOrNeg())==1) //�����豸
			doNewCal(vDev, vIndex);
		
		if ((vDev->GetPosOrNeg()) == 2) //�����豸
			switch (GroundType)
			{
			case xb_Ground20: //˫�����Ե�
			case xb_Ground21: //˫������
				doNewCal(vDev, vIndex);
				break;

			default:
				break;
			}

		vIndex = vIndex + 1;

	}//pObj_Pair

}


void CxbSolves::doNewCal(CDeviceBase * vDev, int vIndex)
{
	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();

	switch (vType)
	{
	case xb_3pVSrc:
		vCal = new CxbCal3pVSrc();
		break;

	case xb_PbDKQ:
		vCal = new CxbCalPbDkq();
		break;

	case xb_DcF:
		vCal = new CxbCalDCF();
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


	default:
		break;

	}//switch
	
	vName = vDev->GetDeviceID();//to-do
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;
	vCal->DevIndex = vIndex;
	//
	vCal->Init(vDev);
	vCal->Init(pxbProfile, pxbHvdc);

	pItems[vName] = vCal;

}

void CxbSolves::Run()
{
	//
	doPrepare();

	//
	doSovle();
}

void CxbSolves::doSovle()
{
	//�γ�Y
	doUpdateY();	
	//
	doUpdateI();
	//
	doSolveU();

}


void CxbSolves::doUpdateY()
{

	//��ÿһ��CxbCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CxbCalculate * vCal = dynamic_cast<CxbCalculate*>(vPair.second);

		vCal->UpdateY();
	}
}


void CxbSolves::doUpdateI()
{
	//��ÿһ��CxbCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CxbCalculate * vCal = dynamic_cast<CxbCalculate*>(vPair.second);

		vCal->UpdateI();
	}
}



void CxbSolves::doSolveU()
{
	//����

	pxbProfile->Solve();

}

