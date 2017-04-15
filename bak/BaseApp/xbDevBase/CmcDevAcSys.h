#pragma once


#include "CHvdcDeviceBase.h"

/**
 * 主回路 交流系统
 */
class CmcDevAcSys : public CDevOneDot
{

public:
	/**
	 * 交流系统无功功率
	 */
	double GetQac();
	/**
	 * 交流系统额定无功功率
	 */
	double GetQacN();
	/**
	 * 交流系统吸收最大无功
	 */
	double GetQinMax();
	/**
	 * 交流系统发出最大无功
	 */
	double GetQoutMax();
	/**
	 * 交流侧电压
	 */
	double GetUac();
	/**
	 * 交流电压极小值
	 */
	double GetUacExMin();
	/**
	 * 交流电压最大值
	 */
	double GetUacMax();
	/**
	 * 交流电压最小值
	 */
	double GetUacMin();
	/**
	 * 交流侧额定电压
	 */
	double GetUacN();
	/**
	 * 交流系统无功功率
	 */
	void SetQac(double newVal);
	/**
	 * 交流系统额定无功功率
	 */
	void SetQacN(double newVal);
	/**
	 * 交流系统吸收最大无功
	 */
	void SetQinMax(double newVal);
	/**
	 * 交流系统发出最大无功
	 */
	void SetQoutMax(double newVal);
	/**
	 * 交流侧电压
	 */
	void SetUac(double newVal);
	/**
	 * 交流电压极小值
	 */
	void SetUacExMin(double newVal);
	/**
	 * 交流电压最大值
	 */
	void SetUacMax(double newVal);
	/**
	 * 交流电压最小值
	 */
	void SetUacMin(double newVal);
	/**
	 * 交流侧额定电压
	 */
	void SetUacN(double newVal);
	/**
	 * 电网频率
	 */
	double GetFreq();
	/**
	 * 电网频率
	 */
	void SetFreq(int newVal);

protected:
	/**
	 * 交流系统无功功率
	 */
	double Qac;
	/**
	 * 交流系统额定无功功率
	 */
	double QacN;
	/**
	 * 交流系统吸收最大无功
	 */
	double QinMax;
	/**
	 * 交流系统发出最大无功
	 */
	double QoutMax;
	/**
	 * 交流侧线电压
	 */
	double Uac;
	/**
	 * 交流电压极小值
	 */
	double UacExMin;
	/**
	 * 交流电压最大值
	 */
	double UacMax;
	/**
	 * 交流电压最小值
	 */
	double UacMin;
	/**
	 * 交流侧额定线电压
	 */
	double UacN;
	/**
	 * 电网频率
	 */
	double Freq;

};
