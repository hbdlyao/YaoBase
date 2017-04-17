#pragma once


#include "CmcCalOneDot.h"

/**
 * 主回路 接地极线
 */
class CmcCalGroundLine : public CmcCalOneDot
{


public:

protected:
	virtual void UpdateY();
};
