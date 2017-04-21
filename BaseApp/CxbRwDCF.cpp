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

}


void CxbRwDCF::doLoad_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwBranch::doLoad(vDev);

}

void CxbRwDCF::doSave_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwBranch::doSave(vDev);

}

