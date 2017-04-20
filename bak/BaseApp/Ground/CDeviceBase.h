#pragma once

#include "CMyDefs.h"
#include "CObjBase.h"

class CDeviceBase : public CObjBase
{
private:
	string DeviceID;
	string DeviceName;
	int DeviceType;

	int dotCount;

	string* NodeNames;
	int* NodeIDs;

protected:
	string StationName;

public:
	CDeviceBase();
	CDeviceBase(const CDeviceBase& theCDeviceBaseVo);
	virtual ~CDeviceBase();

	//
	virtual void Init();
	virtual bool IsLeaf();
	virtual void Add(CDeviceBase* vItem);
	virtual void Remove(CDeviceBase* vItem);

public:
	string GetDeviceID();
	void SetDeviceID(string newVal);
	string GetDeviceName();
	void SetDeviceName(string newVal);
	int GetDeviceType();
	void SetDeviceType(int newVal);
	
	virtual string GetStationName();
	virtual void SetStationName(string newVal);

public:
	int GetDotCount();
	void SetDotCount(int newVal);

	string GetNodeName(int vIndex);
	void SetNodeName(int vIndex, string vName);

	int GetNodeID(int vIndex);
	void SetNodeID(int vIndex, int vID);

	string BusName(int vIndex);
public:

	virtual void ClearNodeID();
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);

};
