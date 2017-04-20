#pragma once

#include "gbHead_Def.h"
#include "CxbDevOneDot.h"

/**
* RLC����֧·
*/
class CxbDevShunt : public CxbDevOneDot
{
protected:
	/**
	* ֧·����
	*/
	struct_Branch structBranch;

	//����
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

	//����	
	double GetYg(int vhOrder);
	double GetYb(int vhOrder);

public:
	virtual void Prepare_hRLC() override;
	virtual void Init();


};
