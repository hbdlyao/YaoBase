#pragma once


#include "CmcDevTwoDot.h"



/**
 * 换流器
 */
class CmcDevConvertor : public CmcDevTwoDot
{

public:
	/**
	 * 触发角/关断角
	 */
	double GetAlhpa_gama();
	/**
	 * 额定触发角/关断角
	 */
	double GetAlpha_gamaN();
	/**
	 * 触发角/关断角最大值
	 */
	double GetAngleMax();
	/**
	 * 触发角/关断角最小值
	 */
	double GetAngleMin();
	
	/**
	 * 换向电阻额定值，按百分数给定  drN=Urp
	 */
	double GetdrN();
	/**
	 * 换向电抗额定值， dxN=(1/2)Ukp 按百分数给定
	 */
	double GetdxN();
	/**
	 * 直流电流,，计算得出
	 */
	double GetId();
	/**
	 * 电压离换流站距离 ?
	 */
	double GetLengthToSide();
	/**
	 * 直流功率
	 */
	double GetPd();
	/**
	 * 额定直流功率
	 */
	double GetPdN();
	/**
	 * 换流站吸收无功最小值
	 */
	double GetQmin();
	/**
	 * 直流电压
	 */
	double GetUd();
	/**
	 * 额定直流电压
	 */
	double GetUdN();
	/**
	 * 6脉动正向导通压降
	 */
	double GetUT();
	/**
	 * 每极12脉动换流组数
	 */
	int GetValvor12Count();
	/**
	 * 触发角/关断角
	 */
	void SetAlhpa_gama(double newVal);
	/**
	 * 额定触发角/关断角
	 */
	void SetAlpha_gamaN(double newVal);
	/**
	 * 触发角/关断角最大值
	 */
	void SetAngleMax(double newVal);
	/**
	 * 触发角/关断角最小值
	 */
	void SetAngleMin(double newVal);
	
	/**
	 * 换向电阻额定值
	 */
	void SetdrN(double newVal);
	/**
	 * 换向电阻额定值，按百分数给定  drN=Urp
	 */
	void SetdxN(double newVal);
	/**
	 * 直流电流,，计算得出
	 */
	void SetId(double newVal);
	/**
	 * 电压离换流站距离 ?
	 */
	void SetLengthToSide(double newVal);
	/**
	 * 直流功率
	 */
	void SetPd(double newVal);
	/**
	 * 额定直流功率
	 */
	void SetPdN(double newVal);
	/**
	 * 换流站吸收无功最小值
	 */
	void SetQmin(double newVal);
	/**
	 * 直流电压
	 */
	void SetUd(double newVal);
	/**
	 * 额定直流电压
	 */
	void SetUdN(double newVal);
	/**
	 * 6脉动正向导通压降
	 */
	void SetUT(double newVal);
	/**
	 * 每极12脉动换流组数
	 */
	void SetValvor12Count(int newVal);
	double GetUdioN();
	void SetUdioN(double newVal);
	double GetUdio();
	void SetUdio(double newVal);
	/**
	 * 阀侧电压
	 */
	double GetUv();
	/**
	 * 阀侧电压
	 */
	void SetUv(double newVal);
	/**
	 * 阀侧额定电压
	 */
	double GetUvN();
	/**
	 * 阀侧额定电压
	 */
	void SetUvN(double newVal);
	/**
	 * 直流电流,，计算得出
	 */
	double GetIdN();
	/**
	 * 直流电流,，计算得出
	 */
	void SetIdN(double newVal);
	/**
	 * 换流器类型（整流逆变）
	 */
	int GetStationType();
	/**
	 * 换流器类型（整流逆变）
	 */
	void SetStationType(int newVal);
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	int GetStationCtrlType();
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	void SetStationCtrlType(int newVal);
	int GetIsGround();
	void SetIsGround(int newVal);
	double GetAngleRef();
	void SetAngleRef(double newVal);

protected:
	/**
	 * 触发角/关断角
	 */
	double Alhpa_gama;
	/**
	 * 额定触发角/关断角
	 */
	double Alpha_gamaN;
	/**
	 * 触发角/关断角最大值
	 */
	double AngleMax;
	/**
	 * 触发角/关断角最小值
	 */
	double AngleMin;
	/**
	 * 换向电阻额定值，按百分数给定  drN=Urp
	 */
	double drN;
	/**
	 * 换向电抗额定值， dxN=(1/2)Ukp 按百分数给定
	 */
	double dxN;
	/**
	 * 直流电流,，计算得出
	 */
	double Id;
	/**
	 * 电压离换流站距离 ?
	 */
	double LengthToSide;
	/**
	 * 直流功率
	 */
	double Pd;
	/**
	 * 额定直流功率
	 */
	double PdN;
	/**
	 * 换流站吸收无功最小值
	 */
	double Qmin;
	/**
	 * 直流电压
	 */
	double Ud;
	/**
	 * 额定直流电压
	 */
	double UdN;
	/**
	 * 6脉动正向导通压降
	 */
	double UT;
	/**
	 * 每极12脉动换流组数
	 */
	int Valvor12Count;
	double UdioN;
	double Udio;
	/**
	 * 阀侧电压
	 */
	double Uv;
	/**
	 * 阀侧额定电压
	 */
	double UvN;
	/**
	 * 直流电流,，计算得出
	 */
	double IdN;
	/**
	 * 换流器类型（整流逆变）
	 */
	int StationType;
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	int StationCtrlType;
	int IsGround;
	double AngleRef;

};
