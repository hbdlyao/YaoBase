///////////////////////////////////////////////////////////
//  CmcDevDcLine.cpp
//  Implementation of the Class CmcDevDcLine
//  Created on:      04-4月-2017 7:27:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevDcLine.h"


/**
 * 电阻最大值
 */
double CmcDevDcLine::GetZrMax(){

	return ZrMax;
}


/**
 * 接地类型（单级大地/金属回线/双极）
 */
double CmcDevDcLine::GetZrMin(){

	return ZrMin;
}


/**
 * 电阻最大值
 */
void CmcDevDcLine::SetZrMax(double newVal){

	ZrMax = newVal;
}


/**
 * 接地类型（单级大地/金属回线/双极）
 */
void CmcDevDcLine::SetZrMin(double newVal){

	ZrMin = newVal;
}

