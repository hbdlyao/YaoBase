///////////////////////////////////////////////////////////
//  CmcDevAcFilter.cpp
//  Implementation of the Class CmcDevAcFilter
//  Created on:      04-4��-2017 7:26:31
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevAcFilter.h"


/**
 * ������ѹ
 */
double CmcDevAcFilter::GetQac()
{
	return Qac;
}


/**
 * �˲����޹�
 */
double CmcDevAcFilter::GetQacf(){

	return Qacf;
}


/**
 * �˲�����޹�
 */
double CmcDevAcFilter::GetQacfN(){

	return QacfN;
}


/**
 * �������ѹ
 */
double CmcDevAcFilter::GetQacN(){

	return QacN;
}


/**
 * ������ѹ
 */
void CmcDevAcFilter::SetQac(double newVal){

	Qac = newVal;
}


/**
 * �˲����޹�
 */
void CmcDevAcFilter::SetQacf(double newVal){

	Qacf = newVal;
}


/**
 * �˲�����޹�
 */
void CmcDevAcFilter::SetQacfN(double newVal){

	QacfN = newVal;
}


/**
 * �������ѹ
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