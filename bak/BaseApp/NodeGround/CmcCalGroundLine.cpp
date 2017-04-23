///////////////////////////////////////////////////////////
//  CmcCalGroundLine.cpp
//  Implementation of the Class CmcCalGroundLine
//  Created on:      02-4ÔÂ-2017 14:42:03
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalGroundLine.h"
#include "CmcDevGroundLine.h"

void CmcCalGroundLine::UpdateY()
{
	int iNode;
	double vY;
	CmcDevGroundLine * vDev;

	vDev = dynamic_cast<CmcDevGroundLine *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);

	vY = vDev->GetY();

	pmcProfile->UpdateY0(iNode, vY);

}

