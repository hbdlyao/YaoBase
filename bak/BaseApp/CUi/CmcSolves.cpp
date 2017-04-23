///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3��-2017 17:29:56
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
		doNewMcSolvers10(); //�������
		break;

	case mc_Ground11:
		doNewMcSolvers11();//������������
		break;

	case mc_Ground20:
		doNewMcSolvers20();//˫�����Ե�
		break;

	case mc_Ground21:
		doNewMcSolvers21();//˫���������
		break;

	default:
		break;
	}//switch
}

void CmcSolves::doNewMcSolvers10()
{
	//�������

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

	//������������

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
	//˫�����Ե�

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
	//˫������

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
		//����ϵͳ  
		vCal = new  CmcCalAcSys();
		break;

	case mc_AcF:
		//�����˲���
		vCal = new  CmcCalAcFilter();
		break;

	case mc_Xf2:
		//˫�����ѹ��  
		vCal = new  CmcCalXf2();
		break;

	case mc_Convertor:
		//������  
		vCal = new  CmcCalConvertor();
		break;

	case mc_DcLine:
		//ֱ������  
		vCal = new  CmcCalDcLine();
		break;

	case mc_GroundLine:
		//�ӵؼ���  
		vCal = new  CmcCalGroundLine();
		break;

	case mc_MetalLine:
		//��������  
		vCal = new  CmcCalMetalLine();
		break;

	case mc_Ground:
		//�ӵؼ�  
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
	//����������ֵ��
	srand((unsigned int)time(0));
	//��ÿһ��CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->InitX();
	}

}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  doSovleDcNet
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.����doOffsetSort����
//			  2.����doSaveX����
// �Ķ�ʱ��:  2017/04/20
//************************************
void CmcSolves::doSovleDcNet()
{
	doOffsetSort();

	doInit_XVect();

	//�γ�Y
	doUpdateY();

	//��NL�����ֱ������
	while (true)
	{
		doUpdateJ();
		//
		doUpdateF_Y();//�ͽڵ㵼�ɶ�Ӧ�Ĳ���
					  //
		doUpdateF_J();//�ͻ�������Ӧ�Ĳ���
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  doOffsetSort
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.���ø���Cal��Offset���
// �Ķ�ʱ��:  2017/04/20
//************************************
void CmcSolves::doOffsetSort()
{
	int offset = 0;
	//��ÿһ��CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->OffsetSort(offset);
	}
	pmcProfile->ResetMatrix(offset);
}
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  doSaveX
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.����doSovleDcNet�ļ�����
// �Ķ�ʱ��:  2017/04/20
//************************************
void CmcSolves::doSaveX()
{
	//��ÿһ��CmcCalculate
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
	//��ÿһ��CmcCalculate
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
	//��ÿһ��CmcCalculate
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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doInit_XVect
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	//doInit_XVect();
	//

	doSovleDcNet();

	doCalStation();

}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  doCalStation
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��վ���㲻����������
// �Ķ�ʱ��:  2017/04/21
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