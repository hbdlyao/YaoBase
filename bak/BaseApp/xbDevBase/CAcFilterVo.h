///////////////////////////////////////////////////////////
//  CAcFilterVo.h
//  Implementation of the Class CAcFilterVo
//  Created on:      04-4月-2017 7:02:53
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_)
#define EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_

#include "CHvdcDeviceVo.h"

/**
 * 主回路 交流滤波器
 */
class CAcFilterVo : public COneDotVo
{

public:
	/**
	 * 交流滤波器类型（单调谐/双调谐）
	 */
	int GetAcfType();
	/**
	 * 交流电压
	 */
	double GetQac();
	/**
	 * 滤波器无功
	 */
	double GetQacf();
	/**
	 * 滤波器额定无功
	 */
	double GetQacfN();
	/**
	 * 额定交流电压
	 */
	double GetQacN();
	/**
	 * 电容
	 */
	double GetZc();
	/**
	 * 电阻
	 */
	double GetZr();
	/**
	 * 电抗
	 */
	double GetZx();
	/**
	 * 交流滤波器类型（单调谐/双调谐）
	 */
	void SetAcfType(int newVal);
	/**
	 * 交流电压
	 */
	void SetQac(double newVal);
	/**
	 * 滤波器无功
	 */
	void SetQacf(double newVal);
	/**
	 * 滤波器额定无功
	 */
	void SetQacfN(double newVal);
	/**
	 * 额定交流电压
	 */
	void SetQacN(double newVal);
	/**
	 * 电容
	 */
	void SetZc(double newVal);
	/**
	 * 电阻
	 */
	void SetZr(double newVal);
	/**
	 * 电抗
	 */
	void SetZx(double newVal);
	double GetUac();
	void SetUac(double newVal);
	double GetUacN();
	void SetUacN(double newVal);

protected:
	/**
	 * 交流滤波器类型（单调谐/双调谐）
	 */
	int AcfType;
	/**
	 * 交流电压
	 */
	double Qac;
	/**
	 * 滤波器无功
	 */
	double Qacf;
	/**
	 * 滤波器额定无功
	 */
	double QacfN;
	/**
	 * 额定交流电压
	 */
	double QacN;
	/**
	 * 电容
	 */
	double Zc;
	/**
	 * 电阻
	 */
	double Zr;
	/**
	 * 电抗
	 */
	double Zx;
	/**
	 * 网侧交流电压
	 */
	double Uac;
	/**
	 * 网侧额定交流电压
	 */
	double UacN;

};
#endif // !defined(EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_)
