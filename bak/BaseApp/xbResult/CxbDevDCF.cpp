///////////////////////////////////////////////////////////
//  CxbDevDCF.cpp
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDCF.h"
#include "gbHead_Def.h"


//马骏鹏
double CxbDevDCF::get_C1() {
	return C1 + ddC1;
}
double CxbDevDCF::get_C2() {
	return C2 + ddC2;
}
double CxbDevDCF::get_C3() {
	return C3 + ddC3;
}
double CxbDevDCF::get_L1() {
	return L1 + ddL1;
}
double CxbDevDCF::get_L2() {
	return L2 + ddL2;
}
double CxbDevDCF::get_L3() {
	return L3 + ddL3;
}
double CxbDevDCF::get_R1() {
	return R1 + ddR1;
}
double CxbDevDCF::get_R2() {
	return R2 + ddR2;
}
double CxbDevDCF::get_f() {
	return Frequency + ddf;
}

void CxbDevDCF::SetType(double newVal)
{
	Type = newVal;
}

void CxbDevDCF::SetFrequency(double newVal) {
	Frequency = newVal;
}

void CxbDevDCF::InitY(int vhOrder)
{
	CComplex vZ, vY;
	double vw = PI * 2 * get_f() * vhOrder;
	switch (Type)
	{
	case DCF_None:
		Yg = 0;
		Yb = 0;
		return;
	case DCF_Single:
		vY = CComplex(get_R1(), vw * get_L3() - 1.0 / vw / get_C3()).inverse();
		Yg = vY.real();
		Yb = vY.image();
		return;
	case DCF_Double:
		vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
		vZ = vY.inverse() + CComplex(0, vw * get_L1() - 1.0 / vw / get_C1());
		Yg = 0;
		Yb = vZ.inverse().image();
		return;
	case DCF_DoubleHighPass:
		vY = CComplex(0, vw * get_C2() - 1.0 / vw / get_L2());
		vZ = vY.inverse() + CComplex(0, vw * get_L1());
		vY = vZ.inverse() + CComplex(1.0 / get_R1(), 0);
		vZ = vY.inverse() + CComplex(0, -1.0 / vw / get_C1());
		vY = vZ.inverse();
		Yg = vY.real();
		Yb = vY.image();
		return;
	case DCF_Triple:
		Yg = 0;
		Yb = -1.0 / (vw*get_L1() - 1.0 / vw / get_C1()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2()) - 1.0 / (vw*get_C2() - 1.0 / vw / get_L2());
		return;
	case DCF_TripleHighPass:
		vZ = CComplex(0, vw*get_L1() - 1.0 / vw / get_C1());
		vY = CComplex(1.0 / get_R1(), vw*get_C2() - 1.0 / vw / get_L2());
		vZ += vY.inverse();
		vY = CComplex(1.0 / get_R2(), vw*get_C3() - 1.0 / vw / get_L3());
		vZ += vY.inverse();
		vY = vZ.inverse();
		return;


	default:return;
	}
}

/**
* 3P的等效电导
*/
double CxbDevDCF::GetYg()
{
	//马俊鹏

	return Yg;

}


/**
* 3P的等效电纳
*/
double CxbDevDCF::GetYb()
{
	//马俊鹏

	return Yb;
}


/**
* 3P的等效电导
*/
void CxbDevDCF::SetYg(double newVal) {

	Yg = newVal;
}


/**
* 3P的等效电纳
*/
void CxbDevDCF::SetYb(double newVal) {

	Yb = newVal;
}

/**
 * 产生实际偏差
 */

void CxbDevDCF::set_dev(int type)
{
	static CRand randC1(NdC1, PdC1, Real_Dis);
	static CRand randC2(NdC2, PdC2, Real_Dis);
	static CRand randC3(NdC3, PdC3, Real_Dis);
	static CRand randL1(NdL1, PdL1, Real_Dis);
	static CRand randL2(NdL2, PdL2, Real_Dis);
	static CRand randL3(NdL3, PdL3, Real_Dis);
	static CRand randR1(NdR1, PdR1, Real_Dis);
	static CRand randR2(NdR2, PdR2, Real_Dis);
	static CRand randf(Ndf, Pdf, Real_Dis);
	switch (type)
	{
	case DCF_NoneDev:
		ddC1 = 0; ddC2 = 0; ddC3 = 0; ddL1 = 0; ddL2 = 0; ddL3 = 0; ddR1 = 0; ddR2 = 0; ddf = 0;
		return;
	case DCF_ConPDev:
		ddC1 = PdC1;	ddC2 = PdC2;	ddC3 = PdC3;	ddL1 = PdL1;	ddL2 = PdL2;	ddL3 = PdL3;	ddR1 = PdR1;	ddR2 = PdR2; ddf = Pdf;
		return;
	case DCF_ConNDev:
		ddC1 = NdC1; ddC2 = NdC2; ddC3 = NdC3; ddL1 = NdL1; ddL2 = NdL2; ddL3 = NdL3; ddR1 = NdR1; ddR2 = NdR2; ddf = Ndf;
		return;
	case DCF_RandDev:
		ddC1 = randC1.getVal()*C1; ddC2 = randC2.getVal()*C2; ddC3 = randC3.getVal()*C3;
		ddL1 = randL1.getVal()*L1; ddL2 = randL2.getVal()*L2; ddL3 = randL3.getVal()*L3;
		ddR1 = randR1.getVal()*R1; ddR2 = randR2.getVal()*R2; ddf = randf.getVal();
		return;
	default: cout << "Abnormal DCF deviation type"; system("pause"); return;
	}
}