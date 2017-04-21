#pragma once

#include <string>
#include <map>

using namespace std;

struct struct_BGXB
{
public:
	int hOrder;
	double hUrms;
	double hAngle;

};


struct struct_Branch
{

public:
	/**
	* 电阻
	*/
	double Zr=0;
	/**
	* 感抗
	*/
	double Zx_L=0;
	/**
	* 容抗
	*/
	double Zx_C=0;
	/**
	* 电感
	*/
	double Z_L=0;
	/**
	* 电容
	*/
	double Z_C=0;

};

struct struct_LineParam
{
	double Ys11re;
	double Ys11im;

	double Ys12re;
	double Ys12im;

	double Ym11re;
	double Ym11im;

	double Ym12re;
	double Ym12im;
};

struct struct_LineMode
{

public:
	/**
	* 直流极线高度
	*/
	double CSXGD;
	/**
	* 直流极线间距
	*/
	double CSXSPJL;
	/**
	* 避雷线与传输线间高度
	*/
	double BLXYCSXGDC;
	/**
	* 线路长度
	*/
	double XLCD;
	/**
	* 避雷线水平距离
	*/
	double BLXSPJL;
	/**
	* 传输线半径
	*/
	double CSXBJ;
	/**
	* 避雷线半径
	*/
	double BLXBJ;
	/**
	* 传输线电导率
	*/
	double CSXDDL;
	/**
	* 传输线电阻类型
	*/
	double CSXDZLX;
	/**
	* 传输线电阻率
	*/
	double CSXDZL;
	/**
	* 传输线直流电阻
	*/
	double CSXZZDZ;
	/**
	* 传输线弧垂
	*/
	double CSXHC;
	/**
	* 传输线分裂数
	*/
	double CSXFLS;
	/**
	* 传输线分裂间距
	*/
	double CSXFLJJ;
	/**
	* 避雷线电阻类型
	*/
	double BLXDZLX;
	/**
	* 避雷线电导率
	*/
	double BLXDDL;
	/**
	* 避雷线电阻率
	*/
	double BLXDZL;
	/**
	* 避雷线直流电阻
	*/
	double BLXZZDZ;
	/**
	* 避雷线弧垂
	*/
	double BLXHC;
	/**
	* 避雷线分裂数
	*/
	double BLXFLS;
	/**
	* 避雷线分裂间距
	*/
	double BLXFLJJ;
	/**
	* 土壤电阻率
	*/
	double TRDZL;

};
