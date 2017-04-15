#pragma once

#include "CmcProfile.h"
#include "CPowerCalculate.h"


class CmcCalculate : public CPowerCalculate
{
protected:
	CmcProfile * pmcProfile;

public:

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);
	
	virtual void CalConvertor();
	virtual void CalTap();
	virtual void UpdateY();
	virtual void Prepare();
	virtual void UpdateJ();
	virtual void UpdateF_J();

	virtual void CalConvertorNormal();
	virtual void CalTapNormal();
	virtual void InitX();
	virtual void PrepareNormal();

protected:

};

/**
 * typedef map<string, CmcCalculate> CalMap;
 */
typedef map<int, CmcCalculate> CalMap;
