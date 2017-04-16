#pragma once

#include "CmcDevBranch.h"
/**
 * 主回路 直流极线
 */
class CmcDevDcLine : public CmcDevBranch
{

public:
	struct_LineMode *structLineMode;
	struct_Branch *structBranch;
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

protected:
	/**
	 * 电阻最大值
	 */
	double ZrMax;
	/**
	 * 接地类型（单级大地/金属回线/双极）
	 */
	double ZrMin;

};

