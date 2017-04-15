///////////////////////////////////////////////////////////
//  CmcDevConvertor.cpp
//  Implementation of the Class CmcDevConvertor
//  Created on:      04-4月-2017 7:26:40
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevConvertor.h"



/**
 * 触发角/关断角
 */
double CmcDevConvertor::GetAlhpa_gama(){

	return Alhpa_gama;
}


/**
 * 额定触发角/关断角
 */
double CmcDevConvertor::GetAlpha_gamaN(){

	return Alpha_gamaN;
}


/**
 * 触发角/关断角最大值
 */
double CmcDevConvertor::GetAngleMax(){

	return AngleMax;
}


/**
 * 触发角/关断角最小值
 */
double CmcDevConvertor::GetAngleMin(){

	return AngleMin;
}


/**
 * 换向电阻额定值，按百分数给定  drN=Urp
 */
double CmcDevConvertor::GetdrN(){

	return drN;
}


/**
 * 换向电抗额定值， dxN=(1/2)Ukp 按百分数给定
 */
double CmcDevConvertor::GetdxN(){

	return dxN;
}


/**
 * 直流电流,，计算得出
 */
double CmcDevConvertor::GetId(){

	return Id;
}


/**
 * 电压离换流站距离 ?
 */
double CmcDevConvertor::GetLengthToSide(){

	return LengthToSide;
}


/**
 * 直流功率
 */
double CmcDevConvertor::GetPd(){

	return Pd;
}


/**
 * 额定直流功率
 */
double CmcDevConvertor::GetPdN(){

	return PdN;
}


/**
 * 换流站吸收无功最小值
 */
double CmcDevConvertor::GetQmin(){

	return Qmin;
}


/**
 * 直流电压
 */
double CmcDevConvertor::GetUd(){

	return Ud;
}


/**
 * 额定直流电压
 */
double CmcDevConvertor::GetUdN(){

	return UdN;
}


/**
 * 6脉动正向导通压降
 */
double CmcDevConvertor::GetUT(){

	return UT;
}


/**
 * 每极12脉动换流组数
 */
int CmcDevConvertor::GetValvor12Count(){

	return Valvor12Count;
}


/**
 * 触发角/关断角
 */
void CmcDevConvertor::SetAlhpa_gama(double newVal){

	Alhpa_gama = newVal;
}


/**
 * 额定触发角/关断角
 */
void CmcDevConvertor::SetAlpha_gamaN(double newVal){

	Alpha_gamaN = newVal;
}


/**
 * 触发角/关断角最大值
 */
void CmcDevConvertor::SetAngleMax(double newVal){

	AngleMax = newVal;
}


/**
 * 触发角/关断角最小值
 */
void CmcDevConvertor::SetAngleMin(double newVal){

	AngleMin = newVal;
}



/**
 * 换向电阻额定值
 */
void CmcDevConvertor::SetdrN(double newVal){

	drN = newVal;
}


/**
 * 换向电阻额定值，按百分数给定  drN=Urp
 */
void CmcDevConvertor::SetdxN(double newVal){

	dxN = newVal;
}


/**
 * 直流电流,，计算得出
 */
void CmcDevConvertor::SetId(double newVal){

	Id = newVal;
}


/**
 * 电压离换流站距离 ?
 */
void CmcDevConvertor::SetLengthToSide(double newVal){

	LengthToSide = newVal;
}


/**
 * 直流功率
 */
void CmcDevConvertor::SetPd(double newVal){

	Pd = newVal;
}


/**
 * 额定直流功率
 */
void CmcDevConvertor::SetPdN(double newVal){

	PdN = newVal;
}


/**
 * 换流站吸收无功最小值
 */
void CmcDevConvertor::SetQmin(double newVal){

	Qmin = newVal;
}


/**
 * 直流电压
 */
void CmcDevConvertor::SetUd(double newVal){

	Ud = newVal;
}


/**
 * 额定直流电压
 */
void CmcDevConvertor::SetUdN(double newVal){

	UdN = newVal;
}


/**
 * 6脉动正向导通压降
 */
void CmcDevConvertor::SetUT(double newVal){

	UT = newVal;
}


/**
 * 每极12脉动换流组数
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
 * 阀侧电压
 */
double CmcDevConvertor::GetUv(){

	return Uv;
}


/**
 * 阀侧电压
 */
void CmcDevConvertor::SetUv(double newVal){

	Uv = newVal;
}


/**
 * 阀侧额定电压
 */
double CmcDevConvertor::GetUvN(){

	return UvN;
}


/**
 * 阀侧额定电压
 */
void CmcDevConvertor::SetUvN(double newVal){

	UvN = newVal;
}


/**
 * 直流电流,，计算得出
 */
double CmcDevConvertor::GetIdN(){

	return IdN;
}


/**
 * 直流电流,，计算得出
 */
void CmcDevConvertor::SetIdN(double newVal){

	IdN = newVal;
}


/**
 * 换流器类型（整流逆变）
 */
int CmcDevConvertor::GetStationType(){

	return StationType;
}


/**
 * 换流器类型（整流逆变）
 */
void CmcDevConvertor::SetStationType(int newVal){

	StationType = newVal;
}


/**
 * 换流器控制类型（定电流，定功率，定电压）
 */
int CmcDevConvertor::GetStationCtrlType(){

	return StationCtrlType;
}


/**
 * 换流器控制类型（定电流，定功率，定电压）
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