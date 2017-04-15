///////////////////////////////////////////////////////////
//  CmcDevAcFilter.cpp
//  Implementation of the Class CmcDevAcFilter
//  Created on:      04-4月-2017 7:26:31
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevAcFilter.h"


/**
 * 交流电压
 */
double CmcDevAcFilter::GetQac()
{
	return Qac;
}


/**
 * 滤波器无功
 */
double CmcDevAcFilter::GetQacf(){

	return Qacf;
}


/**
 * 滤波器额定无功
 */
double CmcDevAcFilter::GetQacfN(){

	return QacfN;
}


/**
 * 额定交流电压
 */
double CmcDevAcFilter::GetQacN(){

	return QacN;
}


/**
 * 交流电压
 */
void CmcDevAcFilter::SetQac(double newVal){

	Qac = newVal;
}


/**
 * 滤波器无功
 */
void CmcDevAcFilter::SetQacf(double newVal){

	Qacf = newVal;
}


/**
 * 滤波器额定无功
 */
void CmcDevAcFilter::SetQacfN(double newVal){

	QacfN = newVal;
}


/**
 * 额定交流电压
 */
void CmcDevAcFilter::SetQacN(double newVal){

	QacN = newVal;
}


double CmcDevAcFilter::GetUac(){

	return Uac;
}


void CmcDevAcFilter::SetUac(double newVal){

	Uac = newVal;
}


double CmcDevAcFilter::GetUacN(){

	return UacN;
}


void CmcDevAcFilter::SetUacN(double newVal){

	UacN = newVal;
}