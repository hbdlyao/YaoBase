///////////////////////////////////////////////////////////
//  CmcRwOne.cpp
//  Implementation of the Class CmcRwOne
//  Created on:      18-4��-2017 20:24:49
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwOne.h"


void CmcRwOne::doLoad(CmcDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	CmcDevOneDot * vDev;
	
	vDev = dynamic_cast<CmcDevOneDot *>(vDevice);
	
	CmcRw::doLoad(vDevice);
	
	
	RwAdo->GetFieldValue("ID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetObjGUID(vValue.iVal);
	};
		
	RwAdo->GetFieldValue("DeviceID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
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
		vDev->SetDeviceType(vValue.iVal);//����
	};
	
		
	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetStationName(vStr);
	};
	
	RwAdo->GetFieldValue("NodeName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetNodeName(0, vStr);
	};
		

}


void CmcRwOne::doSave(CmcDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	CmcDevOneDot * vDev;
	
	vDev = dynamic_cast<CmcDevOneDot *>(vDevice);
	
	CmcRw::doSave(vDevice);
	
	
	vValue = _variant_t(vDev->GetObjGUID()); //����
	RwAdo->SetFieldValue("ID", vValue);
	
	
	vValue = _variant_t(vDev->GetDeviceID().c_str());//�ı���
	RwAdo->SetFieldValue("DeviceID", vValue);
	
	
	vValue = _variant_t(vDev->GetDeviceName().c_str());
	RwAdo->SetFieldValue("DeviceName", vValue);
	
	vValue = _variant_t(vDev->GetDeviceType());
	RwAdo->SetFieldValue("DeviceType", vValue);
	
			
	vValue = _variant_t(vDev->GetStationName().c_str());//�ı���
	RwAdo->SetFieldValue("StationName", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(0).c_str());//�ı���
	RwAdo->SetFieldValue("NodeName", vValue);
	
	
	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID", vValue);

}