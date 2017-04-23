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
	~CmcCalConvertor();
	CmcCalConvertor();
	virtual void StationSort(StationMap& vStaMap);
	void RecordMeasureNode(CmcCalConvertor& vCalConvertor);
	int GetNodeID(int vIndex);

	virtual void UpdateF_J();
	virtual void NodeGround(NodeMap & vNodeMap);
	void InitX();
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  SaveX
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����doSovleDcNet�ļ�����
	//			  2.�̳���CmcCalculate
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
	// �Ķ�����:  1.վ������
	//			  2.�̳���CmcCalculate
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	virtual void CalStation_N();
	virtual void CalStation();
	void CalAngleStation();//++--
	void CalUvStation();//++--
	void LimitUd();//++--
	void ChangeStationCtrlType();//++--
	void SetUdStation();//++--
						//************************************
						// *�Ϸ���������·��г���������*
						// �Ķ�����:  CalConvertor_DC��CalConvertor_Port
						// �Ķ���:    �޿���
						// �Ķ�����:  ɾ��
						// �Ķ�����:  1.
						// �Ķ�ʱ��:  2017/04/21
						//************************************
						//virtual void CalConvertor_AC();//�����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
						//virtual void CalConvertor_Port();//����ֱ���˿���֪��Uv��Ud��Id��
	int  MeasureStationIndex;

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  StationCtrlType��OffsetSort
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��¼����վ�������ͣ����������ͼ�¼���ھ����е�λ��
	//            2.�̳���CmcCalculate
	// �Ķ�ʱ��:  2017/04/20
	//************************************
	int StationCtrlType;
	virtual void OffsetSort(int& vCurrentOffset);

protected:
	int * MeasureNodeIndex;

	virtual void UpdateJ();

};
