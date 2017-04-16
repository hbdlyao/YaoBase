///////////////////////////////////////////////////////////
//  CmcProfile.cpp
//  Implementation of the Class CmcProfile
//  Created on:      10-4��-2017 0:54:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcProfile.h"
#include "time.h"

#include <iostream>


CmcProfile::~CmcProfile()
{
	Clear();

	delete pmcOrder;
	pmcOrder = nullptr;

	/*
	delete[] pmcStaData;
	pmcStaData = nullptr;

	delete[] pmcStaDataN;
	pmcStaDataN = nullptr;
	*/
}

void CmcProfile::Clear()
{
	delete[] pmcStaData;
	pmcStaData = nullptr;

	delete[] pmcStaDataN;
	pmcStaDataN = nullptr;

	//
	delete[] J_Matrix;
	delete[] F_Vect;
	delete[] X_Vect;
	delete[] dX_Vect;

	//
	J_Matrix = nullptr;
	F_Vect = nullptr;
	X_Vect = nullptr;

	dX_Vect = nullptr;

	//
	pmcOrder->Clear();

}

void CmcProfile::Init()
{
	//"DFBFH22"

	NodeCount = 0;
	//
	Ydim = 0;
	Jdim = 0;
	StaDim = 0;

	//
	J_Matrix = nullptr;
	F_Vect = nullptr;
	X_Vect = nullptr;

	dX_Vect = nullptr;
	
	//
	pmcStaData = nullptr;
	pmcStaDataN = nullptr;
	
	//
	pmcOrder = new CmcOrder();
	pmcOrder->Init();

}


void CmcProfile::InitMatrix(int vStaDim)
{
	StaDim = vStaDim;

	Ydim = NodeCount;
	Jdim = Ydim + StaDim;

	//
	doInitMatrix();
	//
	doInitData();

}


void CmcProfile::doInitMatrix()
{
	//
	J_Matrix = new double[Jdim*Jdim];
	F_Vect = new double[Jdim];
	X_Vect = new double[Jdim];
	dX_Vect = new double[Jdim];

	//
	pmcStaData = new struct_mcStationData[StaDim];
	//
	pmcStaDataN = new struct_mcStationData[StaDim];

	//////////////////////////////////////////////////////

}

void CmcProfile::doInitData()
{
	int i, j;

	for (i = 0; i < Jdim; i++)
		for (j = 0; j < Jdim; j++)
			J_Matrix[i*Jdim + j] = 0;

	for (i = 0; i < Jdim; i++)
	{
		F_Vect[i] = 0;
		X_Vect[i] = 0;
		dX_Vect[i] = 0;
	}

	//
	for (i = 0; i < StaDim; i++)
	{
		//�޿���
		//��������
		//pmcStaData[i].Uac=0;
		//pmcStaDataN[i].Uac=0;

	}

}


void CmcProfile::ResetData()
{//�������ֵ
	int i, j;

	for (i = 0; i < Jdim; i++)
		for (j = 0; j < Jdim; j++)
			J_Matrix[i*Jdim + j] = 0;

	for (i = 0; i < Jdim; i++)
	{
		F_Vect[i] = 0;
		X_Vect[i] = 0;
		dX_Vect[i] = 0;
	}

	//
	for (i = 0; i < StaDim; i++)
	{
		//�޿���
		//��������
		//pmcStaData[i].Uac=0;		
	}

}

void CmcProfile::Init_XVect()
{

	//����������ֵ��
	
		//�޿���
		//Yao
	
}


void CmcProfile::UpdateY0(int iNode, double vY)
{

	double vX;
	
	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
}


void CmcProfile::UpdateY(int iNode, int jNode, double vY){

	double vX;
	
	//
	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
	//
	vX = J_Matrix[jNode*Jdim + jNode];
	J_Matrix[jNode*Jdim + jNode] = vX+vY;
	
	//
	vX = J_Matrix[iNode*Jdim + jNode];
	J_Matrix[iNode*Jdim + jNode] = vX-vY;
	J_Matrix[jNode*Jdim + iNode] = vX-vY;
	
	//
}


