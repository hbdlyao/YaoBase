#pragma once


#include "gbHead_Def.h"
#include "CmcDevTwoDot.h"

/**
 * 串联支路
 */
class CmcDevBranch : public CmcDevTwoDot
{

public:
	/**
	 * CmcDevBranch
	 */
	virtual void Init();
	double GetZr();
	double GetZ_C();
	double GetZ_L();
	double GetZx_C();
	double GetZx_L();
	void SetZr(double vValue);
	void SetZ_C(double vValue);
	void SetZ_L(double vValue);
	void SetZx_C(double vValue);
	void SetZx_L(double vValue);
	/**
	 * 受端换流站名称
	 */
	string GetStationName1();
	/**
	 * 受端换流站名称
	 */
	string GetStationName2();
	/**
	 * 受端换流站名称
	 */
	void SetStationName1(string newVal);
	/**
	 * 受端换流站名称
	 */
	void SetStationName2(string newVal);
	virtual double GetY();
	virtual double GetYg();
	virtual double GetYb();
	/**
	 * 马骏鹏
	 */
	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);
	double GetZrN();
	void SetZrN(double vValue);

protected:
	/**
	 * 受端换流站名称
	 */
	string StationName1;
	/**
	 * 受端换流站名称
	 */
	string StationName2;
	/**
	* 支路数据
	*/
	struct_Branch structBranch;

};
