#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
* ������
*/
class CmcCalConvertor : public CmcCalTwoDot
{

public:
	virtual void Prepare();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  StationSort��RecordMeasureNode��GetNodeID��CmcCalConvertor��~CmcCalConvertor
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.׼��MeasureStationIndex��MeasureNodeIndex����
	//            2.
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	~CmcCalConvertor();
	CmcCalConvertor();
	virtual void StationSort(StationMap& vStaMap);
	void RecordMeasureNode(CmcCalConvertor& vCalConvertor);
	int GetNodeID(int vIndex);

	virtual void UpdateF_J();
	virtual void NodeGround(NodeMap & vNodeMap);
	void InitX();
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
	// �Ķ�����:  
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.CalConvertor_DC��CalConvertor_Port����
	//            2.CalConvertor��CalConvertorNormalɾ��
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	virtual void CalConvertor_DC();//ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	virtual void CalConvertor_AC();//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	virtual void CalConvertor_Port();//����ֱ���˿���֪��Uv��Ud��Id��
									 //virtual void CalConvertor();
									 //virtual void CalConvertorNormal();
									 //************************************
									 // *�Ϸ���������·��г���������*
									 // �Ķ�����:  MeasureStationIndex
									 // �Ķ���:    ��Ҫ���޿���
									 // �Ķ�����:  ����
									 // �Ķ�����:  1.������վ���
									 // �Ķ�ʱ��:  2017/04/17
									 //************************************
	int  MeasureStationIndex;
protected:
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  MeasureStationIndex
	// �Ķ���:    ��Ҫ���޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.������ڵ���
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	int * MeasureNodeIndex;

	virtual void UpdateJ();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doUpdateJ_PdCtrl��doUpdateJ_AngCtrl
	// �Ķ���:    �޿���
	// �Ķ�����:  ɾ��
	// �Ķ�����:  1.����������ȫһ�����ж��Ƿ�-1������4������
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	//virtual void doUpdateJ_IdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev);

	//virtual void doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev);

};
