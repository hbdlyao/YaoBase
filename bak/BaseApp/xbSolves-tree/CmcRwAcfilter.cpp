///////////////////////////////////////////////////////////
//  CmcRwAcfilter.cpp
//  Implementation of the Class CmcRwAcfilter
//  Created on:      18-4月-2017 20:38:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwAcfilter.h"


void CmcRwAcfilter::doLoad(CmcDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcFilter * vDev;

	vDev = dynamic_cast<CmcDevAcFilter *>(vDevice);

	CmcRwOne::doLoad(vDevice);


	RwAdo->GetFieldValue("Qacf", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQacf(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QacfN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQacfN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Qac", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQac(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQacN(vValue.dblVal); //双精度
	};

}


void CmcRwAcfilter::doSave(CmcDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcFilter * vDev;

	vDev = dynamic_cast<CmcDevAcFilter *>(vDevice);

	CmcRwOne::doSave(vDevice);


	vValue = _variant_t(vDev->GetQacf()); //
	RwAdo->SetFieldValue("Qacf", vValue); //

	vValue = _variant_t(vDev->GetQacfN()); //
	RwAdo->SetFieldValue("QacfN", vValue); //


	vValue = _variant_t(vDev->GetUac()); //
	RwAdo->SetFieldValue("Uac", vValue); //

	vValue = _variant_t(vDev->GetUacN()); //
	RwAdo->SetFieldValue("UacN", vValue); //

	vValue = _variant_t(vDev->GetQac()); //
	RwAdo->SetFieldValue("Qac", vValue); //

	vValue = _variant_t(vDev->GetQacN()); //
	RwAdo->SetFieldValue("QacN", vValue); //

	//
}