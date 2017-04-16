#pragma once



//����г������
#define H_CAL_NUM 60

enum Enum_xbGroundType
{
	xb_Ground10 = 10,
	xb_Ground11 = 11,
	xb_Ground20 = 20,
	xb_Ground21 = 21


};


enum Enum_xbDeviceType
{
	xb_3pVSrc = 1,
	xb_PbDKQ,
	xb_DcF,
	xb_DcLine,
	xb_GroundLine,
	xb_Ground,
	xb_MetalLine,
	xb_XfC,
	xb_CoupleC,
	xb_PulseC,
	xb_Shunt,
	xb_Branch

};

enum Enum_DCFType
{
	DCF_None,
	DCF_Single,
	DCF_Double,
	DCF_DoubleHighPass,
	DCF_Triple,
	DCF_TripleHighPass
};


//ֱ���˲���ƫ������
enum Enum_DCFOrder
{
	DCF_NoneDev = 0, //��ƫ��
	DCF_ConsDev = 1, //�㶨ƫ��
	DCF_RandDev = 2, //����ƫ��
	DCF_ConPDev = 3, //��ƫ��
	DCF_ConNDev = 4  //��ƫ��
};
