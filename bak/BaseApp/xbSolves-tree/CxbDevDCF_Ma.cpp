///////////////////////////////////////////////////////////
//  CxbDevDCF.cpp
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDCF.h"

//马骏鹏
//初始化
void CxbDevDCF::InitDev(int vDCFType, int vTimes)
{
	DCFType = vDCFType;
	RandTimes = vTimes;
	switch (DCFType)
	{
	case DCF_Single:
		if (OneTuned.ConstDev != nullptr)
			delete OneTuned.ConstDev;
		if (OneTuned.RandDev != nullptr)
			delete OneTuned.RandDev;
		if (OneTuned.ConstDevYg != nullptr)
			delete OneTuned.ConstDevYg;
		if (OneTuned.ConstDevYg != nullptr)
			delete OneTuned.RandDevYb;
		if (OneTuned.RandDevYg != nullptr)
			delete OneTuned.ConstDevYg;
		if (OneTuned.RandDevYg != nullptr)
			delete OneTuned.RandDevYb;
		OneTuned.ConstDev = new CxbDCFOneTunedDev[3];
		OneTuned.RandDev = new CxbDCFOneTunedDev[vTimes];
		OneTuned.ConstDevYg = new double[H_CAL_NUM * 3];
		OneTuned.ConstDevYb = new double[H_CAL_NUM * 3];
		OneTuned.RandDevYg = new double[H_CAL_NUM * vTimes];
		OneTuned.RandDevYb = new double[H_CAL_NUM * vTimes];
		SetOneConstDev();
		SetOneRandDev(vTimes);
		return;
	case DCF_Double:
		if (TwoTuned.ConstDev != nullptr)
			delete TwoTuned.ConstDev;
		if (TwoTuned.RandDev != nullptr)
			delete TwoTuned.RandDev;
		if (TwoTuned.ConstDevYg != nullptr)
			delete TwoTuned.ConstDevYg;
		if (TwoTuned.ConstDevYg != nullptr)
			delete TwoTuned.ConstDevYb;
		if (TwoTuned.RandDevYg != nullptr)
			delete TwoTuned.ConstDevYg;
		if (TwoTuned.RandDevYg != nullptr)
			delete TwoTuned.RandDevYb;
		TwoTuned.ConstDev = new CxbDCFTwoTunedDev[3];
		TwoTuned.RandDev = new CxbDCFTwoTunedDev[vTimes];
		TwoTuned.ConstDevYg = new double[H_CAL_NUM * 3];
		TwoTuned.ConstDevYb = new double[H_CAL_NUM * 3];
		TwoTuned.RandDevYg = new double[H_CAL_NUM * vTimes];
		TwoTuned.RandDevYb = new double[H_CAL_NUM * vTimes];
		SetTwoConstDev();
		SetTwoRandDev(vTimes);
		return;
	case DCF_Triple:
		if (ThreeTuned.ConstDev != nullptr)
			delete ThreeTuned.ConstDev;
		if (ThreeTuned.RandDev != nullptr)
			delete ThreeTuned.RandDev;
		if (ThreeTuned.ConstDevYg != nullptr)
			delete ThreeTuned.ConstDevYg;
		if (ThreeTuned.ConstDevYg != nullptr)
			delete ThreeTuned.ConstDevYb;
		if (ThreeTuned.RandDevYg != nullptr)
			delete ThreeTuned.ConstDevYg;
		if (ThreeTuned.RandDevYg != nullptr)
			delete ThreeTuned.RandDevYb;
		ThreeTuned.ConstDev = new CxbDCFThreeTunedDev[3];
		ThreeTuned.RandDev = new CxbDCFThreeTunedDev[vTimes];
		ThreeTuned.ConstDevYg = new double[H_CAL_NUM * 3];
		ThreeTuned.ConstDevYb = new double[H_CAL_NUM * 3];
		ThreeTuned.RandDevYg = new double[H_CAL_NUM * vTimes];
		ThreeTuned.RandDevYb = new double[H_CAL_NUM * vTimes];
		SetThreeConstDev();
		SetThreeRandDev(vTimes);
		return;
	}


	return;

}
//设置偏差参数

