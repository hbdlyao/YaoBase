///////////////////////////////////////////////////////////
//  CAcFilterVo.cpp
//  Implementation of the Class CAcFilterVo
//  Created on:      04-4月-2017 7:02:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CAcFilterVo.h"




/**
 * 交流滤波器类型（单调谐/双调谐）
 */
int CAcFilterVo::GetAcfType(){

	return AcfType;
}


/**
 * 交流电压
 */
double CAcFilterVo::GetQac(){

	return Qac;
}


/**
 * 滤波器无功
 */
double CAcFilterVo::GetQacf(){

	return Qacf;
}


/**
 * 滤波器额定无功
 */
double CAcFilterVo::GetQacfN(){

	return QacfN;
}


/**
 * 额定交流电压
 */
double CAcFilterVo::GetQacN(){

	return QacN;
}


/**
 * 电容
 */
double CAcFilterVo::GetZc(){

	return Zc;
}


/**
 * 电阻
 */
double CAcFilterVo::GetZr(){

	return Zr;
}


/**
 * 电抗
 */
double CAcFilterVo::GetZx(){

	return Zx;
}


/**
 * 交流滤波器类型（单调谐/双调谐）
 */
void CAcFilterVo::SetAcfType(int newVal){

	AcfType = newVal;
}


/**
 * 交流电压
 */
void CAcFilterVo::SetQac(double newVal){

	Qac = newVal;
}


/**
 * 滤波器无功
 */
void CAcFilterVo::SetQacf(double newVal){

	Qacf = newVal;
}


/**
 * 滤波器额定无功
 */
void CAcFilterVo::SetQacfN(double newVal){

	QacfN = newVal;
}


/**
 * 额定交流电压
 */
void CAcFilterVo::SetQacN(double newVal){

	QacN = newVal;
}


/**
 * 电容
 */
void CAcFilterVo::SetZc(double newVal){

	Zc = newVal;
}


/**
 * 电阻
 */
void CAcFilterVo::SetZr(double newVal){

	Zr = newVal;
}


/**
 * 电抗
 */
void CAcFilterVo::SetZx(double newVal){

	Zx = newVal;
}


double CAcFilterVo::GetUac(){

	return Uac;
}


void CAcFilterVo::SetUac(double newVal){

	Uac = newVal;
}


double CAcFilterVo::GetUacN(){

	return UacN;
}


void CAcFilterVo::SetUacN(double newVal){

	UacN = newVal;
}