#pragma once


#include "gbHead_Def.h"
#include "CmcDevOneDot.h"

/**
 * RLC����֧·
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
	 * ����
	 */
	virtual double GetYg(double vOmega);
	/**
	 * ����
	 */
	virtual double GetYb(double vOmega);

protected:
	/**
	 * ֧·����
	 */
	struct_Branch structBranch;

};
