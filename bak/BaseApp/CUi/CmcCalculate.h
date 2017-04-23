#pragma once

#include "CmcProfile.h"

#include "CPowerCalculate.h"


class CmcCalculate : public CPowerCalculate
{
protected:
	//void doStationSort(StationMap & vStaMap) override;

protected:
	CmcProfile * pmcProfile;

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  Offset
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.记录换流站控制类型，并根据类型记录其在矩阵中的位置
	// 改动时间:  2017/04/20
	//************************************
	int Offset;
public:

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  OffsetSort
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.记录换流站控制类型，并根据类型记录其在矩阵中的位置
	// 改动时间:  2017/04/20
	//************************************
	virtual void OffsetSort(int& vCurrentOffset);

	void Init(CPowerProfile * vProfile) override;

	virtual void UpdateY();
	virtual void Prepare();
	virtual void UpdateJ();
	virtual void UpdateF_J();
	virtual void InitX();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  SaveX
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.保存doSovleDcNet的计算结果
	// 改动时间:  2017/04/20
	//************************************
	virtual void SaveX();
	virtual void PrepareNormal();
	virtual void SaveNormal();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  CalStation_N至CalStation
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.
	// 改动时间:  2017/04/21
	//************************************
	virtual void CalStation_N();
	virtual void CalStation();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  CalConvertor_DC至CalXf2_DownShift
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.
	// 改动时间:  2017/04/21
	//************************************
	//virtual void CalConvertor_DC();//直流侧及角度已知（Ud、Id、alpha/gamma）
	//virtual void CalConvertor_DC();//直流侧及角度已知（Ud、Id、alpha/gamma）
	//virtual void CalConvertor_AC();//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	//virtual void CalConvertor_Port();//交、直流端口已知（Uv、Ud、Id）

	//virtual void CalXf2_l();//网侧及变比已知（Uv、Nnorm、Tc）
	//virtual void CalXf2_v();//阀侧及变比已知（Ul、Nnorm、TC）
	//virtual void CalXf2_Port();//两侧端口及分接头已知（Ul、Uv、TC）
	//virtual void CalXf2_UpShift();//网侧不变，上调一及分接头
	//virtual void CalXf2_DownShift();//网侧不变，下调一及分接头

	virtual void CalACSide();//计算交流系统、交流滤波器的状态

	virtual void LimitUd();//++--

protected:

};

/**
* typedef map<string, CmcCalculate> CalMap;
*/
typedef map<int, CmcCalculate> CalMap;
