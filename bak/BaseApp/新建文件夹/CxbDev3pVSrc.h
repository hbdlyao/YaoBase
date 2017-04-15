///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.h
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4月-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
#define EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_

#include "CxbDevTwoDot.h"
#include "gbHead_Def.h"
#include "CxbU3PData.h"

/**
* 三脉动电压源
*/
class CxbDev3pVSrc : public CxbDevTwoDot
{

protected:
	//马骏鹏
	//接线方式
	//StrVector ConMethod;
	//功率水平
	//StrVector PowLevel;

	//数据DataMap[ConMethod+PowLevel]
	pxbU3PData_Map DataMap;


	//PowPreMap[Condition]=pxbU3PData_Map, pxbU3PData_Map[PowPre]=CxbU3PData
	//pxbU3PPowPre_Map PowPreMap;

	//
	CxbU3PData * Data;

public:

	//马骏鹏
	//virtual void PrepareData(string vCondition, string vPowPre);
	virtual void PrepareData(string vCondition);

	virtual double GetUre(int vhOrder);
	virtual double GetUim(int vhOrder);

	virtual double GetIre(int vhOrder, double vOmega);
	virtual double GetIim(int vhOrder, double vOmega);

	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);
};

#endif // !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
