///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3��-2017 17:29:56
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

		break;//����
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  doInit_XVect
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��Ϊ����ÿ��Cal�趨��ֵ�������ֵ��CalConvertor����
// �Ķ�ʱ��:  2017/04/14
//************************************
void CmcSolves::doInit_XVect()
{
	//����������ֵ��
	//pmcProfile->Init_XVect();

	//��ÿһ��CmcCalculate
	for each (pPowerCal_Pair vPair in pItems)
	{
		CmcCalculate * vCal = dynamic_cast<CmcCalculate*>(vPair.second);
		vCal->InitX();
	}

}


void CmcSolves::doSovleDcNet()
{

	//�γ�Y
	doUpdateY();
	
	//��NL�����ֱ������
	while (true)
	{
		doUpdateJ();
		
		////
		doUpdateF_Y();//�ͽڵ㵼�ɶ�Ӧ�Ĳ���
		//
		doUpdateF_J();//�ͻ�������Ӧ�Ĳ���
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
//�޿���
void CmcSolvesNormal::doPrepare()
{
struct_mcStationData* tem = pmcProfile->pmcStaData;
pmcProfile->pmcStaData = pmcProfile->pmcStaDataN;

CmcSolves::doPrepare();

pmcProfile->pmcStaDataN = pmcProfile->pmcStaData;
pmcProfile->pmcStaData = tem;
}
*/