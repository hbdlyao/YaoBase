///////////////////////////////////////////////////////////
//  CxbDevDcLine.h
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4月-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
#define EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_

#include "CxbDevTwoDot.h"
#include "CMatrix.h"
#include "gbHead_Def.h"
/**
* 直流极线
*/
class CxbDevDcLine : public CxbDevTwoDot
{
public:
	virtual void Init();

protected:
	struct_LineParam * pLineParam;
	
	//马骏鹏
public:
	//返回Y阵
	CMatrix GetYMatrix(int hOrder);

	//
	double GetYs11re(int vhOrder);
	double GetYs11im(int vhOrder);

	double GetYs12re(int vhOrder);
	double GetYs12im(int vhOrder);

	double GetYm11re(int vhOrder);
	double GetYm11im(int vhOrder);
	
	double GetYm12re(int vhOrder);
	double GetYm12im(int vhOrder);

	//
	void SetYs11re(int vhOrder,double vY);
	void SetYs11im(int vhOrder, double vY);
	
	void SetYs12re(int vhOrder,double vY);
	void SetYs12im(int vhOrder,double vY);

	void SetYm11re(int vhOrder,double vY);
	void SetYm11im(int vhOrder, double vY);
	
	void SetYm12re(int vhOrder,double vY);
	void SetYm12im(int vhOrder,double vY);

	//
	virtual void Prepare_hRLC();

};
#endif // !defined(EA_8F46C231_3B03_492f_AF91_2960C3884C16__INCLUDED_)
