#pragma once


#include "gbHead_Def.h"
#include "CmcDevOneDot.h"

/**
 * RLC并联支路
 */
class CmcDevShunt : public CmcDevOneDot
{

public:
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
	virtual void Init();
	virtual double GetY();
	virtual double GetYg();
	virtual double GetYb();
	/**
	 * 马骏鹏
	 */
	virtual double GetYg(double vOmega);
	/**
	 * 马骏鹏
	 */
	virtual double GetYb(double vOmega);
	double GetZrN();
	void SetZrN(double vValue);

protected:
	/**
	 * 支路数据
	 */
	struct_Branch structBranch;

};
