///////////////////////////////////////////////////////////
//  CxbDevDcLine.h
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4月-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
#define EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_

#include "CxbDevBase.h"
//马骏鹏
#include "CMatrix.h"
#include "gbHead_Def.h"
/**
* 直流极线
*/
class CxbDevDcLine : public CxbDevBase
{

public:
	//马骏鹏
	string StationName1;
	string StationName2;

	virtual void Init();

protected:
	//马骏鹏
	/**
	* 复数型2X2矩阵
	*/
	CComplex * Ys;
	//double * Ysr;
	//double * Ysm;
	/**
	* 复数型2X2矩阵
	*/
	CComplex *  Ym;
	virtual void MyFree();

	//马骏鹏
public:
	//
	void SetYs(int hOrder, CComplex *newVal);
	void SetYm(int hOrder, CComplex *newVal);
	//返回Y阵
	CMatrix GetYMatrix(int hOrder);
	//返回Ys，Ym
	CComplex* GetYs(int hOrder);
	CComplex* GetYm(int hOrder);
};
#endif // !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
