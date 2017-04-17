///////////////////////////////////////////////////////////
//  CHvdcFunc.cpp
//  Implementation of the Class CHvdcFunc
//  Created on:      24-3��-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "gbHead_Def.h"
#include "CHvdcFunc.h"


string CHvdcFunc::mcTypeToName(int vType) 
{

	switch (vType)
	{
	case mc_AcSys:
		return "����ϵͳ";
		break;

	case mc_AcF:
		return "�����˲���";
		break;

	case mc_Xf2:
		return "������";
		break;

	case mc_Convertor:
		return "������";
		break;

	case mc_DcLine:
		return "ֱ������";
		break;

	case mc_Ground:
		return "�ӵؼ�";
		break;

	case mc_GroundLine:
		return "�ӵؼ���";
		break;

	case mc_MetalLine:
		return "��������";
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
		return "3������ѹԴ";
		break;

	case xb_PbDKQ:
		return "ƽ���翹��";
		break;

	case xb_DcF:
		return "ֱ���˲���";
		break;

	case xb_DcLine:
		return "ֱ������";
		break;
	
	case xb_GroundLine:
		return "�ӵؼ���";
		break;

	case xb_Ground:
		return "�ӵص���";
		break;
	
	case xb_MetalLine:
		return "��������";
		break;

	case xb_XfC:
		return "��ɢ����";
		break;

	case xb_CoupleC:
		return "��ϵ�����";
		break;
	
	case xb_PulseC:
		return "�弤������";
		break;

	case xb_Shunt:
		return "����֧·";
		break;
	
	case xb_Branch:
		return "����֧·";
		break;

	default:
		return "xbDevice";
		break;
	
	}//switch
}