///////////////////////////////////////////////////////////
//  CxbDevShunt.h
//  Implementation of the Class CxbDevShunt
//  Created on:      12-4月-2017 12:00:41
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_)
#define EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_

#include "gbHead_Def.h"
#include "CxbDevOneDot.h"

/**
* RLC并联支路
*/
class CxbDevShunt : public CxbDevOneDot
{

public:
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
	virtual void Init();
	//马骏鹏
	virtual void InitY(double vFre);
	virtual double GetYg(int vhOrder);
	virtual double GetYb(int vhOrder);

protected:
	/**
	* 支路数据
	*/
	struct_Branch structBranch;

	//马骏鹏
	double * Yg;
	double * Yb;

};
#endif // !defined(EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_)
