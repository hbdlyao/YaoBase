#pragma once


#include "CMyRwAdo.h"

#include <string>

using namespace std;

class CRwDbf
{
public:
	virtual void OnLoad();
	virtual void OnSave();

	virtual void InitAdo(CRwAdo * vAdo);
	virtual void InitTable(string vtblName, int vtblType, int vDevType);

protected:
	
	string dbfName;
	CRwAdo* RwAdo;
	string tblName;
	int tblType;
	int devType;

	virtual bool doOpenDBF();
	virtual bool doCloseDBF();

};
