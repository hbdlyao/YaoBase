#pragma once

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  struct_mcStationData
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.TC改成int型
//			  2.string StationName="";这句需要""进行初始化，否则会出现地址异常
// 改动时间:  2017/04/21
//************************************
struct struct_mcStationData//++--
{
public:
	//结果集中的数据
	string StationName = "";//站名
	int iNodeID,jNodeID;

	//控制参数
	int TapCtrlType;
	int ConvertorType;

	int ConvertorlType;
	int	UdRef_StaIndex;
	int IdRef_StaIndex;



	double PdPer;//功率水平
	double Uac;//交流电压
	double Uv;//阀侧电压
	double Udio;//理想空载直流电压
	double Ud;//直流端口电压
	double UdL;//直流端口对地电压
	double Id;//直流电流
	double Pd;//直流功率
	double Pconv;//换流器有功
	double Qconv;//换流器无功
	int TC;//变压器分接头档位
	double alphaOrgamma;//触发角/关断角
	double miu;//换相角
	double Qf_max;//滤波器提供的最大无功
	double Qf_min;//滤波器提供的最小无功

				  //计算中要用到的参数：来自HVDC设备集
	int nT;//6脉动桥数
	int nPoleNum;//极数（双极或单极）
	double UT;//6脉动桥的压降
	double dr;//阻性换相压降
	double dx;//感性换相压降
	double deltaK;//变压器每档的调压百分比
	double QacInMax;//交流系统可吸收的最大无功
	double QacOutMax;//交流系统可发出的最大无功

					 //计算中要用到的参数：来自HVDC设备集，限值
	double AngCtrl_Max;//分接头控制中换流器触发角/关断角的上限
	double AngCtrl_Min;//分接头控制中换流器触发角/关断角的下限
	double Tap_Max;//分接头最大档位
	double Tap_Min;//分接头最小档位
	double Ang_Min;//换流器触发角/关断角的最小值
	double Uv_Max;//阀侧电压允许的最大值
				  //计算中要用到的参数：计算产生
	double Nnom;//变压器额定变比


};


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  struct_mcResultData
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.TC改成int型
// 改动时间:  2017/04/21
//************************************
struct struct_mcResultData
{
public:
	string CaseId;
	string StationName;//站名

	double PdPer;//功率水平
	double Uac;//交流电压
	double Uv;//阀侧电压
	double Uv_N;//阀侧电压额定值
	double Udio;//理想空载直流电压
	double Udio_N;//理想空载直流电压额定值
	double Ud;//直流端口电压
	double UdL;//直流端口对地电压
	double Id;//直流电流
	double Pd;//直流功率
	double Pconv;//换流器有功
	double Qconv;//换流器无功
	double TC;//变压器分接头档位
	double alphaOrgamma;//触发角/关断角
	double miu;//换相角
	double Qf_max;//滤波器提供的最大无功
	double Qf_min;//滤波器提供的最小无功

	double Nnom;//变压器额定变比
};

typedef map<string, struct_mcResultData> mc_ResultMap;

/////////////////////////////////////////////////////////////

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




enum Enum_mcUdLevel
{
	Ud_Full = 0,
	Ud_Per80,
	Ud_Per70,
	Ud_Custom
};
enum Enum_mcRdLevel
{
	Rd_High = 0,
	Rd_Low,
	Rd_Normal
};

enum Enum_mcUacLevel
{
	Uac_Max = 0,
	Uac_Norm,
	Uac_Min,
	Uac_ExMin
};


const int mc_GndTypeArr[] = { mc_Ground10, mc_Ground11, mc_Ground20, mc_Ground21 };
const int mc_RdLevelArr[] = { Rd_High, Rd_Low, Rd_Normal };
const int mc_UdLevelArr[] = { Ud_Full, Ud_Per80, Ud_Per70, Ud_Custom };
const int mc_UacLevelArr[] = { Uac_Max, Uac_Norm, Uac_Min, Uac_ExMin };

//////////////2017-4-15////////////////
enum Enum_mcStationCtrlType
{
	StaCtrl_ConstantPd = 0,
	StaCtrl_ConstantUd,
	StaCtrl_ConstantId,
	StaCtrl_ConstantAngle,
	StaCtrl_TrackId
};

enum Enum_mcTransformerCtrlType
{
	xfCtrl_FixedAngle = 0,
	xfCtrl_ConstantUv

};

#define M_PI 3.14159265358979323846
#define Epsilon 0.0001
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  R2D和D2R
// 改动者:    崔康生
// 改动类型:  选择
// 改动内容:  1.角度弧度互转
// 改动时间:  2017/04/21
//************************************
static double R2D(double rad) { return rad / M_PI * 180; }
static double D2R(double degree) { return degree / 180 * M_PI; }