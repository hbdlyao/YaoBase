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
	int vK=0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//崔康生
	//实际值
	pmcProfile->pmcStaData[vK].Uac = vDev->GetUac();

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

