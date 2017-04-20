#pragma once

#include "CObjBase.h"
#include "CDeviceBase.h"
#include "CMyFunc.h"
#include "CObjTBLBase.h"

class CDeviceTBL : public CObjTBLBase
{
protected:
	virtual CDeviceBase * doNewDevice(int vDevType) = 0;

public:

	virtual int DeviceCount() { return GetItemCount(); };

	virtual CDeviceBase * Device(int vIndex);
	virtual CDeviceBase * Device(string vName);

	//
	virtual void DeviceAdd(string vID, CObjBase * vItem);
	//
	virtual void DeviceRemove(CObjBase* vItem);
	virtual void DeviceRemove(int vItem);
	virtual void DeviceRemove(string vName);


	virtual CDeviceBase * NewDevice(int vDevType);
	virtual CDeviceBase * NewDevice(int vDevType, string vID) ;
	virtual CDeviceBase * NewDevice(int vDevType, string vID, string vName) ;

	virtual void ClearNodeID();

};


typedef map<int, CDeviceTBL * >  pDeviceTBL;
typedef pair<int, CDeviceTBL * >  pDevTBL_Pair;

