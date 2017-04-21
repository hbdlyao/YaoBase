#pragma once


#include "CmcHvdcGrid.h"
#include "CxbHvdcGrid.h"


class CHvdcVars
{
public:

	static CmcHvdcGrid  * pmcHvdcGrid ;
	static CxbHvdcGrid  * pxbHvdcGrid;

	static void Init();
	static void Release();
	static void Clear();

protected:
	static void doInit_mcHvdcGrid();
	static void doInit_xbHvdcGrid();

	CHvdcVars(const CHvdcVars& vInstance) {};

	CHvdcVars() {};
	~CHvdcVars();

};

//
