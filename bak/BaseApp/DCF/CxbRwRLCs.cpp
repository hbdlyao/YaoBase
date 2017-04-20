///////////////////////////////////////////////////////////
//  CxbRwRLCs.cpp
//  Implementation of the Class CxbRwRLCs
//  Created on:      18-4ÔÂ-2017 17:11:33
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwRLCs.h"
#include "CxbDevRLCs.h"
#include <iostream>


void CxbRwRLCs::doLoad(CxbDevBase * vDevice)
{

}


void CxbRwRLCs::doSave(CxbDevBase * vDevice)
{

}

void CxbRwRLCs::OnLoad()
{
	doLoad_Root();

	doLoad_Tree();
}


void CxbRwRLCs::OnSave()
{
	doSave_Root();

	doSave_Tree();
}


void CxbRwRLCs::doLoad_Root()
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

			doLoad_Root(vDev);

			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRwRLCs::doLoad_Root(CxbDevBase * vRoot)
{
	string vStr;
	_variant_t vValue;
	CxbDevRLCs * vDev;

	vDev = dynamic_cast<CxbDevRLCs *>(vRoot);

	CxbRwTwo::doLoad(vDev);

}


void CxbRwRLCs::doLoad_Tree()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;


	vTBL = pHvdc->DeviceTBL(tblType);

	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevRLCs *>(vPair.second);

		//
		doLoad_Node(vDev, 1);


	}//for each

}


void CxbRwRLCs::doLoad_Node(CxbDevRLCs* vNode, int vIndex)
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
			doLoad_Leaf(vDev,vIndex);
	
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


void CxbRwRLCs::doLoad_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	CxbRwBranch::doLoad(vLeaf);
}



void CxbRwRLCs::doSave_Root()
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

			doSave_Root(vDev);

			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;

		}//for

	}//if

	RwAdo->CloseTBL();

}


void CxbRwRLCs::doSave_Root(CxbDevBase * vRoot)
{
	string vStr;
	_variant_t vValue;
	CxbDevRLCs * vDev;

	vDev = dynamic_cast<CxbDevRLCs *>(vRoot);

	CxbRwTwo::doSave(vDev);

	//

}



void CxbRwRLCs::doSave_Tree()
{
	///////////////////////////////////////////
	CDeviceTBL * vTBL;
	CxbDevRLCs * vDev;


	vTBL = pHvdc->DeviceTBL(tblType);

	for each (pObj_Pair  vPair in  vTBL->GetItems())
	{
		vDev = dynamic_cast<CxbDevRLCs *>(vPair.second);

		//
		doSave_Node(vDev, 1);


	}//for each

}


void CxbRwRLCs::doSave_Node(CxbDevRLCs* vNode, int vIndex)
{
	string vSQL, vStr, vtbl1, vtbl2;
	_variant_t vValue;

	bool vOk = S_FALSE;

	vtbl1 = tblName;
	vtbl2 = tblName + "_tree ";

	//delete *  from xbTrap_tree 
	//where ParentDeviceName = "Trap1"
	
	//
	vSQL = "delete *  from  " + vtbl2 ;
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

			
			doSave_Leaf(vDev,vIndex);

			//
			RwAdo->Record_Update();
			//
			cout << "   --" << vDev->GetDeviceName() << endl;

		}//for

	}//if


	RwAdo->CloseTBL();

	//
}


void CxbRwRLCs::doSave_Leaf(CxbDevBase * vLeaf, int vIndex)
{
	CxbRwBranch::doSave(vLeaf);
}

