#pragma once


#include "CDeviceBase.h"

class CmcDevBase : public CDeviceBase
{
protected:
	/**
	 * 所属拓扑类型
	 * 
	 * 单极大地
	 * 单极金属
	 * 双极
	 */
	string tpFlag;



public:
	/**
	 * 所属拓扑类型
	 * 
	 * 单极大地
	 * 单极金属
	 * 双极
	 */
	string GettpFlag();
	/**
	 * 所属拓扑类型
	 * 
	 * 单极大地
	 * 单极金属
	 * 双极
	 */
	void SettpFlag(string newVal);
};
