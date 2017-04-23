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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  Offset
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��¼����վ�������ͣ����������ͼ�¼���ھ����е�λ��
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	int Offset;
public:

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  OffsetSort
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��¼����վ�������ͣ����������ͼ�¼���ھ����е�λ��
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	virtual void OffsetSort(int& vCurrentOffset);

	void Init(CPowerProfile * vProfile) override;

	virtual void UpdateY();
	virtual void Prepare();
	virtual void UpdateJ();
	virtual void UpdateF_J();
	virtual void InitX();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  SaveX
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����doSovleDcNet�ļ�����
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	virtual void SaveX();
	virtual void PrepareNormal();
	virtual void SaveNormal();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  CalStation_N��CalStation
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.
	// �Ķ�ʱ��:  2017/04/21
	//************************************
	virtual void CalStation_N();
	virtual void CalStation();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  CalConvertor_DC��CalXf2_DownShift
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.
	// �Ķ�ʱ��:  2017/04/21
	//************************************
	//virtual void CalConvertor_DC();//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	//virtual void CalConvertor_DC();//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	//virtual void CalConvertor_AC();//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	//virtual void CalConvertor_Port();//����ֱ���˿���֪��Uv��Ud��Id��

	//virtual void CalXf2_l();//���༰�����֪��Uv��Nnorm��Tc��
	//virtual void CalXf2_v();//���༰�����֪��Ul��Nnorm��TC��
	//virtual void CalXf2_Port();//����˿ڼ��ֽ�ͷ��֪��Ul��Uv��TC��
	//virtual void CalXf2_UpShift();//���಻�䣬�ϵ�һ���ֽ�ͷ
	//virtual void CalXf2_DownShift();//���಻�䣬�µ�һ���ֽ�ͷ

	virtual void CalACSide();//���㽻��ϵͳ�������˲�����״̬

	virtual void LimitUd();//++--

protected:

};

/**
* typedef map<string, CmcCalculate> CalMap;
*/
typedef map<int, CmcCalculate> CalMap;
