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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  PrepareNormal
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.�洢�ֵ��Device��
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	virtual void SaveNormal();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  CalConvertorNormal��CalTap
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	// 	virtual void CalConvertorNormal();
	// 	virtual void CalTapNormal();
	// 	virtual void CalConvertor();
	// 	virtual void CalTap();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  UpdateConvertor_DC��UpdateACSide
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.
	//            2.
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	virtual void CalConvertor_DC();//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	virtual void CalConvertor_AC();//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	virtual void CalConvertor_Port();//����ֱ���˿���֪��Uv��Ud��Id��

	virtual void CalXf2_l();//���༰�����֪��Uv��Nnorm��Tc��
	virtual void CalXf2_v();//���༰�����֪��Ul��Nnorm��TC��
	virtual void CalXf2_Port();//����˿ڼ��ֽ�ͷ��֪��Ul��Uv��TC��
	virtual void CalXf2_UpShift();//���಻�䣬�ϵ�һ���ֽ�ͷ
	virtual void CalXf2_DownShift();//���಻�䣬�µ�һ���ֽ�ͷ

	virtual void CalACSide();//���㽻��ϵͳ�������˲�����״̬

public:	
	int StaionCtrlType;

protected:	
	virtual bool IsFixed_I();

};

/**
* typedef map<string, CmcCalculate> CalMap;
*/
typedef map<int, CmcCalculate> CalMap;
