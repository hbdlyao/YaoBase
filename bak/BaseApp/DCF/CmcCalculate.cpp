///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4月-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"


void CmcCalculate::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	//pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	//pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}


/**
 * 南方电网主回路及谐波计算软件* 改动对象:  PrepareNormal 改动者:    崔康生 改动类型:  新增 改动内容:  1.
 * 存储额定值到Device中 改动时间:  2017/04/18
 */
void CmcCalculate::SaveNormal()
{

}
/**
 * 南方电网主回路及谐波计算软件* 改动对象:  UpdateConvertor_DC至UpdateACSide 改动者:    崔康生 改动类型:  新增
 * 改动内容:  1. 2. 改动时间:  2017/04/18
 */
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