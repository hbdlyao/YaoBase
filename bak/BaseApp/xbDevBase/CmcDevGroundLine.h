#pragma once

#include "CHvdcDeviceBase.h"

/**
 * 主回路 接地极
 */
class CmcDevGroundLine : public CDevShunt
{

protected:	/**
	 * 电阻最大值
	 */
	double ZrMax;
	/**
	 * 接地类型（单级大地/金属回线/双极）
	 */
	double ZrMin;


public:
	/**
	 * 电阻最大值
	 */
	double GetZrMax();
	/**
	 * 接地类型（单级大地/金属回线/双极）
	 */
	double GetZrMin();
	/**
	 * 电阻最大值
	 */
	void SetZrMax(double newVal);
	/**
	 * 接地类型（单级大地/金属回线/双极）
	 */
	void SetZrMin(double newVal);
};

