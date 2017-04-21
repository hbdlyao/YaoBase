///////////////////////////////////////////////////////////
//  CmcCalDcLine.cpp
//  Implementation of the Class CmcCalDcLine
//  Created on:      02-4��-2017 14:41:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalDcLine.h"
#include "CmcDevDcLine.h"


void CmcCalDcLine::StationSort(StationMap& vStaMap)
{//������

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
	
	//�����0��ʼ
	if ((iNode != -1) && (jNode != -1)) //�ӵ�
		pmcProfile->UpdateY(iNode, jNode, vY);
	
	if (iNode == -1)
		pmcProfile->UpdateY0(jNode, vY);
	
	if (jNode == -1)
		pmcProfile->UpdateY0(iNode, vY);

	
}

