///////////////////////////////////////////////////////////
//  CxbRwDCF.cpp
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4��-2017 23:40:50
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
		vDev->SetDCFType(vValue.iVal); //����
	};

	RwAdo->GetFieldValue("MaxFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxFreqDelta(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("MinFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinFreqDelta(vValue.dblVal); //˫����
	};
	
}


void CxbRwDCF::doSave_Root(CxbDevBase* vRoot)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(vRoot);

	CxbRw::doSave(vDev);

	vValue = _variant_t(vDev->GetDCFType()); //����
	RwAdo->SetFieldValue("DcfType", vValue);

	vValue = _variant_t(vDev->GetMaxFreqDelta()); //˫����
	RwAdo->SetFieldValue("MaxFreqDelta", vValue);

	vValue = _variant_t(vDev->GetMinFreqDelta()); //˫����
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
		vDev->SetMaxRDelta(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("MinRDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinRDelta(vValue.dblVal); //˫����
	};

	//
	RwAdo->GetFieldValue("MaxLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxLDelta(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("MinLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinLDelta(vValue.dblVal); //˫����
	};

	//
	RwAdo->GetFieldValue("MaxCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxCDelta(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("MinCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinCDelta(vValue.dblVal); //˫����
	};

}

void CxbRwDCF::doSave_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwBranch::doSave(vDev);

	vValue = _variant_t(vDev->GetMaxRDelta()); //˫����
	RwAdo->SetFieldValue("MaxRDelta", vValue);

	vValue = _variant_t(vDev->GetMinRDelta()); //˫����
	RwAdo->SetFieldValue("MinRDelta", vValue);

	vValue = _variant_t(vDev->GetMaxLDelta()); //˫����
	RwAdo->SetFieldValue("MaxLDelta", vValue);

	vValue = _variant_t(vDev->GetMinLDelta()); //˫����
	RwAdo->SetFieldValue("MinLDelta", vValue);

	vValue = _variant_t(vDev->GetMaxCDelta()); //˫����
	RwAdo->SetFieldValue("MaxCDelta", vValue);

	vValue = _variant_t(vDev->GetMinCDelta()); //˫����
	RwAdo->SetFieldValue("MinCDelta", vValue);

}

