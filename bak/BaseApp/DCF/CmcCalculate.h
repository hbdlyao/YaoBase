#pragma once

#include "CmcProfile.h"
#include "CPowerCalculate.h"


class CmcCalculate : public CPowerCalculate
{
protected:
	CmcProfile * pmcProfile;

public:

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

	virtual void UpdateY();
	virtual void Prepare();
	virtual void UpdateJ();
	virtual void UpdateF_J();
	virtual void InitX();
	virtual void PrepareNormal();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  PrepareNormal
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.存储额定值到Device中
	// 改动时间:  2017/04/18
	//************************************
	virtual void SaveNormal();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  CalConvertorNormal至CalTap
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.
	// 改动时间:  2017/04/18
	//************************************
	// 	virtual void CalConvertorNormal();
	// 	virtual void CalTapNormal();
	// 	virtual void CalConvertor();
	// 	virtual void CalTap();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateConvertor_DC至UpdateACSide
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.
	//            2.
	// 改动时间:  2017/04/18
	//************************************
	virtual void CalConvertor_DC();//直流侧及角度已知（Ud、Id、alpha/gamma）
	virtual void CalConvertor_AC();//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	virtual void CalConvertor_Port();//交、直流端口已知（Uv、Ud、Id）

	virtual void CalXf2_l();//网侧及变比已知（Uv、Nnorm、Tc）
	virtual void CalXf2_v();//阀侧及变比已知（Ul、Nnorm、TC）
	virtual void CalXf2_Port();//两侧端口及分接头已知（Ul、Uv、TC）
	virtual void CalXf2_UpShift();//网侧不变，上调一及分接头
	virtual void CalXf2_DownShift();//网侧不变，下调一及分接头

	virtual void CalACSide();//计算交流系统、交流滤波器的状态

public:	
	int StaionCtrlType;

protected:	
	virtual bool IsFixed_I();

};

/**
* typedef map<string, CmcCalculate> CalMap;
*/
typedef map<int, CmcCalculate> CalMap;
