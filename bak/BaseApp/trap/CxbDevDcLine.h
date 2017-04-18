///////////////////////////////////////////////////////////
//  CxbDevDcLine.h
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4��-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
#define EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_

#include "CxbDevBase.h"
//����
#include "CMatrix.h"
#include "gbHead_Def.h"
/**
* ֱ������
*/
class CxbDevDcLine : public CxbDevBase
{

public:

	virtual void Init();

protected:
	//����
	/**
	* ������2X2����
	*/
	CComplex * Ys;
	//double * Ysr;
	//double * Ysm;
	/**
	* ������2X2����
	*/
	CComplex *  Ym;
	double Ys11;
	double Ys12;
	double Ym11;
	double Ym12;

	//����
public:
	/**
	 * ����
	 */
	string StationName1;
	string StationName2;
	//
	void SetYs(int hOrder, CComplex *newVal);
	void SetYm(int hOrder, CComplex *newVal);
	//����Y��
	CMatrix GetYMatrix(int hOrder);
	//����Ys��Ym
	CComplex* GetYs(int hOrder);
	CComplex* GetYm(int hOrder);
	/**
	 * ����
	 */
	string GetStationName1();
	string GetStationName2();
	/**
	 * ����
	 */
	void SetStationName1(string newVal);
	void SetStationName2(string newVal);
	double GetYs11();
	void SetYs11(double newVal);
	double GetYs12();
	void SetYs12(double newVal);
	double GetYm11();
	void SetYm11(double newVal);
	double GetYm12();
	void SetYm12(double newVal);
};
#endif // !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
