///////////////////////////////////////////////////////////
//  CxbRwDcLine.cpp
//  Implementation of the Class CxbRwDcLine
//  Created on:      18-4月-2017 17:11:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDcLine.h"

//
void CxbRwDcLine::OnLoad()
{
	doLoad();

	doLoad_hData();
}

void CxbRwDcLine::OnSave()
{
	doSave();

	doSave_hData();
}


void CxbRwDcLine::doLoad()
{
	CDeviceTBL * vTBL;
	CxbDevDcLine * vDev;

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
			vDev = dynamic_cast<CxbDevDcLine *>(vTBL->NewDevice(devType));

			doLoad(vDev);

			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}

void CxbRwDcLine::doLoad(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine *>(vDevice);

	CxbRwTwo::doLoad(vDev);

	
}

void CxbRwDcLine::doLoad_hData()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevDcLine * vDev;


	vTBL = pHvdc->DeviceTBL(tblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevDcLine *>(vPair.second);

		//
		doLoad_hData(vDev);


	}//for each

}


void CxbRwDcLine::doLoad_hData(CxbDevDcLine * vDev)
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
			

			RwAdo->GetFieldValue("Ys11re", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYs11re(vh, vValue.dblVal);
			};
			

			RwAdo->GetFieldValue("Ys11im", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYs11im(vh, vValue.dblVal);
			};

			RwAdo->GetFieldValue("Ys12re", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYs12re(vh, vValue.dblVal);
			};


			RwAdo->GetFieldValue("Ys12im", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYs12im(vh, vValue.dblVal);
			};


			RwAdo->GetFieldValue("Ym11re", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYm11re(vh, vValue.dblVal);
			};


			RwAdo->GetFieldValue("Ym11im", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYm11im(vh, vValue.dblVal);
			};

			RwAdo->GetFieldValue("Ym12re", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYm12re(vh, vValue.dblVal);
			};


			RwAdo->GetFieldValue("Ym12im", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetYm12im(vh, vValue.dblVal);
			};

			//
			RwAdo->Record_MoveNext();


		}//while

		cout << "   --" << vDev->GetDeviceName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}


void CxbRwDcLine::doSave()
{
	CDeviceTBL * vTBL;
	CxbDevDcLine * vDev;

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

			vDev = dynamic_cast<CxbDevDcLine *>(vTBL->Device(i));
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



void CxbRwDcLine::doSave(CxbDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDcLine * vDev;

	vDev = dynamic_cast<CxbDevDcLine *>(vDevice);

	CxbRwTwo::doSave(vDev);

	
}

void CxbRwDcLine::doSave_hData()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevDcLine * vDev;


	vTBL = pHvdc->DeviceTBL(tblType);
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevDcLine *>(vPair.second);

		//
		doSave_hData(vDev);


	}//for each

}


void CxbRwDcLine::doSave_hData(CxbDevDcLine * vDev)
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

		for (i = 0; i<vDev->hMax(); i++)
		{
			RwAdo->Record_AddNew();
			//
			vValue = _variant_t(i);//整型
			RwAdo->SetFieldValue("hOrder", vValue);


			vValue = _variant_t(vDev->GetYs11re(i));//双精度
			RwAdo->SetFieldValue("Ys11re", vValue);


			vValue = _variant_t(vDev->GetYs11im(i));//双精度
			RwAdo->SetFieldValue("Ys11im", vValue);


			vValue = _variant_t(vDev->GetYs12re(i));//双精度
			RwAdo->SetFieldValue("Ys12re", vValue);


			vValue = _variant_t(vDev->GetYs12im(i));//双精度
			RwAdo->SetFieldValue("Ys12im", vValue);


			vValue = _variant_t(vDev->GetYm11re(i));//双精度
			RwAdo->SetFieldValue("Ym11re", vValue);


			vValue = _variant_t(vDev->GetYm11im(i));//双精度
			RwAdo->SetFieldValue("Ym11im", vValue);


			vValue = _variant_t(vDev->GetYm12re(i));//双精度
			RwAdo->SetFieldValue("Ym12re", vValue);


			vValue = _variant_t(vDev->GetYm12im(i));//双精度
			RwAdo->SetFieldValue("Ym12im", vValue);


			//
			RwAdo->Record_Update();
			

		}//
		
		cout << "   --" << vDev->GetDeviceName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}