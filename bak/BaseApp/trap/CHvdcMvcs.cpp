///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcMvcs.h"
#include "CMyParams.h"

#include "CHvdcVars.h"

CProjectRwMDB *  CHvdcMvcs::pProjectRw = nullptr;

CmcRw * CHvdcMvcs::pmcRws=nullptr;
CxbRw * CHvdcMvcs::pxbRws = nullptr;


void CHvdcMvcs::Init()
{
	pProjectRw = new CProjectRwMDB();
	pProjectRw->InitAdo(CMyParams::dbf_mdb);


	pmcRws = new CmcRw();
	pmcRws->InitAdo(CMyParams::dbf_mdb);
	pmcRws->InitGrid(CHvdcVars::pmcHvdcGrid);


	pxbRws = new CxbRw();
	pxbRws->InitAdo(CMyParams::dbf_mdb);
	pxbRws->InitGrid(CHvdcVars::pxbHvdcGrid);
	
}


void CHvdcMvcs::Clear()
{
	pProjectRw->Clear();

	pmcRws->Clear();

	pxbRws->Clear();


}

void CHvdcMvcs::Release()
{
	delete pProjectRw;
	pProjectRw = nullptr;
	//
	delete pmcRws;
	pmcRws = nullptr;
	//
	delete pxbRws;
	pxbRws = nullptr;
	//

}

void CHvdcMvcs::OnLoad()
{
	pProjectRw->OnLoad();

	//pmcRws->OnLoad();

	pxbRws->OnLoad();
}

void CHvdcMvcs::OnSave()
{
	pProjectRw->OnSave();

	//pmcRws->OnSave();

	pxbRws->OnSave();
}
