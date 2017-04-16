///////////////////////////////////////////////////////////
//  CxbDevDCF.h
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
#define EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_

#include "CxbDevTwoDot.h"

//马骏鹏
#include "CComplex.h"
#include "gbHead_Def.h"
#include "CRand.h"
#include "CxbDCFData.h"

/**
* 直流滤波器
*/
class CxbDevDCF : public CxbDevTwoDot
{
protected:
	/**
	* 等效电导
	*/
	double * Yg;
	/**
	* 等效电纳
	*/
	double * Yb;
	//马骏鹏
	CxbDCFOneTunedData OneTuned;
	CxbDCFTwoTunedData TwoTuned;
	CxbDCFThreeTunedData ThreeTuned;

	//类型
	int DCFType;

	int DevType;
public:
	//初始化
	void InitDev(int DCFType, int vTimes);
	void ReleaseDev(int DCFType, int vTimes);
	//设置偏差参数
	void SetOneConstDev();
	void SetOneRandDev(int vTimes);

	void SetTwoConstDev();
	void SetTwoRandDev(int vTimes);

	void SetThreeConstDev();
	void SetThreeRandDev(int vTimes);

	void InitY();
	//形成一次的导纳参数
	void InitYNoneDev(int vhOrder);
	void InitYConsDev(int vhOrder, int vCount);
	void InitYRandDev(int vhOrder, int vCount);

	void selectNoneDevY();
	void selectConsDevY(int vCount);
	void selectRandDevY(int vCount);
	/**
	* 等效电导
	*/
	double GetYg(int vhOrder);
	/**
	* 等效电纳
	*/
	double GetYb(int vhOrder);
};
#endif // !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
