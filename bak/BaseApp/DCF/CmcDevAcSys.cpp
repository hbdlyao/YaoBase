///////////////////////////////////////////////////////////
//  CmcDevAcSys.cpp
//  Implementation of the Class CmcDevAcSys
//  Created on:      04-4��-2017 7:26:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevAcSys.h"


/**
 * ����ϵͳ�޹�����
 */
double CmcDevAcSys::GetQac(){

	return Qac;
}


/**
 * ����ϵͳ��޹�����
 */
double CmcDevAcSys::GetQacN(){

	return QacN;
}


/**
 * ����ϵͳ��������޹�
 */
double CmcDevAcSys::GetQinMax(){

	return QinMax;
}


/**
 * ����ϵͳ��������޹�
 */
double CmcDevAcSys::GetQoutMax(){

	return QoutMax;
}


/**
 * �������ѹ
 */
double CmcDevAcSys::GetUac(){

	return Uac;
}


/**
 * ������ѹ��Сֵ
 */
double CmcDevAcSys::GetUacExMin(){

	return UacExMin;
}


/**
 * ������ѹ���ֵ
 */
double CmcDevAcSys::GetUacMax(){

	return UacMax;
}


/**
 * ������ѹ��Сֵ
 */
double CmcDevAcSys::GetUacMin(){

	return UacMin;
}


/**
 * ��������ѹ
 */
double CmcDevAcSys::GetUacN(){

	return UacN;
}


/**
 * ����ϵͳ�޹�����
 */
void CmcDevAcSys::SetQac(double newVal){

	Qac = newVal;
}


/**
 * ����ϵͳ��޹�����
 */
void CmcDevAcSys::SetQacN(double newVal){

	QacN = newVal;
}


/**
 * ����ϵͳ��������޹�
 */
void CmcDevAcSys::SetQinMax(double newVal){

	QinMax = newVal;
}


/**
 * ����ϵͳ��������޹�
 */
void CmcDevAcSys::SetQoutMax(double newVal){

	QoutMax = newVal;
}


/**
 * �������ѹ
 */
void CmcDevAcSys::SetUac(double newVal){

	Uac = newVal;
}


/**
 * ������ѹ��Сֵ
 */
void CmcDevAcSys::SetUacExMin(double newVal){

	UacExMin = newVal;
}


/**
 * ������ѹ���ֵ
 */
void CmcDevAcSys::SetUacMax(double newVal){

	UacMax = newVal;
}


/**
 * ������ѹ��Сֵ
 */
void CmcDevAcSys::SetUacMin(double newVal){

	UacMin = newVal;
}


/**
 * ��������ѹ
 */
void CmcDevAcSys::SetUacN(double newVal){

	UacN = newVal;
}


/**
 * ����Ƶ��
 */
double CmcDevAcSys::GetFreq(){

	return Freq;
}


/**
 * ����Ƶ��
 */
void CmcDevAcSys::SetFreq(int newVal){

	Freq = newVal;
}