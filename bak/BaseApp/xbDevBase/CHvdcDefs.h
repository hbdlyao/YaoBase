#pragma once

#include <string>
#include <map>


using namespace std;

/////////////////////////////////////////
struct struct_mcStaDevIndex
{
	string StatioName;

	int AcSys_Index;
	int AcF_Index;
	int Xf_Index;
	int Convertor_Index;
};

typedef map<string, struct_mcStaDevIndex> mcStaDevIndexMap;

struct struct_mcResult
{
public:
	string CaseID;
	string StatioName;

	double PdPercent;

	int nValvor12;

	double UT;
	double dr, dx;

	//实际数据
	double Uac;
	double Uv;
	double Tap;

	double Udio;
	double Pd;
	double Ud;
	double Id;

	double Ang;
	double AngMax;
	double AngMin;

};


struct struct_mcStation
{
public:
	string StatioName;

	int nValvor12;

	double UT;
	double dr, dx;

	//实际数据
	double Uac;
	double Uv;
	double Tap;

	double Udio;
	double Pd;
	double Ud;
	double Id;

	double Ang;
	double AngMax;
	double AngMin;

};

struct struct_BGXB
{

public:
	int hOrder;
	double Urms;
	double Phase;

};


struct struct_Branch
{

public:
	/**
	* 电阻
	*/
	double Zr;
	/**
	* 感抗
	*/
	double Zx_L;
	/**
	* 容抗
	*/
	double Zx_C;
	/**
	* 电感
	*/
	double Z_L;
	/**
	* 电容
	*/
	double Z_C;

};

struct struct_LineMode
{

public:
	/**
	* 直流极线高度
	*/
	double CSXGD;
	/**
	* 直流极线间距
	*/
	double CSXSPJL;
	/**
	* 避雷线与传输线间高度
	*/
	double BLXYCSXGDC;
	/**
	* 线路长度
	*/
	double XLCD;
	/**
	* 避雷线水平距离
	*/
	double BLXSPJL;
	/**
	* 传输线半径
	*/
	double CSXBJ;
	/**
	* 避雷线半径
	*/
	double BLXBJ;
	/**
	* 传输线电导率
	*/
	double CSXDDL;
	/**
	* 传输线电阻类型
	*/
	double CSXDZLX;
	/**
	* 传输线电阻率
	*/
	double CSXDZL;
	/**
	* 传输线直流电阻
	*/
	double CSXZZDZ;
	/**
	* 传输线弧垂
	*/
	double CSXHC;
	/**
	* 传输线分裂数
	*/
	double CSXFLS;
	/**
	* 传输线分裂间距
	*/
	double CSXFLJJ;
	/**
	* 避雷线电阻类型
	*/
	double BLXDZLX;
	/**
	* 避雷线电导率
	*/
	double BLXDDL;
	/**
	* 避雷线电阻率
	*/
	double BLXDZL;
	/**
	* 避雷线直流电阻
	*/
	double BLXZZDZ;
	/**
	* 避雷线弧垂
	*/
	double BLXHC;
	/**
	* 避雷线分裂数
	*/
	double BLXFLS;
	/**
	* 避雷线分裂间距
	*/
	double BLXFLJJ;
	/**
	* 土壤电阻率
	*/
	double TRDZL;

};

enum Enum_HvdcConvertorType
{
	Hvdc_Rectify = 0,
	Hvdc_Invertor = 1,

};

enum Enum_mcGroundType
{
	mc_Ground10 = 10,
	mc_Ground11 = 11,
	mc_Ground20 = 20,
	mc_Ground21 = 21

};

enum Enum_mcDeviceType
{
	mc_AcSys = 11,
	mc_AcF,
	mc_Xf2,
	mc_Convertor,
	mc_DcLine,
	mc_GroundLine,
	mc_MetalLine,
	mc_Ground

};

enum Enum_mcCaseFlag
{
	mcCaseBit_Pulse = 0,
	mcCaseBit_Power,
	mcCaseBit_GND,
	mcCaseBit_Ud,
	mcCaseBit_Rd,
	mcCaseBit_Uac
};

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
	xb_xf2,
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
	xb_Branch,

	//
	xb_Branch3,
	xb_Trap,
	xb_Jkzz

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
