#pragma once

#include "CmcCalTwoDot.h"

/**
* ����·������ѹ��
*/
class CmcCalXf2 : public CmcCalTwoDot
{

public:
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.CalXf2_l��CalXf2_DownShift����
	//            2.CalTap��CalTapNormalɾ��
	// �Ķ�ʱ��:  2017/04/18
	//************************************
	virtual void CalXf2_l();//���༰�����֪��Uv��Nnorm��Tc��
	virtual void CalXf2_v();//���༰�����֪��Ul��Nnorm��TC��
	virtual void CalXf2_Port();//����˿ڼ��ֽ�ͷ��֪��Ul��Uv��TC��
	virtual void CalXf2_UpShift();//���಻�䣬�ϵ�һ���ֽ�ͷ
	virtual void CalXf2_DownShift();//���಻�䣬�µ�һ���ֽ�ͷ
									//virtual void CalTap();
									//virtual void CalTapNormal();

	virtual void Prepare();
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

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
};
