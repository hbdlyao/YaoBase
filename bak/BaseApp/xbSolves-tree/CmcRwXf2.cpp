///////////////////////////////////////////////////////////
//  CmcRwXf2.cpp
//  Implementation of the Class CmcRwXf2
//  Created on:      18-4��-2017 20:38:23
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
		vDev->SetAngleMax(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("AngleMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMin(vValue.dblVal);
	};

	RwAdo->GetFieldValue("TapCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapCtrlType(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("FixedURef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetFixedURef(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("FixedUType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetFixedUType(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("SN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetSN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Tap", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTap(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("TapMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMax(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("TapMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMin(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("TapN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapN(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("Tk", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTk(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("TkN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTkN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Uac", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUac(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Uv", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUv(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UvMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvMax(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Ukp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUkp(vValue.dblVal); //˫����
	};

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.Urp
	//            2.
	// �Ķ�ʱ��:  2017/04/17
	//************************************
	RwAdo->GetFieldValue("Urp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUrp(vValue.dblVal); //˫����
	};



	RwAdo->GetFieldValue("TapSetup", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapSetup(vValue.dblVal); //˫����
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