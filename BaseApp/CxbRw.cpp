///////////////////////////////////////////////////////////
//  CxbRw.cpp
//  Implementation of the Class CxbRw
//  Created on:      06-4月-2017 17:56:23
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
	string vStr;
	_variant_t vValue;
	CxbDevBase * vDev;

	vDev = dynamic_cast<CxbDevBase *>(vDevice);


	RwAdo->GetFieldValue("ID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetObjGUID(vValue.iVal);
	};

	RwAdo->GetFieldValue("DeviceID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetDeviceID(vStr);
	};

	RwAdo->GetFieldValue("DeviceName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue;
		vDev->SetDeviceName(vStr);
	};

	RwAdo->GetFieldValue("DeviceType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDeviceType(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};
}


void CxbRw::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevBase * vDev;

	vDev = dynamic_cast<CxbDevBase *>(vDevice);

	vValue = _variant_t(vDev->GetObjGUID()); //整型
	RwAdo->SetFieldValue("ID", vValue);

	vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
	RwAdo->SetFieldValue("DeviceID", vValue);

	vValue = _variant_t(vDev->GetDeviceName().c_str());
	RwAdo->SetFieldValue("DeviceName", vValue);

	vValue = _variant_t(vDev->GetDeviceType());
	RwAdo->SetFieldValue("DeviceType", vValue);

	vValue = _variant_t(vDev->GetPosOrNeg());
	RwAdo->SetFieldValue("PosOrNeg", vValue);

}