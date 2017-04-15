///////////////////////////////////////////////////////////
//  CPowerMath.cpp
//  Implementation of the Class CPower_YU_I
//  Created on:      05-4月-2017 19:43:25
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerMath.h"


CPower_YU_I::~CPower_YU_I()
{
	Release();
}


void CPower_YU_I::Release() 
{

	Clear();

}


void CPower_YU_I::Clear() 
{
	delete[] Yg_Matrix;
	delete[] Yb_Matrix;

	delete[] Ur_Vect;
	delete[] Um_Vect;

	delete[] Ir_Vect;
	delete[] Im_Vect;

	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;
	Ir_Vect = nullptr;
	Im_Vect = nullptr;
}


void CPower_YU_I::Init()
{
	NodeCount = 0;
	//
	Ydim = 0;

	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;

	Ir_Vect = nullptr;
	Um_Vect = nullptr;

}



void CPower_YU_I::InitMatrix(int vN)
{
	Ydim = vN;
	
	Yg_Matrix = new double[Ydim*Ydim];
	Yb_Matrix = new double[Ydim*Ydim];
	
	Ur_Vect     = new double[Ydim];
	Um_Vect		= new double[Ydim];
	Ir_Vect		= new double[Ydim];
	Im_Vect	    = new double[Ydim];

}


void CPower_YU_I::UpdateY0(int iNode, double vYg, double vYb)
{

	doUpdateYg0(iNode, vYg);

	doUpdateYb0(iNode, vYb);
}


void CPower_YU_I::UpdateY(int iNode, int jNode, double vYg, double vYb)
{

	doUpdateYg(iNode, jNode, vYg);

	doUpdateYb(iNode, jNode, vYb);

}

void CPower_YU_I::UpdateI(int iNode, double vIr,double vIm)
{
	Ir_Vect[iNode] = Ir_Vect[iNode]+vIr;

	Im_Vect[iNode] = Im_Vect[iNode]+vIm;

}

void CPower_YU_I::UpdateI(int iNode, int jNode, double vIr, double vIm)
{
	//注意电流注入正方向的规定

	Ir_Vect[iNode] = Ir_Vect[iNode] + vIr;

	Im_Vect[iNode] = Im_Vect[iNode] + vIm;


	Ir_Vect[jNode] = Ir_Vect[iNode] - vIr;

	Im_Vect[jNode] = Im_Vect[iNode] - vIm;


}


void CPower_YU_I::doUpdateYg0(int iNode, double vY)
{
	//对地支路
		int vN;
		double vX;
	
		vN = Ydim;
		//
		vX = Yg_Matrix[iNode*vN + iNode];
		Yg_Matrix[iNode*vN + iNode] = vX+vY;

}

void CPower_YU_I::doUpdateYb0(int iNode, double vY)
{
	//对地支路
	int vN;
	double vX;

	vN = Ydim;
	//
	vX = Yb_Matrix[iNode*vN + iNode];
	Yb_Matrix[iNode*vN + iNode] = vX + vY;

}


void CPower_YU_I::doUpdateYg(int iNode, int jNode, double vY)
{

	//串联支路
	
		int vN;
		double vX;
	
		vN = Ydim;

		//自导纳
		vX = Yg_Matrix[iNode*vN + iNode];
		Yg_Matrix[iNode*vN + iNode] = vX + vY;
		//
		vX = Yg_Matrix[jNode*vN + jNode];
		Yg_Matrix[jNode*vN + jNode] = vX + vY;
		
		//互导纳
		vX = Yg_Matrix[iNode*vN + jNode];
		Yg_Matrix[iNode*vN + jNode] = vX + (-vY);
	
		vX = Yg_Matrix[jNode*vN + iNode];
		Yg_Matrix[jNode*vN + iNode] = vX + (-vY);
}

void CPower_YU_I::doUpdateYb(int iNode, int jNode, double vY)
{

	//串联支路

	int vN;
	double vX;

	vN = Ydim;

	//自导纳
	vX = Yb_Matrix[iNode*vN + iNode];
	Yb_Matrix[iNode*vN + iNode] = vX + vY;
	//
	vX = Yb_Matrix[jNode*vN + jNode];
	Yb_Matrix[jNode*vN + jNode] = vX + vY;

	//互导纳
	vX = Yb_Matrix[iNode*vN + jNode];
	Yb_Matrix[iNode*vN + jNode] = vX + (-vY);

	vX = Yb_Matrix[jNode*vN + iNode];
	Yb_Matrix[jNode*vN + iNode] = vX + (-vY);
}


void CPower_YU_I::Solve()
{
	//马俊鹏
}


void CPower_YU_I::ClearData()
{
	Clear();

}