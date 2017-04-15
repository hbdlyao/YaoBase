#pragma once

#include "CMyRw.h"

class CMyMvcs
{
protected:
	CMyMvcs(const CMyMvcs& theInstance) {};

	CMyMvcs() {};	
    ~CMyMvcs() {};
	
public:
	static void Release();
	static void Clear();
	static void Init();

	static CRwDbf RwMvc;
};


