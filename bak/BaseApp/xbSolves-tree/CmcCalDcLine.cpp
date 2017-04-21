///////////////////////////////////////////////////////////
//  CmcCalDcLine.cpp
//  Implementation of the Class CmcCalDcLine
//  Created on:      02-4月-2017 14:41:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalDcLine.h"
#include "CmcDevDcLine.h"


void CmcCalDcLine::StationSort(StationMap& vStaMap)
{//不参与

}

void CmcCalDcLine::UpdateY()
{
	int iNode, jNode;
	double vY;
	
	CmcDevDcLine * vDev;
	
	vDev = dynamic_cast<CmcDevDcLine *>(pDevice);
	
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	//
	vY = vDev->GetY();
	
	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pmcProfile->UpdateY(iNode, jNode, vY);
	
	if (iNode == -1)
		pmcProfile->UpdateY0(jNode, vY);
	
	if (jNode == -1)
		pmcProfile->UpdateY0(iNode, vY);

	
}

