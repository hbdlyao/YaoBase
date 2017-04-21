///////////////////////////////////////////////////////////
//  CxbRwDCF.cpp
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4月-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDCF.h"
#include "CxbDevDCF.h"
#include "CxbDevDCF_RLC.h"


void CxbRwDCF::doLoad_Root(CxbDevBase* vRoot)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;
	
	vDev = dynamic_cast<CxbDevDCF *>(vRoot);
	
	CxbRw::doLoad(vDev);
	
	RwAdo->GetFieldValue("DcfType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDCFType(vValue.iVal); //整型
	};

	RwAdo->GetFieldValue("MaxFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxFreqDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinFreqDelta(vValue.dblVal); //双精度
	};
	
}


void CxbRwDCF::doSave_Root(CxbDevBase* vRoot)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(vRoot);

	CxbRw::doSave(vDev);

	vValue = _variant_t(vDev->GetDCFType()); //整型
	RwAdo->SetFieldValue("DcfType", vValue);

	vValue = _variant_t(vDev->GetMaxFreqDelta()); //双精度
	RwAdo->SetFieldValue("MaxFreqDelta", vValue);

	vValue = _variant_t(vDev->GetMinFreqDelta()); //双精度
	RwAdo->SetFieldValue("MinFreqDelta", vValue);
}


void CxbRwDCF::doLoad_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwBranch::doLoad(vDev);

	//
	RwAdo->GetFieldValue("MaxRDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxRDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinRDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinRDelta(vValue.dblVal); //双精度
	};

	//
	RwAdo->GetFieldValue("MaxLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxLDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinLDelta(vValue.dblVal); //双精度
	};

	//
	RwAdo->GetFieldValue("MaxCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxCDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinCDelta(vValue.dblVal); //双精度
	};

}

void CxbRwDCF::doSave_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwBranch::doSave(vDev);

	vValue = _variant_t(vDev->GetMaxRDelta()); //双精度
	RwAdo->SetFieldValue("MaxRDelta", vValue);

	vValue = _variant_t(vDev->GetMinRDelta()); //双精度
	RwAdo->SetFieldValue("MinRDelta", vValue);

	vValue = _variant_t(vDev->GetMaxLDelta()); //双精度
	RwAdo->SetFieldValue("MaxLDelta", vValue);

	vValue = _variant_t(vDev->GetMinLDelta()); //双精度
	RwAdo->SetFieldValue("MinLDelta", vValue);

	vValue = _variant_t(vDev->GetMaxCDelta()); //双精度
	RwAdo->SetFieldValue("MaxCDelta", vValue);

	vValue = _variant_t(vDev->GetMinCDelta()); //双精度
	RwAdo->SetFieldValue("MinCDelta", vValue);

}

