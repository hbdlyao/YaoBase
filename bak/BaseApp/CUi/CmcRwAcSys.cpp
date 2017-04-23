///////////////////////////////////////////////////////////
//  CmcRwAcSys.cpp
//  Implementation of the Class CmcRwAcSys
//  Created on:      18-4月-2017 20:38:07
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwAcSys.h"

void CmcRwAcSys::doLoad(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(vDevice);

	CmcRwOne::doLoad(vDevice);

	//
	//RwAdo->GetFieldValue("Qac", vValue);
	//if (vValue.vt != VT_NULL)
	//{
	//	vDev->SetQac(vValue.dblVal); //双精度
	//};

	//RwAdo->GetFieldValue("QacN", vValue);
	//if (vValue.vt != VT_NULL)
	//{
	//	vDev->SetQacN(vValue.dblVal); //双精度
	//};


	//RwAdo->GetFieldValue("Uac", vValue);
	//if (vValue.vt != VT_NULL)
	//{
	//	vDev->SetUac(vValue.dblVal); //双精度
	//};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Qinmax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQinMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Qoutmax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQinMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacExMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacExMin(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMin(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMin(vValue.dblVal); //双精度
	};

}

void CmcRwAcSys::doSave(CmcDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(vDevice);

	CmcRwOne::doSave(vDevice);


	//vValue = _variant_t(vDev->GetQac()); //
	//RwAdo->SetFieldValue("Qac", vValue); //

	//vValue = _variant_t(vDev->GetQacN()); //
	//RwAdo->SetFieldValue("QacN", vValue); //


	//vValue = _variant_t(vDev->GetUac()); //
	//RwAdo->SetFieldValue("Uac", vValue); //

	vValue = _variant_t(vDev->GetUacN()); //
	RwAdo->SetFieldValue("UacN", vValue); //

	vValue = _variant_t(vDev->GetQinMax()); //
	RwAdo->SetFieldValue("QinMax", vValue); //

	vValue = _variant_t(vDev->GetQoutMax()); //
	RwAdo->SetFieldValue("QoutMax", vValue); //

	vValue = _variant_t(vDev->GetUacExMin()); //
	RwAdo->SetFieldValue("UacExMin", vValue); //

	vValue = _variant_t(vDev->GetUacMax()); //
	RwAdo->SetFieldValue("UacMax", vValue); //

	vValue = _variant_t(vDev->GetUacMin()); //
	RwAdo->SetFieldValue("UacMin", vValue); //

											//
}