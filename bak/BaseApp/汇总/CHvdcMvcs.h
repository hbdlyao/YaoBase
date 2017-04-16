#pragma once

#include "CmcRw.h"
#include "CmcSolveMvc.h"

#include "CxbRw.h"
#include "CxbSolveMvc.h"


class CHvdcMvcs
{
public:
	//
	static CmcRw *  pmcRws;
	static CxbRw *  pxbRws;
	CmcRw *pRws;
	CmcRw *pRwMvcs;
	CmcSolveMvc *pmcSolveMvc;
	CxbSolveMvc *pxbSolveMvc;

	/**
	 * CxbSolveMvc * CHvdcMvcs::pxbSolveMvc;
	 */
	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad();
	static void OnSave();

	
protected:
	CHvdcMvcs(const CHvdcMvcs& theCmcMvcs) {};

	CHvdcMvcs() {};

	~CHvdcMvcs() {};


};

