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

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  GetMaxdX
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.���ӷ���
	//            2.����dX_Vect�����ľ���ֵ
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	double GetMaxdX();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateF_PdCtrl��UpdateJ_AngCtrl
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.���ӷ���
	//            2.���Ӳ���
	// �Ķ�ʱ��:  2017/04/17
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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateF_PdCtrl0��UpdateJ_AngCtrl0
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.����������ȫһ�����ж��Ƿ�-1������4������
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	//void UpdateF_PdCtrl0(int vK, int iNode);
	//void UpdateF_UdCtrl0(int vK, int iNode);
	//void UpdateF_AngCtrl0(int vK, int iNode);
	//void UpdateJ_PdCtrl0(int vK, int iNode);
	//void UpdateJ_UdCtrl0(int vK, int iNode);
	//void UpdateJ_AngCtrl0(int vK, int iNode);

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateConvertor_DC��UpdateACSide
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.ÿ�˵ļ���
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	void UpdateConvertor_DC(int vK, bool isRectifier);//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	void UpdateConvertor_AC(int vK, bool isRectifier);//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	void UpdateConvertor_Port(int vK, bool isRectifier);//����ֱ���˿���֪��Uv��Ud��Id��

	void UpdateXf2_l(int vK);//���༰�����֪��Uv��Nnorm��Tc��
	void UpdateXf2_v(int vK);//���༰�����֪��Ul��Nnorm��TC��
	void UpdateXf2_Port(int vK);//����˿ڼ��ֽ�ͷ��֪��Ul��Uv��TC��
	void UpdateXf2_UpShift(int vK);//���಻�䣬�ϵ�һ���ֽ�ͷ
	void UpdateXf2_DownShift(int vK);//���಻�䣬�µ�һ���ֽ�ͷ

	void UpdateACSide(int vK);//���㽻��ϵͳ�������˲�����״̬


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
