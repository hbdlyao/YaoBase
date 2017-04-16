///////////////////////////////////////////////////////////
//  CxbDevDCF.h
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4��-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
#define EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_

#include "CxbDevTwoDot.h"

//����
#include "CComplex.h"
#include "gbHead_Def.h"
#include "CRand.h"
#include "CxbDCFData.h"

/**
* ֱ���˲���
*/
class CxbDevDCF : public CxbDevTwoDot
{
protected:
	/**
	* ��Ч�絼
	*/
	double * Yg;
	/**
	* ��Ч����
	*/
	double * Yb;
	//����
	CxbDCFOneTunedData OneTuned;
	CxbDCFTwoTunedData TwoTuned;
	CxbDCFThreeTunedData ThreeTuned;

	//����
	int DCFType;

	int DevType;
public:
	//��ʼ��
	void InitDev(int DCFType, int vTimes);
	void ReleaseDev(int DCFType, int vTimes);
	//����ƫ�����
	void SetOneConstDev();
	void SetOneRandDev(int vTimes);

	void SetTwoConstDev();
	void SetTwoRandDev(int vTimes);

	void SetThreeConstDev();
	void SetThreeRandDev(int vTimes);

	void InitY();
	//�γ�һ�εĵ��ɲ���
	void InitYNoneDev(int vhOrder);
	void InitYConsDev(int vhOrder, int vCount);
	void InitYRandDev(int vhOrder, int vCount);

	void selectNoneDevY();
	void selectConsDevY(int vCount);
	void selectRandDevY(int vCount);
	/**
	* ��Ч�絼
	*/
	double GetYg(int vhOrder);
	/**
	* ��Ч����
	*/
	double GetYb(int vhOrder);
};
#endif // !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
