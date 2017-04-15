///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4月-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"



CmcResult::~CmcResult()
{
	Release();

}

void CmcResult::Release()
{

	Clear();

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Init
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.初始化时使用的数据维数：StaDim改为nDataDim
// 改动时间:  2017/04/12
//************************************
void CmcResult::Init()
{

	nStaDim = 0;
	nCaseDim = 0;
	nPdPreDim = 0;

	//pmcData = nullptr;


}


void CmcResult::Clear()
{
	//delete[] pmcData;
	//pmcData = nullptr;

	mcResultMap.clear();

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  InitMatrix
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.初始化时使用的数据维数：StaDim改为nDataDim
// 改动时间:  2017/04/12
//************************************
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  InitMatrix
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.初始化时使用的数据维数：nDataDim改为nStaDim*nCaseDim*nPdPreDim
// 改动时间:  2017/04/13
//************************************
void CmcResult::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;
	
	//int vN = nStaDim*nCaseDim*nPdPreDim;
	//pmcResultMap = new struct_mcResultData[vN];

}