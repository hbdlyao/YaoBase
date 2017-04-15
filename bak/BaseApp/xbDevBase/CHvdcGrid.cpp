///////////////////////////////////////////////////////////
//  CHvdcGrid.cpp
//  Implementation of the Class CmcHVDC
//  Created on:      24-3月-2017 15:52:58
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyFunc.h"

#include "CHvdcGrid.h"

#include "CHvdcDefs.h"
#include "CHvdcFunc.h"
#include "gbHead_mcDevice.h"



string CHvdcGrid::TypeToName(int vType)
{

	string vName;
	vName = CHvdcFunc::mcTypeToName(vType);
	
	return vName;
}

int CHvdcGrid::StaCount()
{
	CDeviceTBL * vTBL;

	int vN=0;

	vTBL = DeviceTBL(mc_Convertor);

	if (vTBL!=nullptr)
		vN = vTBL->GetItemCount();
	
	return vN;


}

void CHvdcGrid::Init()
{
	int i;
	CDeviceTBL * vTBL;

	for (i = mc_AcSys; i <= mc_MetalLine; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);

	}

}


string CHvdcDeviceTBL::TypeToName(int vDevType){

	string vName;
	vName = CHvdcFunc::mcTypeToName(vDevType);
	
	return vName;
}



CDeviceBase * CHvdcDeviceTBL::doNewDevice(int vDevType) 
{
	CDeviceBase * vDev=nullptr; 
	
	switch (vDevType)
	{
	case mc_AcSys:
		//交流系统  
		vDev = new  CmcDevAcSys();
		break;

	case mc_AcF:
		//交流滤波器
		vDev = new  CmcDevAcFilter();
		break;

	case mc_Xf2:
		//双绕组变压器  
		vDev = new  CmcDevXf2();
		break;


	case mc_Convertor:
		//换流器  
		vDev = new  CmcDevConvertor();
		break;

	case mc_DcLine:
		//直流极线  
		vDev = new  CmcDevDcLine();
		break;


	case mc_GroundLine:
		//接地极线  
		vDev = new  CmcDevGroundLine();
		break;

	case mc_MetalLine:
		//金属回线  
		vDev = new  CmcDevMetalLine();
		break;

	case mc_Ground:
		//接地极  
		vDev = new  CmcDevGround();
		break;

	default:
		break;

	}//switch

	vDev->Init();

	return vDev;
}


CDeviceTBL * CHvdcGrid::NewDeviceTBL(int vType)
{

	string vName;
	CHvdcDeviceTBL * vTBL;
	
	vName = TypeToName(vType);
	
	//
	vTBL = new CHvdcDeviceTBL();
	vTBL->SetTblType(vType);
	vTBL->SetTblName(vName);
	
	//
	pItems[vType] = vTBL;
	
	return pItems[vType];
}
