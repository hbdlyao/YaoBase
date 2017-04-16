///////////////////////////////////////////////////////////
//  CxbRw.cpp
//  Implementation of the Class CxbRw
//  Created on:      06-4ÔÂ-2017 17:56:23
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbRw.h"


void CxbRw::InitAdo(string vDbf)
{

	dbfName = vDbf;
	
	//RwAdo = new CRwAdo_MDB();
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CxbRw::doLoad()
{
	//


}


void CxbRw::doSave()
{
	//
}