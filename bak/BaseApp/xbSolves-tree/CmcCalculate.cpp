///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4��-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"


void CmcCalculate::Init(CPowerProfile * vProfile)
{
	pProfile = vProfile;
	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
}

void CmcCalculate::SaveNormal()
{

}


void CmcCalculate::CalConvertor_DC()
{

}
/**
 * ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
 */
void CmcCalculate::CalConvertor_AC()
{

}
/**
 * �����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
 */
void CmcCalculate::CalConvertor_Port()
{

}

/**
 * ����ֱ���˿���֪��Uv��Ud��Id��
 */
void CmcCalculate::CalXf2_l()
{

}
/**
 * ���༰�����֪��Uv��Nnorm��Tc��
 */
void CmcCalculate::CalXf2_v()
{

}
/**
 * ���༰�����֪��Ul��Nnorm��TC��
 */
void CmcCalculate::CalXf2_Port()
{

}
/**
 * ����˿ڼ��ֽ�ͷ��֪��Ul��Uv��TC��
 */
void CmcCalculate::CalXf2_UpShift()
{

}
/**
 * ���಻�䣬�ϵ�һ���ֽ�ͷ
 */
void CmcCalculate::CalXf2_DownShift()
{

}

/**
 * ���಻�䣬�µ�һ���ֽ�ͷ
 */
void CmcCalculate::CalACSide()
{

}


void CmcCalculate::InitX()
{


}


void CmcCalculate::UpdateY() {

}


void CmcCalculate::Prepare()
{

}


void CmcCalculate::UpdateJ() {

	//
}


void CmcCalculate::UpdateF_J() {

	//
}




void CmcCalculate::PrepareNormal() {

}