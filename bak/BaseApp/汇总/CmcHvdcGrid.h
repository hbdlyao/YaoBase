#pragma once


#include "CDeviceTBL.h"
#include "CPowerGrid.h"

/**
 * ����·ֱ���豸��
 */
class CmcDeviceTBL : public CDeviceTBL
{

public:

	virtual string TypeToName(int vDevType);

protected:
	virtual CDeviceBase * doNewDevice(int vDevType);

};

class CmcHvdcGrid : public CPowerGrid
{

public:
	virtual void Init();
	int StaCount();
	virtual string TypeToName(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType);

};

