///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      05-4月-2017 18:22:30
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolves.h"
#include "CHvdcFunc.h"

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
	int vN;

	vN = pxbHvdc->StaCount();//to-do

	pxbProfile->StationNum = vN;
	//pxbProfile->pmcResult->StaDim = vN;

	//
	pxbProfile->InitMatrix(vN);

	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}


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
	//单极大地	
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
	//单极金属回线	
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
	//双极中性点	
	doNewItem(xb_3pVSrc);
	doNewItem(xb_xf2);
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
	//双极并联

	doNewItem(xb_3pVSrc);

	doNewItem(xb_xf2);

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

		//case xb_Trap:
		//	vCal = new CxbCalTrap();
		//	break;

		//case xb_Jkzz:
		//	vCal = new CxbCalJkzz();
		//	break;

	case xb_Shunt:
		vCal = new CxbCalShunt();
		break;

	case xb_Branch:
		vCal = new CxbCalBranch();
		break;

		//case xb_Branch3:
		//	vCal = new CxbCalBranch3();
		//	break;

	default:
		break;

	}//switch
	
	vName = vDev->GetDeviceName();//to-do
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
	//形成Y
	doUpdateY();	
	//
	doUpdateI();
	//
	doSolveU();

}


void CxbSolves::doUpdateY()
{

	//对每一个CxbCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CxbCalculate * vCal = dynamic_cast<CxbCalculate*>(vPair.second);

		vCal->UpdateY();
	}
}


void CxbSolves::doUpdateI()
{
	//对每一个CxbCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CxbCalculate * vCal = dynamic_cast<CxbCalculate*>(vPair.second);

		vCal->UpdateI();
	}
}



void CxbSolves::doSolveU()
{
	//马俊鹏

	pxbProfile->Solve();

}