void CxbDevDCF::SetOneConstDev()
{
	OneTuned.ConstDev[0].ddC1 = 0;
	OneTuned.ConstDev[0].ddL1 = 0;
	OneTuned.ConstDev[0].ddR1 = 0;
	OneTuned.ConstDev[0].ddf = 0;

	OneTuned.ConstDev[1].ddC1 = OneTuned.PdC1 * OneTuned.C1;
	OneTuned.ConstDev[1].ddL1 = OneTuned.PdL1 * OneTuned.L1;
	OneTuned.ConstDev[1].ddR1 = OneTuned.PdR1 * OneTuned.R1;
	OneTuned.ConstDev[1].ddf = OneTuned.Pdf;

	OneTuned.ConstDev[2].ddC1 = OneTuned.NdC1 * OneTuned.C1;
	OneTuned.ConstDev[2].ddL1 = OneTuned.NdL1 * OneTuned.L1;
	OneTuned.ConstDev[2].ddR1 = OneTuned.NdR1 * OneTuned.R1;
	OneTuned.ConstDev[2].ddf = OneTuned.Ndf;

}
void CxbDevDCF::SetOneRandDev(int vTimes)
{
	CRand randC1(OneTuned.NdC1, OneTuned.PdC1, Real_Dis);
	CRand randL1(OneTuned.NdL1, OneTuned.PdL1, Real_Dis);
	CRand randR1(OneTuned.NdR1, OneTuned.PdR1, Real_Dis);
	CRand randf(OneTuned.Ndf, OneTuned.Pdf, Real_Dis);
	for (int i = 0; i < vTimes; i++)
	{
		OneTuned.RandDev[i].ddC1 = randC1.getVal() * OneTuned.C1;
		OneTuned.RandDev[i].ddL1 = randL1.getVal() * OneTuned.L1;
		OneTuned.RandDev[i].ddR1 = randR1.getVal() * OneTuned.R1;
		OneTuned.RandDev[i].ddf = randf.getVal();
	}
}

void CxbDevDCF::SetTwoConstDev()
{
	TwoTuned.ConstDev[0].ddC1 = 0;
	TwoTuned.ConstDev[0].ddL1 = 0;
	TwoTuned.ConstDev[0].ddC2 = 0;
	TwoTuned.ConstDev[0].ddL2 = 0;
	TwoTuned.ConstDev[0].ddR1 = 0;
	TwoTuned.ConstDev[0].ddf = 0;

	TwoTuned.ConstDev[1].ddC1 = TwoTuned.PdC1 * TwoTuned.C1;
	TwoTuned.ConstDev[1].ddL1 = TwoTuned.PdL1 * TwoTuned.L1;
	TwoTuned.ConstDev[1].ddC2 = TwoTuned.PdC2 * TwoTuned.C2;
	TwoTuned.ConstDev[1].ddL2 = TwoTuned.PdL2 * TwoTuned.L2;
	TwoTuned.ConstDev[1].ddR1 = TwoTuned.PdR1 * TwoTuned.R1;
	TwoTuned.ConstDev[1].ddf = TwoTuned.Pdf;

	TwoTuned.ConstDev[2].ddC1 = TwoTuned.NdC1 * TwoTuned.C1;
	TwoTuned.ConstDev[2].ddL1 = TwoTuned.NdL1 * TwoTuned.L1;
	TwoTuned.ConstDev[2].ddC2 = TwoTuned.NdC2 * TwoTuned.C2;
	TwoTuned.ConstDev[2].ddL2 = TwoTuned.NdL2 * TwoTuned.L2;
	TwoTuned.ConstDev[2].ddR1 = TwoTuned.NdR1 * TwoTuned.R1;
	TwoTuned.ConstDev[2].ddf = TwoTuned.Ndf;
}
void CxbDevDCF::SetTwoRandDev(int vTimes)
{
	CRand randC1(TwoTuned.NdC1, TwoTuned.PdC1, Real_Dis);
	CRand randC2(TwoTuned.NdC2, TwoTuned.PdC2, Real_Dis);
	CRand randL1(TwoTuned.NdL1, TwoTuned.PdL1, Real_Dis);
	CRand randL2(TwoTuned.NdL2, TwoTuned.PdL2, Real_Dis);
	CRand randR1(TwoTuned.NdR1, TwoTuned.PdR1, Real_Dis);
	CRand randf(TwoTuned.Ndf, TwoTuned.Pdf, Real_Dis);
	for (int i = 0; i < vTimes; i++)
	{
		TwoTuned.RandDev[i].ddC1 = randC1.getVal() * TwoTuned.C1;
		TwoTuned.RandDev[i].ddC2 = randC2.getVal() * TwoTuned.C2;
		TwoTuned.RandDev[i].ddL1 = randL1.getVal() * TwoTuned.L1;
		TwoTuned.RandDev[i].ddL2 = randL2.getVal() * TwoTuned.L2;
		TwoTuned.RandDev[i].ddR1 = randR1.getVal() * TwoTuned.R1;
		TwoTuned.RandDev[i].ddf = randf.getVal();
	}
}


