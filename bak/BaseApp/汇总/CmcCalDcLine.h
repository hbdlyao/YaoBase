#pragma once

#include "CmcCalTwoDot.h"

/**
 * ����· ֱ������
 */
class CmcCalDcLine : public CmcCalTwoDot
{

public:
	virtual void StationSort(StationMap & vStaMap);

protected:
	virtual void UpdateY();

};