void CmcProfile::UpdateF_Y(){

	//�޿���
	//������
	//
}


void CmcProfile::UpdateX(){

	//�޿���
		//X=x0+dx;
}


void CmcProfile::Solve_dX(){

	//�޿���
}


void CmcProfile::UpdateF_PdCtrl(int vK, int iNode, int jNode){

	int vRow;
	double vPd,vU1,vU2,vId;
	
	//�޿���
	
	vU1 = X_Vect[iNode];
	vU2 = X_Vect[jNode];
	
	//
	vRow = Ydim + vK;
	vId = dX_Vect[vRow];//x1=x0+dx
	
	//
	vPd = pmcStaData[vK].Pd; 
	
	F_Vect[vRow]=(vPd -(vU1 - vU2)*vId);
}


void CmcProfile::UpdateF_UdCtrl(int vK, int iNode, int jNode){

	int vRow;
	double vU1, vU2;
	double vUd;
	
	vU1 = X_Vect[iNode];
	vU2 = X_Vect[jNode];
	
	//
	vUd = pmcStaData[vK].Ud; //�޿���
	
	vRow = Ydim + vK;	
	F_Vect[vRow] = (vUd - (vU1 - vU2));
}


void CmcProfile::UpdateF_AngCtrl(int vK, int iNode, int jNode){

	//�޿���
	int vRow;
	
	//
	vRow = Ydim + vK;
	//vFVect[vRow]=
}


void CmcProfile::UpdateJ_PdCtrl(int vK, int iNode, int jNode){

	//Ҫ�����Ƿ����Ե�ӵ�
	
	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	//
	vRow = jNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = 1;
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[Ydim + vK];
	
	//
	vRow = Ydim + vK;
	vCol = jNode;
	J_Matrix[vRow*Jdim + vCol] = dX_Vect[Ydim + vK];
	
	//
	vRow = Ydim + vK;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode] + dX_Vect[jNode];
	
	//
	vRow = Ydim + vK;
	//vFVect[vRow]=
}


void CmcProfile::UpdateJ_UdCtrl(int vK, int iNode, int jNode){

	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	//
	vRow = jNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = 1;
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	//
	vRow = Ydim + vK;
	vCol = jNode;
	J_Matrix[vRow*Jdim + vCol] = 1;
	
	//
}


void CmcProfile::UpdateJ_AngCtrl(int vK, int iNode, int jNode){

	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	//
	vRow = jNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = 1;
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	//J_Matrix[vRow*Jdim + vCol] = -1/n;
	
	//
	vRow = Ydim + vK;
	vCol = jNode;
	//J_Matrix[vRow*Jdim + vCol] = 1/n;
	
	//
	vRow = Ydim + vK;
	vCol = Ydim + vK;
	//J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode] + dX_Vect[jNode];
	
	//�޿���
}


void CmcProfile::UpdateF_PdCtrl0(int vK, int iNode)
{

	int vRow;
	double vPd, vU1, vU2, vId;
	
	vU1 = X_Vect[iNode];
	vU2 = 0;
	
	//
	vRow = Ydim + vK;
	vId = dX_Vect[vRow];//x1=x0+dx
	
						//
	vPd = pmcStaData[vK].Pd; //�޿���
	
	F_Vect[vRow] = (vPd - (vU1 - vU2)*vId);
}


void CmcProfile::UpdateF_UdCtrl0(int vK, int iNode){

	int vRow;
	double vU1, vU2;
	double vUd;
	
	vU1 = X_Vect[iNode];
	vU2 = 0;
	
	//
	vUd = pmcStaData[vK].Ud; //�޿���
	
	vRow = Ydim + vK;
	F_Vect[vRow] = (vUd - (vU1 - vU2));
}


void CmcProfile::UpdateF_AngCtrl0(int vK, int iNode){

	//�޿���
	int vRow;
	
	//
	vRow = Ydim + vK;
	//vFVect[vRow]=
}


