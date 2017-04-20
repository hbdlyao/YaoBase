///////////////////////////////////////////////////////////
//  CmcRwConvertor.cpp
//  Implementation of the Class CmcRwConvertor
//  Created on:      18-4月-2017 20:38:18
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwConvertor.h"


void CmcRwConvertor::doLoad(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(vDevice);

	CmcRwTwo::doLoad(vDevice);

	RwAdo->GetFieldValue("Alpha_gamaN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAlpha_gamaN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("AngleMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMax(vValue.dblVal); //双精度
	};


	RwAdo->GetFieldValue("AngleMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMin(vValue.dblVal);
	};

	RwAdo->GetFieldValue("AngleRef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleRef(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MeasureStation", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
		vDev->SetMeasureStation(vStr);
	};

	RwAdo->GetFieldValue("StationType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationType(vValue.iVal);//整型
	};


	RwAdo->GetFieldValue("StationCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationCtrlType(vValue.iVal);//整型
	};


	RwAdo->GetFieldValue("drN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdrN(vValue.dblVal); //双精度
	};


	RwAdo->GetFieldValue("dxN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdxN(vValue.dblVal); //双精度
	};


	RwAdo->GetFieldValue("PdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPdN(vValue.dblVal); //双精度
	};


	RwAdo->GetFieldValue("UdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUdN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UT", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUT(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Valvor12Count", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetValvor12Count(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("Qmin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQmin(vValue.dblVal); //双精度
	};


	RwAdo->GetFieldValue("IsGround", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetIsGround(vValue.iVal); //双精度
	};

}


void CmcRwConvertor::doSave(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(vDevice);

	CmcRwTwo::doSave(vDevice);


	vValue = _variant_t(vDev->GetAlhpa_gama());
	RwAdo->SetFieldValue("Alhpa_gama", vValue);


	vValue = _variant_t(vDev->GetAlpha_gamaN()); //
	RwAdo->SetFieldValue("Alpha_gamaN", vValue); //

	vValue = _variant_t(vDev->GetAngleMax()); //
	RwAdo->SetFieldValue("AngleMax", vValue); //

	vValue = _variant_t(vDev->GetAngleMin()); //
	RwAdo->SetFieldValue("AngleMin", vValue); //

	vValue = _variant_t(vDev->GetAngleRef()); //
	RwAdo->SetFieldValue("AngleRef", vValue); //

	vValue = _variant_t(vDev->GetMeasureStation().c_str());//文本型
	RwAdo->SetFieldValue("MeasureStation", vValue);

	vValue = _variant_t(vDev->GetStationType()); //
	RwAdo->SetFieldValue("StationType", vValue); //

	vValue = _variant_t(vDev->GetStationCtrlType()); //
	RwAdo->SetFieldValue("StationCtrlType", vValue); //

	vValue = _variant_t(vDev->GetdrN()); //
	RwAdo->SetFieldValue("drN", vValue); //

	vValue = _variant_t(vDev->GetdxN()); //
	RwAdo->SetFieldValue("dxN", vValue); //

	vValue = _variant_t(vDev->GetLengthToSide()); //
	RwAdo->SetFieldValue("LengthToSide", vValue); //

	vValue = _variant_t(vDev->GetPd()); //
	RwAdo->SetFieldValue("Pd", vValue); //

	vValue = _variant_t(vDev->GetPdN()); //
	RwAdo->SetFieldValue("PdN", vValue); //

	vValue = _variant_t(vDev->GetUd()); //
	RwAdo->SetFieldValue("Ud", vValue); //

	vValue = _variant_t(vDev->GetUdN()); //
	RwAdo->SetFieldValue("UdN", vValue); //

	vValue = _variant_t(vDev->GetUT()); //
	RwAdo->SetFieldValue("UT", vValue); //

	vValue = _variant_t(vDev->GetValvor12Count()); //
	RwAdo->SetFieldValue("Valvor12Count", vValue); //

	vValue = _variant_t(vDev->GetQmin()); //
	RwAdo->SetFieldValue("Qmin", vValue); //

	vValue = _variant_t(vDev->GetIsGround()); //
	RwAdo->SetFieldValue("IsGround", vValue); //

	vValue = _variant_t(vDev->GetId()); //
	RwAdo->SetFieldValue("DcId", vValue); //

}