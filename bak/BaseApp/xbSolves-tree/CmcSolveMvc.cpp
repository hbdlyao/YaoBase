///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      13-4��-2017 13:56:17
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
	
	//�ڵ���
	doNodeID();
}


void CmcSolveMvc::doNewSolves(int vGNDType)
{
	pmcSolves->Clear();
	pmcSolves->NewSolves(vGNDType);
}


int CmcSolveMvc::StaCount() 
{
	//Ӧ�ôӹ��������ж�ȡ
	return CHvdcParams::mcStationCount;

}
/**
 * �Ϸ���������·��г���������* �Ķ�����:  Run �Ķ���:    �޿��� �Ķ�����:  �޸� �Ķ�����:  1.
 * �޸ķ������ܵĶ��壺�������Order�����й��� 2.ȡ�����int vGNDType �Ķ�ʱ��:  2017/04/12
 */
void CmcSolveMvc::Run()
{//�๤������
	
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  doRun_Ground
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.����doRecordMeasureNode����
//            2.
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcSolveMvc::doRun_Ground(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pmcProfile->pmcOrder->GroundType = mc_GndTypeArr[i];

			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(mc_GndTypeArr[i]);

			//�ڵ���
			doNodeID();

			//����վ����
			doStationSort();

			//��¼��վ������Ľڵ���
			doRecordMeasureNode();

			//��ʼ�������þ���
			doInitMatrix();

			//�����ֵ
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

	//���衢����
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1') //
		{
			pmcProfile->pmcOrder->RdLevel = mc_RdLevelArr[i];
			
			//
			if (pmcProfile->pmcOrder->IsUdCustom) //ָ��Ud
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

	//ȫѹ/80%/70%
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

	//Ud����
	//�޿���......

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

	//���/�/��С/��С
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
	
	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex ==vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  doRun
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.pmcProfile->Clear()��ΪpmcProfile->ClearSingle()����Clear pmcProfile����ı������������е�Order��Result
// �Ķ�ʱ��:  2017/04/13
//************************************
void CmcSolveMvc::doRun()
{

	pmcProfile->ResetData();
	//
	pmcSolves->Run();

	//��¼���
	doRecordResult();
}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  doRecordResult
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ʽ�ϵ���pmcResult->Record();
//            2.������pmcResult��map�ļ�ֵ��ʲô
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcSolveMvc::doRecordResult()
{
	string vCaseID = pmcProfile->pmcOrder->CreateCaseID();
	pmcResult->Record(vCaseID, pmcProfile->pmcStaData, pmcProfile->pmcStaDataN);

	//������
	static int vN = 1;

	//pmcResult->mcResultMap[vCaseID]=

	cout << "����·:";
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  Run
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.InitNormal()��Ϊ
//InitNormal(dynamic_cast<CmcDevConvertor *>(vDev->second)->GetValvor12Count())
// �Ķ�ʱ��:  2017/04/17
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  doRecordResult
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.Result���ڸ���Device��
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcSolveMvcNormal::doRecordResult()
{
	dynamic_cast<CmcSolvesNormal*>(pmcSolves)->doSaveNorml();

	//������
	static int vN = 1;
	string vCaseID = pmcProfile->pmcOrder->CreateCaseID();

	//pmcResult->mcResultMap[vCaseID]=

	cout << "����·�:";
	cout << vCaseID;
	cout << "%";
	cout << pmcProfile->pmcOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}