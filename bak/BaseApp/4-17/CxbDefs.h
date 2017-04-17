#pragma once



//计算谐波次数
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


//直流滤波器偏差类型
enum Enum_DCFOrder
{
	DCF_NoneDev = 0, //无偏差
	DCF_ConsDev = 1, //恒定偏差
	DCF_RandDev = 2, //概率偏差
	DCF_ConPDev = 3, //正偏差
	DCF_ConNDev = 4  //负偏差
};