void CxbDevDCF::SetThreeConstDev()
{
	ThreeTuned.ConstDev[0].ddC1 = 0;
	ThreeTuned.ConstDev[0].ddL1 = 0;
	ThreeTuned.ConstDev[0].ddC2 = 0;
	ThreeTuned.ConstDev[0].ddL2 = 0;
	ThreeTuned.ConstDev[0].ddR1 = 0;
	ThreeTuned.ConstDev[0].ddC3 = 0;
	ThreeTuned.ConstDev[0].ddL3 = 0;
	ThreeTuned.ConstDev[0].ddR2 = 0;
	ThreeTuned.ConstDev[0].ddf = 0;

	ThreeTuned.ConstDev[1].ddC1 = ThreeTuned.PdC1 * ThreeTuned.C1;
	ThreeTuned.ConstDev[1].ddL1 = ThreeTuned.PdL1 * ThreeTuned.L1;
	ThreeTuned.ConstDev[1].ddC2 = ThreeTuned.PdC2 * ThreeTuned.C2;
	ThreeTuned.ConstDev[1].ddL2 = ThreeTuned.PdL2 * ThreeTuned.L2;
	ThreeTuned.ConstDev[1].ddR1 = ThreeTuned.PdR1 * ThreeTuned.R1;
	ThreeTuned.ConstDev[1].ddC3 = ThreeTuned.PdC3 * ThreeTuned.C3;
	ThreeTuned.ConstDev[1].ddL3 = ThreeTuned.PdL3 * ThreeTuned.L3;
	ThreeTuned.ConstDev[1].ddR2 = ThreeTuned.PdR2 * ThreeTuned.R2;
	ThreeTuned.ConstDev[1].ddf = ThreeTuned.Pdf;

	ThreeTuned.ConstDev[2].ddC1 = ThreeTuned.NdC1 * ThreeTuned.C1;
	ThreeTuned.ConstDev[2].ddL1 = ThreeTuned.NdL1 * ThreeTuned.L1;
	ThreeTuned.ConstDev[2].ddC2 = ThreeTuned.NdC2 * ThreeTuned.C2;
	ThreeTuned.ConstDev[2].ddL2 = ThreeTuned.NdL2 * ThreeTuned.L2;
	ThreeTuned.ConstDev[2].ddR1 = ThreeTuned.NdR1 * ThreeTuned.R1;
	ThreeTuned.ConstDev[2].ddC3 = ThreeTuned.NdC3 * ThreeTuned.C3;
	ThreeTuned.ConstDev[2].ddL3 = ThreeTuned.NdL3 * ThreeTuned.L3;
	ThreeTuned.ConstDev[2].ddR2 = ThreeTuned.NdR2 * ThreeTuned.R2;
	ThreeTuned.ConstDev[2].ddf = ThreeTuned.Ndf;
}
void CxbDevDCF::SetThreeRandDev(int vTimes) {
	CRand randC1(ThreeTuned.NdC1, ThreeTuned.PdC1, Real_Dis);
	CRand randC2(ThreeTuned.NdC2, ThreeTuned.PdC2, Real_Dis);
	CRand randC3(ThreeTuned.NdC3, ThreeTuned.PdC3, Real_Dis);
	CRand randL1(ThreeTuned.NdL1, ThreeTuned.PdL1, Real_Dis);
	CRand randL2(ThreeTuned.NdL2, ThreeTuned.PdL2, Real_Dis);
	CRand randL3(ThreeTuned.NdL3, ThreeTuned.PdL3, Real_Dis);
	CRand randR1(ThreeTuned.NdR1, ThreeTuned.PdR1, Real_Dis);
	CRand randR2(ThreeTuned.NdR2, ThreeTuned.PdR2, Real_Dis);
	CRand randf(ThreeTuned.Ndf, ThreeTuned.Pdf, Real_Dis);
	for (int i = 0; i < vTimes; i++)
	{
		ThreeTuned.RandDev[i].ddC1 = randC1.getVal() * ThreeTuned.C1;
		ThreeTuned.RandDev[i].ddC2 = randC2.getVal() * ThreeTuned.C2;
		ThreeTuned.RandDev[i].ddC3 = randC2.getVal() * ThreeTuned.C3;
		ThreeTuned.RandDev[i].ddL1 = randL1.getVal() * ThreeTuned.L1;
		ThreeTuned.RandDev[i].ddL2 = randL2.getVal() * ThreeTuned.L2;
		ThreeTuned.RandDev[i].ddL3 = randL2.getVal() * ThreeTuned.L3;
		ThreeTuned.RandDev[i].ddR1 = randR1.getVal() * ThreeTuned.R1;
		ThreeTuned.RandDev[i].ddR2 = randR1.getVal() * ThreeTuned.R2;
		ThreeTuned.RandDev[i].ddf = randf.getVal();
	}
}

