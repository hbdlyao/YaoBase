///////////////////////////////////////////////////////////
//  CxbDevBranch.h
//  Implementation of the Class CxbDevBranch
//  Created on:      12-4月-2017 12:00:47
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_)
#define EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_

#include "gbHead_Def.h"
#include "CxbDevTwoDot.h"

/**
* 串联支路
*/
class CxbDevBranch : public CxbDevTwoDot
{

public:
	/**
	* 支路数据
	*/
	struct_Branch structBranch;

	/**
	* CmcDevBranch
	*/
	virtual void Init();
	double GetZr();
	double GetZ_C();
	double GetZ_L();
	double GetZx_C();
	double GetZx_L();

	void SetZr(double vValue);
	void SetZ_C(double vValue);
	void SetZ_L(double vValue);
	void SetZx_C(double vValue);
	void SetZx_L(double vValue);
	//马骏鹏
	double * Yg;
	double * Yb;
	//马骏鹏
	virtual void InitY(double vFre);
	virtual double GetYg(int vhOrder);
	virtual double GetYb(int vhOrder);


protected:

};
#endif // !defined(EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_)
