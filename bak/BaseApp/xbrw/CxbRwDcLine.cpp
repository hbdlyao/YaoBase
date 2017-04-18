///////////////////////////////////////////////////////////
//  CxbRwDcLine.cpp
//  Implementation of the Class CxbRwDcLine
//  Created on:      18-4月-2017 17:11:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDcLine.h"
#include "CxbDevDcLine.h"

void CxbRwDcLine::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine *>(vDevice);

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
	
	RwAdo->GetFieldValue("NodeName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(0, vStr);
	};
	
	RwAdo->GetFieldValue("NodeName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(1, vStr);
	};
	
	RwAdo->GetFieldValue("NodeName3", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(2, vStr);
	};
	
	RwAdo->GetFieldValue("NodeName4", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(3, vStr);
	};
	
	
	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};
	
	
	RwAdo->GetFieldValue("Ys11re", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYs11re(vValue.dblVal);//双精度
	};
	
	
	RwAdo->GetFieldValue("Ys12re", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYs12re(vValue.dblVal);//双精度
	};
	
	
	RwAdo->GetFieldValue("Ym11re", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYm11re(vValue.dblVal);//双精度
	};
	
	
	RwAdo->GetFieldValue("Ym12re", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYm12re(vValue.dblVal);//双精度
	};
	


	RwAdo->GetFieldValue("Ys11im", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYs11im(vValue.dblVal);//双精度
	};


	RwAdo->GetFieldValue("Ys12im", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYs12im(vValue.dblVal);//双精度
	};


	RwAdo->GetFieldValue("Ym11im", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYm11im(vValue.dblVal);//双精度
	};


	RwAdo->GetFieldValue("Ym12im", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetYm12im(vValue.dblVal);//双精度
	};

}


void CxbRwDcLine::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine *>(vDevice);

	CxbRw::doSave(vDevice);

	vValue = _variant_t(vDev->GetObjGUID()); //整型
	RwAdo->SetFieldValue("ID", vValue);
	
	vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
	RwAdo->SetFieldValue("DeviceID", vValue);
	
	vValue = _variant_t(vDev->GetDeviceName().c_str());
	RwAdo->SetFieldValue("DeviceName", vValue);
	
	vValue = _variant_t(vDev->GetDeviceType());
	RwAdo->SetFieldValue("DeviceType", vValue);
	
	
	vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
	RwAdo->SetFieldValue("NodeName1", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(1).c_str());//文本型
	RwAdo->SetFieldValue("NodeName2", vValue);
	
	
	vValue = _variant_t(vDev->GetNodeName(2).c_str());//文本型
	RwAdo->SetFieldValue("NodeName3", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(3).c_str());//文本型
	RwAdo->SetFieldValue("NodeName4", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID1", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(1));
	RwAdo->SetFieldValue("NodeID2", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(2));
	RwAdo->SetFieldValue("NodeID3", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(3));
	RwAdo->SetFieldValue("NodeID4", vValue);
	
	vValue = _variant_t(vDev->GetPosOrNeg());
	RwAdo->SetFieldValue("PosOrNeg", vValue);							
	
	vValue = _variant_t(vDev->GetYs11re());
	RwAdo->SetFieldValue("Ys11re", vValue);
	
	vValue = _variant_t(vDev->GetYs12re());
	RwAdo->SetFieldValue("Ys12re", vValue);
	
	vValue = _variant_t(vDev->GetYm11re());
	RwAdo->SetFieldValue("Ym11re", vValue);
	
	vValue = _variant_t(vDev->GetYm12re());
	RwAdo->SetFieldValue("Ym12re", vValue);

	vValue = _variant_t(vDev->GetYs11im());
	RwAdo->SetFieldValue("Ys11im", vValue);
	
	vValue = _variant_t(vDev->GetYs12im());
	RwAdo->SetFieldValue("Ys12im", vValue);
	
	vValue = _variant_t(vDev->GetYm11im());
	RwAdo->SetFieldValue("Ym11im", vValue);
	
	vValue = _variant_t(vDev->GetYm12im());
	RwAdo->SetFieldValue("Ym12im", vValue);
}