///////////////////////////////////////////////////////////
//  CxbOrder.h
//  Implementation of the Class CxbOrder
//  Created on:      05-4��-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
#define EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_

#include "CmcOrder.h"

#include <string>

using namespace std;

class CxbOrder : public CmcOrder
{
public:
	//����
	string GroundStaiton;
	//����
	//�˲���ƫ������
	int DCFDevType;
	int DCFRandTimes;
	void Init();
	/**
	 * �Ϸ���������·��г���������* �Ķ�����:  CreateCaseID �Ķ���:    �޿��� �Ķ�����:  ���� �Ķ�����:  1.
	 * ����Order�ﱣ��ĵ��������ɹ������� �Ķ�ʱ��:  2017/04/13
	 */
	string CreateCaseID();


};
#endif // !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
