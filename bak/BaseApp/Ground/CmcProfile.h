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

	int Jdim;
	int StaDim;
	
	struct_mcStationData* pmcStaData;
	struct_mcStationData* pmcStaDataN;

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

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  GetMaxdX
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.增加方法
	//            2.返回dX_Vect里最大的绝对值
	// 改动时间:  2017/04/17
	//************************************
	double GetMaxdX();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateF_PdCtrl至UpdateJ_AngCtrl
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.增加方法
	//            2.增加参数
	// 改动时间:  2017/04/17
	//************************************
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m);
	void UpdateF_PdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateF_UdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateF_AngCtrl(int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	void UpdateJ_IdCtrl(int vK_s, int  iNode_s, int  jNode_s);
	void UpdateJ_PdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_UdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateJ_AngCtrl(int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateF_PdCtrl0至UpdateJ_AngCtrl0
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.函数功能完全一样，判断是否-1将引起4种重载
	// 改动时间:  2017/04/17
	//************************************
	//void UpdateF_PdCtrl0(int vK, int iNode);
	//void UpdateF_UdCtrl0(int vK, int iNode);
	//void UpdateF_AngCtrl0(int vK, int iNode);
	//void UpdateJ_PdCtrl0(int vK, int iNode);
	//void UpdateJ_UdCtrl0(int vK, int iNode);
	//void UpdateJ_AngCtrl0(int vK, int iNode);

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  UpdateConvertor_DC至UpdateACSide
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.每端的计算
	// 改动时间:  2017/04/18
	//************************************
	void UpdateConvertor_DC(int vK, bool isRectifier);//直流侧及角度已知（Ud、Id、alpha/gamma）
	void UpdateConvertor_AC(int vK, bool isRectifier);//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	void UpdateConvertor_Port(int vK, bool isRectifier);//交、直流端口已知（Uv、Ud、Id）

	void UpdateXf2_l(int vK);//网侧及变比已知（Uv、Nnorm、Tc）
	void UpdateXf2_v(int vK);//阀侧及变比已知（Ul、Nnorm、TC）
	void UpdateXf2_Port(int vK);//两侧端口及分接头已知（Ul、Uv、TC）
	void UpdateXf2_UpShift(int vK);//网侧不变，上调一及分接头
	void UpdateXf2_DownShift(int vK);//网侧不变，下调一及分接头

	void UpdateACSide(int vK);//计算交流系统、交流滤波器的状态


public:
	void InitMatrix(int vStaDim);
	void Init_XVect();

	/**
	 * 南方电网主回路及谐波计算软件* 改动对象:  ClearSingle 改动者:    崔康生 改动类型:  新增 改动内容:  1.
	 * 用于每个单工况计算完成后的清理 改动时间:  2017/04/13
	 */
	void ResetData();

protected:
	void doInitMatrix();
	void doInitData();

};
