#pragma once


#include "CMyRwAdo.h"

#include <string>

using namespace std;

class CRwDbf
{

public:
	~CRwDbf();
	virtual void OnLoad();
	virtual void OnSave();
	virtual void InitAdo(string vDbf);
	/**
	 * virtual void InitAdo(string vDbf);
	 */
	virtual void Clear();
	virtual void Release();

protected:
	string dbfName;
	CRwAdo* RwAdo;

	virtual void doLoad();
	virtual void doSave();
	virtual bool doOpenDBF();
	virtual bool doCloseDBF();

};
