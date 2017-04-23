///////////////////////////////////////////////////////////
//  CxbDevBase.cpp
//  Implementation of the Class CxbDevBase
//  Created on:      12-4月-2017 14:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBase.h"
#include "CHvdcParams.h"

void CxbDevBase::InitData()
{
}

/**
 * 所属拓扑类型  单极大地 单极金属 双极
 */
int CxbDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}


/**
 * 所属拓扑类型  单极大地 单极金属 双极
 */
void CxbDevBase::SetPosOrNeg(int newVal){

	PosOrNeg = newVal;
}


void CxbDevBase::Prepare_hRLC()
{

}


/**
 * 最大谐波次数
 */
int CxbDevBase::hMax()
{

	return CHvdcParams::hMax;
}


/**
 * 基波频率
 */
double CxbDevBase::FreqRef()
{
	return CHvdcParams::Frequence;
}


double CxbDevBase::Omega()
{

	return 2 * PI*FreqRef();
}


string CxbDevBase::BusName(int vIndex)
{
	string vBus;
	
	vBus = GetStationName() + "---" + GetNodeName(vIndex);
	
	if (GetNodeName(vIndex) == "-1")
		vBus = "-1";
	
	return vBus;
}