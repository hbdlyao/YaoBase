///////////////////////////////////////////////////////////
//  CmcHvdcGrid.cpp
//  Implementation of the Class CmcDeviceTBL
//  Created on:      13-4��-2017 15:38:09
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcHvdcGrid.h"
#include "CHvdcFunc.h"
#include "gbHead_mcDevice.h"


string CmcDeviceTBL::TypeToName(int vDevType)
{
	string vName;
	vName = CHvdcFunc::mcTypeToName(vDevType);
	
	return vName;
}


CDeviceBase * CmcDeviceTBL::doNewDevice(int vDevType)
{
	return CmcDeviceTBL::mcNewDevice(vDevType);
}

CDeviceBase * CmcDeviceTBL::mcNewDevice(int vDevType)
{
	CDeviceBase * vDev=nullptr; 
	
	switch (vDevType)
	{
	case mc_AcSys:
		//����ϵͳ  
		vDev = new  CmcDevAcSys();
		break;
	
	case mc_AcF:
		//�����˲���
		vDev = new  CmcDevAcFilter();
		break;
	
	case mc_Xf2:
		//˫�����ѹ��  
		vDev = new  CmcDevXf2();
		break;
	
	
	case mc_Convertor:
		//������  
		vDev = new  CmcDevConvertor();
		break;
	
	case mc_DcLine:
		//ֱ������  
		vDev = new  CmcDevDcLine();
		break;
	
	
	case mc_GroundLine:
		//�ӵؼ���  
		vDev = new  CmcDevGroundLine();
		break;
	
	case mc_MetalLine:
		//��������  
		vDev = new  CmcDevMetalLine();
		break;
	
	case mc_Ground:
		//�ӵؼ�  
		vDev = new  CmcDevGround();
		break;
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}

////////////////////////////////////////////////////////
string CmcHvdcGrid::TypeToName(int vType)
{
	return CHvdcFunc::mcTypeToName(vType);
}


void CmcHvdcGrid::Init()
{
	int i;
	CDeviceTBL * vTBL;

	for (i = mc_AcSys; i <= mc_Ground; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);
	}
}

CDeviceTBL * CmcHvdcGrid::NewDeviceTBL(int vType)
{
	string vName;
	CmcDeviceTBL * vSet;
	
	vName = TypeToName(vType);
	
	//
	vSet = new CmcDeviceTBL();
	vSet->SetTblType(vType);
	vSet->SetTblName(vName);
	
	//
	pItems[vType] = vSet;
	
	return pItems[vType];

}