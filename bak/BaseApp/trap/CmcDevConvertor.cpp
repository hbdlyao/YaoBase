///////////////////////////////////////////////////////////
//  CmcDevConvertor.cpp
//  Implementation of the Class CmcDevConvertor
//  Created on:      04-4��-2017 7:26:40
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevConvertor.h"



/**
 * ������/�ضϽ�
 */
double CmcDevConvertor::GetAlhpa_gama(){

	return Alhpa_gama;
}


/**
 * �������/�ضϽ�
 */
double CmcDevConvertor::GetAlpha_gamaN(){

	return Alpha_gamaN;
}


/**
 * ������/�ضϽ����ֵ
 */
double CmcDevConvertor::GetAngleMax(){

	return AngleMax;
}


/**
 * ������/�ضϽ���Сֵ
 */
double CmcDevConvertor::GetAngleMin(){

	return AngleMin;
}


/**
 * �������ֵ�����ٷ�������  drN=Urp
 */
double CmcDevConvertor::GetdrN(){

	return drN;
}


/**
 * ����翹�ֵ�� dxN=(1/2)Ukp ���ٷ�������
 */
double CmcDevConvertor::GetdxN(){

	return dxN;
}


/**
 * ֱ������,������ó�
 */
double CmcDevConvertor::GetId(){

	return Id;
}


/**
 * ��ѹ�뻻��վ���� ?
 */
double CmcDevConvertor::GetLengthToSide(){

	return LengthToSide;
}


/**
 * ֱ������
 */
double CmcDevConvertor::GetPd(){

	return Pd;
}


/**
 * �ֱ������
 */
double CmcDevConvertor::GetPdN(){

	return PdN;
}


/**
 * ����վ�����޹���Сֵ
 */
double CmcDevConvertor::GetQmin(){

	return Qmin;
}


/**
 * ֱ����ѹ
 */
double CmcDevConvertor::GetUd(){

	return Ud;
}


/**
 * �ֱ����ѹ
 */
double CmcDevConvertor::GetUdN(){

	return UdN;
}


/**
 * 6��������ͨѹ��
 */
double CmcDevConvertor::GetUT(){

	return UT;
}


/**
 * ÿ��12������������
 */
int CmcDevConvertor::GetValvor12Count(){

	return Valvor12Count;
}


/**
 * ������/�ضϽ�
 */
void CmcDevConvertor::SetAlhpa_gama(double newVal){

	Alhpa_gama = newVal;
}


/**
 * �������/�ضϽ�
 */
void CmcDevConvertor::SetAlpha_gamaN(double newVal){

	Alpha_gamaN = newVal;
}


/**
 * ������/�ضϽ����ֵ
 */
void CmcDevConvertor::SetAngleMax(double newVal){

	AngleMax = newVal;
}


/**
 * ������/�ضϽ���Сֵ
 */
void CmcDevConvertor::SetAngleMin(double newVal){

	AngleMin = newVal;
}



/**
 * �������ֵ
 */
void CmcDevConvertor::SetdrN(double newVal){

	drN = newVal;
}


/**
 * �������ֵ�����ٷ�������  drN=Urp
 */
void CmcDevConvertor::SetdxN(double newVal){

	dxN = newVal;
}


/**
 * ֱ������,������ó�
 */
void CmcDevConvertor::SetId(double newVal){

	Id = newVal;
}


/**
 * ��ѹ�뻻��վ���� ?
 */
void CmcDevConvertor::SetLengthToSide(double newVal){

	LengthToSide = newVal;
}


/**
 * ֱ������
 */
void CmcDevConvertor::SetPd(double newVal){

	Pd = newVal;
}


/**
 * �ֱ������
 */
void CmcDevConvertor::SetPdN(double newVal){

	PdN = newVal;
}


/**
 * ����վ�����޹���Сֵ
 */
void CmcDevConvertor::SetQmin(double newVal){

	Qmin = newVal;
}


/**
 * ֱ����ѹ
 */
void CmcDevConvertor::SetUd(double newVal){

	Ud = newVal;
}


/**
 * �ֱ����ѹ
 */
void CmcDevConvertor::SetUdN(double newVal){

	UdN = newVal;
}


/**
 * 6��������ͨѹ��
 */
void CmcDevConvertor::SetUT(double newVal){

	UT = newVal;
}


/**
 * ÿ��12������������
 */
void CmcDevConvertor::SetValvor12Count(int newVal){

	Valvor12Count = newVal;
}


double CmcDevConvertor::GetUdioN(){

	return UdioN;
}


void CmcDevConvertor::SetUdioN(double newVal){

	UdioN = newVal;
}


double CmcDevConvertor::GetUdio(){

	return Udio;
}


void CmcDevConvertor::SetUdio(double newVal){

	Udio = newVal;
}


/**
 * �����ѹ
 */
double CmcDevConvertor::GetUv(){

	return Uv;
}


/**
 * �����ѹ
 */
void CmcDevConvertor::SetUv(double newVal){

	Uv = newVal;
}


/**
 * ������ѹ
 */
double CmcDevConvertor::GetUvN(){

	return UvN;
}


/**
 * ������ѹ
 */
void CmcDevConvertor::SetUvN(double newVal){

	UvN = newVal;
}


/**
 * ֱ������,������ó�
 */
double CmcDevConvertor::GetIdN(){

	return IdN;
}


/**
 * ֱ������,������ó�
 */
void CmcDevConvertor::SetIdN(double newVal){

	IdN = newVal;
}


/**
 * ���������ͣ�������䣩
 */
int CmcDevConvertor::GetStationType(){

	return StationType;
}


/**
 * ���������ͣ�������䣩
 */
void CmcDevConvertor::SetStationType(int newVal){

	StationType = newVal;
}


/**
 * �������������ͣ��������������ʣ�����ѹ��
 */
int CmcDevConvertor::GetStationCtrlType(){

	return StationCtrlType;
}


/**
 * �������������ͣ��������������ʣ�����ѹ��
 */
void CmcDevConvertor::SetStationCtrlType(int newVal)
{

	StationCtrlType = newVal;
}


int CmcDevConvertor::GetIsGround(){

	return IsGround;
}


void CmcDevConvertor::SetIsGround(int newVal){

	IsGround = newVal;
}


double CmcDevConvertor::GetAngleRef(){

	return AngleRef;
}


void CmcDevConvertor::SetAngleRef(double newVal){

	AngleRef = newVal;
}