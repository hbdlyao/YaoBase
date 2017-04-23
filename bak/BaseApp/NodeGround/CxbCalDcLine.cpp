///////////////////////////////////////////////////////////
//  CxbCalDcLine.cpp
//  Implementation of the Class CxbCalDcLine
//  Created on:      05-4月-2017 18:32:32
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalDcLine.h"
//马骏鹏
#include "CxbDevDcLine.h"
#include "CMatrix.h"

void CxbCalDcLine::StationSort(StationMap& vStaMap)
{

}


void CxbCalDcLine::UpdateY()
{
	//有问题

	return;

	//马俊鹏
	//双端口
	int pNode[4];
	CMatrix vY;

	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine * >(pDevice);

	pNode[0] = vDev->GetNodeID(0);
	pNode[1] = vDev->GetNodeID(1);
	pNode[2] = vDev->GetNodeID(2);
	pNode[3] = vDev->GetNodeID(3);

	vY = vDev->GetYMatrix(pxbProfile->xbHOrder);

	//数组从0开始
	//to-do 需考虑接地情况
	pxbProfile->UpdateYLine(pNode, vY);

}


void CxbCalDcLine::NodeGround(NodeMap & vNodeMap)
{
	pDevice->NodeGround(vNodeMap);

	//马俊鹏
	//双端口
	int vdotCount;

	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine * >(pDevice);
	vdotCount = vDev->GetDotCount();

	//马俊鹏
	switch (pxbProfile->pxbOrder->GroundType)
	{
	case xb_Ground10:
		//单极大地
		vNodeMap[vDev->BusName(1)] = -1;
		vNodeMap[vDev->BusName(3)] = -1;
		break;

	case xb_Ground11:
		//单极金属回线
		if (pxbProfile->pxbOrder->GroundStaiton == vDev->StationName1)
			vNodeMap[vDev->BusName(1)] = -1;
		if (pxbProfile->pxbOrder->GroundStaiton == vDev->StationName2)
			vNodeMap[vDev->BusName(3)] = -1;
		break;

		//case xb_Ground20:
		//	//双极中性点
		//case xb_Ground21:
		//	//双极并联大地
		//	break;

	default:
		break;
	}

	//


}
