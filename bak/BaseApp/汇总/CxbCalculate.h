#pragma once

#include "CPowerCalculate.h"
#include "CxbProfile.h"
#include "CxbHvdcGrid.h"

class CxbCalculate : public CPowerCalculate
{
private:
	CxbHvdcGrid *pHvdc;

protected:
	CxbProfile * pxbProfile;
	//CxbHvdcGrid * pxbHvdc;

public:
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid) override;

	/**
	 * void Init(CPowerProfile * vProfile, CPowerGrid * vGrid) override;
	 */
	virtual void UpdateY();
	virtual void Prepare();
	virtual void UpdateI();
	virtual void StationSort(StationMap& vStaMap) override;
	
};

