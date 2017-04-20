///////////////////////////////////////////////////////////
//  CxbRwOne.cpp
//  Implementation of the Class CxbRwOne
//  Created on:      18-4月-2017 17:11:02
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwOne.h"
#include "CxbDevOneDot.h"

void CxbRwOne::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevOneDot * vDev;

	vDev = dynamic_cast<CxbDevOneDot *>(vDevice);

	CxbRw::doLoad(vDevice);


	RwAdo->GetFieldValue("ID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetObjGUID(vValue.iVal);
	};
		
	RwAdo->GetFieldValue("DeviceID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetDeviceID(vStr);
	};
	
	RwAdo->GetFieldValue("DeviceName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue;
		vDev->SetDeviceName(vStr);
	};
	
	RwAdo->GetFieldValue("DeviceType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDeviceType(vValue.iVal);//整型
	};
	
	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};


	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetStationName(vStr);
	};
	
	RwAdo->GetFieldValue("NodeName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(0, vStr);
	};
		
	/*
	RwAdo->GetFieldValue("NodeID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(0, vValue.iVal);//整型
	};
	*/
}


void CxbRwOne::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevOneDot * vDev;

	vDev = dynamic_cast<CxbDevOneDot *>(vDevice);

	CxbRw::doSave(vDevice);


	vValue = _variant_t(vDev->GetObjGUID()); //整型
	RwAdo->SetFieldValue("ID", vValue);
	
	
	vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
	RwAdo->SetFieldValue("DeviceID", vValue);
	
	
	vValue = _variant_t(vDev->GetDeviceName().c_str());
	RwAdo->SetFieldValue("DeviceName", vValue);
	
	vValue = _variant_t(vDev->GetDeviceType());
	RwAdo->SetFieldValue("DeviceType", vValue);
	

	vValue = _variant_t(vDev->GetPosOrNeg());
	RwAdo->SetFieldValue("PosOrNeg", vValue);


	vValue = _variant_t(vDev->GetStationName().c_str());//文本型
	RwAdo->SetFieldValue("StationName", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
	RwAdo->SetFieldValue("NodeName", vValue);

	
	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID", vValue);
}