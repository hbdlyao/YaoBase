///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4月-2017 14:41:33
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcSys.h"
#include "CmcDevAcSys.h"

void CmcCalAcSys::Prepare()
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//设备参数
	pmcProfile->pmcStaData[vK].QacInMax = vDev->GetQinMax();
	pmcProfile->pmcStaData[vK].QacOutMax = vDev->GetQoutMax();

	//指令相关
	switch (pmcProfile->pmcOrder->UacLevel[vK])
	{
	case Uac_Max:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacMax();
		break;
	case Uac_Min:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacMin();
		break;
	case Uac_ExMin:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacExMin();
		break;
	default:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacN();
		break;
	}

}


void CmcCalAcSys::PrepareNormal() 
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//崔康生
	//额定值
	pmcProfile->pmcStaDataN[vK].Uac = vDev->GetUacN();

}

void CmcCalAcSys::NodeSort(NodeMap& vNodeMap)
{
	//不参与节点编号
}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
	//不参与节点编号
}

