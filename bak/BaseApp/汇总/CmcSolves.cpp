///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3月-2017 17:29:56
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolves.h"
#include "gbHead_mcCal.h"
#include "CHvdcFunc.h"


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
	
		doNewItem(mc_AcSys   );
	
		doNewItem(mc_AcF     );
	
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


void CmcSolves::doNewItem(int vtblType)
{
	CPowerSolves::doNewItem(vtblType);
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
	vCal->DevIndex = vIndex;
	//
	vCal->Init(vDev);
	vCal->Init(pmcProfile, pmcHvdc);

	pItems[vName] = vCal;

}



void CmcSolves::Run()
{
	doPrepare();

	doInit_XVect();

	while (true)
	{
		doSovleDcNet();

		doCalConvertor();

		doCalTap();

		break;//测试
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

void CmcSolves::doPrepare()
{
	//
	for each (pPowerCal_Pair vPair in pItems)
	{
		vPair.second->Prepare();
	}

}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doInit_XVect
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.改为调用每个Cal设定初值，具体初值由CalConvertor给出
// 改动时间:  2017/04/14
//************************************
void CmcSolves::doInit_XVect()
{
	//给定迭代初值；
	//pmcProfile->Init_XVect();

	//对每一个CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->InitX();
	}

}


void CmcSolves::doSovleDcNet()
{

	//形成Y
	doUpdateY();
	
	//用NL法求解直流网络
	while (true)
	{
		doUpdateJ();
		
		////
		doUpdateF_Y();//和节点导纳对应的部分
		//
		doUpdateF_J();//和换流器对应的部分
		//
		doSolve_dX();
		//
		doUpdateX();
	
		break;
	}//while
}


void CmcSolves::doSolve_dX()
{

	pmcProfile->Solve_dX();
	//
	//pmcProfile->UpdateX();
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

void CmcSolves::doUpdateJ(){

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


void CmcSolves::doCalConvertor()
{
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalConvertor();
	}
}



void CmcSolves::doCalTap()
{

	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalTap();
	}
}


void CmcSolvesNormal::Run(CmcProfile* vProfile)
{
	pmcProfile = vProfile;

	doPrepare();

	doInit_XVect();

	doSovleDcNet();
	
	doCalConvertor();

}


void CmcSolvesNormal::doCalConvertor()
{
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalConvertorNormal();
	}
}


void CmcSolvesNormal::doCalTap()
{

	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->CalTapNormal();
	}
}

/*
//崔康生
void CmcSolvesNormal::doPrepare()
{
struct_mcStationData* tem = pmcProfile->pmcStaData;
pmcProfile->pmcStaData = pmcProfile->pmcStaDataN;

CmcSolves::doPrepare();

pmcProfile->pmcStaDataN = pmcProfile->pmcStaData;
pmcProfile->pmcStaData = tem;
}
*/