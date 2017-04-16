///////////////////////////////////////////////////////////
//  CxbDevBranch.h
//  Implementation of the Class CxbDevBranch
//  Created on:      12-4��-2017 12:00:47
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_)
#define EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_

#include "gbHead_Def.h"
#include "CxbDevTwoDot.h"

/**
* ����֧·
*/
class CxbDevBranch : public CxbDevTwoDot
{

public:
	/**
	* ֧·����
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
	//����
	double * Yg;
	double * Yb;

	/**
	* �ܶ˻���վ����
	*/
	string GetStationName1();
	/**
	* �ܶ˻���վ����
	*/
	string GetStationName2();
	/**
	* �ܶ˻���վ����
	*/
	void SetStationName1(string newVal);
	/**
	* �ܶ˻���վ����
	*/
	void SetStationName2(string newVal);
	//����
	virtual void InitY(double vFre);
	virtual double GetYg(int vhOrder);
	virtual double GetYb(int vhOrder);


protected:
	/**
	* �ܶ˻���վ����
	*/
	string StationName1;
	/**
	* �ܶ˻���վ����
	*/
	string StationName2;

};
#endif // !defined(EA_F5DF077B_7C96_4a64_AB81_338A47E67934__INCLUDED_)
