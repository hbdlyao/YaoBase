///////////////////////////////////////////////////////////
//  CxbDevDCF_RLC.cpp
//  Implementation of the Class CxbDevDCF_RLC
//  Created on:      20-4月-2017 21:29:23
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
	delete[] NoneDevYg;
	delete[] NoneDevYb;

	delete[] ConstDevYg;
	delete[] ConstDevYb;

	delete[] RandDevYg;
	delete[] RandDevYb;
}

void CxbDevDCF_RLC::InitData()
{

	//
	NoneDevYg = new double[hMax()];
	NoneDevYb = new double[hMax()];

	ConstDevYg = new double[3*hMax()];
	ConstDevYb = new double[3*hMax()];

	RandDevYg = new double[GetSampleNum()*hMax()];
	RandDevYb = new double[GetSampleNum()*hMax()];

}

void CxbDevDCF_RLC::Prepare_hRLC()
{
	//
	Yg = new double[hMax()];
	Yb = new double[hMax()];

	//
	doDelta_None();

	doDelta_Ref_None();

	doDelta_Ref_Max();

	doDelta_Ref_Min();

	doDelta_Rand();

	//
	//delete[] Yg;
	//delete[] Yb;

}

void CxbDevDCF_RLC::doDelta_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta();

	//
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		NoneDevYg[vhOrder-1] = Yg[vhOrder-1];
		NoneDevYb[vhOrder-1] = Yb[vhOrder-1];
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
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vhOrder-1] = Yg[vhOrder-1];
		ConstDevYg[vhOrder-1] = Yb[vhOrder-1];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_Max()
{
	ddC = MaxCDelta;
	ddL = MaxLDelta;
	ddR = MaxRDelta;

	ddf = MaxFreqDelta;

	doDelta();

	int vK = hMax();
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vK + vhOrder - 1] = Yg[vhOrder-1];
		ConstDevYb[vK + vhOrder - 1] = Yb[vhOrder-1];
	}
	
}


void CxbDevDCF_RLC::doDelta_Ref_Min()
{
	ddC = MinCDelta;
	ddL = MinLDelta;
	ddR = MinRDelta;

	ddf = MinFreqDelta;

	doDelta();

	//
	int vK = 2*hMax();
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vK+ vhOrder - 1] = Yg[vhOrder-1];
		ConstDevYb[vK+ vhOrder - 1] = Yb[vhOrder-1];
	}

}

void CxbDevDCF_RLC::doDelta_Rand()
{
	CRand randC1(MinCDelta, MaxCDelta, Real_Dis);
	CRand randL1(MinLDelta, MaxLDelta, Real_Dis);
	CRand randR1(MinRDelta, MaxRDelta, Real_Dis);

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
		for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
		{
			RandDevYg[vK + vhOrder-1] = Yg[vhOrder - 1];
			RandDevYg[vK + vhOrder-1] = Yb[vhOrder - 1];
		}//hOrder

	}// for i

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


/**
 * 输入参数，正负偏差
 */
double CxbDevDCF_RLC::GetMaxCDelta(){

	return MaxCDelta;
}


/**
 * 输入参数，正负偏差
 */
void CxbDevDCF_RLC::SetMaxCDelta(double newVal){

	MaxCDelta = newVal;
}


double CxbDevDCF_RLC::GetMaxLDelta(){

	return MaxLDelta;
}


void CxbDevDCF_RLC::SetMaxLDelta(double newVal){

	MaxLDelta = newVal;
}


double CxbDevDCF_RLC::GetMaxRDelta(){

	return MaxRDelta;
}


void CxbDevDCF_RLC::SetMaxRDelta(double newVal){

	MaxRDelta = newVal;
}


double CxbDevDCF_RLC::GetMinCDelta(){

	return MinCDelta;
}


void CxbDevDCF_RLC::SetMinCDelta(double newVal){

	MinCDelta = newVal;
}


double CxbDevDCF_RLC::GetMinLDelta(){

	return MinLDelta;
}


void CxbDevDCF_RLC::SetMinLDelta(double newVal){

	MinLDelta = newVal;
}


double CxbDevDCF_RLC::GetMinRDelta(){

	return MinRDelta;
}


void CxbDevDCF_RLC::SetMinRDelta(double newVal){

	MinRDelta = newVal;
}