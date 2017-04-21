///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcMvcs.h"
#include "CMyParams.h"

#include "CHvdcVars.h"

CProjectRwMvc *  CHvdcMvcs::pProjectRwMvc = nullptr;

CmcRwMvc * CHvdcMvcs::pmcRwMvc=nullptr;
CxbRwMvc * CHvdcMvcs::pxbRwMvc = nullptr;


void CHvdcMvcs::Init()
{
	
	pProjectRwMvc = new CProjectRwMvc();
	pProjectRwMvc->InitAdo(CMyParams::dbf_mdb);


	pmcRwMvc = new CmcRwMvc();
	pmcRwMvc->InitAdo(CMyParams::dbf_mdb);
	pmcRwMvc->InitGrid(CHvdcVars::pmcHvdcGrid);
	
	
	pxbRwMvc = new CxbRwMvc();
	pxbRwMvc->InitAdo(CMyParams::dbf_mdb);
	pxbRwMvc->InitGrid(CHvdcVars::pxbHvdcGrid);
	

}


void CHvdcMvcs::Clear()
{
	//pProjectRw->Clear();

	//pmcRws->Clear();

	//pxbRws->Clear();


}

void CHvdcMvcs::Release()
{
	
	delete pProjectRwMvc;
	pProjectRwMvc = nullptr;
	

	delete pmcRwMvc;
	pmcRwMvc = nullptr;

	//
	delete pxbRwMvc;
	pxbRwMvc = nullptr;
	//

}

void CHvdcMvcs::OnLoad()
{
	pProjectRwMvc->OnLoad();

	//pmcRwMvc->OnLoad();
	//pxbRwMvc->OnLoad();
}

void CHvdcMvcs::OnSave()
{
	//pProjectRwMvc->OnSave();

	//pmcRwMvc->OnSave();
	//pxbRwMvc->OnSave();

}
