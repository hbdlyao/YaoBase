///////////////////////////////////////////////////////////
//  CxbRw3pVSrc.cpp
//  Implementation of the Class CxbRw3pVSrc
//  Created on:      18-4月-2017 17:17:11
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRw3pVSrc.h"

#include <iostream>
//
void CxbRw3pVSrc::OnLoad()
{
	doLoad();

	doLoad_hData();
}

void CxbRw3pVSrc::OnSave()
{
	doSave();

	doSave_hData();
}

void CxbRw3pVSrc::doLoad()
{
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from " + tblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" << tblName << "---" << endl;


		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(tblType);
			vDev = dynamic_cast<CxbDev3pVSrc *>(vTBL->NewDevice(devType));

			doLoad(vDev);

			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}

void CxbRw3pVSrc::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(vDevice);

	CxbRwTwo::doLoad(vDev);
	//

}


void CxbRw3pVSrc::doLoad_hData()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;

	vTBL = pHvdc->DeviceTBL(tblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDev3pVSrc *>(vPair.second);

		//
		doLoad_hData(vDev);


	}//for each

}


void CxbRw3pVSrc::doLoad_hData(CxbDev3pVSrc * vDev)
{
	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	int vh;

	//
	vSQL = "select * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by DeviceName ,hOrder ";

	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + tblName + "_hData " << endl;

		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("hOrder", vValue);
			if (vValue.vt != VT_NULL)
			{
				vh = vValue.iVal;
			};

			RwAdo->GetFieldValue("hUrms", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hUrms(vh, vValue.dblVal);
			};

			RwAdo->GetFieldValue("hAngle", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hAngle(vh, vValue.dblVal);
			};
			RwAdo->GetFieldValue("hYb", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hYb(vh, vValue.dblVal);
			};


			//
			RwAdo->Record_MoveNext();


		}//while

		cout << "   --" << vDev->GetDeviceName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}


void CxbRw3pVSrc::doSave()
{
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;

	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vSQL = "delete * from " + tblName;
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

			vDev = dynamic_cast<CxbDev3pVSrc *>(vTBL->Device(i));
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



void CxbRw3pVSrc::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(vDevice);

	CxbRwTwo::doSave(vDev);


}

void CxbRw3pVSrc::doSave_hData()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;


	vTBL = pHvdc->DeviceTBL(tblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDev3pVSrc *>(vPair.second);

		//
		doSave_hData(vDev);


	}//for each

}


void CxbRw3pVSrc::doSave_hData(CxbDev3pVSrc * vDev)
{
	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vSQL = "delete * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";

	vOk = RwAdo->ExecSQL(vSQL);

	vSQL = "select * from " + tblName + "_hData ";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	//
	if (vOk)
	{
		cout << "save---" + tblName + "_hData " << endl;

		for (i = 1; i<=vDev->hMax(); i++)
		{
			RwAdo->Record_AddNew();
			//
			vValue = _variant_t(i);//整型
			RwAdo->SetFieldValue("hOrder", vValue);

			vValue = _variant_t(vDev->Get_hUrms(i));//双精度
			RwAdo->SetFieldValue("hUrms", vValue);

			vValue = _variant_t(vDev->Get_hAngle(i));//双精度
			RwAdo->SetFieldValue("hAngle", vValue);
			
			vValue = _variant_t(vDev->Get_hYb(i));//双精度
			RwAdo->SetFieldValue("hYb", vValue);
			
			//
			RwAdo->Record_Update();

		}//

		cout << "   --" << vDev->GetDeviceName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}