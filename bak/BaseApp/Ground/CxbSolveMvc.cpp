///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4��-2017 18:22:37
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolveMvc.h"
#include "CxbDevDCF.h"
#include "CMyParams.h"
#include "CHvdcParams.h"
#include "CxbDev3pVSrc.h"

#include "CxbRwOrderMvc.h"


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

void CxbSolveMvc::InitOrder()
{
	CxbRwOrderMvc  vRwMvc;

	vRwMvc.InitAdo(CMyParams::dbf_mdb);
	vRwMvc.Init(pxbProfile->pxbOrder);

	vRwMvc.OnLoad();
	
}
//����
void CxbSolveMvc::InitDevY()
{

}

void CxbSolveMvc::NodeID(int vGNDType)
{
	pxbProfile->pxbOrder->GroundType = vGNDType;

	//
	pxbSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();

	doStationSort();

	//��ʼ�������þ���
	doInitMatrix();

	doRun();

}



void CxbSolveMvc::doNewSolves(int vGNDType)
{
	pxbSolves->Clear();
	pxbSolves->NewSolves(vGNDType);

	//
}


int CxbSolveMvc::StaCount()
{
	//Ӧ�ôӹ��������ж�ȡ
	return CHvdcParams::xbStationCount;

	//return 3;

}

void CxbSolveMvc::Run()
{
	//
	doPrepare_hRLC();


	doInitRun();

	//�๤������
	doRun_Ground(pxbProfile->pxbOrder->Flag_Ground);
}



void CxbSolveMvc::doPrepare_hRLC()
{
	//����
	//���������豸�ĸ���г���迹��
	pxbHvdc->Prepare_hRLC();

}

double CxbSolveMvc::Frequence()
{
	return CHvdcParams::Frequence;
}

double CxbSolveMvc::hMax()
{
	return CHvdcParams::hMax;
}

void CxbSolveMvc::doRun()
{
	//����

	//���ǹ���(����ˮƽ)��DCFƫ�����͡�г������
	doPrepare_U3p(pxbProfile->pxbOrder->CreateCaseID());
	
	//г������1-hMax()
	for (int i = 1; i <= hMax(); i++)
	{
		pxbProfile->ReSetData();

		pxbProfile->xbHOrder = i;

		pxbSolves->Run();

	}

	//��¼���
	doRecordResult();

}


void CxbSolveMvc::doRecordResult()
{

	//�޿�����

	//������
	static int vN = 1;
	string vCaseID = pxbProfile->pxbOrder->CreateCaseID();

	//pxbResult->mcResultMap[vCaseID]=

	cout << "г��:";
	cout << vCaseID;
	cout << "%";
	cout << pxbProfile->pxbOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
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


void CxbSolveMvc::doInitMatrix() 
{

	int vN;

	vN = StaCount();

	//
	pxbProfile->InitMatrix(vN);
}


void CxbSolveMvc::doRun_Ground(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pxbProfile->pxbOrder->GroundType = mc_GndTypeArr[i];

			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(mc_GndTypeArr[i]);

			//�ڵ���
			doNodeID();

			//����վ����
			doStationSort();

			//��ʼ�������þ���
			doInitMatrix();

			doRun_Rd(pxbProfile->pxbOrder->Flag_Rd);

		}//if

	}//for
}


void CxbSolveMvc::doRun_Rd(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//���衢����
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //
		{
			pxbProfile->pxbOrder->RdLevel = mc_RdLevelArr[i];

			//
			if (pxbProfile->pxbOrder->IsUdCustom) //ָ��Ud
				doRun_UdCustom();
			else
				doRun_Ud(pxbProfile->pxbOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void CxbSolveMvc::doRun_Ud(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//ȫѹ/80%/70%
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1')
		{
			pxbProfile->pxbOrder->UdLevel = mc_UdLevelArr[i];

			if (pxbProfile->pxbOrder->IsUacSwap)
				doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
			else
				doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);

		}//if

	}//for
}


void CxbSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();

	pxbProfile->pxbOrder->UdLevel = Ud_Custom;

	//Ud����
	//�޿���......

	//
	if (pxbProfile->pxbOrder->IsUacSwap)
		doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
}


void CxbSolveMvc::doRun_Uac(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//���/�/��С/��С
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j = 0; j<vStaCount; j++)
				pxbProfile->pxbOrder->UacLevel[j] = mc_UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CxbSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount) {

	int vN = static_cast<int> (vFlag.size());


	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pxbProfile->pxbOrder->UacLevel[vIndex] = mc_UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex + 1, vStaCount);
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

		doRun_DCF();

		

	}//for
}

void CxbSolveMvc::doRun_DCF()
{
	//����
	static int vCount = 1;
	int i, vDevN;
	CDeviceTBL * vTBL;
	CxbDevDCF * vDev;


	vTBL = pGrid->DeviceTBL(xb_DCF);
	vDevN = vTBL->DeviceCount();
	switch (pxbProfile->pxbOrder->DCFDevType)
	{
	case DCF_NoneDev://��ƫ��
		for (i = 0; i < vDevN; i++)
		{
			vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
			vDev->selectNoneDevY();
		}
		doRun();
		return;

	case DCF_ConsDev://�㶨ƫ��
		for (vCount = 0; vCount < 3; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;

	case DCF_RandDev: //����ƫ��
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


void CxbSolveMvc::doPrepare_U3p(string  vCondition)
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


