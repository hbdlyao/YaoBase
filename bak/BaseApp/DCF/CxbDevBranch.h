///////////////////////////////////////////////////////////
//  CxbDevBranch.h
//  Implementation of the Class CxbDevBranch
//  Created on:      19-4��-2017 23:19:31
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_)
#define EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_

#include "CHvdcDefs.h"
#include "CxbDevTwoDot.h"

#include "CComplex.h"

/**
 * ����֧·
 */
class CxbDevBranch : public CxbDevTwoDot
{

protected:
	/**
	* ֧·����
	*/
	struct_Branch structBranch;

	/**
	 * ����
	 */
	double* Yg;
	double* Yb;

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
	/**
	 * ����
	 */
	double GetYg(int vhOrder);
	double GetYb(int vhOrder);
	virtual void Prepare_hRLC() override;
	virtual void Init();


};
#endif // !defined(EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_)
