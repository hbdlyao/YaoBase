///////////////////////////////////////////////////////////
//  CmcRwAcSys.cpp
//  Implementation of the Class CmcRwAcSys
//  Created on:      18-4��-2017 20:38:07
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
	//	vDev->SetQac(vValue.dblVal); //˫����
	//};

	//RwAdo->GetFieldValue("QacN", vValue);
	//if (vValue.vt != VT_NULL)
	//{
	//	vDev->SetQacN(vValue.dblVal); //˫����
	//};


	//RwAdo->GetFieldValue("Uac", vValue);
	//if (vValue.vt != VT_NULL)
	//{
	//	vDev->SetUac(vValue.dblVal); //˫����
	//};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Qinmax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQinMax(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Qoutmax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQinMax(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UacExMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacExMin(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UacMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMin(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UacMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMin(vValue.dblVal); //˫����
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