///////////////////////////////////////////////////////////
//  CmcDevXf2.cpp
//  Implementation of the Class CmcDevXf2
//  Created on:      04-4��-2017 7:26:45
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevXf2.h"


/**
 * ���
 */
double CmcDevXf2::GetTk(){

	return Tk;
}


/**
 * ����
 */
double CmcDevXf2::GetTkN(){

	return TkN;
}


/**
 * ���ཻ����ѹ
 */
double CmcDevXf2::GetUac(){

	return Uac;
}


/**
 * ����������ѹ
 */
double CmcDevXf2::GetUacN(){

	return UacN;
}


/**
 * ��·�迹�ٷֱ�
 */
double CmcDevXf2::GetUkp(){

	return Ukp;
}


/**
 * ����ѹ���ٷֱ�
 */
double CmcDevXf2::GetUrp(){

	return Urp;
}


/**
 * ���ཻ����ѹ
 */
double CmcDevXf2::GetUv(){

	return Uv;
}


/**
 * �����������ѹ
 */
double CmcDevXf2::GetUvMax(){

	return UvMax;
}


/**
 * ����������ѹ
 */
double CmcDevXf2::GetUvN(){

	return UvN;
}


/**
 * ������/�ضϽ����ֵ
 */
void CmcDevXf2::SetAngleMax(double newVal){

	AngleMax = newVal;
}


/**
 * ������/�ضϽ���Сֵ
 */
void CmcDevXf2::SetAngleMin(double newVal){

	AngleMin = newVal;
}


/**
 * ����ѹ�ο�ֵ
 */
void CmcDevXf2::SetFixedURef(double newVal){

	FixedURef = newVal;
}


/**
 * ����ѹ�ο�����
 */
void CmcDevXf2::SetFixedUType(int newVal){

	FixedUType = newVal;
}


/**
 * ��ѹ�������
 */
void CmcDevXf2::SetSN(double newVal){

	SN = newVal;
}


/**
 * �ֽ�ͷ��������
 */
void CmcDevXf2::SetTapCtrlType(int newVal){

	TapCtrlType = newVal;
}


/**
 * �ֽ�ͷ���λ
 */
void CmcDevXf2::SetTapMax(int newVal){

	TapMax = newVal;
}


/**
 * �ֽ�ͷ��С��λ
 */
void CmcDevXf2::SetTapMin(int newVal){

	TapMin = newVal;
}


/**
 * �ֽ�ͷ���λ
 */
void CmcDevXf2::SetTapN(int newVal){

	TapN = newVal;
}


/**
 * �ֽ�ͷ��������
 */
void CmcDevXf2::SetTapSetup(double newVal){

	TapSetup = newVal;
}


/**
 * ���
 */
void CmcDevXf2::SetTk(double newVal){

	Tk = newVal;
}


/**
 * ����
 */
void CmcDevXf2::SetTkN(double newVal){

	TkN = newVal;
}


/**
 * ���ཻ����ѹ
 */
void CmcDevXf2::SetUac(double newVal){

	Uac = newVal;
}


/**
 * ����������ѹ
 */
void CmcDevXf2::SetUacN(double newVal){

	UacN = newVal;
}


/**
 * ��·�迹�ٷֱ�
 */
void CmcDevXf2::SetUkp(double newVal){

	Ukp = newVal;
}


/**
 * ����ѹ���ٷֱ�
 */
void CmcDevXf2::SetUrp(double newVal){

	Urp = newVal;
}


/**
 * ���ཻ����ѹ
 */
void CmcDevXf2::SetUv(double newVal){

	Uv = newVal;
}


/**
 * �����������ѹ
 */
void CmcDevXf2::SetUvMax(double newVal){

	UvMax = newVal;
}


/**
 * ����������ѹ
 */
void CmcDevXf2::SetUvN(double newVal){

	UvN = newVal;
}


/**
 * �ֽ�ͷ��λ
 */
void CmcDevXf2::SetTap(int newVal){

	Tap = newVal;
}


/**
 * ������/�ضϽ����ֵ
 */
double CmcDevXf2::GetAngleMax(){

	return 0;
}


/**
 * ������/�ضϽ���Сֵ
 */
double CmcDevXf2::GetAngleMin(){

	return 0;
}


/**
 * ����ѹ�ο�ֵ
 */
double CmcDevXf2::GetFixedURef(){

	return 0;
}


/**
 * ����ѹ�ο�����
 */
int CmcDevXf2::GetFixedUType(){

	return 0;
}


/**
 * ��ѹ�������
 */
double CmcDevXf2::GetSN(){

	return 0;
}


/**
 * �ֽ�ͷ��λ
 */
int CmcDevXf2::GetTap(){

	return 0;
}


/**
 * �ֽ�ͷ��������
 */
int CmcDevXf2::GetTapCtrlType(){

	return 0;
}


/**
 * �ֽ�ͷ���λ
 */
int CmcDevXf2::GetTapMax(){

	return 0;
}


/**
 * �ֽ�ͷ��С��λ
 */
int CmcDevXf2::GetTapMin(){

	return 0;
}


/**
 * �ֽ�ͷ���λ
 */
int CmcDevXf2::GetTapN(){

	return 0;
}


/**
 * �ֽ�ͷ��������
 */
double CmcDevXf2::GetTapSetup(){

	return 0;
}