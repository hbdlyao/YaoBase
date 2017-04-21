///////////////////////////////////////////////////////////
//  CxbDevBase.cpp
//  Implementation of the Class CxbDevBase
//  Created on:      12-4��-2017 14:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBase.h"
#include "CHvdcParams.h"

void CxbDevBase::InitData()
{
}

/**
 * ������������  ������� �������� ˫��
 */
int CxbDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}


/**
 * ������������  ������� �������� ˫��
 */
void CxbDevBase::SetPosOrNeg(int newVal){

	PosOrNeg = newVal;
}


void CxbDevBase::Prepare_hRLC()
{

}


/**
 * ���г������
 */
int CxbDevBase::hMax()
{

	return CHvdcParams::hMax;
}


/**
 * ����Ƶ��
 */
double CxbDevBase::FreqRef()
{
	return CHvdcParams::Frequence;
}


double CxbDevBase::Omega()
{

	return 2 * PI*FreqRef();
}