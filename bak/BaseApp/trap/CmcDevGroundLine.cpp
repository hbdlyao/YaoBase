///////////////////////////////////////////////////////////
//  CmcDevGroundLine.cpp
//  Implementation of the Class CmcDevGroundLine
//  Created on:      04-4��-2017 7:27:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevGroundLine.h"



/**
 * �������ֵ
 */
double CmcDevGroundLine::GetZrMax(){

	return ZrMax;
}


/**
 * �ӵ����ͣ��������/��������/˫����
 */
double CmcDevGroundLine::GetZrMin(){

	return ZrMin;
}


/**
 * �������ֵ
 */
void CmcDevGroundLine::SetZrMax(double newVal){

	ZrMax = newVal;
}


/**
 * �ӵ����ͣ��������/��������/˫����
 */
void CmcDevGroundLine::SetZrMin(double newVal){

	ZrMin = newVal;
}

