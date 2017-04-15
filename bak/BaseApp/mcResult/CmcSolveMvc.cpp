///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      13-4月-2017 13:56:17
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolveMvc.h"
#include <iostream>
#include <set>

using namespace std;


CmcSolveMvc::~CmcSolveMvc()
{
	Release();
}

void CmcSolveMvc::Clear()
{
	//CPowerSolveMvc::Clear();

	pmcResult->Clear();

}

void CmcSolveMvc::Release()
{
	Clear();

	delete pmcResult;
	pmcResult = nullptr;

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
	int vStaCount = pmcHvdc->StaCount();
	pmcProfile->pmcOrder->Clear();
	pmcProfile->pmcOrder->InitMatrix(vStaCount);

	//
	int vCaseCount = pmcProfile->pmcOrder->CaseCount();
	pmcResult->Clear();
	pmcResult->Init(vStaCount, vCaseCount, pmcProfile->pmcOrder->PdSize);

}

void CmcSolveMvc::doRun_Ground(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());
	
	//单极大地/金属回线/双极/双极并联
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1')
		{
			pmcProfile->pmcOrder->GroundType = mc_GndTypeArr[i];

			//
			doNewSolves(mc_GndTypeArr[i]);

			//节点编号
			doNodeID();

			//换流站排序
			doStationSort();

			//
			doRun_Rd(pmcProfile->pmcOrder->Flag_Rd);
		}//if

	}//for 
}

void CmcSolveMvc::doRun_Rd(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//高阻、低阻
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1')
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
	int vStaCount = pmcHvdc->StaCount();

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
	int vStaCount = pmcHvdc->StaCount();

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
	int vStaCount = pmcHvdc->StaCount();

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
	{
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

	pmcProfile->ClearSingle();
	//
	pmcSolves->Run();

	//记录结果
	RecordResult();
}

/**
 * 南方电网主回路及谐波计算软件* 改动对象:  RecordResult 改动者:    崔康生 改动类型:  新增 改动内容:  1.
 * 在一次单功率水平计算结束后将结果保存在Result里 改动时间:  2017/04/13
 */
void CmcSolveMvc::RecordResult()
{
	//崔康生：将pmcProfile->pmcStaData的数据记录在Result中

	//测试用
	static int vN = 1;

	cout << pmcProfile->pmcOrder->CreateCaseID();
	cout << "%";
	cout << pmcProfile->pmcOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}


void CmcSolvesMvcNormal::Init(){

	pSolves = new CmcSolvesNormal();
	pmcSolves = dynamic_cast<CmcSolves *> (pSolves);
}

