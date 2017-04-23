///////////////////////////////////////////////////////////
//  CRwMvc.h
//  Implementation of the Class CRwMvc
//  Created on:      18-4ÔÂ-2017 18:14:29
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_)
#define EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_

#include "CMyRwAdo.h"
#include <string>

using namespace std;

class CRwMvc
{

protected:
	CRwAdo* RwAdo;
	string dbfName;
	string tblName;
	int tblType;
	int devType;

public:
	virtual ~CRwMvc();

	virtual void OnLoad();
	virtual void OnSave();

	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();
	virtual bool doOpenDBF();
	virtual bool doCloseDBF();

};

class CRwMvcAccess : public CRwMvc
{

public:
	virtual void InitAdo(string vDbf);

};
#endif // !defined(EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_)
