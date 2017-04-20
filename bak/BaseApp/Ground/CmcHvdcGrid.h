#pragma once


#include "CDeviceTBL.h"
#include "CPowerGrid.h"

/**
 * ����·ֱ���豸��
 */
class CmcDeviceTBL : public CDeviceTBL
{
public:

	virtual string TypeToName(int vDevType)override;
	static CDeviceBase * mcNewDevice(int vDevType);

protected:
	virtual CDeviceBase * doNewDevice(int vDevType)override;

};

class CmcHvdcGrid : public CPowerGrid
{
public:
	virtual void Init()override;
	virtual string TypeToName(int vType)override;
	virtual CDeviceTBL * NewDeviceTBL(int vType) override;

};

