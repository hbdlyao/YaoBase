#pragma once
#include "CObjBase.h"

class CDeviceBase : public CObjBase
{

public:
	CDeviceBase();
	CDeviceBase(const CDeviceBase& theCDeviceBaseVo);
	virtual ~CDeviceBase();
	string GetDeviceID();
	void SetDeviceID(string newVal);
	string GetDeviceName();
	void SetDeviceName(string newVal);
	int GetDeviceType();
	void SetDeviceType(int newVal);
	int GetDotCount();
	void SetDotCount(int newVal);
	string GetNodeName(int vIndex);
	void SetNodeName(int vIndex, string vName);
	int GetNodeID(int vIndex);
	void SetNodeID(int vIndex, int vID);
	string GetStationName();
	void SetStationName(string newVal);
	virtual void Init();
	int GetdotCount();
	void SetdotCount(int newVal);

protected:
	string DeviceID;
	string DeviceName;
	int DeviceType;
	int dotCount;
	string StationName;
	int* NodeIDs;
	string* NodeNames;

};

