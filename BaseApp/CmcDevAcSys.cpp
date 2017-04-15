///////////////////////////////////////////////////////////
//  CmcDevAcSys.cpp
//  Implementation of the Class CmcDevAcSys
//  Created on:      04-4月-2017 7:26:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevAcSys.h"


/**
 * 交流系统无功功率
 */
double CmcDevAcSys::GetQac(){

	return Qac;
}


/**
 * 交流系统额定无功功率
 */
double CmcDevAcSys::GetQacN(){

	return QacN;
}


/**
 * 交流系统吸收最大无功
 */
double CmcDevAcSys::GetQinMax(){

	return QinMax;
}


/**
 * 交流系统发出最大无功
 */
double CmcDevAcSys::GetQoutMax(){

	return QoutMax;
}


/**
 * 交流侧电压
 */
double CmcDevAcSys::GetUac(){

	return Uac;
}


/**
 * 交流电压极小值
 */
double CmcDevAcSys::GetUacExMin(){

	return UacExMin;
}


/**
 * 交流电压最大值
 */
double CmcDevAcSys::GetUacMax(){

	return UacMax;
}


/**
 * 交流电压最小值
 */
double CmcDevAcSys::GetUacMin(){

	return UacMin;
}


/**
 * 交流侧额定电压
 */
double CmcDevAcSys::GetUacN(){

	return UacN;
}


/**
 * 交流系统无功功率
 */
void CmcDevAcSys::SetQac(double newVal){

	Qac = newVal;
}


/**
 * 交流系统额定无功功率
 */
void CmcDevAcSys::SetQacN(double newVal){

	QacN = newVal;
}


/**
 * 交流系统吸收最大无功
 */
void CmcDevAcSys::SetQinMax(double newVal){

	QinMax = newVal;
}


/**
 * 交流系统发出最大无功
 */
void CmcDevAcSys::SetQoutMax(double newVal){

	QoutMax = newVal;
}


/**
 * 交流侧电压
 */
void CmcDevAcSys::SetUac(double newVal){

	Uac = newVal;
}


/**
 * 交流电压极小值
 */
void CmcDevAcSys::SetUacExMin(double newVal){

	UacExMin = newVal;
}


/**
 * 交流电压最大值
 */
void CmcDevAcSys::SetUacMax(double newVal){

	UacMax = newVal;
}


/**
 * 交流电压最小值
 */
void CmcDevAcSys::SetUacMin(double newVal){

	UacMin = newVal;
}


/**
 * 交流侧额定电压
 */
void CmcDevAcSys::SetUacN(double newVal){

	UacN = newVal;
}


/**
 * 电网频率
 */
double CmcDevAcSys::GetFreq(){

	return Freq;
}


/**
 * 电网频率
 */
void CmcDevAcSys::SetFreq(int newVal){

	Freq = newVal;
}