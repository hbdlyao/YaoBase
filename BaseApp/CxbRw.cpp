///////////////////////////////////////////////////////////
//  CxbRw.cpp
//  Implementation of the Class CxbRw
//  Created on:      06-4月-2017 17:56:23
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbRw.h"
#include "CHvdcParams.h"
#include "CHvdcVars.h"



void CxbRw::InitGrid(CxbHvdcGrid * vHvdc)
{
	pHvdc = vHvdc;
}

void CxbRw::InitAdo(string vDbf)
{

	dbfName = vDbf;
	
	//RwAdo = new CRwAdo_MDB();
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CxbRw::OnLoad_Order() {

	try
	{
		if (doOpenDBF())
		{
			doLoad_Order();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CxbRw::OnSave_Order() {

	try
	{
		if (doOpenDBF())
		{
			doSave_Order();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CxbRw::OnLoad_Result() {

	try
	{
		if (doOpenDBF())
		{
			doLoad_Result();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CxbRw::OnSave_Result() {

	try
	{
		if (doOpenDBF())
		{
			doSave_Order();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CxbRw::doLoad_Order()
{

}


void CxbRw::doSave_Order() 
{

}


void CxbRw::doLoad_Result()
{

}


void CxbRw::doSave_Result()
{

}


void CxbRw::doLoad()
{
	
	doLoad_xb3pVSrc();

	doLoad_xbPbDKQ();
	doLoad_xbDcF();

	doLoad_xbDcLine();
	doLoad_xbGroundLine();
	doLoad_xbMetalLine();

	doLoad_xbGround();
	
	doLoad_xbXfC();
	doLoad_xbCoupleC();
	doLoad_xbPulseC();
	
	doLoad_xbShunt();
	doLoad_xbBranch();

}


void CxbRw::doSave()
{
	doSave_xb3pVSrc();

	doSave_xbPbDKQ();
	doSave_xbDcF();

	doSave_xbDcLine();
	doSave_xbGroundLine();
	doSave_xbMetalLine();

	doSave_xbGround();

	doSave_xbXfC();
	doSave_xbCoupleC();
	doSave_xbPulseC();

	doSave_xbShunt();
	doSave_xbBranch();

}


void CxbRw::doLoad_xb3pVSrc()
{
	CDeviceTBL * vTBL;
	CxbDev3pVSrc * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xb3PVSrc";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb3PVSrc---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_3pVSrc);
			vDev = dynamic_cast<CxbDev3pVSrc *>(vTBL->NewDevice(xb_3pVSrc));

			//doLoad_Branch(vDev);
			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbPbDKQ()
{
	CDeviceTBL * vTBL;
	CxbDevPbDkq * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbPbDKQ";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_PbDKQ---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_PbDKQ);
			vDev = dynamic_cast<CxbDevPbDkq *>(vTBL->NewDevice(xb_PbDKQ));

			doLoad_Branch(vDev);
			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbDcF()
{
	CDeviceTBL * vTBL;
	CxbDevDCF * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbDcFilter";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_DCF---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_DcF);
			vDev = dynamic_cast<CxbDevDCF *>(vTBL->NewDevice(xb_DcF));

			//
			doLoad_Two(vDev);

			//doLoad_Branch(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbDcLine()
{
	CDeviceTBL * vTBL;
	CxbDevDcLine * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbDcLine";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_DcLine---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_DcLine);
			vDev = dynamic_cast<CxbDevDcLine *>(vTBL->NewDevice(xb_DcLine));

			doLoad_DcLine(vDev);
			//
			RwAdo->GetFieldValue("StationName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName1(vStr);
			};

			RwAdo->GetFieldValue("StationName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName2(vStr);
			};


			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbMetalLine()
{
	CDeviceTBL * vTBL;
	CxbDevMetalLine * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbMetalLine";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_MetalLine---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_MetalLine);
			vDev = dynamic_cast<CxbDevMetalLine *>(vTBL->NewDevice(xb_MetalLine));

			doLoad_DcLine(vDev);
			//
			RwAdo->GetFieldValue("StationName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName1(vStr);
			};

			RwAdo->GetFieldValue("StationName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName2(vStr);
			};


			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbGroundLine()
{
	CDeviceTBL * vTBL;
	CxbDevGroundLine * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbGroundLine";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_GroundLine---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_GroundLine);
			vDev = dynamic_cast<CxbDevGroundLine *>(vTBL->NewDevice(xb_GroundLine));

			
			doLoad_DcLine(vDev);

			//
			RwAdo->GetFieldValue("StationName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName(vStr);
			};
			

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}

void CxbRw::doLoad_xbGround()
{
	CDeviceTBL * vTBL;
	CxbDevGround * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbGround";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_Ground---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_Ground);
			vDev = dynamic_cast<CxbDevGround *>(vTBL->NewDevice(xb_Ground));

			doLoad_Shunt(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}

void CxbRw::doLoad_xbXfC()
{
	CDeviceTBL * vTBL;
	CxbDevXf_C * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbXf_C";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_XfC---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_XfC);
			vDev = dynamic_cast<CxbDevXf_C *>(vTBL->NewDevice(xb_XfC));

			doLoad_Shunt(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbCoupleC()
{
	CDeviceTBL * vTBL;
	CxbDevCouple_C * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbCouple_C";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_CoupleC---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_CoupleC);
			vDev = dynamic_cast<CxbDevCouple_C *>(vTBL->NewDevice(xb_CoupleC));

			doLoad_Shunt(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}

void CxbRw::doLoad_xbPulseC()
{
	CDeviceTBL * vTBL;
	CxbDevPulse_C * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbPulse_C";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_PulseC---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_PulseC);
			vDev = dynamic_cast<CxbDevPulse_C *>(vTBL->NewDevice(xb_PulseC));

			doLoad_Shunt(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbShunt()
{
	CDeviceTBL * vTBL;
	CxbDevShunt * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbShunt";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_Shunt---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_Shunt);
			vDev = dynamic_cast<CxbDevShunt *>(vTBL->NewDevice(xb_Shunt));

			doLoad_Shunt(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}


void CxbRw::doLoad_xbBranch()
{
	CDeviceTBL * vTBL;
	CxbDevBranch * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	vSQL = "select * from xbBranch";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---xb_Branch---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pHvdc->DeviceTBL(xb_Branch);
			vDev = dynamic_cast<CxbDevBranch *>(vTBL->NewDevice(xb_Branch));

			doLoad_Branch(vDev);

			//
			vTBL->DeviceAdd(vDev->GetDeviceID(), vDev);
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}



void CxbRw::doSave_xb3pVSrc()
{

}


void CxbRw::doSave_xbPbDKQ(){

}


void CxbRw::doSave_xbDcF(){

}


void CxbRw::doSave_xbDcLine(){

}


void CxbRw::doSave_xbGroundLine(){

}


void CxbRw::doSave_xbMetalLine(){

}


void CxbRw::doSave_xbGround(){

}


void CxbRw::doSave_xbXfC(){

}


void CxbRw::doSave_xbCoupleC(){

}


void CxbRw::doSave_xbPulseC(){

}


void CxbRw::doSave_xbShunt(){

}


void CxbRw::doSave_xbBranch()
{

}


void CxbRw::doLoad_One(CxbDevOneDot * vDev)
{

	string vStr;
	_variant_t vValue;
	
	
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
	
	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetStationName(vStr);
	};
	
	
	RwAdo->GetFieldValue("NodeName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(0, vStr);
	};
	
	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};

	/*
	RwAdo->GetFieldValue("NodeID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(0, vValue.iVal);//整型
	};
	*/
	
}


void CxbRw::doLoad_Shunt(CxbDevShunt * vDev)
{

	string vStr;
	_variant_t vValue;

	doLoad_One(vDev);

	RwAdo->GetFieldValue("Zr", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZr(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_C(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_C(vValue.dblVal); //双精度
	};

}


void CxbRw::doLoad_Two(CxbDevTwoDot * vDev)
{
	string vStr;
	_variant_t vValue;


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

	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetStationName(vStr);
	};

	RwAdo->GetFieldValue("NodeName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(0, vStr);
	};

	RwAdo->GetFieldValue("NodeName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(1, vStr);
	};

	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};


	/*
	RwAdo->GetFieldValue("NodeID1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(0, vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("NodeID2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetNodeID(1, vValue.iVal);//整型
	};
	*/


}


void CxbRw::doLoad_Branch(CxbDevBranch * vDev)
{

	string vStr;
	_variant_t vValue;
	

	doLoad_Two(vDev);
	
	RwAdo->GetFieldValue("Zr", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZr(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_C(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_C(vValue.dblVal); //双精度
	};

}


void CxbRw::doLoad_DcLine(CxbDevDcLine * vDev)
{

	string vStr;
	_variant_t vValue;


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


	RwAdo->GetFieldValue("NodeName1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(0, vStr);
	};

	RwAdo->GetFieldValue("NodeName2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetNodeName(1, vStr);
	};

	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//整型
	};


	/*
	RwAdo->GetFieldValue("NodeID1", vValue);
	if (vValue.vt != VT_NULL)
	{
	vDev->SetNodeID(0, vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("NodeID2", vValue);
	if (vValue.vt != VT_NULL)
	{
	vDev->SetNodeID(1, vValue.iVal);//整型
	};
	*/

	
}
