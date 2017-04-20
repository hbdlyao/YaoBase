///////////////////////////////////////////////////////////
//  CxbCalDCF.cpp
//  Implementation of the Class CxbCalDCF
//  Created on:      05-4��-2017 18:32:09
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalDCF.h"
#include "CxbDevDCF.h"


void CxbCalDCF::UpdateY()
{
	//����
	int iNode, jNode;
	double vYg, vYb;

	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pxbProfile->xbHOrder;

	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);

	//�����0��ʼ
	pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}

