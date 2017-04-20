#pragma once

#include "gbHead_Def.h"
#include "CxbDevOneDot.h"

/**
* RLC并联支路
*/
class CxbDevShunt : public CxbDevOneDot
{
protected:
	/**
	* 支路数据
	*/
	struct_Branch structBranch;

	//马骏鹏
	double * Yg = nullptr;
	double * Yb = nullptr;

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

	//马骏鹏	
	double GetYg(int vhOrder);
	double GetYb(int vhOrder);

public:
	virtual void Prepare_hRLC() override;
	virtual void Init();


};
