///////////////////////////////////////////////////////////
//  CmcRwXf2.cpp
//  Implementation of the Class CmcRwXf2
//  Created on:      18-4月-2017 20:38:23
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwXf2.h"



void CmcRwXf2::doLoad(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(vDevice);

	CmcRwTwo::doLoad(vDevice);


	//
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

	RwAdo->GetFieldValue("TapCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapCtrlType(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("FixedURef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetFixedURef(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("FixedUType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetFixedUType(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("SN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetSN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Tap", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTap(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMax(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMin(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapN(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("Tk", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTk(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("TkN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTkN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Uac", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUac(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Uv", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUv(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UvMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Ukp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUkp(vValue.dblVal); //双精度
	};

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.Urp
	//            2.
	// 改动时间:  2017/04/17
	//************************************
	RwAdo->GetFieldValue("Urp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUrp(vValue.dblVal); //双精度
	};



	RwAdo->GetFieldValue("TapSetup", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapSetup(vValue.dblVal); //双精度
	};

}

void CmcRwXf2::doSave(CmcDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(vDevice);

	CmcRwTwo::doSave(vDevice);



	vValue = _variant_t(vDev->GetAngleMax()); //
	RwAdo->SetFieldValue("AngleMax", vValue); //

	vValue = _variant_t(vDev->GetAngleMin()); //
	RwAdo->SetFieldValue("AngleMin", vValue); //

	vValue = _variant_t(vDev->GetTapCtrlType()); //
	RwAdo->SetFieldValue("TapCtrlType", vValue); //

	vValue = _variant_t(vDev->GetFixedURef()); //
	RwAdo->SetFieldValue("FixedURef", vValue); //

	vValue = _variant_t(vDev->GetFixedUType()); //
	RwAdo->SetFieldValue("FixedUType", vValue); //


	vValue = _variant_t(vDev->GetSN()); //
	RwAdo->SetFieldValue("SN", vValue); //

	vValue = _variant_t(vDev->GetTap()); //
	RwAdo->SetFieldValue("Tap", vValue); //

	vValue = _variant_t(vDev->GetTapMax()); //
	RwAdo->SetFieldValue("TapMax", vValue); //

	vValue = _variant_t(vDev->GetTapMin()); //
	RwAdo->SetFieldValue("TapMin", vValue); //

	vValue = _variant_t(vDev->GetTapN()); //
	RwAdo->SetFieldValue("TapN", vValue); //

	vValue = _variant_t(vDev->GetTk()); //
	RwAdo->SetFieldValue("Tk", vValue); //

	vValue = _variant_t(vDev->GetTkN()); //
	RwAdo->SetFieldValue("TkN", vValue); //

	vValue = _variant_t(vDev->GetUac()); //
	RwAdo->SetFieldValue("Uac", vValue); //

	vValue = _variant_t(vDev->GetUacN()); //
	RwAdo->SetFieldValue("UacN", vValue); //

	vValue = _variant_t(vDev->GetUv()); //
	RwAdo->SetFieldValue("Uv", vValue); //

	vValue = _variant_t(vDev->GetUvMax()); //
	RwAdo->SetFieldValue("UvMax", vValue); //

	vValue = _variant_t(vDev->GetUvN()); //
	RwAdo->SetFieldValue("UvN", vValue); //

	vValue = _variant_t(vDev->GetUkp()); //
	RwAdo->SetFieldValue("Ukp", vValue); //

	vValue = _variant_t(vDev->GetUrp()); //
	RwAdo->SetFieldValue("Urp", vValue); //

	vValue = _variant_t(vDev->GetTapSetup()); //
	RwAdo->SetFieldValue("TapSetup", vValue); //

}