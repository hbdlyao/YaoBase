///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3月-2017 17:29:56
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolves.h"
#include "gbHead_mcCal.h"
#include "CHvdcFunc.h"
#include <iostream>

#include "time.h"
#include <exception>


string CmcSolves::TypeToName(int vType)
{
	string vName;
	vName = CHvdcFunc::mcTypeToName(vType);

	return vName;
}


void CmcSolves::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}


void CmcSolves::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case mc_Ground10:
		doNewMcSolvers10(); //单极大地
		break;

	case mc_Ground11:
		doNewMcSolvers11();//单极金属回线
		break;

	case mc_Ground20:
		doNewMcSolvers20();//双极中性点
		break;

	case mc_Ground21:
		doNewMcSolvers21();//双极并联大地
		break;

	default:
		break;
	}//switch
}

void CmcSolves::doNewMcSolvers10()
{
	//单极大地

	doNewItem(mc_AcSys);

	doNewItem(mc_AcF);

	doNewItem(mc_Xf2);

	doNewItem(mc_Convertor);

	doNewItem(mc_DcLine);

	doNewItem(mc_GroundLine);

	//doNewItem(mc_Ground);

	//doNewItem(mc_MetalLine);
}


void CmcSolves::doNewMcSolvers11()
{

	//单极金属回线

	doNewItem(mc_AcSys);

	doNewItem(mc_AcF);

	doNewItem(mc_Xf2);

	doNewItem(mc_Convertor);

	doNewItem(mc_DcLine);

	//doNewItem(mc_GroundLine);

	//doNewItem(mc_Ground);

	doNewItem(mc_MetalLine);
}


void CmcSolves::doNewMcSolvers20()
{
	//双极中性点

	doNewItem(mc_AcSys);

	doNewItem(mc_AcF);

	doNewItem(mc_Xf2);

	doNewItem(mc_Convertor);

	doNewItem(mc_DcLine);


	//doNewItem(mc_GroundLine);

	//doNewItem(mc_Ground);

	//doNewItem(mc_MetalLine);

}


void CmcSolves::doNewMcSolvers21()
{
	//双极并联

	doNewItem(mc_AcSys);

	doNewItem(mc_AcF);

	doNewItem(mc_Xf2);

	doNewItem(mc_Convertor);

	doNewItem(mc_DcLine);

	doNewItem(mc_GroundLine);

	//doNewItem(mc_Ground);

	//doNewItem(mc_MetalLine);
}



void CmcSolves::doNewCal(CDeviceBase * vDev, int vIndex)
{
	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();
	switch (vType)
	{
	case mc_AcSys:
		//交流系统  
		vCal = new  CmcCalAcSys();
		break;

	case mc_AcF:
		//交流滤波器
		vCal = new  CmcCalAcFilter();
		break;

	case mc_Xf2:
		//双绕组变压器  
		vCal = new  CmcCalXf2();
		break;

	case mc_Convertor:
		//换流器  
		vCal = new  CmcCalConvertor();
		break;

	case mc_DcLine:
		//直流极线  
		vCal = new  CmcCalDcLine();
		break;

	case mc_GroundLine:
		//接地极线  
		vCal = new  CmcCalGroundLine();
		break;

	case mc_MetalLine:
		//金属回线  
		vCal = new  CmcCalMetalLine();
		break;

	case mc_Ground:
		//接地极  
		vCal = new  CmcCalGround();
		break;

	default:
		vCal = new  CmcCalculate();
		break;

	}//switch


	 //
	vName = vDev->GetDeviceName();
	vCal->SelfID = vName;
	vCal->SelfType = vType;
	vCal->DevType = vType;
	
	//
	vCal->Init(vDev);
	vCal->Init(pmcProfile);

	pItems[vName] = vCal;

	//
	cout << "doNewCal---" << CHvdcFunc::mcTypeToName(vType) << "  " << vName << endl;


}

void CmcSolves::Run()//++--
{
	doPrepare();

	pmcProfile->LimitOK = true;

	doUpdateUdio();

	while (true)
	{
		doSovleDcNet();

		doLimitUd();

		if (pmcProfile->LimitOK)
			doCalStation();

		if (pmcProfile->LimitOK)
			break;
	}

}
void CmcSolves::doUpdateUdio()//++--
{
	pmcProfile->UpdateUdio();
}

