///////////////////////////////////////////////////////////
//  CxbRw_Tree1.cpp
//  Implementation of the Class CxbRw_Tree1
//  Created on:      22-4ÔÂ-2017 7:07:32
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRw_Tree1.h"




void CxbRw_Tree1::OnLoad()
{

	doLoad_Root();
	
	doLoad_Tree();
}


void CxbRw_Tree1::doLoad(CxbDevBase* vDevice)
{

}

void CxbRw_Tree1::doSave(CxbDevBase* vDevice)
{

}


void CxbRw_Tree1::doLoad_Root()
{

	CDeviceTBL * vTBL;
	CxbDevBase * vDev;
	
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
			vDev = dynamic_cast<CxbDevBase *>(vTBL->NewDevice(devType));
	
			doLoad_RootData(vDev);
	
			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();
	
			cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//while
	
	}//if
	
	RwAdo->CloseTBL();
}


void CxbRw_Tree1::doLoad_RootData(CxbDevBase* vRoot)
{

	string vStr;
	_variant_t vValue;
	CxbDev_Tree * vDev;

	vDev = dynamic_cast<CxbDev_Tree *>(vRoot);

	CxbRw::doLoad(vDev);
}



void CxbRw_Tree1::doLoad_Tree()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;	
	//
	vTBL = pHvdc->DeviceTBL(tblType);	
	for each (CxbDevBase * vDev in vTBL->ItemVect())
	{	
		if (vDev->IsLeaf())
			doLoad_Leaf(vDev);
		else
		{
			doLoad_Node(vDev);
		}
	
	}//for each
}



void CxbRw_Tree1::doLoad_Node(CxbDev_Tree* vNode, int vIndex)
{

	CxbDevBase * vDev;
	
	string  vSQL, vStr,vtbl1,vtbl2;
	_variant_t vValue;
	bool vOk;
	int vType;
	
	vtbl1 = tblName;
	vtbl2 = tblName + "_tree ";
	
	//select a.stationname1, a.stationname2, b.* from xbTrap as a, xbTrap_tree as b  
	//where b.ParentDeviceName = a.Devicename 
	//and b.ParentDeviceName = "Trap1"
	//order by b.ParentDeviceName , b.DeviceName
	//
	vSQL = "select a.StationName1 , a.StationName2 , a.PosOrNeg , b.* from " ;
	vSQL = vSQL + vtbl1 +" as a , " + vtbl2 + " as b ";
	vSQL = vSQL + " where b.ParentDeviceName = a.devicename  ";
	vSQL = vSQL + " and b.ParentDeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vNode->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by b.ParentDeviceName , b.DeviceName ";
	
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load---" + vtbl2 +"----" << vNode->GetDeviceName() <<endl;
	
		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vType=vValue.iVal;
			};
	
			vDev = dynamic_cast<CxbDevBase *>(CxbDeviceTBL::xbNewDevice(vType));
	
			//
			doLoad_LeafData(vDev,vIndex);
	
			//to-do
			vNode->Add(vDev);
	
			//
			RwAdo->Record_MoveNext();
	
			cout << "   --" << vDev->GetDeviceName() << endl;
	
		}//while
	
	}//if
	
	RwAdo->CloseTBL();
	
	//
}


void CxbRw_Tree1::doLoad_NodeData(CxbDevBase* vNode, int vIndex)
{

	CxbRw::doLoad(vLeaf);
}




void CxbRw_Tree1::OnSave() 
{

	doSave_Root();

	doSave_Tree();
}

void CxbRw_Tree1::doSave_Root()
{

	CDeviceTBL * vTBL;

	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;

	vSQL = "delete * from " + tblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + tblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" << tblName << "---" << endl;

		vTBL = pHvdc->DeviceTBL(tblType);
		for each (CxbDevBase * vDev in vTBL->ItemVect())
		{
			//
			RwAdo->Record_AddNew();

			doSave_RootData(vDev);

			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;

		}//for

	}//if

	RwAdo->CloseTBL();
}


void CxbRw_Tree1::doSave_RootData(CxbDevBase* vRoot)
{

	string vStr;
	_variant_t vValue;
	CxbDev_Tree * vDev;

	vDev = dynamic_cast<CxbDev_Tree *>(vRoot);

	CxbRw::doSave(vDev);

	//
}


void CxbRw_Tree1::doSave_Tree()
{

	CDeviceTBL * vTBL;

	vTBL = pHvdc->DeviceTBL(tblType);
	for each (CxbDev_Tree * vDev in vTBL->ItemVect())
	{

		doSave_Node(vDev, 1);


	}//for each
}


void CxbRw_Tree1::doSave_Leaf(CxbDev_Tree* vNode, int vIndex)
{

	string vSQL, vStr, vtbl1, vtbl2;
	_variant_t vValue;

	bool vOk = S_FALSE;

	vtbl1 = tblName;
	vtbl2 = tblName + "_tree ";

	//delete *  from xbTrap_tree 
	//where ParentDeviceName = "Trap1"

	//
	vSQL = "delete *  from  " + vtbl2;
	vSQL = vSQL + " where ParentDeviceName = ";
	vSQL = vSQL + " "" ";
	vSQL = vSQL + vNode->GetDeviceName();
	vSQL = vSQL + " "" ";


	vOk = RwAdo->ExecSQL(vSQL);

	//
	vSQL = "select * from " + vtbl2;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));


	if (vOk)
	{
		cout << "Save---" << vtbl2 << "---" << endl;

		for each (CxbDevBase *  vDev in  vNode->Children())
		{
			//
			RwAdo->Record_AddNew();


			doSave_LeafData(vDev, vIndex);

			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;

		}//for

	}//if


	RwAdo->CloseTBL();

	//
}


void CxbRw_Tree1::doSave_LeafData(CxbDevBase* vLeaf, int vIndex)
{

	CxbRw::doSave(vLeaf);
}