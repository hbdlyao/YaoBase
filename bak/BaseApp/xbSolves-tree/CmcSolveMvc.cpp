///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      13-4月-2017 13:56:17
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolveMvc.h"

#include "CmcRwOrderMvc.h"

#include "CMyParams.h"
#include "CHvdcParams.h"
#include "CmcDevConvertor.h"

#include <iostream>

using namespace std;


CmcSolveMvc::~CmcSolveMvc()
{
	pmcResult->Clear();

	delete pmcResult;
	pmcResult = nullptr;

}

void CmcSolveMvc::Clear()
{
	CPowerSolveMvc::Clear();

	pmcResult->Clear();

}


void CmcSolveMvc::Init()
{
	pSolves = new CmcSolves();
	pmcSolves= dynamic_cast<CmcSolves *> (pSolves);
	
	//
	pProfile = new CmcProfile();
	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);

	pmcProfile->Init();

	//
	pmcResult = new CmcResult();
	pmcResult->Init();

}


void CmcSolveMvc::Init(CPowerGrid* vGrid)
{
	pGrid = vGrid;
	pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

	//
	pmcSolves->Init(pmcProfile, pmcHvdc);

}

void CmcSolveMvc::InitOrder()
{

	CmcRwOrderMvc vRwMvc;

	vRwMvc.InitAdo(CMyParams::dbf_mdb);
	vRwMvc.Init(pmcProfile->pmcOrder);

	vRwMvc.OnLoad();

	
}


void CmcSolveMvc::NodeID(int vGNDType)
{

	pmcProfile->pmcOrder->GroundType = vGNDType;
	
	//
	pmcSolves->Init(pmcProfile, pmcHvdc);
	//
	doNewSolves(vGNDType);
	
	//节点编号
	doNodeID();
}


void CmcSolveMvc::doNewSolves(int vGNDType)
{
	pmcSolves->Clear();
	pmcSolves->NewSolves(vGNDType);
}


int CmcSolveMvc::StaCount() 
{
	//应该从工程属性中读取
	return CHvdcParams::mcStationCount;

}
/**
 * 南方电网主回路及谐波计算软件* 改动对象:  Run 改动者:    崔康生 改动类型:  修改 改动内容:  1.
 * 修改方法功能的定义：用于求解Order中所有工况 2.取消入参int vGNDType 改动时间:  2017/04/12
 */
void CmcSolveMvc::Run()
{//多工况运行
	
	doInitRun();
	
	//
	doRun_Ground(pmcProfile->pmcOrder->Flag_Ground);
	
}

void CmcSolveMvc::doInitRun()
{
	//
	pmcSolves->Init(pmcProfile, pmcHvdc);
	//
	int vStaCount = StaCount();
	pmcProfile->pmcOrder->Clear();
	pmcProfile->pmcOrder->InitMatrix(vStaCount);

	//
	int vCaseCount = pmcProfile->pmcOrder->CaseCount();
	pmcResult->Clear();
	pmcResult->Init(vStaCount, vCaseCount, pmcProfile->pmcOrder->PdSize);

}



//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doRun_Ground
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.增加doRecordMeasureNode过程
//            2.
// 改动时间:  2017/04/17
//************************************
void CmcSolveMvc::doRun_Ground(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//单极大地/金属回线/双极/双极并联
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pmcProfile->pmcOrder->GroundType = mc_GndTypeArr[i];

			//根据接地类型生成 mcCalculate,与设备一一对应
			doNewSolves(mc_GndTypeArr[i]);

			//节点编号
			doNodeID();

			//换流站排序
			doStationSort();

			//记录各站测量点的节点编号
			doRecordMeasureNode();

			//初始化计算用矩阵
			doInitMatrix();

			//给定额定值
			doPrepareNormal();

			//
			doRun_Rd(pmcProfile->pmcOrder->Flag_Rd);

		}//if

	}//for 
}
void CmcSolveMvc::doRecordMeasureNode()
{
	pmcSolves->RecordMeasureNode();
}


void CmcSolveMvc::doInitMatrix()
{
	int vN;

	vN = StaCount();

	//
	pmcProfile->InitMatrix(vN);

}


void CmcSolveMvc::doPrepareNormal()
{
	pmcSolves->PrepareNormal();
}

