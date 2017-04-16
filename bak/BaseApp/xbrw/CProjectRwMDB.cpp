///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CProjectRwMDB
//  Created on:      16-4月-2017 11:10:21
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
			vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
			CHvdcParams::ProjectName = vStr;
		};

		RwAdo->GetFieldValue("ID", vValue);
		if (vValue.vt != VT_NULL)
		{
			CHvdcParams::ProjectID = vValue.iVal;
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
	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;

	vSQL = "delete * from Hvdc_Project";
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from Hvdc_Project";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---Hvdc_Project---" << endl;

			RwAdo->Record_AddNew();
		
			vValue = _variant_t(CHvdcParams::ProjectID); //整型
			RwAdo->SetFieldValue("ID", vValue);

			vValue = _variant_t(CHvdcParams::ProjectName.c_str());//文本型
			RwAdo->SetFieldValue("ProjectName", vValue);

			vValue = _variant_t(CHvdcParams::StationCount); 
			RwAdo->SetFieldValue("StationCount", vValue); 

			RwAdo->Record_Update();

			cout << " Finished Hvdc_Project " << endl;


	}//if

	RwAdo->CloseTBL();
}
