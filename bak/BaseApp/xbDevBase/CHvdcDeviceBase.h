#pragma once


#include "CDeviceBase.h"
#include "CHvdcDefs.h"
#include "CComplex.h"

class CHvdcDeviceBase : public CDeviceBase
{
};

/**
 * 一端点设备
 */
class CDevOneDot : public CHvdcDeviceBase
{
protected:
	virtual void Init()  ;

};

/**
 * 双端点设备
 */
class CDevTwoDot : public CHvdcDeviceBase
{

protected:
	virtual void Init() ;

};

/**
 * RLC并联支路
 */
class CDevShunt : public CDevOneDot
{
protected:
	/**
	 * 支路数据
	 */
	struct_Branch structBranch;

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

	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);

};

/**
 * 串联支路
 */
class CDevBranch : public CDevTwoDot
{
protected:
	/**
	 * 受端换流站名称
	 */
	string StationName1;
	/**
	 * 受端换流站名称
	 */
	string StationName2;


public:
	/**
	 * 支路数据
	 */
	struct_Branch structBranch;

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

	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);


};
