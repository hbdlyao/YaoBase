///////////////////////////////////////////////////////////
//  CxbRwTwo.cpp
//  Implementation of the Class CxbRwTwo
//  Created on:      18-4月-2017 17:11:07
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwTwo.h"
#include "CxbDevTwoDot.h"

void CxbRwTwo::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevTwoDot * vDev;

	vDev = dynamic_cast<CxbDevTwoDot *>(vDevice);

	CxbRw::doLoad(vDevice);

	
	RwAdo->GetFieldValue("StationName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetStationName1(vStr);
	};
	
	RwAdo->GetFieldValue("StationName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetStationName2(vStr);
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

	/*
	RwAdo->GetFieldValue("NodeID1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(0, vValue.iVal);//整型
	};
	
	RwAdo->GetFieldValue("NodeID2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(1, vValue.iVal);//整型
	};
	*/
}


void CxbRwTwo::doSave(CxbDevBase * vDevice) 
{
	string vStr;
	_variant_t vValue;
	CxbDevTwoDot * vDev;

	vDev = dynamic_cast<CxbDevTwoDot *>(vDevice);

	CxbRw::doSave(vDevice);

	vValue = _variant_t(vDev->GetStationName1().c_str());//文本型
	RwAdo->SetFieldValue("StationName1", vValue);
	
	vValue = _variant_t(vDev->GetStationName2().c_str());//文本型
	RwAdo->SetFieldValue("StationName2", vValue);

	vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
	RwAdo->SetFieldValue("NodeName1", vValue);
	
	vValue = _variant_t(vDev->GetNodeName(1).c_str());//文本型
	RwAdo->SetFieldValue("NodeName2", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(0));
	RwAdo->SetFieldValue("NodeID1", vValue);
	
	vValue = _variant_t(vDev->GetNodeID(1));
	RwAdo->SetFieldValue("NodeID2", vValue);
}