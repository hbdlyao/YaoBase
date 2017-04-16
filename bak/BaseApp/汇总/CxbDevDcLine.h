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
	//����
	string StationName1;
	string StationName2;

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
	virtual void MyFree();

	//����
public:
	//
	void SetYs(int hOrder, CComplex *newVal);
	void SetYm(int hOrder, CComplex *newVal);
	//����Y��
	CMatrix GetYMatrix(int hOrder);
	//����Ys��Ym
	CComplex* GetYs(int hOrder);
	CComplex* GetYm(int hOrder);
};
#endif // !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
