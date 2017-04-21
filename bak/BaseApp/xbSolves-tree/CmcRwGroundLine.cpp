///////////////////////////////////////////////////////////
//  CmcRwGroundLine.cpp
//  Implementation of the Class CmcRwGroundLine
//  Created on:      18-4月-2017 22:02:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwGroundLine.h"


void CmcRwGroundLine::doLoad(CmcDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	CmcDevGroundLine * vDev;
	
	vDev = dynamic_cast<CmcDevGroundLine *>(vDevice);
	
	CmcRwOne::doLoad(vDevice);
	
	//
	RwAdo->GetFieldValue("ZrN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrN(vValue.dblVal); //双精度
	};


	//
	RwAdo->GetFieldValue("ZrMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMax(vValue.dblVal); //双精度
	};


	//
	RwAdo->GetFieldValue("ZrMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMin(vValue.dblVal); //双精度
	};

}


void CmcRwGroundLine::doSave(CmcDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	CmcDevGroundLine * vDev;
	
	vDev = dynamic_cast<CmcDevGroundLine *>(vDevice);
	
	CmcRwOne::doSave(vDevice);

	vValue = _variant_t(vDev->GetZrN()); //
	RwAdo->SetFieldValue("ZrN", vValue); //

	vValue = _variant_t(vDev->GetZrMax()); //
	RwAdo->SetFieldValue("ZrMax", vValue); //

	vValue = _variant_t(vDev->GetZrMin()); //
	RwAdo->SetFieldValue("ZrMin", vValue); //

	
										  //
}