#pragma once


#include "CmcCalculate.h"
#include "CPowerSolves.h"
#include "CmcHvdcGrid.h"

class CmcSolves : public CPowerSolves
{

public:
	CmcProfile * pmcProfile;
	CmcHvdcGrid * pmcHvdc;

	virtual string TypeToName(int vType);

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

public:
	virtual void NewSolves(int vGndType);

protected:
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);

	void doNewMcSolvers10();
	void doNewMcSolvers11();
	void doNewMcSolvers20();
	void doNewMcSolvers21();


public:	
	virtual void Run();
	virtual void PrepareNormal();
	int StaCount();
	void StationSort() override;
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  RecordMeasureNode
	// �Ķ���:    ��Ҫ���޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��¼��վ������Ľڵ���
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	void RecordMeasureNode();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doGetMaxdX
	// �Ķ���:    ��Ҫ���޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����CmcProfile->GetMaxdX()
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	double doGetMaxdX();

protected:
	virtual void doPrepare();


	void doInit_XVect();
	void doSovleDcNet();
	void doSolve_dX();
	
	void doUpdateF_Y();
	void doUpdateF_J();


	void doUpdateJ();
	void doUpdateY();
	void doUpdateX();
	void doCalConvertor();
	void doCalTap();


	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doCalConvertor��doCalTap
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.���ڷֽ�ͷ���ն˽���
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	//void doCalConvertor();
	//void doCalTap();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doCalStation
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.���ڷֽ�ͷ���ն˽���
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	void doCalStation();

};


class CmcSolvesNormal : public CmcSolves
{

public:
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  Run
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.ȡ������CmcProfile* vProfile
	//            2.
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	virtual void Run();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doSaveNorml
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����������¼�ڸ���Device��
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	void doSaveNorml();
protected:

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doCalConvertor��doCalTap
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.���ڷֽ�ͷ���ն˽���
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	//void doCalConvertor();
	//void doCalTap();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doCalStation
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.���ڷֽ�ͷ���ն˽���
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	void doCalStation();
};
