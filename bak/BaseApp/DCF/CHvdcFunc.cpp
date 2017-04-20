///////////////////////////////////////////////////////////
//  CHvdcFunc.cpp
//  Implementation of the Class CHvdcFunc
//  Created on:      24-3月-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "gbHead_Def.h"
#include "CHvdcFunc.h"


string CHvdcFunc::mcTypeToName(int vType) 
{

	switch (vType)
	{
	case mc_AcSys:
		return "交流系统";
		break;

	case mc_AcF:
		return "交流滤波器";
		break;

	case mc_Xf2:
		return "换流变";
		break;

	case mc_Convertor:
		return "换流器";
		break;

	case mc_DcLine:
		return "直流极线";
		break;

	case mc_Ground:
		return "接地极";
		break;

	case mc_GroundLine:
		return "接地极线";
		break;

	case mc_MetalLine:
		return "金属回线";
		break;

	default:
		return "HvdcDevice";
		break;

	}//switch

}


string CHvdcFunc::xbTypeToName(int vType)
{

	//Yao_xb: 
	switch (vType)
	{	
	case xb_3pVSrc:
		return "3脉动电压源";
		break;

	case xb_PbDKQ:
		return "平波电抗器";
		break;

	case xb_DCF:
		return "直流滤波器";
		break;

	case xb_DCF_RLC:
		return "直流滤波器RLC";
		break;

	case xb_DcLine:
		return "直流极线";
		break;
	
	case xb_GroundLine:
		return "接地极线";
		break;

	case xb_Ground:
		return "接地电阻";
		break;
	
	case xb_MetalLine:
		return "金属回线";
		break;

	case xb_XfC:
		return "杂散电容";
		break;

	case xb_CoupleC:
		return "耦合电容器";
		break;
	
	case xb_PulseC:
		return "冲激电容器";
		break;

	case xb_Shunt:
		return "并联支路";
		break;
	
	case xb_Branch:
		return "串联支路";
		break;

	case xb_Trap:
		return "阻波器";
		break;

	case xb_Monitor:
		return "监控装置";
		break;

	default:
		return "xbDevice";
		break;
	
	}//switch
}