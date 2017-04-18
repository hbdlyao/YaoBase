///////////////////////////////////////////////////////////
//  CxbRw3pVSrc.cpp
//  Implementation of the Class CxbRw3pVSrc
//  Created on:      18-4ÔÂ-2017 17:17:11
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRw3pVSrc.h"
#include "CxbDev3pVSrc.h"


void CxbRw3pVSrc::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevTwoDot * vDev;

	vDev = dynamic_cast<CxbDevTwoDot *>(vDevice);

	CxbRwTwo::doLoad(vDevice);
}


void CxbRw3pVSrc::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(vDevice);

	CxbRwTwo::doSave(vDevice);

}