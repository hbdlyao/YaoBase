///////////////////////////////////////////////////////////
//  CMyRw.cpp
//  Implementation of the Class CRwDbf
//  Created on:      02-4ÔÂ-2017 15:37:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRw.h"
#include <iostream>

void CRwDbf::InitAdo(CRwAdo * vAdo)
{
	RwAdo = vAdo;
}

void CRwDbf::InitTable(string vtblName, int vtblType, int vDevType) 
{
	tblName = vtblName;
	tblType = vtblType;
	devType = vDevType;
}


void CRwDbf::OnLoad() 
{

}


void CRwDbf::OnSave()
{

}


bool CRwDbf::doOpenDBF()
{
	bool vOk;
	
	vOk=RwAdo->OpenDBF();
	
	return vOk;
}


bool CRwDbf::doCloseDBF()
{
	bool vOk;
	
	vOk=RwAdo->CloseDBF();
	
	return vOk;
}

