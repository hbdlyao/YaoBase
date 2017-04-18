///////////////////////////////////////////////////////////
//  CxbCalDcLine.cpp
//  Implementation of the Class CxbCalDcLine
//  Created on:      05-4��-2017 18:32:32
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalDcLine.h"
//����
#include "CxbDevDcLine.h"
#include "CMatrix.h"

void CxbCalDcLine::StationSort(StationMap& vStaMap)
{

}


void CxbCalDcLine::UpdateY()
{
	//����
	//˫�˿�
	int pNode[4];
	CMatrix vY;

	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine * >(pDevice);

	pNode[0] = vDev->GetNodeID(0);
	pNode[1] = vDev->GetNodeID(1);
	pNode[2] = vDev->GetNodeID(2);
	pNode[3] = vDev->GetNodeID(3);

	vY = vDev->GetYMatrix(pxbProfile->xbHOrder);

	//�����0��ʼ
	//to-do �迼�ǽӵ����
	pxbProfile->UpdateYLine(pNode, vY);


}


void CxbCalDcLine::NodeGround(NodeMap & vNodeMap)
{
	//����
	//˫�˿�
	int vdotCount;

	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine * >(pDevice);
	vdotCount = vDev->GetDotCount();

	//����
	switch (pxbProfile->pxbOrder->GroundType)
	{
	case xb_Ground10:
		//�������
		vNodeMap[vDev->GetNodeName(1)] = -1;
		vNodeMap[vDev->GetNodeName(3)] = -1;
		break;

	case xb_Ground11:
		//������������
		if (pxbProfile->pxbOrder->GroundStaiton == vDev->StationName1)
			vNodeMap[vDev->GetNodeName(1)] = -1;
		if (pxbProfile->pxbOrder->GroundStaiton == vDev->StationName2)
			vNodeMap[vDev->GetNodeName(3)] = -1;
		break;
		//case xb_Ground20:
		//	//˫�����Ե�
		//case xb_Ground21:
		//	//˫���������
		//	break;

	default:
		break;
	}

}
