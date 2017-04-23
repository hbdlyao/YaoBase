///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      23-3��-2017 17:29:56
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


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  Run
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.doInit_XVect()�Ƶ�doSovleDcNet()����
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcSolves::Run()
{
	doPrepare();

	while (true)
	{
		doSovleDcNet();

		doCalStation();

		break;//�����ã�����ʱӦ�����˳�����
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
	//Ӧ�ôӹ��������ж�ȡ
	return CHvdcParams::mcStationCount;

}

void CmcSolves::StationSort()
{
	StationMap vStaMap;

	for each (pPowerCal_Pair vPair in pItems)
	{
		//���վ���
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
// �Ķ�����:  1.����doInit_XVect()����
//            2.
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcSolves::doSovleDcNet()
{
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


	//��Ҫ���޿�����֮��������дΪ����������ͨ���⹤���а���վ���ڷֽ�ͷ(ͬվmc_Convertor��mc_Xf2�໥����)
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
