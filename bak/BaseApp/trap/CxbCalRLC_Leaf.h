#pragma once

#include "CxbCalRLC.h"


class CxbCalRLC_Leaf : public CxbCalRLC
{

public:
	void Add(CxbCalRLC * vItem) override;
	void Remove(CxbCalRLC * vItem) override;


protected:
	virtual void UpdateY();
};
