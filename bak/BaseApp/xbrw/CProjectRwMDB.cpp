///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CProjectRwMDB
//  Created on:      16-4ÔÂ-2017 11:10:21
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CProjectRwMDB.h"
#include "CHvdcParams.h"

#include <iostream>

void CProjectRwMDB::InitAdo(string vDbf) 
{

	dbfName = vDbf;

	//RwAdo = new CRwAdo_MDB();

	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}

void CProjectRwMDB::doLoad()
{
	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	//
	vSQL = "select * from Hvdc_Project";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---Hvdc_Project---" << endl;

		RwAdo->GetFieldValue("ProjectName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (LPCTSTR)(_bstr_t)vValue; //×Ö·ûÐÍ
			CHvdcParams::ProjectName = vStr;
		};

		RwAdo->GetFieldValue("StationCount", vValue);
		if (vValue.vt != VT_NULL)
		{
			CHvdcParams::StationCount = vValue.iVal;
		};

		cout << "   Finished " << endl;

	}//if
		
	RwAdo->CloseTBL();

}

void CProjectRwMDB::doSave()
{


}

