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


/**
* 三脉动电压源
*/
class CxbDev3pVSrc : public CxbDevTwoDot
{

protected:
	//马骏鹏
	/**
	* 3P的等效电导
	*/
	//doubleVector Yg;
	/**
	* 3P的等效电纳
	*/
	//doubleVector Yb;
	doubleVector UhVect;
	/**
	* 三脉动源相角
	*/
	doubleVector PhhVect;
	/**
	* 三脉动电感
	*/
	double L;
public:

	//马骏鹏
	/**
	* 3P的等效电导
	*/
	//double GetYg();
	/**
	* 3P的等效电导
	*/
	//void SetYg(double newVal);
	/**
	* 3P的等效电纳
	*/
	//double GetYb();//马骏鹏
	/**
	* 3P的等效电纳
	*/
	//void SetYb(double newVal);

	//马骏鹏
	void SetL(double newVal);
	virtual double GetUre(int vhOrder);
	virtual double GetUim(int vhOrder);
	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmeg);
};

#endif // !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
