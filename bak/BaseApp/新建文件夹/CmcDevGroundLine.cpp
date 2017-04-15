///////////////////////////////////////////////////////////
//  CmcDevGroundLine.cpp
//  Implementation of the Class CmcDevGroundLine
//  Created on:      04-4月-2017 7:27:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevGroundLine.h"



/**
 * 电阻最大值
 */
double CmcDevGroundLine::GetZrMax(){

	return ZrMax;
}


/**
 * 接地类型（单级大地/金属回线/双极）
 */
double CmcDevGroundLine::GetZrMin(){

	return ZrMin;
}


/**
 * 电阻最大值
 */
void CmcDevGroundLine::SetZrMax(double newVal){

	ZrMax = newVal;
}


/**
 * 接地类型（单级大地/金属回线/双极）
 */
void CmcDevGroundLine::SetZrMin(double newVal){

	ZrMin = newVal;
}

