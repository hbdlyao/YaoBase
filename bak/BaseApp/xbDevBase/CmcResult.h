#pragma once

#include "CHvdcDefs.h"

class CmcResult
{
public:
	int StaDim;

	struct_mcResult * pmcResult;

	~CmcResult();
	void Init();
	void Clear();
	void Release();
	void InitMatrix();

};
