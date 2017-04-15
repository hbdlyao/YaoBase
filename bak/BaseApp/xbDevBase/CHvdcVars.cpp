///////////////////////////////////////////////////////////
//  CHvdcVars.cpp
//  Implementation of the Class CHvdcVars
//  Created on:      23-3ÔÂ-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcDefs.h"
#include "CHvdcVars.h"

#include "CHvdcParams.h"
#include "gbHead_Var.h"

/////////////////////////////////

//
CmcHvdcGrid * CHvdcVars::pmcHvdcGrid =nullptr;
CxbHvdcGrid * CHvdcVars::pxbHvdcGrid =nullptr;

///////////////////////////////////////////

CHvdcVars::~CHvdcVars()
{
	Release();
}

void CHvdcVars::Release()
{
	delete pmcHvdcGrid;
	pmcHvdcGrid = nullptr;

	delete pxbHvdcGrid;
	pxbHvdcGrid = nullptr;
	
}


void CHvdcVars::Clear()
{
	pmcHvdcGrid->Clear();
	pxbHvdcGrid->Clear();
}


void CHvdcVars::Init()
{

	doInit_mcHvdcGrid();

	doInit_xbHvdcGrid();
	
}

void CHvdcVars::doInit_mcHvdcGrid() 
{

	if (pmcHvdcGrid != nullptr)
		pmcHvdcGrid->Clear();
	else
	{
		pmcHvdcGrid = new CmcHvdcGrid();
		//
		pmcHvdcGrid->Init();
	}//else
	
}


void CHvdcVars::doInit_xbHvdcGrid()
{

	if (pxbHvdcGrid != nullptr)
		pxbHvdcGrid->Clear();
	else
	{
		pxbHvdcGrid = new CxbHvdcGrid();
		//
		pxbHvdcGrid->Init();
	}//else

}

