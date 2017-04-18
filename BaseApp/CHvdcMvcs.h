#pragma once

#include "CProjectRwMvc.h"

#include "CmcRwMvc.h"
#include "CmcSolveMvc.h"

#include "CxbRwMvc.h"
#include "CxbSolveMvc.h"


class CHvdcMvcs
{
public:
	//

	static CProjectRwMvc *  pProjectRwMvc;

	static CmcRwMvc *  pmcRwMvc;
	static CxbRwMvc *  pxbRwMvc;

		
	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad();
	static void OnSave();

	
protected:
	CHvdcMvcs(const CHvdcMvcs& theCmcMvcs) {};

	CHvdcMvcs() {};

	virtual ~CHvdcMvcs() {};


};