void CmcSolveMvc::doRun_Rd(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//高阻、低阻
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1') //
		{
			pmcProfile->pmcOrder->RdLevel = mc_RdLevelArr[i];
			
			//
			if (pmcProfile->pmcOrder->IsUdCustom) //指定Ud
				doRun_UdCustom();
			else
				doRun_Ud(pmcProfile->pmcOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void CmcSolveMvc::doRun_Ud(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//全压/80%/70%
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1')
		{
			pmcProfile->pmcOrder->UdLevel = mc_UdLevelArr[i];

			if (pmcProfile->pmcOrder->IsUacSwap)
				doRun_UacSwap(pmcProfile->pmcOrder->Flag_Uac, 0 ,vStaCount);
			else
				doRun_Uac(pmcProfile->pmcOrder->Flag_Uac);

		}//if

	}//for 
}

void CmcSolveMvc::doRun_UdCustom()
{
	int vStaCount = StaCount();

	pmcProfile->pmcOrder->UdLevel = Ud_Custom;

	//Ud处理
	//崔康生......

	//
	if (pmcProfile->pmcOrder->IsUacSwap)
		doRun_UacSwap(pmcProfile->pmcOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pmcProfile->pmcOrder->Flag_Uac);

}

void CmcSolveMvc::doRun_Uac(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//最大/额定/最小/极小
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j=0;j<vStaCount;j++)
				pmcProfile->pmcOrder->UacLevel[j] = mc_UacLevelArr[i];
			//
			doRun_Pd();
		}//if


}


void CmcSolveMvc::doRun_UacSwap(string vFlag,int vIndex, int  vStaCount)
{
	
	int vN = static_cast<int> (vFlag.size());
	
	//vIndex从0开始,当vIndex==vStaCount,说明所有的换流站都已设置Uac
	if (vIndex ==vStaCount)
		doRun_Pd();
	else
	{//最大/额定/最小/极小
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pmcProfile->pmcOrder->UacLevel[vIndex] = mc_UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex +1,vStaCount);
			}//if

	}//else

}


void CmcSolveMvc::doRun_Pd()
{
	int vPdSize;

	vPdSize = pmcProfile->pmcOrder->PdSize;

	for (int i = 0 ; i<vPdSize; i++)
	{		
		pmcProfile->pmcOrder->UpdatePdPercent(i);

		doRun();

	}//for
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doRun
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.pmcProfile->Clear()改为pmcProfile->ClearSingle()，仅Clear pmcProfile自身的变量，保留其中的Order和Result
// 改动时间:  2017/04/13
//************************************
void CmcSolveMvc::doRun()
{

	pmcProfile->ResetData();
	//
	pmcSolves->Run();

	//记录结果
	doRecordResult();
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doRecordResult
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.形式上调用pmcResult->Record();
//            2.不明白pmcResult里map的键值是什么
// 改动时间:  2017/04/18
//************************************
void CmcSolveMvc::doRecordResult()
{
	string vCaseID = pmcProfile->pmcOrder->CreateCaseID();
	pmcResult->Record(vCaseID, pmcProfile->pmcStaData, pmcProfile->pmcStaDataN);

	//测试用
	static int vN = 1;

	//pmcResult->mcResultMap[vCaseID]=

	cout << "主回路:";
	cout << vCaseID;
	cout << "%";
	cout << pmcProfile->pmcOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}



void CmcSolveMvcNormal::Init()
{

	pSolves = new CmcSolvesNormal();
	pmcSolves = dynamic_cast<CmcSolves *> (pSolves);

	//
	pProfile = new CmcProfile();
	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);

	pmcProfile->Init();

	//
	pmcResult = new CmcResult();
	pmcResult->Init();

}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Run
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.InitNormal()改为
//InitNormal(dynamic_cast<CmcDevConvertor *>(vDev->second)->GetValvor12Count())
// 改动时间:  2017/04/17
//************************************
void CmcSolveMvcNormal::Run()
{
	//
	pmcSolves->Init(pmcProfile, pmcHvdc);

	CDeviceTBL * vTBL = pmcHvdc->DeviceTBL(mc_Convertor);
	pObjMap  vDevs = vTBL->GetItems();
	pObjMap::iterator vDev = vDevs.begin();

	int vN = dynamic_cast<CmcDevConvertor *>(vDev->second)->GetValvor12Count();
	
	pmcProfile->pmcOrder->InitNormal(vN);

	//
	CmcSolveMvc::Run();

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doRecordResult
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.Result存在各个Device里
// 改动时间:  2017/04/18
//************************************
void CmcSolveMvcNormal::doRecordResult()
{
	dynamic_cast<CmcSolvesNormal*>(pmcSolves)->doSaveNorml();

	//测试用
	static int vN = 1;
	string vCaseID = pmcProfile->pmcOrder->CreateCaseID();

	//pmcResult->mcResultMap[vCaseID]=

	cout << "主回路额定:";
	cout << vCaseID;
	cout << "%";
	cout << pmcProfile->pmcOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}