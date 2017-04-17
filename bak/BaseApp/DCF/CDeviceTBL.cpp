///////////////////////////////////////////////////////////
//  CDeviceBaseVoMap.cpp
//  Implementation of the Class CDeviceBaseVoMap
//  Created on:      22-3ÔÂ-2017 13:47:10
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcFunc.h"

#include "CDeviceTBL.h"


CDeviceBase * CDeviceTBL::Device(int vIndex)
{

	return dynamic_cast<CDeviceBase *>(Item(vIndex));
		
}


CDeviceBase * CDeviceTBL::Device(string vName)
{

	return dynamic_cast<CDeviceBase *>(Item(vName));

}

void CDeviceTBL::DeviceAdd(string vID, CObjBase * vItem)
{
	ItemAdd(vID,vItem);
}


void CDeviceTBL::DeviceRemove(CObjBase * vItem)
{
	ItemRemove(vItem);
}

void CDeviceTBL::DeviceRemove(int vItem)
{
	ItemRemove(vItem);
}

void CDeviceTBL::DeviceRemove(string vName)
{
	ItemRemove(vName);
}


CDeviceBase * CDeviceTBL::NewDevice(int vDevType)
{
	string vID,vName;
	CDeviceBase * vDev;

	vDev = doNewDevice(vDevType);

	vID = CMyFunc::CreateObjID();
	vName = TypeToName(vDevType) + to_string(GetItemCount()) + "_" + vID;

	vDev = NewDevice(vDevType, vID, vName);

	return  vDev;

}


CDeviceBase * CDeviceTBL::NewDevice(int vDevType, string vID)
{
	CDeviceBase * vDev;

	vDev = NewDevice(vDevType, vID, vID);

	return  vDev;
}


CDeviceBase * CDeviceTBL::NewDevice(int vDevType, string vID, string vName)
{

	CDeviceBase * vDev;

	vDev = doNewDevice(vDevType);

	vDev->SetDeviceID(vID);
	vDev->SetDeviceName(vName);
	vDev->SetDeviceType(vDevType);

	//
	//DeviceAdd(vDev);
	//
	
	//return  dynamic_cast<CDeviceBase *>(ItemsMap[vID]);

	return vDev;

}

