///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      05-4月-2017 18:22:30
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolves.h"
#include "CHvdcFunc.h"
#include "CxbDevBase.h"
#include "CxbDevRLCs.h"

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

void CxbSolves::NewSolves(int vGndType)
{
	GroundType = vGndType;
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


void CxbSolves::doNewItem(int vtblType)
{
	CPowerSolves::doNewItem(vtblType);
}

void CxbSolves::doNewItem(CDeviceTBL * vTBL)
{
	int vIndex;
	CxbDevBase * vDev;

	vIndex = 0;
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevBase *>(vPair.second);

		if ((vDev->GetPosOrNeg()) == xb_Pos) //正极设备
			if (vDev->IsLeaf())
				doNewCal(vDev, vIndex);
			else
				doNewCal_Tree(vDev, vIndex);


		if ((vDev->GetPosOrNeg()) == xb_Neg) //负极设备
			switch (GroundType)
			{
			case xb_Ground20: //双极中性点
			case xb_Ground21: //双极并联
				if (vDev->IsLeaf())
					doNewCal(vDev, vIndex);
				else
					doNewCal_Tree(vDev,vIndex);

				break;

			default:
				break;
			}

		vIndex = vIndex + 1;

	}//pObj_Pair

}

void CxbSolves::doNewCal_Tree(CDeviceBase * vDev,int vIndex)
{
	int i,vN;

	CDeviceBase * vChild;
	CxbDevRLCs * vRLCs;

	if (vDev->IsLeaf())
	{
		doNewCal(vDev, vIndex);
	}
	else
	{
		vRLCs = dynamic_cast<CxbDevRLCs *> (vDev);
		vN = vRLCs->ChildCount();
		for (i = 0; i<vN; i++)
		{
			vChild = vRLCs->Child(i);
			doNewCal_Tree(vChild,vIndex);
		}//for
	}//else
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

	case xb_DCF:
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

		/*
	case xb_Branch:
		vCal = new CxbCalBranch();
		break;
		*/

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

	//
	pItems[vName] = vCal;

	//
	cout << "doNewCal---" << CHvdcFunc::xbTypeToName(vType) << "  "<< vName << endl;

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
	//doUpdateI();
	//
	//doSolveU();

}


void CxbSolves::doPrepare()
{
	//
	//pxbProfile->ReSetData();

	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}


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

