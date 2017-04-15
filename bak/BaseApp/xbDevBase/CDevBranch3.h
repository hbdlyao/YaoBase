///////////////////////////////////////////////////////////
//  CDevBranch3.h
//  Implementation of the Class CxbDevBranch3
//  Created on:      05-4月-2017 18:06:38
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_)
#define EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_

#include "CHvdcDeviceBase.h"

class CDevBranch3 : public CDevTwoDot
{
protected:
	/**
	 * 3P的等效电导
	 */
	double Yg;
	/**
	 * 3P的等效电纳
	 */
	double Yb;



public:
	/**
	 * 3P的等效电导
	 */
	double GetYg();
	/**
	 * 3P的等效电导
	 */
	void SetYg(double newVal);
	/**
	 * 3P的等效电纳
	 */
	double GetYb();
	/**
	 * 3P的等效电纳
	 */
	void SetYb(double newVal);
};
#endif // !defined(EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_)
