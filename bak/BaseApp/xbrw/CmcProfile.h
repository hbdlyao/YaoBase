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
	 * ���㹤��ָ��
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


public:
	void InitMatrix(int vStaDim);
	void Init_XVect();

	/**
	 * �Ϸ���������·��г���������* �Ķ�����:  ClearSingle �Ķ���:    �޿��� �Ķ�����:  ���� �Ķ�����:  1.
	 * ����ÿ��������������ɺ������ �Ķ�ʱ��:  2017/04/13
	 */
	void ResetData();

protected:
	void doInitMatrix();
	void doInitData();

};
