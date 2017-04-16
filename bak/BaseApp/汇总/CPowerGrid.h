#pragma once

#include "CDeviceBase.h"
#include "CDeviceTBL.h"
#include "gbHead_Def.h"

class CPowerGrid
{
protected:
	pDeviceTBL pItems;
	//NodeMap *GridNodeMap;

public:
	virtual ~CPowerGrid();
	virtual string TypeToName(int vType);

	virtual CDeviceBase * Device(int vType, string vName);

	virtual void DeviceAdd(int vType, string vID, CDeviceBase* vDev);

	virtual void Clear();
	virtual void Release();

public:	
	int NodeCount = 0;
	pDeviceTBL GetItems() { return pItems; };

	virtual void ClearNodeID();

	virtual void Init()=0;
	virtual CDeviceTBL * DeviceTBL(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType) =0;
	//
	
};