void CxbDevDCF::InitY(int vDevType)
{
	DevType = vDevType;

	switch (DevType)
	{
	case DCF_NoneDev:
		InitYNoneDev();
	case DCF_ConsDev:
		InitYConsDev();
	case DCF_RandDev:
		InitYRandDev();
	}

}

//形成一次的导纳参数
void CxbDevDCF::InitYNoneDev()
{
	CComplex vZ, vY;
	double vw;
	for (int vhOrder = 1; vhOrder <= H_CAL_NUM; vhOrder++)
	{
		//double vw = PI * 2 * (Frequency + OneTuned.ConstDev->ddf) * vhOrder;
		switch (DCFType)
		{
		case DCF_Single:
			vw = PI * 2 * (Frequency)* vhOrder;
			vY = CComplex((OneTuned.R1 + OneTuned.ConstDev->ddR1), vw *(OneTuned.L1 + OneTuned.ConstDev->ddL1) - 1.0 / vw / (OneTuned.C1 + OneTuned.ConstDev->ddC1)).inverse();
			OneTuned.ConstDevYg[vhOrder - 1] = vY.real();
			OneTuned.ConstDevYb[vhOrder - 1] = vY.image();
			break;
		case DCF_Double:
			vw = PI * 2 * (Frequency)* vhOrder;
			if (TwoTuned.R1 == 0)
			{
				vY = CComplex(0, vw * (TwoTuned.C2 + TwoTuned.ConstDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.ConstDev->ddL2));
				vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.ConstDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.ConstDev->ddC1));
				vY = vZ.inverse();
				TwoTuned.ConstDevYg[vhOrder - 1] = vY.real();
				TwoTuned.ConstDevYb[vhOrder - 1] = vY.image();
			}
			else
			{
				vY = CComplex(1.0 / (TwoTuned.R1 + TwoTuned.ConstDev->ddR1), vw * (TwoTuned.C2 + TwoTuned.ConstDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.ConstDev->ddL2));
				vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.ConstDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.ConstDev->ddC1));
				vY = vZ.inverse();
				TwoTuned.ConstDevYg[vhOrder - 1] = vY.real();
				TwoTuned.ConstDevYb[vhOrder - 1] = vY.image();
			}

			break;

		case DCF_Triple:
			vw = PI * 2 * (Frequency)* vhOrder;
			if (ThreeTuned.R1 == 0)
			{
				vY = CComplex(0, vw * (ThreeTuned.C3 + ThreeTuned.ConstDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL3));
				vZ = vY.inverse();
				vY = CComplex(0, vw * (ThreeTuned.C2 + ThreeTuned.ConstDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL2));
				vZ += vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.ConstDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.ConstDev->ddC1));
				vY = vZ.inverse();
				ThreeTuned.ConstDevYg[vhOrder - 1] = vY.real();
				ThreeTuned.ConstDevYb[vhOrder - 1] = vY.image();
			}
			else
			{
				vY = CComplex(1.0 / (ThreeTuned.R2 + ThreeTuned.ConstDev->ddR2), vw * (ThreeTuned.C3 + ThreeTuned.ConstDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL3));
				vZ = vY.inverse();
				vY = CComplex(1.0 / (ThreeTuned.R1 + ThreeTuned.ConstDev->ddR1), vw * (ThreeTuned.C2 + ThreeTuned.ConstDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL2));
				vZ = vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.ConstDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.ConstDev->ddC1));
				vY = vZ.inverse();
				ThreeTuned.ConstDevYg[vhOrder - 1] = vY.real();
				ThreeTuned.ConstDevYb[vhOrder - 1] = vY.image();
			}

			break;
		default:return;
		}

	}

}
void CxbDevDCF::InitYConsDev()
{
	CComplex vZ, vY;
	double vw;
	for (int vCount = 0; vCount < 3; vCount++)
		for (int vhOrder = 1; vhOrder <= H_CAL_NUM; vhOrder++)
		{
			//double vw = PI * 2 * (Frequency + OneTuned.ConstDev->ddf) * vhOrder;
			switch (DCFType)
			{
			case DCF_Single:
				vw = PI * 2 * (Frequency)* vhOrder;
				vY = CComplex((OneTuned.R1 + OneTuned.ConstDev->ddR1), vw *(OneTuned.L1 + OneTuned.ConstDev->ddL1) - 1.0 / vw / (OneTuned.C1 + OneTuned.ConstDev->ddC1)).inverse();
				OneTuned.ConstDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
				OneTuned.ConstDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				break;
			case DCF_Double:
				vw = PI * 2 * (Frequency)* vhOrder;
				if (TwoTuned.R1 == 0)
				{
					vY = CComplex(0, vw * (TwoTuned.C2 + TwoTuned.ConstDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.ConstDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.ConstDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.ConstDev->ddC1));
					vY = vZ.inverse();
					TwoTuned.ConstDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					TwoTuned.ConstDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}
				else
				{
					vY = CComplex(1.0 / (TwoTuned.R1 + TwoTuned.ConstDev->ddR1), vw * (TwoTuned.C2 + TwoTuned.ConstDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.ConstDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.ConstDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.ConstDev->ddC1));
					vY = vZ.inverse();
					TwoTuned.ConstDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					TwoTuned.ConstDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}

				break;

			case DCF_Triple:
				vw = PI * 2 * (Frequency)* vhOrder;
				if (ThreeTuned.R1 == 0)
				{
					vY = CComplex(0, vw * (ThreeTuned.C3 + ThreeTuned.ConstDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL3));
					vZ = vY.inverse();
					vY = CComplex(0, vw * (ThreeTuned.C2 + ThreeTuned.ConstDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL2));
					vZ += vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.ConstDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.ConstDev->ddC1));
					vY = vZ.inverse();
					ThreeTuned.ConstDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					ThreeTuned.ConstDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}
				else
				{
					vY = CComplex(1.0 / (ThreeTuned.R2 + ThreeTuned.ConstDev->ddR2), vw * (ThreeTuned.C3 + ThreeTuned.ConstDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL3));
					vZ = vY.inverse();
					vY = CComplex(1.0 / (ThreeTuned.R1 + ThreeTuned.ConstDev->ddR1), vw * (ThreeTuned.C2 + ThreeTuned.ConstDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.ConstDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.ConstDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.ConstDev->ddC1));
					vY = vZ.inverse();
					ThreeTuned.ConstDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					ThreeTuned.ConstDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}

				break;
			default:return;
			}

		}
}
void CxbDevDCF::InitYRandDev()
{
	CComplex vZ, vY;
	double vw;
	for (int vCount = 0; vCount < RandTimes; vCount++)
		for (int vhOrder = 1; vhOrder <= H_CAL_NUM; vhOrder++)
		{
			//double vw = PI * 2 * (Frequency + OneTuned.ConstDev->ddf) * vhOrder;
			switch (DCFType)
			{
			case DCF_Single:
				vw = PI * 2 * (Frequency)* vhOrder;
				vY = CComplex((OneTuned.R1 + OneTuned.RandDev->ddR1), vw *(OneTuned.L1 + OneTuned.RandDev->ddL1) - 1.0 / vw / (OneTuned.C1 + OneTuned.RandDev->ddC1)).inverse();
				OneTuned.RandDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
				OneTuned.RandDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				break;
			case DCF_Double:
				vw = PI * 2 * (Frequency)* vhOrder;
				if (TwoTuned.R1 == 0)
				{
					vY = CComplex(0, vw * (TwoTuned.C2 + TwoTuned.RandDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.RandDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.RandDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.RandDev->ddC1));
					vY = vZ.inverse();
					TwoTuned.RandDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					TwoTuned.RandDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}
				else
				{
					vY = CComplex(1.0 / (TwoTuned.R1 + TwoTuned.RandDev->ddR1), vw * (TwoTuned.C2 + TwoTuned.RandDev->ddC2) - 1.0 / vw / (TwoTuned.L2 + TwoTuned.RandDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (TwoTuned.L1 + TwoTuned.RandDev->ddL1) - 1.0 / vw / (TwoTuned.C1 + TwoTuned.RandDev->ddC1));
					vY = vZ.inverse();
					TwoTuned.RandDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					TwoTuned.RandDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}

				break;

			case DCF_Triple:
				vw = PI * 2 * (Frequency)* vhOrder;
				if (ThreeTuned.R1 == 0)
				{
					vY = CComplex(0, vw * (ThreeTuned.C3 + ThreeTuned.RandDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.RandDev->ddL3));
					vZ = vY.inverse();
					vY = CComplex(0, vw * (ThreeTuned.C2 + ThreeTuned.RandDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.RandDev->ddL2));
					vZ += vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.RandDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.RandDev->ddC1));
					vY = vZ.inverse();
					ThreeTuned.RandDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					ThreeTuned.RandDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}
				else
				{
					vY = CComplex(1.0 / (ThreeTuned.R2 + ThreeTuned.RandDev->ddR2), vw * (ThreeTuned.C3 + ThreeTuned.RandDev->ddC3) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.RandDev->ddL3));
					vZ = vY.inverse();
					vY = CComplex(1.0 / (ThreeTuned.R1 + ThreeTuned.RandDev->ddR1), vw * (ThreeTuned.C2 + ThreeTuned.RandDev->ddC2) - 1.0 / vw / (ThreeTuned.L2 + ThreeTuned.RandDev->ddL2));
					vZ = vY.inverse() + CComplex(0, vw * (ThreeTuned.L1 + ThreeTuned.RandDev->ddL1) - 1.0 / vw / (ThreeTuned.C1 + ThreeTuned.RandDev->ddC1));
					vY = vZ.inverse();
					ThreeTuned.RandDevYg[vhOrder - 1 + H_CAL_NUM * vCount] = vY.real();
					ThreeTuned.RandDevYb[vhOrder - 1 + H_CAL_NUM * vCount] = vY.image();
				}

				break;
			default:return;
			}

		}
}

void CxbDevDCF::selectNoneDevY()
{
	Yg = OneTuned.ConstDevYg;
	Yb = OneTuned.ConstDevYb;
}

void CxbDevDCF::selectConsDevY(int vCount)
{
	Yg = OneTuned.ConstDevYg + vCount * H_CAL_NUM;
	Yb = OneTuned.ConstDevYb + vCount * H_CAL_NUM;
}

void CxbDevDCF::selectRandDevY(int vCount)
{
	Yg = OneTuned.RandDevYg + vCount * H_CAL_NUM;
	Yb = OneTuned.RandDevYb + vCount * H_CAL_NUM;
}

double CxbDevDCF::GetYg(int vhOrder)
{
	//马俊鹏

	return Yg[vhOrder - 1];

}

double CxbDevDCF::GetYb(int vhOrder)
{
	//马俊鹏

	return Yb[vhOrder - 1];
}

