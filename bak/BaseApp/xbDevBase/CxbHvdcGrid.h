#pragma once

#include "CHvdcGrid.h"

/**
* 直流设备表
*/
class CxbHvdcDeviceTBL : public CHvdcDeviceTBL
{

public:
	virtual string TypeToName(int vDevType);

protected:
	virtual CDeviceBase * doNewDevice(int vDevType);

};

class CxbHvdcGrid : public CHvdcGrid
{

public:
	virtual void Init();
	virtual string TypeToName(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType);

};

