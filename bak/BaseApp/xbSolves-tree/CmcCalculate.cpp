///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4月-2017 14:40:28
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
 * 直流侧及角度已知（Ud、Id、alpha/gamma）
 */
void CmcCalculate::CalConvertor_AC()
{

}
/**
 * 交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
 */
void CmcCalculate::CalConvertor_Port()
{

}

/**
 * 交、直流端口已知（Uv、Ud、Id）
 */
void CmcCalculate::CalXf2_l()
{

}
/**
 * 网侧及变比已知（Uv、Nnorm、Tc）
 */
void CmcCalculate::CalXf2_v()
{

}
/**
 * 阀侧及变比已知（Ul、Nnorm、TC）
 */
void CmcCalculate::CalXf2_Port()
{

}
/**
 * 两侧端口及分接头已知（Ul、Uv、TC）
 */
void CmcCalculate::CalXf2_UpShift()
{

}
/**
 * 网侧不变，上调一及分接头
 */
void CmcCalculate::CalXf2_DownShift()
{

}

/**
 * 网侧不变，下调一及分接头
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