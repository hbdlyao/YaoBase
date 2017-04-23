///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4月-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  OffsetSort
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.默认实现
// 改动时间:  2017/04/20
//************************************
void CmcCalculate::OffsetSort(int& vCurrentOffset)
{
	Offset = -1;
}

void CmcCalculate::Init(CPowerProfile * vProfile)
{
	pProfile = vProfile;
	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
}

void CmcCalculate::LimitUd()//++--
{

}

void CmcCalculate::SaveNormal()
{

}

void CmcCalculate::CalStation_N()
{

}

void CmcCalculate::CalStation()
{

}

void CmcCalculate::CalACSide()
{

}

void CmcCalculate::InitX()
{


}

void CmcCalculate::SaveX()
{


}


void CmcCalculate::UpdateY()
{

}


void CmcCalculate::Prepare()
{

}


void CmcCalculate::UpdateJ() 
{

	//
}


void CmcCalculate::UpdateF_J() 
{

	//
}


void CmcCalculate::PrepareNormal()
{

}

/*
void CmcCalculate::doStationSort(StationMap& vStaMap)
{
	int vN, vID;
	string vName;

	vName = pDevice->GetStationName();
	vN = static_cast<int > (vStaMap.count(vName));

	if (vN == 0)
	{//不存在 vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}

	StationIndex = vStaMap[vName];
}
*/