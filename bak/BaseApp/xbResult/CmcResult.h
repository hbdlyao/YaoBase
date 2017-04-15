#pragma once

#include "gbHead_def.h"

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  CmcResult
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.成员int StaDim改为int nDataDim;
//            2.成员mcStation 修改为 pmcStaData
// 改动时间:  2017/04/12
//************************************
class CmcResult
{
public:
	int nStaDim;
	int nCaseDim;
	int nPdPreDim;

	mc_ResultMap mcResultMap;

	~CmcResult();
	void Init();
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);

	void Clear();
	void Release();

};
