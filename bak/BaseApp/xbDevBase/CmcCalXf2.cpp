///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4月-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalXf2.h"


void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//崔康生
	//额定值
	pmcProfile->pmcStaDataN[vK].Tap = vDev->GetTapN();

	//实际值
	pmcProfile->pmcStaData[vK].Tap = vDev->GetTap();

}


void CmcCalXf2::CalTap()
{

}

void CmcCalXf2::CalTapNormal()
{
	int vK = 0;
	double vX;

	CmcDevXf2 * vDev;

	//崔康生
	vK = StationIndex;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
		
	//TapN=0 ?
	pmcProfile->UpdateTapN(vK);

	vX = pmcProfile->pmcStaDataN[vK].Tap;

	vDev->SetTapN(ceil(vX)); //取整

}



void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{

}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
}