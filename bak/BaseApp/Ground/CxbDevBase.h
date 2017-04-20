#pragma once

#include "CDeviceBase.h"

class CxbDevBase : public CDeviceBase
{
protected:	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	int PosOrNeg;

public:
	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	int GetPosOrNeg();
	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	void SetPosOrNeg(int newVal);
	virtual void Prepare_hRLC();
	/**
	 * 最大谐波次数
	 */
	int hMax();
	/**
	 * 基波频率
	 */
	double FreqRef();
	double Omega();
	
};
