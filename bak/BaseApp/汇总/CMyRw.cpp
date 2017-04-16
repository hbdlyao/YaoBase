///////////////////////////////////////////////////////////
//  CMyRw.cpp
//  Implementation of the Class CRwDbf
//  Created on:      02-4ÔÂ-2017 15:37:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRw.h"
#include <iostream>


CRwDbf::~CRwDbf(){

	Release();
}


void CRwDbf::OnLoad(){

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


void CRwDbf::OnSave(){

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


void CRwDbf::InitAdo(string vDbf){

	dbfName = vDbf;
	
	RwAdo = new CRwAdo();
	RwAdo->InitDbf(dbfName,"","","false");
}


/**
 * virtual void InitAdo(string vDbf);
 */
void CRwDbf::Clear(){

}


void CRwDbf::Release(){

	Clear();
	//
	delete RwAdo;
	RwAdo = nullptr;
}


void CRwDbf::doLoad(){

}


void CRwDbf::doSave(){

}


bool CRwDbf::doOpenDBF(){

	bool vOk;
	
		vOk=RwAdo->OpenDBF();
	
		return vOk;
}


bool CRwDbf::doCloseDBF(){

	bool vOk;
	
		vOk=RwAdo->CloseDBF();
	
		return vOk;
}