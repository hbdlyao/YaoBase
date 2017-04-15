///////////////////////////////////////////////////////////
//  CxbCalDCF.cpp
//  Implementation of the Class CxbCalDCF
//  Created on:      05-4月-2017 18:32:09
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalDCF.h"
#include "CxbDevDCF.h"


void CxbCalDCF::UpdateY()
{
	//马俊鹏
	int iNode, jNode;
	double vYg, vYb;

	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pxbProfile->xbHOrder;

	vDev->InitY(vhOrder); //还要传入频率

	vYg = vDev->GetYg();
	vYb = vDev->GetYb();

	//数组从0开始
	pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}