void CmcSolves::doLimitUd()//++--
{
	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->LimitUd();
		if (!pmcProfile->LimitOK)
			break;
	}
}

void CmcSolves::PrepareNormal()
{
	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->PrepareNormal();
	}
}

void CmcSolves::RecordMeasureNode()
{//
	CmcCalConvertor * vCalself;
	CmcCalConvertor * vCalmmr;
	for each (pPowerCal_Pair vPairself in pItems)
	{
		if (vPairself.second->SelfType == mc_Convertor)
		{
			vCalself = dynamic_cast<CmcCalConvertor*>(vPairself.second);
			for each (pPowerCal_Pair vPairmr in pItems)
			{
				if (vPairmr.second->SelfType == mc_Convertor&&vCalself->MeasureStationIndex == vPairmr.second->StationIndex)
				{
					vCalmmr = dynamic_cast<CmcCalConvertor*>(vPairmr.second);
					vCalself->RecordMeasureNode(*vCalmmr);
				}
			}
		}
	}
}


void CmcSolves::doPrepare()
{
	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}

}


void CmcSolves::doInit_XVect()
{
	//给定迭代初值；
	srand((unsigned int)time(0));
	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->InitX();
	}

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doSovleDcNet
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.加入doOffsetSort流程
//			  2.加入doSaveX流程
// 改动时间:  2017/04/20
//************************************
void CmcSolves::doSovleDcNet()
{
	doOffsetSort();

	doInit_XVect();

	//形成Y
	doUpdateY();

	//用NL法求解直流网络
	while (true)
	{
		doUpdateJ();
		//
		doUpdateF_Y();//和节点导纳对应的部分
					  //
		doUpdateF_J();//和换流器对应的部分
					  //
		doSolve_dX();
		//
		doUpdateX();

		if (doGetMaxdX() < Epsilon)
			break;
	}//while
	doSaveX();
}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doOffsetSort
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.调用各个Cal对Offset编号
// 改动时间:  2017/04/20
//************************************
void CmcSolves::doOffsetSort()
{
	int offset = 0;
	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->OffsetSort(offset);
	}
	pmcProfile->ResetMatrix(offset);
}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doSaveX
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.保存doSovleDcNet的计算结果
// 改动时间:  2017/04/20
//************************************
void CmcSolves::doSaveX()
{
	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->SaveX();
	}
}
double CmcSolves::doGetMaxdX()
{
	return pmcProfile->GetMaxdX();
}

void CmcSolves::doSolve_dX()
{
	pmcProfile->Solve_dX();
}


void CmcSolves::doUpdateF_Y()
{

	pmcProfile->UpdateF_Y();

}

void CmcSolves::doUpdateF_J()
{
	//CmcCalclulate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->UpdateF_J();
	}
}

void CmcSolves::doUpdateJ() {

	//CmcCalclulate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->UpdateJ();
	}
}


void CmcSolves::doUpdateY()
{
	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->UpdateY();
	}
}


void CmcSolves::doUpdateX()
{
	//
	pmcProfile->UpdateX();
}

void CmcSolves::doCalStation()//++--
{
	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalStation();
		if (!pmcProfile->LimitOK)
		{
			if (pmcProfile->URefStation != -1)
				for each (pPowerCal_Pair vConPair in pItems)
				{
					CmcCalConvertor * vCon = dynamic_cast<CmcCalConvertor*>(vConPair.second);
					vCon->SetUdStation();
				}
			break;
		}
	}
}

void CmcSolvesNormal::Run()
{

	doPrepare();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doInit_XVect
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.
	// 改动时间:  2017/04/20
	//************************************
	//doInit_XVect();
	//

	doSovleDcNet();

	doCalStation();

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doCalStation
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.按站计算不在这里体现
// 改动时间:  2017/04/21
//************************************
void CmcSolvesNormal::doCalStation()
{
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalStation_N();
	}

	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalACSide();
	}
}

void CmcSolvesNormal::doSaveNorml()
{
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->SaveNormal();
	}
}