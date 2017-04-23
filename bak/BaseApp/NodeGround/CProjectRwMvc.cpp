///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CProjectRwMvc
//  Created on:      18-4月-2017 22:23:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CProjectRwMvc.h"
#include "CHvdcParams.h"
#include <iostream>


void CProjectRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	//RwAdo = new CRwAdo_MDB();

	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}

void CProjectRwMvc::doLoad()
{

	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	
	//
	vSQL = "select * from Hvdc_Project";
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
		while (!RwAdo->IsEOF())
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

			RwAdo->GetFieldValue("mcStationCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				CHvdcParams::mcStationCount = vValue.iVal;
			};

			RwAdo->GetFieldValue("xbStationCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				CHvdcParams::xbStationCount = vValue.iVal;
			};
			cout << "   Finished " << endl;

			RwAdo->Record_MoveNext();

		}//while
		
	RwAdo->CloseTBL();
}


void CProjectRwMvc::doSave(){

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
	
			vValue = _variant_t(CHvdcParams::mcStationCount);
			RwAdo->SetFieldValue("mcStationCount", vValue);

			vValue = _variant_t(CHvdcParams::xbStationCount);
			RwAdo->SetFieldValue("xbStationCount", vValue);


	
			RwAdo->Record_Update();
	
			cout << " Finished Hvdc_Project " << endl;
	
	
	}//if
	
	RwAdo->CloseTBL();
}

