///////////////////////////////////////////////////////////
//  CxbHvdcGrid.cpp
//  Implementation of the Class CxbDeviceTBL
//  Created on:      13-4ÔÂ-2017 15:39:07
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbHvdcGrid.h"
#include "CHvdcFunc.h"

#include "gbHead_xbDevice.h"



string CxbDeviceTBL::TypeToName(int vDevType)
{

	string vName;
	vName = CHvdcFunc::xbTypeToName(vDevType);
	
	return vName;
}


CDeviceBase * CxbDeviceTBL::doNewDevice(int vDevType)
{
	return CxbDeviceTBL::xbNewDevice(vDevType) ;
}



CDeviceBase * CxbDeviceTBL::xbNewDevice(int vDevType)
{

	CDeviceBase * vDev = nullptr;

	//Yao_xb: 
	switch (vDevType)
	{
	case xb_3pVSrc:
		vDev = new CxbDev3pVSrc();
		break;

	case xb_PbDKQ:
		vDev = new CxbDevPbDkq();
		break;

	case xb_DcF:
		vDev = new CxbDevDCF();
		break;

	case xb_DcLine:
		vDev = new CxbDevDcLine();
		break;

	case xb_GroundLine:
		vDev = new CxbDevGroundLine();
		break;

	case xb_Ground:
		vDev = new CxbDevGround();
		break;

	case xb_MetalLine:
		vDev = new CxbDevMetalLine();
		break;

	case xb_XfC:
		vDev = new CxbDevXf_C();
		break;

	case xb_CoupleC:
		vDev = new CxbDevCouple_C();
		break;

	case xb_PulseC:
		vDev = new CxbDevPulse_C();
		break;

	case xb_Shunt:
		vDev = new CxbDevShunt();
		break;

	case xb_Branch:
		vDev = new CxbDevBranch();
		break;

	case xb_Trap:
		vDev = new CxbDevTrap();
		break;

	case xb_Monitor:
		vDev = new CxbDevMonitor();
		break;

	default:
		break;

	}//switch

	vDev->Init();

	return vDev;
}



void CxbHvdcGrid::Init()
{

	int i;
	CDeviceTBL * vTBL;
	
	//Yao_xb: 
	//for (i = xb_3pVSrc; i < xb_Branch3; i++)
	for (i = xb_3pVSrc; i <= xb_Monitor; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);	
	}
}

string CxbHvdcGrid::TypeToName(int vType)
{

	string vName;
	vName = CHvdcFunc::xbTypeToName(vType);
	
	return vName;
}


CDeviceTBL * CxbHvdcGrid::NewDeviceTBL(int vType)
{

	string vName;
	CxbDeviceTBL * vSet;
	
	vName = TypeToName(vType);
	
	//
	vSet = new CxbDeviceTBL();
	vSet->SetTblType(vType);
	vSet->SetTblName(vName);
	
	//
	pItems[vType] = vSet;
	
	return pItems[vType];
}