void CmcProfile::UpdateJ_PdCtrl0(int vK, int iNode){

	//Ҫ�����Ƿ����Ե�ӵ�
	
	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[Ydim + vK];
	
	
	//
	vRow = Ydim + vK;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode];
}


void CmcProfile::UpdateJ_UdCtrl0(int vK, int iNode){

	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	
	//
}


void CmcProfile::UpdateJ_AngCtrl0(int vK, int iNode){

	int vRow, vCol;
	
	//
	vRow = iNode;
	vCol = Ydim + vK;
	J_Matrix[vRow*Jdim + vCol] = -1;
	
	
	//
	vRow = Ydim + vK;
	vCol = iNode;
	//J_Matrix[vRow*Jdim + vCol] = -1/n;
	
	
	//
	vRow = Ydim + vK;
	vCol = Ydim + vK;
	//J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode] + dX_Vect[jNode];
	
	//�޿���
}


void CmcProfile::UpdateR_UN(int vK)
{//���������� UdioN,UvN

	double vX, vUd, vNT, vUT, vAngle, vdx, vdr;
	
	vUd = pmcStaDataN[vK].Ud;
	vNT = pmcStaDataN[vK].nValNum;
	vUT = pmcStaDataN[vK].UT;
	vdr = pmcStaDataN[vK].dr;
	vdx = pmcStaDataN[vK].dx;
	vAngle = pmcStaDataN[vK].alphaOrgamma;
	
	//	
	try
	{
		vX = (vUd / vNT + vUT) / (cos(vAngle) - (vdx + vdr) / 100);
		pmcStaDataN[vK].Udio = vX;
		pmcStaDataN[vK].Uv = vX / 1.35;
	}
	catch (const std::exception& )
	{
		cout << "UpdateR_UN" << endl;
	}
}


void CmcProfile::UpdateI_UN(int vK)
{//�������� UdioN,UvN

	double vX, vUd, vNT, vUT, vAngle, vdx, vdr;
	
	vUd = pmcStaDataN[vK].Ud;
	vNT = pmcStaDataN[vK].nValNum;
	vUT = pmcStaDataN[vK].UT;
	vdr = pmcStaDataN[vK].dr;
	vdx = pmcStaDataN[vK].dx;
	vAngle = pmcStaDataN[vK].alphaOrgamma;
	
	//
	//	
	try
	{
		vX = (vUd / vNT - vUT) / (cos(vAngle) - (vdx - vdr) / 100);
	
		pmcStaDataN[vK].Udio = vX;
		pmcStaDataN[vK].Uv = vX / 1.35;
	}
	catch (const std::exception& )
	{
		cout << "UpdateI_UN" << endl;
	}
}


void CmcProfile::UpdateTapN(int vK){

	double vUac,vUvN ;
	
	vUac = pmcStaDataN[vK].Uac;
	vUvN = pmcStaDataN[vK].Uv;
	
	try
	{
		pmcStaDataN[vK].TC = vUac / vUvN;
	}
	catch (const std::exception& )
	{
		cout << "UvN=0"  << endl;
	}
}



bool CmcProfile::IsBiPole()
{

	bool vOk;

	vOk = (pmcOrder->GroundType == mc_Ground20);

	return vOk;
}


bool CmcProfile::IsMetalLine()
{

	bool vOk;

	vOk = (pmcOrder->GroundType == mc_Ground11);

	return vOk;
}


void CmcProfile::InitX_Y(int vNode, double vUnode)
{
	//�޿���2014-4-15
	//����������ֵ
	srand(time(0));

	X_Vect[vNode] = vUnode + rand() % 30 - 15;

}
void CmcProfile::InitX_I(int vK, double vId)
{
	//�޿���2014-4-15
	int vRow = Ydim + vK;
	//����������ֵ
	srand(time(0));
	X_Vect[vRow] = vId + (rand() % 20) / 10.0 - 1;

}
