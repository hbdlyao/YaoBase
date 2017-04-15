///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4月-2017 14:41:33
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcSys.h"


void CmcCalAcSys::Prepare()
{
	int vK=0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//崔康生
	//Yao
	//额定值
	pmcProfile->pmcStaDataN[vK].Uac = vDev->GetUacN();

	//实际值
	pmcProfile->pmcStaData[vK].Uac = vDev->GetUac();

}


void CmcCalAcSys::NodeSort(NodeMap& vNodeMap)
{

}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
}