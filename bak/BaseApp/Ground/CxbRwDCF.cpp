///////////////////////////////////////////////////////////
//  CxbRwDCF.cpp
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4月-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDCF.h"
#include "CxbDevDCF.h"

void CxbRwDCF::doLoad_Data_Root(CxbDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;
	
	vDev = dynamic_cast<CxbDevDCF *>(vDevice);
	
	CxbRwTwo::doLoad(vDev);
	
	RwAdo->GetFieldValue("DcfType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDCFType(vValue.iVal); //双精度
	};
	

}


void CxbRwDCF::doSave_Data_Root(CxbDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(vDevice);

	CxbRwTwo::doSave(vDev);

	vValue = _variant_t(vDev->GetDCFType()); //整型
	RwAdo->SetFieldValue("DcfType", vValue);

}