///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4月-2017 18:22:37
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolveMvc.h"
#include "CxbDevDCF.h"
#include "CHvdcParams.h"
#include "CxbDev3pVSrc.h"


CxbSolveMvc::~CxbSolveMvc()
{
	pxbResult->Clear();

	delete pxbResult;
	pxbResult = nullptr;

}

void CxbSolveMvc::Clear()
{
	CPowerSolveMvc::Clear();

	pxbResult->Clear();

}


void CxbSolveMvc::Init()
{
	pSolves = new CxbSolves();
	pxbSolves = dynamic_cast<CxbSolves *> (pSolves);

	//
	pProfile = new CxbProfile();
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	pxbProfile->Init();

	//
	pxbResult = new CxbResult();
	pxbResult->Init();

}


void CxbSolveMvc::Init(CPowerGrid* vGrid)
{
	pGrid = vGrid;
	pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);

	//
	pxbSolves->Init(pxbProfile, pxbHvdc);

}


void CxbSolveMvc::NodeID(int vGNDType)
{
	pxbProfile->pxbOrder->GroundType = vGNDType;

	//
	pxbSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//节点编号
	doNodeID();

}



void CxbSolveMvc::doNewSolves(int vGNDType)
{
	pxbSolves->Clear();
	pxbSolves->NewSolves(vGNDType);
}


int CxbSolveMvc::StaCount()
{
	//应该从工程属性中读取
	return CHvdcParams::StationCount;

	//return 3;

}

void CxbSolveMvc::Run()
{

	//多工况运行
		
		doInitRun();
		
		//
		doRun_Ground(pxbProfile->pxbOrder->Flag_Ground);
}

void CxbSolveMvc::doRecordResult()
{

	//崔康生：
	
	//测试用
	static int vN = 1;
	string vCaseID = pxbProfile->pxbOrder->CreateCaseID();
	
	//pxbResult->mcResultMap[vCaseID]=
	
	cout << "谐波:";
	cout << vCaseID;
	cout << "%";
	cout << pxbProfile->pxbOrder->PdPer;
	
	cout << "======" << vN++;
	
	cout << endl;
}


void CxbSolveMvc::doRun()
{
	//考虑工况(功率水平)、DCF偏差类型、谐波次数
	selectU3P(pxbProfile->pxbOrder->CreateCaseID());
	//马俊鹏

	//谐波次数1-H_CAL_NUM
	for (int i = 1; i <= H_CAL_NUM; i++)
	{
		pxbProfile->ReSetData();
		pxbProfile->xbHOrder = i;
		pxbSolves->Run();
	}

	//记录结果
	doRecordResult();

}


void CxbSolveMvc::doInitRun()
{

	//
	pxbSolves->Init(pxbProfile, pxbHvdc);
	//
	int vStaCount = StaCount();

	pxbProfile->pxbOrder->Clear();
	pxbProfile->pxbOrder->InitMatrix(vStaCount);
	
	//
	int vCaseCount = pxbProfile->pxbOrder->CaseCount();
	pxbResult->Clear();
	//pxbResult->Init(vStaCount, vCaseCount, pxbProfile->pxbOrder->PdSize);
}


void CxbSolveMvc::doInitMatrix(){

	int vN;
	
	vN = StaCount();
	
	//
	pxbProfile->InitMatrix(vN);
}


void CxbSolveMvc::doRun_Ground(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	
	//单极大地/金属回线/双极/双极并联
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pxbProfile->pxbOrder->GroundType = mc_GndTypeArr[i];
			
			//根据接地类型生成 mcCalculate,与设备一一对应
			doNewSolves(mc_GndTypeArr[i]);
	
			//节点编号
			doNodeID();
	
			//换流站排序
			doStationSort();
	
			//初始化计算用矩阵
			doInitMatrix();
		
			//
			doRun_Rd(pxbProfile->pxbOrder->Flag_Rd);
	
		}//if
	
	}//for
}


void CxbSolveMvc::doRun_Rd(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	
	//高阻、低阻
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1') //
		{
			pxbProfile->pxbOrder->RdLevel = mc_RdLevelArr[i];
			
			//
			if (pxbProfile->pxbOrder->IsUdCustom) //指定Ud
				doRun_UdCustom();
			else
				doRun_Ud(pxbProfile->pxbOrder->Flag_Ud);
	
		}//if vFlag
	
	}//for
}


void CxbSolveMvc::doRun_Ud(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();
	
	//全压/80%/70%
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1')
		{
			pxbProfile->pxbOrder->UdLevel = mc_UdLevelArr[i];
	
			if (pxbProfile->pxbOrder->IsUacSwap)
				doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0 ,vStaCount);
			else
				doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
	
		}//if
	
	}//for
}


void CxbSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();
	
	pxbProfile->pxbOrder->UdLevel = Ud_Custom;
	
	//Ud处理
	//崔康生......
	
	//
	if (pxbProfile->pxbOrder->IsUacSwap)
		doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
}


void CxbSolveMvc::doRun_Uac(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();
	
	//最大/额定/最小/极小
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j=0;j<vStaCount;j++)
				pxbProfile->pxbOrder->UacLevel[j] = mc_UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CxbSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount){

	int vN = static_cast<int> (vFlag.size());
	

	//vIndex从0开始,当vIndex==vStaCount,说明所有的换流站都已设置Uac
	if (vIndex ==vStaCount)
		doRun_Pd();
	else
	{//最大/额定/最小/极小
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pxbProfile->pxbOrder->UacLevel[vIndex] = mc_UacLevelArr[i];
	
				doRun_UacSwap(vFlag, vIndex +1,vStaCount);
			}//if
	
	}//else
}


void CxbSolveMvc::doRun_Pd() 
{

	int vPdSize;

	vPdSize = pxbProfile->pxbOrder->PdSize;

	for (int i = 0; i<vPdSize; i++)
	{
		pxbProfile->pxbOrder->UpdatePdPercent(i);

		doDCF();

	}//for
}

void CxbSolveMvc::doDCF()
{
	//马俊鹏
	static int vCount = 1;
	int i, vDevN;
	CDeviceTBL * vTBL;
	CxbDevDCF * vDev;


	vTBL = pGrid->DeviceTBL(xb_DcF);
	vDevN = vTBL->DeviceCount();
	switch (pxbProfile->pxbOrder->DCFDevType)
	{
	case DCF_NoneDev://无偏差
		for (i = 0; i < vDevN; i++)
		{
			vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
			vDev->selectNoneDevY();
		}
		doRun();
		return;

	case DCF_ConsDev://恒定偏差
		for (vCount = 0; vCount < 3; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;

	case DCF_RandDev: //概率偏差
		for (vCount = 0; vCount < pxbProfile->pxbOrder->DCFRandTimes; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;
	}
	return;
}

void CxbSolveMvc::selectU3P(string  vCondition)
{
	static int vCount = 1;
	int i, vDevN;
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;

	vTBL = pGrid->DeviceTBL(xb_3pVSrc);
	vDevN = vTBL->DeviceCount();

	for (i = 0; i < vDevN; i++)
	{
		vDev = dynamic_cast<CxbDev3pVSrc *>(vTBL->Device(i));
		vDev->PrepareData(vCondition);
	}
}

