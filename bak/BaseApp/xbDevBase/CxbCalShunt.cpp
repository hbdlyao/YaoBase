///////////////////////////////////////////////////////////
//  CxbCalShunt.cpp
//  Implementation of the Class CxbCalShunt
//  Created on:      05-4月-2017 18:32:21
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalShunt.h"

void CxbCalShunt::UpdateY()
{
	int iNode;
	double vYg, vYb;

	CDevShunt * vDev;

	vDev = dynamic_cast<CDevShunt *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);
	
	//马骏鹏
	double vOmega = pxbProfile->Omega();
	vYg = vDev->GetYg(vOmega);
	vYb = vDev->GetYb(vOmega);

	//数组从0开始
	pxbProfile->UpdateY0(iNode, vYg, vYb);

}