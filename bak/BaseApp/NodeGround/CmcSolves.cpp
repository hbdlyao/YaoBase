///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3月-2017 17:29:56
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolves.h"
#include "gbHead_mcCal.h"
#include "CHvdcFunc.h"
#include "CHvdcParams.h"

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


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Run
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.doInit_XVect()移到doSovleDcNet()里面
// 改动时间:  2017/04/17
//************************************
void CmcSolves::Run()
{
	doPrepare();

	while (true)
	{
		doSovleDcNet();

		doCalStation();

		break;//测试用，正常时应设置退出条件
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


int CmcSolves::StaCount()
{
	//应该从工程属性中读取
	return CHvdcParams::mcStationCount;

}

void CmcSolves::StationSort()
{
	StationMap vStaMap;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//变电站编号
		vPair.second->StationSort(vStaMap);
	}//

	int vK, vN;

	vK = static_cast<int>(vStaMap.size());
	vN= StaCount();

	pmcProfile->SetDim(vN, vK, vN - vK);

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
// 改动内容:  1.加入doInit_XVect()流程
//            2.
// 改动时间:  2017/04/17
//************************************
void CmcSolves::doSovleDcNet()
{
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
}

double CmcSolves::doGetMaxdX()
{
	return pmcProfile->GetMaxdX();
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

/*
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

*/

void CmcSolves::doCalStation()
{

}

void CmcSolvesNormal::Run()
{

	doPrepare();

	doInit_XVect();

	doSovleDcNet();

	doCalStation();

}

void CmcSolvesNormal::doCalStation()
{
	pmcProfile->CalStation();


	//重要：崔康生：之所以这样写为了体现在普通任意工况中按照站调节分接头(同站mc_Convertor和mc_Xf2相互调节)
	for each (pPowerCal_Pair vPair in pItems)
	{
		if (vPair.second->SelfType == mc_Convertor)
		{
			CmcCalConvertor * vCon = dynamic_cast<CmcCalConvertor*>(vPair.second);
			for each (pPowerCal_Pair vPair in pItems)
			{
				if (vPair.second->SelfType == mc_Xf2 && vPair.second->StationIndex == vCon->StationIndex)
				{
					CmcCalXf2 * vXf2 = dynamic_cast<CmcCalXf2*>(vPair.second);
					vCon->CalConvertor_DC();
					vXf2->CalXf2_Port();
					break;
				}
			}
		}
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

//
//void CmcSolvesNormal::doCalConvertor()
//{
//	for each (pPowerCal_Pair vPair in pItems)
//	{
//		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
//		vCal->CalConvertorNormal();
//	}
//}
//
//
//void CmcSolvesNormal::doCalTap()
//{
//
//	for each (pPowerCal_Pair vPair in pItems)
//	{
//		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
//		vCal->CalTapNormal();
//	}
//}
