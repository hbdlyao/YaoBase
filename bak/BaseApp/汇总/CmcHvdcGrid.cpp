///////////////////////////////////////////////////////////
//  CmcHvdcGrid.cpp
//  Implementation of the Class CmcDeviceTBL
//  Created on:      13-4月-2017 15:38:09
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcHvdcGrid.h"
#include "CHvdcFunc.h"
#include "gbHead_mcDevice.h"


string CmcDeviceTBL::TypeToName(int vDevType){

	string vName;
	vName = CHvdcFunc::mcTypeToName(vDevType);
	
	return vName;
}


CDeviceBase * CmcDeviceTBL::doNewDevice(int vDevType){

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




void CmcHvdcGrid::Init(){

	int i;
	CDeviceTBL * vTBL;
	
	for (i = mc_AcSys; i <= mc_MetalLine; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);
	
	}
}


int CmcHvdcGrid::StaCount(){

	CDeviceTBL * vTBL;
	
	int vN=0;
	
	vTBL = DeviceTBL(mc_Convertor);
	
	if (vTBL!=nullptr)
		vN = vTBL->GetItemCount();
	
	return vN;
}


string CmcHvdcGrid::TypeToName(int vType){

	string vName;
	vName = CHvdcFunc::mcTypeToName(vType);
	
	return vName;
}


CDeviceTBL * CmcHvdcGrid::NewDeviceTBL(int vType){

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