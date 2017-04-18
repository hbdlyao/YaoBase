///////////////////////////////////////////////////////////
//  CxbRw.cpp
//  Implementation of the Class CxbRw
//  Created on:      06-4ÔÂ-2017 17:56:23
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbRw.h"

#include "CHvdcParams.h"
#include "CHvdcVars.h"

#include <iostream>


void CxbRw::InitGrid(CxbHvdcGrid * vHvdc)
{
	pHvdc = vHvdc;
}


void CxbRw::OnLoad()
{
	CDeviceTBL * vTBL;
	CxbDevBase * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from "+ tblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" << tblName <<"---" << endl;


		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(tblType);
			vDev = dynamic_cast<CxbDevBase *>(vTBL->NewDevice(devType));

			doLoad(vDev);

			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::OnSave()
{
	CDeviceTBL * vTBL;
	CxbDevBase * vDev;

	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vSQL = "delete * from "+ tblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + tblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" << tblName << "---" << endl;

		vTBL = pHvdc->DeviceTBL(tblType);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CxbDevBase *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			doSave(vDev);

			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;

		}//for

	}//if

	RwAdo->CloseTBL();



}



void CxbRw::doLoad(CxbDevBase * vDevice)
{

}


void CxbRw::doSave(CxbDevBase * vDevice)
{

}

void CxbRw::OnLoad_Order(CxbOrder* vOrder){

	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	
	//
	vSQL = "select * from xbOrder ";
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
		while (!RwAdo->IsEOF())
		{
			cout << "Load---xbOrder---" << endl;
	
			RwAdo->GetFieldValue("Flag_Ground", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //×Ö·ûÐÍ
				vOrder->Flag_Ground = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Ud", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //×Ö·ûÐÍ
				vOrder->Flag_Ud = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Rd", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //×Ö·ûÐÍ
				vOrder->Flag_Rd = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //×Ö·ûÐÍ
				vOrder->Flag_Uac = vStr;
			};
	
			RwAdo->GetFieldValue("IsUdCustom", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->IsUdCustom = (vValue.iVal == 1);
			};
	
			RwAdo->GetFieldValue("IsUacSwap", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->IsUacSwap = (vValue.iVal == 1);
			};
	
			RwAdo->GetFieldValue("IsUdToGround", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->IsUdToGround = (vValue.iVal == 1);
			};
	
			/*
			RwAdo->GetFieldValue("Is6p", vValue);
			if (vValue.vt != VT_NULL)
			{
			vOrder->Is6p = (vValue.iVal == 1);
			};
	
			RwAdo->GetFieldValue("Is12pDouble", vValue);
			if (vValue.vt != VT_NULL)
			{
			vOrder->Is12pDouble = (vValue.iVal == 1);
			};
			*/
	
			RwAdo->GetFieldValue("nValvor", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->nValNum = vValue.iVal;
			};
	
			RwAdo->GetFieldValue("PdStartPercent", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->PdStartPer = vValue.dblVal;
			};
	
			RwAdo->GetFieldValue("PdPercent", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->PdPer = vValue.dblVal;
			};
	
			RwAdo->GetFieldValue("PdSize", vValue);
			if (vValue.vt != VT_NULL)
			{
				vOrder->PdSize = vValue.iVal;
			};
	
			RwAdo->Record_MoveNext();
	
			cout << "   Finished " << endl;
	
		}//while
	
	RwAdo->CloseTBL();
}


void CxbRw::OnSave_Order(CxbOrder* vOrder)
{

}


void CxbRw::OnLoad_Result(CxbResult* vRes)
{

}


void CxbRw::OnSave_Result(CxbResult* vRes)
{

}