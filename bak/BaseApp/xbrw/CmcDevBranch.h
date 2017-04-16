#pragma once


#include "gbHead_Def.h"
#include "CmcDevTwoDot.h"

/**
 * ����֧·
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
	 * �ܶ˻���վ����
	 */
	string GetStationName1();
	/**
	 * �ܶ˻���վ����
	 */
	string GetStationName2();
	/**
	 * �ܶ˻���վ����
	 */
	void SetStationName1(string newVal);
	/**
	 * �ܶ˻���վ����
	 */
	void SetStationName2(string newVal);
	virtual double GetY();
	virtual double GetYg();
	virtual double GetYb();
	/**
	 * ����
	 */
	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);

protected:
	/**
	 * �ܶ˻���վ����
	 */
	string StationName1;
	/**
	 * �ܶ˻���վ����
	 */
	string StationName2;
	/**
	* ֧·����
	*/
	struct_Branch structBranch;

};
