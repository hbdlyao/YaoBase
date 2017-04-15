///////////////////////////////////////////////////////////
//  CMath.cpp
//  Implementation of the Class CMath_Ax_B
//  Created on:      05-4月-2017 19:51:25
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMath.h"


CMath_Ax_B::CMath_Ax_B()
{
	Init();
}

CMath_Ax_B::~CMath_Ax_B()
{
	//
	Release();
}

void CMath_Ax_B::Init()
{
	nDim = 0;	
	//
	A_Matrix = nullptr;
	X_Vect = nullptr;
	B_Vect = nullptr;
}


void CMath_Ax_B::Clear()
{
	//
	delete[] A_Matrix;
	delete[] X_Vect;
	delete[] B_Vect;
	//
}


void CMath_Ax_B::Release()
{
	Clear();
}

void CMath_Ax_B::InitMatrix(int vN)
{
	nDim=vN;
	//
	doInitMatrix();
}

void CMath_Ax_B::doInitMatrix()
{

	int vN;

	vN = nDim;
	//
	A_Matrix = new double[vN*vN];
	X_Vect = new double[vN];
	B_Vect = new double[vN];

}

/**
* 解线性方程组
*/

void CMath_Ax_B::Sovle(int vDim,double * vAMatrix, double * vBVect, double * vXVect)
{
	nDim = vDim;

	A_Matrix =vAMatrix;
	B_Vect = vBVect;
	X_Vect = vXVect;

	//
	Sovle();

}

void CMath_Ax_B::Sovle()
{
	doSovle();
}


/**
* 解线性方程组
*/
void CMath_Ax_B::doSovle()
{
	//
}


void CMath_Ax_B::UpdateA(double * vAMatrix)
{
	A_Matrix = vAMatrix;
}


void CMath_Ax_B::UpdateB(double * vBVect)
{
	B_Vect=vBVect;
}