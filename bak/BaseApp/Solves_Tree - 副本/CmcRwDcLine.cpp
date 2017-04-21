///////////////////////////////////////////////////////////
//  CmcRwDcLine.cpp
//  Implementation of the Class CmcRwDcLine
//  Created on:      18-4��-2017 21:41:07
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwDcLine.h"


void CmcRwDcLine::doLoad(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevDcLine * vDev;

	vDev = dynamic_cast<CmcDevDcLine *>(vDevice);

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

	RwAdo->GetFieldValue("StationName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetStationName1(vStr);
	};

	RwAdo->GetFieldValue("StationName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetStationName2(vStr);
	};

	RwAdo->GetFieldValue("NodeName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetNodeName(0, vStr);
	};

	RwAdo->GetFieldValue("NodeName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //�ַ���
		vDev->SetNodeName(1, vStr);
	};


	/*
	RwAdo->GetFieldValue("NodeID1", vValue);
	if (vValue.vt != VT_NULL)
	{
	vDev->SetNodeID(0, vValue.iVal);//����
	};

	RwAdo->GetFieldValue("NodeID2", vValue);
	if (vValue.vt != VT_NULL)
	{
	vDev->SetNodeID(1, vValue.iVal);//����
	};
	*/


	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  
	// �Ķ���:    �޿���
	// �Ķ�����:  
	// �Ķ�����:  Zr��ΪZrN
	// �Ķ�ʱ��:  2017/04/17
	//************************************

	RwAdo->GetFieldValue("ZrN", vValue);

	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrN(vValue.dblVal); //˫����
	};


	//
	RwAdo->GetFieldValue("ZrMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMax(vValue.dblVal); //˫����
	};


	//
	RwAdo->GetFieldValue("ZrMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMin(vValue.dblVal); //˫����
	};

}


void CmcRwDcLine::doSave(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevDcLine * vDev;

	vDev = dynamic_cast<CmcDevDcLine *>(vDevice);

	CmcRw::doSave(vDevice);

	vValue = _variant_t(vDev->GetObjGUID()); //����
	RwAdo->SetFieldValue("ID", vValue);

	vValue = _variant_t(vDev->GetDeviceID().c_str());//�ı���
	RwAdo->SetFieldValue("DeviceID", vValue);

	vValue = _variant_t(vDev->GetDeviceName().c_str());
	RwAdo->SetFieldValue("DeviceName", vValue);

	vValue = _variant_t(vDev->GetDeviceType());
	RwAdo->SetFieldValue("DeviceType", vValue);

	vValue = _variant_t(vDev->GetStationName1().c_str());//�ı���
	RwAdo->SetFieldValue("StationName1", vValue);

	vValue = _variant_t(vDev->GetStationName2().c_str());//�ı���
	RwAdo->SetFieldValue("StationName2", vValue);

	vValue = _variant_t(vDev->GetNodeName(0).c_str());//�ı���
	RwAdo->SetFieldValue("NodeName1", vValue);

	vValue = _variant_t(vDev->GetNodeName(1).c_str());//�ı���
	RwAdo->SetFieldValue("NodeName2", vValue);

	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID1", vValue);

	vValue = _variant_t(vDev->GetNodeID(1));
	RwAdo->SetFieldValue("NodeID2", vValue);

	vValue = _variant_t(vDev->GetZrN()); //
	RwAdo->SetFieldValue("ZrN", vValue); //

	vValue = _variant_t(vDev->GetZrMax()); //
	RwAdo->SetFieldValue("ZrMax", vValue); //

	vValue = _variant_t(vDev->GetZrMin()); //
	RwAdo->SetFieldValue("ZrMin", vValue); //


										  //
}