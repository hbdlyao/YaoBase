///////////////////////////////////////////////////////////
//  CxbDevDCF.h
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
#define EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_

#include "CxbDev_Tree.h"

//马骏鹏
#include "CComplex.h"
#include "gbHead_Def.h"
#include "CRand.h"
#include "CxbDCFData.h"


/**
* 直流滤波器
*/
class CxbDevDCF : public CxbDev_Tree
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
	double Frequency;

	/**
	 * 类型
	 */
	int DCFType;

	int DevType;

	int RandTimes;
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

	void InitY(int vDevType);
	//形成一次的导纳参数
	void InitYNoneDev();
	void InitYConsDev();
	void InitYRandDev();

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
	/**
	 * 类型
	 */
	int GetDCFType();
	/**
	 * 类型
	 */
	void SetDCFType(int newVal);
};
#endif // !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
