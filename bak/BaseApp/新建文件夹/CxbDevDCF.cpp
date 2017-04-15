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
	switch (DCFType)
	{
	case DCF_Single:
		OneTuned.ConstDev = new CxbDCFOneTunedDev[3];
		OneTuned.RandDev = new CxbDCFOneTunedDev[vTimes];
		SetOneConstDev();
		SetOneRandDev(vTimes);
		return;
	case DCF_Double:
		TwoTuned.ConstDev = new CxbDCFTwoTunedDev[3];
		TwoTuned.RandDev = new CxbDCFTwoTunedDev[vTimes];
		SetTwoConstDev();
		SetTwoRandDev(vTimes);
		return;
	case DCF_Triple:
		TwoTuned.ConstDev = new CxbDCFTwoTunedDev[3];
		TwoTuned.RandDev = new CxbDCFTwoTunedDev[vTimes];
		SetTwoConstDev();
		SetTwoRandDev(vTimes);
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

void CxbDevDCF::InitY()
{

}

//形成一次的导纳参数
void CxbDevDCF::InitYNoneDev(int vhOrder)
{
	//CComplex vZ, vY;
	//double vw = PI * 2 * get_f() * vhOrder;
	//switch (DCFType)
	//{
	//case DCF_None:
	//	Yg = 0;
	//	Yb = 0;
	//	return;
	//case DCF_Single:
	//	vY = CComplex(get_R1(), vw * get_L3() - 1.0 / vw / get_C3()).inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Double:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1() - 1.0 / vw / get_C1());
	//	Yg = 0;
	//	Yb = vZ.inverse().image();
	//	return;
	//case DCF_DoubleHighPass:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1());
	//	vY = vZ.inverse() + CComplex(1.0 / get_R1(), 0);
	//	vZ = vY.inverse() + CComplex(0, -1.0 / vw / get_C1());
	//	vY = vZ.inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Triple:
	//	Yg = 0;
	//	Yb = -1.0 / (vw*get_L1() - 1.0 / vw / get_C1()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2());
	//	return;
	//case DCF_TripleHighPass:
	//	vZ = CComplex(0, vw*get_L1() - 1.0 / vw / get_C1());
	//	vY = CComplex(1.0 / get_R1(), vw*get_C2() - 1.0 / vw / get_L2());
	//	vZ += vY.inverse();
	//	vY = CComplex(1.0 / get_R2(), vw*get_C3() - 1.0 / vw / get_L3());
	//	vZ += vY.inverse();
	//	vY = vZ.inverse();
	//	return;


	//default:return;
	//}

}
void CxbDevDCF::InitYConsDev(int vhOrder, int vCount)
{
	//CComplex vZ, vY;
	//double vw = PI * 2 * get_f() * vhOrder;
	//switch (DCFType)
	//{
	//case DCF_None:
	//	Yg = 0;
	//	Yb = 0;
	//	return;
	//case DCF_Single:
	//	vY = CComplex(get_R1(), vw * get_L3() - 1.0 / vw / get_C3()).inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Double:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1() - 1.0 / vw / get_C1());
	//	Yg = 0;
	//	Yb = vZ.inverse().image();
	//	return;
	//case DCF_DoubleHighPass:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1());
	//	vY = vZ.inverse() + CComplex(1.0 / get_R1(), 0);
	//	vZ = vY.inverse() + CComplex(0, -1.0 / vw / get_C1());
	//	vY = vZ.inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Triple:
	//	Yg = 0;
	//	Yb = -1.0 / (vw*get_L1() - 1.0 / vw / get_C1()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2());
	//	return;
	//case DCF_TripleHighPass:
	//	vZ = CComplex(0, vw*get_L1() - 1.0 / vw / get_C1());
	//	vY = CComplex(1.0 / get_R1(), vw*get_C2() - 1.0 / vw / get_L2());
	//	vZ += vY.inverse();
	//	vY = CComplex(1.0 / get_R2(), vw*get_C3() - 1.0 / vw / get_L3());
	//	vZ += vY.inverse();
	//	vY = vZ.inverse();
	//	return;


	//default:return;
	//}
}
void CxbDevDCF::InitYRandDev(int vhOrder, int vCount)
{
	//CComplex vZ, vY;
	//double vw = PI * 2 * get_f() * vhOrder;
	//switch (DCFType)
	//{
	//case DCF_None:
	//	Yg = 0;
	//	Yb = 0;
	//	return;
	//case DCF_Single:
	//	vY = CComplex(get_R1(), vw * get_L3() - 1.0 / vw / get_C3()).inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Double:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1() - 1.0 / vw / get_C1());
	//	Yg = 0;
	//	Yb = vZ.inverse().image();
	//	return;
	//case DCF_DoubleHighPass:
	//	vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
	//	vZ = vY.inverse() + CComplex(0, vw * get_L1());
	//	vY = vZ.inverse() + CComplex(1.0 / get_R1(), 0);
	//	vZ = vY.inverse() + CComplex(0, -1.0 / vw / get_C1());
	//	vY = vZ.inverse();
	//	Yg = vY.real();
	//	Yb = vY.image();
	//	return;
	//case DCF_Triple:
	//	Yg = 0;
	//	Yb = -1.0 / (vw*get_L1() - 1.0 / vw / get_C1()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2());
	//	return;
	//case DCF_TripleHighPass:
	//	vZ = CComplex(0, vw*get_L1() - 1.0 / vw / get_C1());
	//	vY = CComplex(1.0 / get_R1(), vw*get_C2() - 1.0 / vw / get_L2());
	//	vZ += vY.inverse();
	//	vY = CComplex(1.0 / get_R2(), vw*get_C3() - 1.0 / vw / get_L3());
	//	vZ += vY.inverse();
	//	vY = vZ.inverse();
	//	return;


	//default:return;
	//}
}

void CxbDevDCF::selectNoneDevY()
{

}

void CxbDevDCF::selectConsDevY(int vCount)
{

}

void CxbDevDCF::selectRandDevY(int vCount)
{

}

double CxbDevDCF::GetYg(int vhOrder)
{
	//马俊鹏

	return Yg[vhOrder];

}

double CxbDevDCF::GetYb(int vhOrder)
{
	//马俊鹏

	return Yb[vhOrder];
}

