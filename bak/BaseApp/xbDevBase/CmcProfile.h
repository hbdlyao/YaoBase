///////////////////////////////////////////////////////////
//  CmcProfile.h
//  Implementation of the Class CmcProfile
//  Created on:      10-4月-2017 0:54:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_72AEBF1C_C60C_4187_B18B_F637077E1B33__INCLUDED_)
#define EA_72AEBF1C_C60C_4187_B18B_F637077E1B33__INCLUDED_

#include "CmcOrder.h"
#include "CHvdcGrid.h"
#include "CmcResult.h"
#include "CPowerProfile.h"

class CmcProfile : public CPowerProfile
{

public:
	/**
	 * 计算工况指令
	 */
	CmcOrder* pmcOrder;
	CmcResult* pmcResult;
	
	//mcStaDevIndexMap StaDevIndexMap;

	string Flag_Case;
	int Jdim;
	int Ydim;
	int StaDim;
	struct_mcStation* pmcStaData;
	struct_mcStation* pmcStaDataN;
	double* J_Matrix;
	double* F_Vect;
	double* X_Vect;
	double* dX_Vect;


	virtual ~CmcProfile();
	virtual void Release();
	virtual void Init();
	virtual void Clear();
	bool IsBiPole();
	bool IsMetalLine();
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

protected:
	void doInit();
	void doClear();

};
#endif // !defined(EA_72AEBF1C_C60C_4187_B18B_F637077E1B33__INCLUDED_)
