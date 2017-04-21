///////////////////////////////////////////////////////////
//  CxbDevDCF_RLC.cpp
//  Implementation of the Class CxbDevDCF_RLC
//  Created on:      20-4ÔÂ-2017 21:29:23
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDCF_RLC.h"

#include "CxbDevDCF_RLC.h"
#include "CComplex.h"
#include "gbHead_Def.h"
#include "CRand.h"


CxbDevDCF_RLC::~CxbDevDCF_RLC()
{
	delete[] NoneDevYg;
	delete[] NoneDevYb;

	delete[] ConstDevYg;
	delete[] ConstDevYb;

	delete[] RandDevYg;
	delete[] RandDevYb;

}

void CxbDevDCF_RLC::Init()
{
	//
	SetDotCount(2);

	InitData();

}

void CxbDevDCF_RLC::Clear()
{
	delete[] Yg;
	delete[] Yb;

	delete[] NoneDevYg;
	delete[] NoneDevYb;

	delete[] ConstDevYg;
	delete[] ConstDevYb;

	delete[] RandDevYg;
	delete[] RandDevYb;

}

void CxbDevDCF_RLC::InitData()
{
	Yg = new double[hMax()];
	Yb = new double[hMax()];

	NoneDevYg = new double[hMax()];
	NoneDevYb = new double[hMax()];

	ConstDevYg = new double[3*hMax()];
	ConstDevYb = new double[3*hMax()];

	RandDevYg = new double[GetSampleNum()*hMax()];
	RandDevYb = new double[GetSampleNum()*hMax()];

}

void CxbDevDCF_RLC::Prepare_hRLC()
{
	Clear();

	InitData();


	//
	doDelta_None();

	doDelta_Ref_None();

	doDelta_Ref_Max();

	doDelta_Ref_Min();

	doDelta_Rand();

}

void CxbDevDCF_RLC::doDelta_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta();

	//
	for (int vhOrder = 0; vhOrder < hMax(); vhOrder++)
	{
		NoneDevYg[vhOrder] = Yg[vhOrder];
		NoneDevYb[vhOrder] = Yb[vhOrder];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta();

	//
	for (int vhOrder = 0; vhOrder < hMax(); vhOrder++)
	{
		ConstDevYg[vhOrder] = Yg[vhOrder];
		ConstDevYg[vhOrder] = Yb[vhOrder];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_Max()
{
	ddC = PdC;
	ddL = PdL;
	ddR = PdR;

	ddf = MaxFreqDelta;

	doDelta();

	int vK = hMax();
	for (int vhOrder = 0; vhOrder < hMax(); vhOrder++)
	{
		ConstDevYg[vK + vhOrder] = Yg[vhOrder];
		ConstDevYb[vK + vhOrder] = Yb[vhOrder];
	}
	
}


void CxbDevDCF_RLC::doDelta_Ref_Min()
{
	ddC = NdC;
	ddL = NdL;
	ddR = NdR;

	ddf = MinFreqDelta;

	doDelta();

	//
	int vK = 2*hMax();
	for (int vhOrder = 0; vhOrder < hMax(); vhOrder++)
	{
		ConstDevYg[vK+vhOrder] = Yg[vhOrder];
		ConstDevYb[vK+vhOrder] = Yb[vhOrder];
	}

}

void CxbDevDCF_RLC::doDelta_Rand()
{
	CRand randC1(NdC, PdC, Real_Dis);
	CRand randL1(NdL, PdL, Real_Dis);
	CRand randR1(NdR, PdR, Real_Dis);

	CRand randf(MinFreqDelta, MaxFreqDelta, Real_Dis);

	//
	int vK = 0;
	for (int i = 0; i < GetSampleNum(); i++)
	{
		ddC = randC1.getVal() * GetZ_C();
		ddL = randL1.getVal() * GetZ_L();
		ddR = randR1.getVal() * GetZr();
		ddf = randf.getVal();

		doDelta();

		vK = i*hMax();
		RandDevYg[vK + i] = Yg[i];
		RandDevYg[vK + i] = Yb[i];
	}

}


void CxbDevDCF_RLC::doDelta()
{
	CComplex vY;
	double vZg,vZb;

	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		vZg = GetR();
		vZb = vhOrder* GetOmega0() * GetL();

		if (GetZ_C()==0)
			vZb = vZb + -1.0 / (vhOrder * GetOmega0() *  GetC());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vhOrder - 1] = vY.real();
		Yb[vhOrder - 1] = vY.image();
	}
}


double CxbDevDCF_RLC::GetC() 
{

	return ddC + GetZ_C();


}

double CxbDevDCF_RLC::GetL() 
{
	return ddL + GetZ_L();
}

double CxbDevDCF_RLC::GetR() 
{
	return ddR + GetZr();
}

double CxbDevDCF_RLC::GetOmega0() 
{
	return (ddf + FreqRef()) * 2 * PI;

}

void CxbDevDCF_RLC::selectNoneDevY() 
{
	Yg = NoneDevYg;
	Yb = NoneDevYb;
}

void CxbDevDCF_RLC::selectConsDevY(int vCount)
{
	Yg = ConstDevYg + vCount * hMax();
	Yb = ConstDevYb + vCount * hMax();
}

void CxbDevDCF_RLC::selectRandDevY(int vCount) 
{
	Yg = RandDevYg + vCount * hMax();
	Yb = RandDevYb + vCount * hMax();
}


double CxbDevDCF_RLC::GetMaxFreqDelta(){

	return MaxFreqDelta;
}


void CxbDevDCF_RLC::SetMaxFreqDelta(double newVal){

	MaxFreqDelta = newVal;
}


double CxbDevDCF_RLC::GetMinFreqDelta(){

	return MinFreqDelta;
}


void CxbDevDCF_RLC::SetMinFreqDelta(double newVal){

	MinFreqDelta = newVal;
}


int CxbDevDCF_RLC::GetSampleNum(){

	return SampleNum;
}


void CxbDevDCF_RLC::SetSampleNum(int newVal){

	SampleNum = newVal;
}