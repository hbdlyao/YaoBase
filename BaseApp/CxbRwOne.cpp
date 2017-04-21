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
	
	vValue = _variant_t(vDev->GetStationName().c_str());//文本型
	RwAdo->SetFieldValue("StationName", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
	RwAdo->SetFieldValue("NodeName", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID", vValue);
}