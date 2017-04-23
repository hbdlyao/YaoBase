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
	int URefStation;//Ϊָ�����ѹվ�洢��ʱ����//++--
	int URefNode[2];//Ϊָ�����ѹվ�洢��ʱ����//++--

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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doSaveX
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����SovleDcNet�ļ�����
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void SaveX(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m);
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateF_PdCtrl��UpdateF_AngCtrl
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.���Ӳ���vOffset
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void UpdateF_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateF_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateF_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateJ_IdCtrl
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void UpdateJ_IdCtrl(int vK_s, int  iNode_s, int  jNode_s);
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateJ_PdCtrl��UpdateJ_AngCtrl
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.���Ӳ���vOffset
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void UpdateJ_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateJ_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier);

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateConvertor_N
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.�������
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void UpdateConvertor_N(int vK, bool isRectifier);//����㣨Ud��Id��alpha/gamma_N��
	void UpdateConvertor_DC(int vK, bool isRectifier);//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	void UpdateConvertor_AC(int vK, bool isRectifier);//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	void UpdateConvertor_Port(int vK, bool isRectifier);//����ֱ���˿���֪��Uv��Ud��Id��

	void UpdateXf2_N(int vK);//����㣨Ul��Uv��TC��//++-- 
	void UpdateXf2_l(int vK);//���༰�����֪��Uv��Nnorm��Tc��
	void UpdateXf2_v(int vK);//���༰�����֪��Ul��Nnorm��TC��
	void UpdateXf2_Port(int vK);//��Ul��Uv��Nnom��//++--
	void UpdateXf2_UpShift(int vK);//���಻�䣬�ϵ�һ���ֽ�ͷ
	void UpdateXf2_DownShift(int vK);//���಻�䣬�µ�һ���ֽ�ͷ

	void UpdateACSide(int vK);//���㽻��ϵͳ�������˲�����״̬


public:
	void InitMatrix(int vStaDim);
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  ResetMatrix
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����offsetDim�������ά��
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	void ResetMatrix(int vOffsetDim);
	void Init_XVect();

	void ResetData();

protected:
	void doInitMatrix();
	void doInitData();

};
