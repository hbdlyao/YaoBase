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

	virtual void Init();

protected:
	//马骏鹏
	/**
	* 复数型2X2矩阵
	*/
	CComplex * Ys;
	CComplex *  Ym;

	CComplex* GetYs(int hOrder);
	CComplex* GetYm(int hOrder);

	void SetYs(int hOrder, CComplex *newVal);
	void SetYm(int hOrder, CComplex *newVal);
	

	double Ys11re;
	double Ys12re;
	double Ym11re;
	double Ys11im;
	double Ym12re;
	double Ys12im;
	double Ym11im;
	double Ym12im;

	//马骏鹏
public:
	/**
	 * 马骏鹏
	 */
	string StationName1;
	string StationName2;
	//返回Y阵
	CMatrix GetYMatrix(int hOrder);
	/**
	 * 马骏鹏
	 */
	string GetStationName1();
	string GetStationName2();
	/**
	 * 马骏鹏
	 */
	void SetStationName1(string newVal);
	void SetStationName2(string newVal);
	void SetYm12re(double newVal);
	double GetYm11re();
	double GetYs11im();
	void SetYm11re(double newVal);
	void SetYs11im(double newVal);
	double GetYs12im();
	void SetYs12im(double newVal);
	double GetYm11im();
	double GetYs11re();
	void SetYm11im(double newVal);
	void SetYs11re(double newVal);
	double GetYm12im();
	double GetYs12re();
	void SetYm12im(double newVal);
	void SetYs12re(double newVal);
	double GetYm12re();
};
#endif // !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
