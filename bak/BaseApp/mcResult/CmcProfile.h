#pragma once


#include "CmcOrder.h"
#include "CmcResult.h"
#include "CPowerProfile.h"

class CmcProfile : public CPowerProfile
{

public:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  ClearSingle
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.用于每个单工况计算完成后的清理
	// 改动时间:  2017/04/13
	//************************************
	virtual void ClearSingle();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  Init_OrderResult
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.用于初始化Order和Result的维数
	// 改动时间:  2017/04/13
	//************************************

protected:
	void doInit();
	void doClear();

public:
	/**
	 * 计算工况指令
	 */
	CmcOrder* pmcOrder;

	int Jdim;
	int Ydim;
	int StaDim;
	
	struct_mcStationData* pmcStaData;
	struct_mcStationData* pmcStaDataN;

	double* J_Matrix;
	double* F_Vect;
	double* X_Vect;
	double* dX_Vect;
	NodeMap *mcNodeMap;

	virtual ~CmcProfile();
	virtual void Release();
	virtual void Init();
	virtual void Clear();
	bool IsBiPole();
	bool IsMetalLine();
	virtual void ClearData();
	void InitMatrix(int vStaDim);

	void Init_XVect();
	void UpdateY0(int iNode, double vY);
	void UpdateY(int iNode, int jNode, double vY);
	void UpdateF_Y();
	void UpdateX();
	void Solve_dX();
	void UpdateF_PdCtrl(int vK, int iNode, int jNode);
	void UpdateF_UdCtrl(int vK, int iNode, int jNode);
	void UpdateF_AngCtrl(int vK, int iNode, int jNode);
	void UpdateJ_PdCtrl(int vK, int iNode, int jNode);
	void UpdateJ_UdCtrl(int vK, int iNode, int jNode);
	void UpdateJ_AngCtrl(int vK, int iNode, int jNode);
	void UpdateF_PdCtrl0(int vK, int iNode);
	void UpdateF_UdCtrl0(int vK, int iNode);
	void UpdateF_AngCtrl0(int vK, int iNode);
	void UpdateJ_PdCtrl0(int vK, int iNode);
	void UpdateJ_UdCtrl0(int vK, int iNode);
	void UpdateJ_AngCtrl0(int vK, int iNode);
	void UpdateR_UN(int vK);
	void UpdateI_UN(int vK);
	void UpdateTapN(int vK);



};
