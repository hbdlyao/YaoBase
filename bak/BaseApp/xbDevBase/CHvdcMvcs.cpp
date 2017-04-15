///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcMvcs.h"
#include "CMyParams.h"

#include "CHvdcVars.h"

CmcRw * CHvdcMvcs::pmcRws=nullptr;
CxbRw * CHvdcMvcs::pxbRws = nullptr;


void CHvdcMvcs::Init()
{
	pmcRws = new CmcRw();
	pmcRws->InitAdo(CMyParams::dbf_mdb);

	pxbRws = new CxbRw();
	pxbRws->InitAdo(CMyParams::dbf_mdb);
	
}


void CHvdcMvcs::Clear()
{
	pmcRws->Clear();

	pxbRws->Clear();


}

void CHvdcMvcs::Release()
{

	delete pmcRws;
	//
	delete pxbRws;
	//

}

void CHvdcMvcs::OnLoad()
{
	pmcRws->OnLoad();
	pxbRws->OnLoad();
}

void CHvdcMvcs::OnSave()
{
	pmcRws->OnSave();
	//pxbRws->OnSave();
}
