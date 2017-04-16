#pragma once

#include "gbHead_def.h"

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  CmcResult
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��Աint StaDim��Ϊint nDataDim;
//            2.��ԱmcStation �޸�Ϊ pmcStaData
// �Ķ�ʱ��:  2017/04/12
//************************************
class CmcResult
{
public:
	int nStaDim;
	int nCaseDim;
	int nPdPreDim;

	mc_ResultMap mcResultMap;

	virtual ~CmcResult();
	void Init();
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);

	void Clear();


};
