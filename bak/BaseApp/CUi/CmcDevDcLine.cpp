///////////////////////////////////////////////////////////
//  CmcDevDcLine.cpp
//  Implementation of the Class CmcDevDcLine
//  Created on:      04-4��-2017 7:27:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevDcLine.h"


/**
 * �������ֵ
 */
double CmcDevDcLine::GetZrMax(){

	return ZrMax;
}


/**
 * �ӵ����ͣ��������/��������/˫����
 */
double CmcDevDcLine::GetZrMin(){

	return ZrMin;
}


/**
 * �������ֵ
 */
void CmcDevDcLine::SetZrMax(double newVal){

	ZrMax = newVal;
}


/**
 * �ӵ����ͣ��������/��������/˫����
 */
void CmcDevDcLine::SetZrMin(double newVal){

	ZrMin = newVal;
}

