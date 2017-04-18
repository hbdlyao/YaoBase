///////////////////////////////////////////////////////////
//  CxbRwRLCs.cpp
//  Implementation of the Class CxbRwRLCs
//  Created on:      18-4月-2017 17:11:33
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwRLCs.h"
#include "CxbDevRLCs.h"
#include <iostream>


void CxbRwRLCs::doLoad(CxbDevBase * vDevice)
{

	//doLoad_Data_Root(vDevice);
	
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;
	
	
	vTBL = pHvdc->DeviceTBL(xb_Monitor);
	
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevRLCs *>(vPair.second);
	
		//
		//doLoad_Data_Tree(vDev,1);
	
	
	}//for each
	
	//doLoad_Data_Tree();
}


void CxbRwRLCs::doLoad_Data_Root(CxbDevBase * vDevice)
{

	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;
	
	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	
	
	vSQL = "select * from Data";
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load---Data---" << endl;
	
		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_Monitor);
			vDev = dynamic_cast<CxbDevRLCs *>(vTBL->NewDevice(xb_Monitor));
	
			//CxbRwTwo::OnLoad_Data(vDev); 
	
			//to-do
			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();
	
			cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//while
	
	}//if
	
	RwAdo->CloseTBL();
}


void CxbRwRLCs::doLoad_Data_Tree(CxbDevRLCs* vParent, int vIndex)
{
	CxbDevBranch * vDev;
	
	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	int vType;
	
	//
	vSQL = "select * from Data_tree where RootDeviceName= ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vParent->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + "and TreeLevel= "+ to_string(vIndex);
	vSQL = vSQL + " order by RootDeviceName, TreeLevel, ParentDeviceName ";
	
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load---Data_Tree---" << endl;
	
		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vType=vValue.iVal;
			};
	
			vDev = dynamic_cast<CxbDevBranch *>(CxbDeviceTBL::xbNewDevice(vType));
	
			//
			////CxbRwBranch::OnLoad_Data(vDev);
	
			//to-do
			vParent->Add(vDev);
	
			//
			RwAdo->Record_MoveNext();
	
			//cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//while
	
	}//if
	
	RwAdo->CloseTBL();
	
	//
}


void CxbRwRLCs::doSave(CxbDevBase * vDevice)
{

	//doSave_Data_Root(vDevice);
	
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;
	
	
	vTBL = pHvdc->DeviceTBL(xb_Monitor);
	
	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevRLCs *>(vPair.second);
	
		//
		//doSave_Data_Tree(vDev, 1);
	
	
	}//for each
	
	 //doLoad_Data_Tree();
}


void CxbRwRLCs::doSave_Data_Root(CxbDevBase * vDevice)
{

	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;
	
	string vSQL, vStr;
	_variant_t vValue;
	
	bool vOk = S_FALSE;
	int i;
	
	vSQL = "delete * from Data ";
	vOk = RwAdo->ExecSQL(vSQL);
	
	
	vSQL = "select * from Data ";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));
	
	if (vOk)
	{
		cout << "Save---Data---" << endl;
	
		vTBL = pHvdc->DeviceTBL(xb_Monitor);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{
	
			vDev = dynamic_cast<CxbDevRLCs *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();
	
			//doSave_Two(vDev);
	
			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//for
	
	}//if
	
	RwAdo->CloseTBL();
}


void CxbRwRLCs::doSave_Data_Tree(CxbDevRLCs* vParent, int vIndex)
{

	CxbDevBranch * vDev;
	
	string vSQL, vStr;
	_variant_t vValue;
	
	bool vOk = S_FALSE;
	int i;
	
	vSQL = "delete * from Data_tree where RootDeviceName= ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vParent->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + "and TreeLevel= " + to_string(vIndex);
	
	
	vOk = RwAdo->ExecSQL(vSQL);
	
	
	vSQL = "select * from Data_tree ";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));
	
	if (vOk)
	{
		cout << "Save---Data_tree---" << endl;
		
		for (i = 0; i<vParent->ChildCount(); i++)
		{
	
			vDev = dynamic_cast<CxbDevBranch *>(vParent->Child(i));
			//
			RwAdo->Record_AddNew();
	
			//
			//doSave_Branch(vDev);
	
			//
			vValue = _variant_t(vParent->GetDeviceName().c_str());//文本型
			RwAdo->SetFieldValue("RootDeviceName", vValue);
	
			vValue = _variant_t(vParent->GetDeviceName().c_str());//文本型
			RwAdo->SetFieldValue("ParentDeviceName", vValue);
	
			vValue = _variant_t(vIndex);//整型
			RwAdo->SetFieldValue("TreeLevel", vValue);
	
			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//for
	
	}//if
	
	RwAdo->CloseTBL();
	
	//
}