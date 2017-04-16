#pragma once

#include "CProjectRwMDB.h"

#include "CmcRw.h"
#include "CmcSolveMvc.h"

#include "CxbRw.h"
#include "CxbSolveMvc.h"


class CHvdcMvcs
{
public:
	//

	static CProjectRwMDB *  pProjectRw;

	static CmcRw *  pmcRws;
	static CxbRw *  pxbRws;

		
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

