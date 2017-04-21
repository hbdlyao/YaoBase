///////////////////////////////////////////////////////////
//  CxbCalShunt.cpp
//  Implementation of the Class CxbCalShunt
//  Created on:      05-4月-2017 18:32:21
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalShunt.h"
#include "CxbDevShunt.h"

void CxbCalShunt::UpdateY()
{

	int iNode ;
	double vYg, vYb;

	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);

	//马骏鹏
	int vhOrder = pxbProfile->xbHOrder;
	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);

	//数组从0开始
	pxbProfile->UpdateY0(iNode, vYg, vYb);


}