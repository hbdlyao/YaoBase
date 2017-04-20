///////////////////////////////////////////////////////////
//  CmcRwShunt.cpp
//  Implementation of the Class CmcRwShunt
//  Created on:      18-4��-2017 20:25:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwShunt.h"

void CmcRwShunt::doLoad(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevShunt * vDev;
	
	vDev = dynamic_cast<CmcDevShunt *>(vDevice);
	
	CmcRwOne::doLoad(vDevice);
	
	
	RwAdo->GetFieldValue("Zr", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZr(vValue.dblVal); //˫����
	};
	
	RwAdo->GetFieldValue("Z_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_L(vValue.dblVal); //˫����
	};
	
	RwAdo->GetFieldValue("Z_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_C(vValue.dblVal); //˫����
	};
	
	RwAdo->GetFieldValue("Zx_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_L(vValue.dblVal); //˫����
	};
	
	RwAdo->GetFieldValue("Zx_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_C(vValue.dblVal); //˫����
	};
}


void CmcRwShunt::doSave(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevShunt * vDev;
	
	vDev = dynamic_cast<CmcDevShunt *>(vDevice);
	
	CmcRwOne::doSave(vDevice);
	
	
	//
	vValue = _variant_t(vDev->GetZr()); //
	RwAdo->SetFieldValue("Zr", vValue); //
	
	
	vValue = _variant_t(vDev->GetZ_L()); //
	RwAdo->SetFieldValue("Z_L", vValue); //
	
	vValue = _variant_t(vDev->GetZ_C()); //
	RwAdo->SetFieldValue("Z_C", vValue); //
	
	vValue = _variant_t(vDev->GetZx_L()); //
	RwAdo->SetFieldValue("Zx_L", vValue); //
	
	vValue = _variant_t(vDev->GetZx_C()); //
	RwAdo->SetFieldValue("Zx_C", vValue); //
}