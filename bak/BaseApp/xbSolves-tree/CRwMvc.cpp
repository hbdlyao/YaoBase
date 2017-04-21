///////////////////////////////////////////////////////////
//  CRwMvc.cpp
//  Implementation of the Class CRwMvc
//  Created on:      18-4ÔÂ-2017 18:14:29
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CRwMvc.h"
#include <iostream>

CRwMvc::~CRwMvc()
{
	//
	delete RwAdo;
	RwAdo = nullptr;
}



void CRwMvc::OnLoad()
{

	try
	{
		if (doOpenDBF())
		{
			doLoad();
	
			//
			doCloseDBF();
	
		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CRwMvc::OnSave()
{

	try
	{
		if (doOpenDBF())
		{
			
			doSave();
	
			//
			doCloseDBF();
	
		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;
	
	RwAdo = new CRwAdo();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CRwMvc::doLoad()
{

}


void CRwMvc::doSave()
{

}


bool CRwMvc::doOpenDBF()
{
	bool vOk;
	
	vOk=RwAdo->OpenDBF();
	
	return vOk;
}


bool CRwMvc::doCloseDBF()
{
	bool vOk;
	
	vOk=RwAdo->CloseDBF();
	
	return vOk;
}




void CRwMvcAccess::InitAdo(string vDbf){

	dbfName = vDbf;
	
	//RwAdo = new CRwAdo_MDB();
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}