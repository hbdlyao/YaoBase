#pragma once

#include "CmcHvdcGrid.h"
#include "CmcProfile.h"
#include "CmcSolves.h"
#include "CPowerSolveMvc.h"

class CmcSolveMvc : public CPowerSolveMvc
{

protected:
	CmcProfile* pmcProfile;
	CmcSolves* pmcSolves;
	CmcHvdcGrid * pmcHvdc;
	CmcResult* pmcResult;

public:
	virtual ~CmcSolveMvc();

	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void Clear();

public:
	virtual void NodeID(int vGNDType);

public:
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  Run
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.�޸ķ������ܵĶ��壺�������Order�����й���
	//            2.ȡ�����int vGNDType
	// �Ķ�ʱ��:  2017/04/12
	//************************************
	virtual void Run();

protected:

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  RecordResult
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��һ�ε�����ˮƽ��������󽫽��������Result��
	// �Ķ�ʱ��:  2017/04/13
	//************************************
	virtual void doRecordResult();

protected:

	virtual void doNewSolves(int vGNDType);
	virtual void doRun();

	void doInitRun();

	void doInitMatrix();


	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);
	void doRun_UdCustom();
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();
	virtual void doPrepareNormal();



};

class CmcSolveMvcNormal : public CmcSolveMvc
{

public:
	virtual void Init();
	/**
	 * �Ϸ���������·��г���������* �Ķ�����:  Run �Ķ���:    �޿��� �Ķ�����:  �޸� �Ķ�����:  1.
	 * �޸ķ������ܵĶ��壺�������Order�����й��� 2.ȡ�����int vGNDType �Ķ�ʱ��:  2017/04/12
	 */
	virtual void Run();

	virtual void doRecordResult();

};
