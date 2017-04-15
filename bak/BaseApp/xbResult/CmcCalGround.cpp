///////////////////////////////////////////////////////////
//  CmcCalGround.cpp
//  Implementation of the Class CmcCalGround
//  Created on:      02-4ÔÂ-2017 14:41:41
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcDevGround.h"
#include "CmcCalGround.h"

void CmcCalGround::UpdateY()
{
	int iNode;
	double vY;
	CmcDevGround * vDev;

	vDev = dynamic_cast<CmcDevGround *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);

	vY = vDev->GetY();

	pmcProfile->UpdateY0(iNode, vY);
	
}

