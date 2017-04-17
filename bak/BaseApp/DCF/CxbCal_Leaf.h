#pragma once

#include "CxbCalculate.h"


class CxbCal_Leaf : public CxbCalculate
{

public:
	virtual void Add(CxbCalculate * vItem);
	virtual void Remove(CxbCalculate * vItem);
	/**
	 * void Init(CPowerProfile * vProfile, CPowerGrid * vGrid) override;
	 */
	virtual void UpdateY();
	virtual void UpdateI();

protected:

};
