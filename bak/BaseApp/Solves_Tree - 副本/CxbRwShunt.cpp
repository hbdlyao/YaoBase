///////////////////////////////////////////////////////////
//  CxbRwShunt.cpp
//  Implementation of the Class CxbRwShunt
//  Created on:      18-4月-2017 17:11:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwShunt.h"
#include "CxbDevShunt.h"

void CxbRwShunt::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(vDevice);

	CxbRwOne::doLoad(vDev);


	RwAdo->GetFieldValue("Zr", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZr(vValue.dblVal); //双精度
	};
	
	RwAdo->GetFieldValue("Z_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_L(vValue.dblVal); //双精度
	};
	
	RwAdo->GetFieldValue("Z_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_C(vValue.dblVal); //双精度
	};
	
	RwAdo->GetFieldValue("Zx_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_L(vValue.dblVal); //双精度
	};
	
	RwAdo->GetFieldValue("Zx_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_C(vValue.dblVal); //双精度
	};
}


void CxbRwShunt::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(vDevice);

	CxbRwOne::doSave(vDev);

	
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