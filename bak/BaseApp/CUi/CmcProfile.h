#pragma once


#include "CmcOrder.h"
#include "CmcResult.h"
#include "CPowerProfile.h"

class CmcProfile : public CPowerProfile
{

public:
	virtual ~CmcProfile();
	virtual void Init();
	virtual void Clear();

public:
	/**
	* 计算工况指令
	*/
	CmcOrder* pmcOrder;

	bool LimitOK;

	int Jdim;
	int StaDim;

	int NodeCount=0;

	struct_mcStationData* pmcStaData;
	struct_mcStationData* pmcStaDataN;
	double Ud_Max;//++--
	void UpdateUdio();//++--
	void UpdateUdio(int vK);//++--
	bool IsTapUpAble(int vK);//++--
	bool IsTapDownAble(int vK);//++--
	int URefStation;//为指定点电压站存储临时数据//++--
	int URefNode[2];//为指定点电压站存储临时数据//++--

	double* J_Matrix;
	double* F_Vect;
	double* X_Vect;
	double* dX_Vect;


	bool IsBiPole();
	bool IsMetalLine();

	void InitX_Y(int vNode, double vUnode);

	void InitX_I(int vK, double vId);


	void UpdateY0(int iNode, double vY);
	void UpdateY(int iNode, int jNode, double vY);
	void UpdateF_Y();
	void UpdateX();
	void Solve_dX();

	double GetMaxdX();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doSaveX
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.保存SovleDcNet的计算结果
	// 改动时间:  2017/04/20
	//************************************
	void SaveX(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m);
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateF_PdCtrl至UpdateF_AngCtrl
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.增加参数vOffset
	// 改动时间:  2017/04/20
	//************************************
	void UpdateF_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateF_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateF_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateJ_IdCtrl
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.
	// 改动时间:  2017/04/20
	//************************************
	void UpdateJ_IdCtrl(int vK_s, int  iNode_s, int  jNode_s);
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateJ_PdCtrl至UpdateJ_AngCtrl
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.增加参数vOffset
	// 改动时间:  2017/04/20
	//************************************
	void UpdateJ_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateJ_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateConvertor_N
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.额定计算用
	// 改动时间:  2017/04/20
	//************************************
	void UpdateConvertor_N(int vK, bool isRectifier);//额定计算（Ud、Id、alpha/gamma_N）
	void UpdateConvertor_DC(int vK, bool isRectifier);//直流侧及角度已知（Ud、Id、alpha/gamma）
	void UpdateConvertor_AC(int vK, bool isRectifier);//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	void UpdateConvertor_Port(int vK, bool isRectifier);//交、直流端口已知（Uv、Ud、Id）

	void UpdateXf2_N(int vK);//额定计算（Ul、Uv、TC）//++-- 
	void UpdateXf2_l(int vK);//网侧及变比已知（Uv、Nnorm、Tc）
	void UpdateXf2_v(int vK);//阀侧及变比已知（Ul、Nnorm、TC）
	void UpdateXf2_Port(int vK);//（Ul、Uv、Nnom）//++--
	void UpdateXf2_UpShift(int vK);//网侧不变，上调一及分接头
	void UpdateXf2_DownShift(int vK);//网侧不变，下调一及分接头

	void UpdateACSide(int vK);//计算交流系统、交流滤波器的状态


public:
	void InitMatrix(int vStaDim);
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  ResetMatrix
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.根据offsetDim重设矩阵维数
	// 改动时间:  2017/04/20
	//************************************
	void ResetMatrix(int vOffsetDim);
	void Init_XVect();

	void ResetData();

protected:
	void doInitMatrix();
	void doInitData();

};
