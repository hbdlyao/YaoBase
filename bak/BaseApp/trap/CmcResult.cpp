///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4��-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"


CmcResult::~CmcResult()
{
	Clear();
}


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  Init
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ʼ��ʱʹ�õ�����ά����StaDim��ΪnDataDim
// �Ķ�ʱ��:  2017/04/12
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
// *�Ϸ���������·��г���������*
// �Ķ�����:  InitMatrix
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ʼ��ʱʹ�õ�����ά����StaDim��ΪnDataDim
// �Ķ�ʱ��:  2017/04/12
//************************************
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  InitMatrix
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ʼ��ʱʹ�õ�����ά����nDataDim��ΪnStaDim*nCaseDim*nPdPreDim
// �Ķ�ʱ��:  2017/04/13
//************************************
void CmcResult::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;
	
	//int vN = nStaDim*nCaseDim*nPdPreDim;
	//pmcResultMap = new struct_mcResultData[vN];

}