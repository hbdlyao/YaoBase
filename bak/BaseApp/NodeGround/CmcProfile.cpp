///////////////////////////////////////////////////////////
//  CmcProfile.cpp
//  Implementation of the Class CmcProfile
//  Created on:      10-4��-2017 0:54:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcProfile.h"
#include "time.h"
#include "CLU.h"

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
	//
	Ydim = 0;
	Jdim = 0;
	kDim = 0;
	iDim = 0;

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


void CmcProfile::InitMatrix()
{
	//
	doInitMatrix();
	//
	doInitData();

}

void CmcProfile::SetDim(int vStaCount,int vkDim,int viDim)
{
	StaCount = vStaCount;

	kDim = vkDim;
	iDim = viDim;

	Jdim = Ydim + kDim;

}

void CmcProfile::doInitMatrix()
{
	//
	J_Matrix = new double[Jdim*Jdim];
	F_Vect = new double[Jdim];
	X_Vect = new double[Jdim];
	dX_Vect = new double[Jdim];

	//
	pmcStaData = new struct_mcStationData[kDim];
	//
	pmcStaDataN = new struct_mcStationData[kDim];

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
	for (i = 0; i < kDim; i++)
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
	for (i = 0; i < kDim; i++)
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


double CmcProfile::GetMaxdX()
{
	double vMax = 0;
	for (int i = 0; i < Jdim; i++)
		if (abs(dX_Vect[i])>vMax)
		{
			vMax = abs(dX_Vect[i]);
		}
	return vMax;
}
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  UpdateX
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ɹ���
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcProfile::UpdateX()
{
	for (int i = 0; i < Jdim; i++)
		X_Vect[i] = X_Vect[i] - dX_Vect[i];
}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  Solve_dX
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ɹ���
//            2.ʹ����LU�ֽ⣬����������
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcProfile::Solve_dX()
{
	CLU::ALU(J_Matrix, F_Vect, dX_Vect, Jdim);
}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  UpdateF_Y
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ɹ���
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcProfile::UpdateF_Y()
{
	for (int i = 0; i < Ydim; i++)
	{
		F_Vect[i] = 0;
		for (int j = 0; j < Ydim; j++)
		{
			F_Vect[i] += J_Matrix[i*Jdim + j] * X_Vect[j];
		}
	}
}
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  UpdateF_IdCtrl��UpdateF_AngCtrl
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ɹ���
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcProfile::UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= pmcStaData[vK_s].Id;
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -pmcStaData[vK_s].Id;
}
void CmcProfile::UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= (pmcStaDataN[vK_s].Pd / pmcStaDataN[vK_m].Pd)*X_Vect[Ydim + vK_m];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -(pmcStaDataN[vK_s].Pd / pmcStaDataN[vK_m].Pd)*X_Vect[Ydim + vK_m];
}
void CmcProfile::UpdateF_PdCtrl(int vK_s, int iNode_s, int jNode_s)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vK_s];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vK_s];

	//Pd-U1Id+U2Id
	double vPd, vU1, vU2, vId;

	vPd = pmcStaData[vK_s].Pd;
	vU1 = X_Vect[iNode_s];
	vU2 = X_Vect[jNode_s];
	vId = dX_Vect[Ydim + vK_s];

	vRow = Ydim + vK_s;
	F_Vect[vRow] = (vPd - (vU1 - vU2)*vId);
}
void CmcProfile::UpdateF_UdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vK_s];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vK_s];

	//Ud-U1+U2
	double vUd, vU1, vU2;

	vUd = pmcStaData[vK_m].Ud;
	vU1 = X_Vect[iNode_m];
	vU2 = X_Vect[jNode_m];

	vRow = Ydim + vK_s;
	F_Vect[vRow] = (vUd - (vU1 - vU2));
}
void CmcProfile::UpdateF_AngCtrl(int vK_s, int iNode_s, int jNode_s, bool isRectifier)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vK_s];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vK_s];

	//Udio*cos(alpha)-(U1-U2)/nT-UT-(dx+dr)/100*UdioN/IdN*Id
	//��Udio*cos(gamma)-(U1-U2)/nT+UT+(dx-dr)/100*UdioN/IdN*Id
	double vUdio, vangle, vU1, vU2, vnT, vUT, vdx, vdr, vUdioN, vIdN, vId;

	vUdio = pmcStaData[vK_s].Udio;
	vangle = pmcStaData[vK_s].alphaOrgamma;
	vU1 = X_Vect[iNode_s];
	vU2 = X_Vect[jNode_s];
	vnT = pmcStaData[vK_s].nT;
	vUT = pmcStaData[vK_s].UT;
	vdx = pmcStaData[vK_s].dx;
	vdr = pmcStaData[vK_s].dr;
	vUdioN = pmcStaDataN[vK_s].Udio;
	vIdN = pmcStaDataN[vK_s].Id;
	vId = dX_Vect[Ydim + vK_s];

	vRow = Ydim + vK_s;
	if (isRectifier)
		F_Vect[vRow] = vUdio*cos(vangle) - (vU1 - vU2) / vnT - vUT - (vdx + vdr) / 100 * vUdioN / vIdN*vId;
	else
		F_Vect[vRow] = vUdio*cos(vangle) - (vU1 - vU2) / vnT + vUT + (vdx - vdr) / 100 * vUdioN / vIdN*vId;
}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  UpdateJ_IdCtrl��UpdateJ_AngCtrl
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.��ɹ���
// �Ķ�ʱ��:  2017/04/18
//************************************
void CmcProfile::UpdateJ_IdCtrl(int vK_s, int  iNode_s, int  jNode_s)
{
	int vRow, vCol;

	//����i
	vRow = iNode_s;
	vCol = Ydim + vK_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//����j
	vRow = jNode_s;
	vCol = Ydim + vK_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1
}

void CmcProfile::UpdateJ_PdCtrl(int vK_s, int iNode_s, int jNode_s)
{
	int vRow, vCol;

	//����i
	vRow = iNode_s;
	vCol = Ydim + vK_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//����j
	vRow = jNode_s;
	vCol = Ydim + vK_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//����i
	vRow = Ydim + vK_s;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -X_Vect[Ydim + vK_s];// -Id[vK]

														  //����j
	vRow = Ydim + vK_s;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +X_Vect[Ydim + vK_s];// +Id[vK]

														  //����
	vRow = Ydim + vK_s;
	vCol = Ydim + vK_s;
	J_Matrix[vRow*Jdim + vCol] = 0;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += -X_Vect[iNode_s];
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += +X_Vect[jNode_s];
}
void CmcProfile::UpdateJ_UdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m) {

	int vRow, vCol;

	//����i
	vRow = iNode_s;
	vCol = Ydim + vK_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//����j
	vRow = jNode_s;
	vCol = Ydim + vK_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//����i
	vRow = Ydim + vK_s;
	vCol = iNode_m;
	if (iNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//����j
	vRow = Ydim + vK_s;
	vCol = jNode_m;
	if (jNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1
}
void CmcProfile::UpdateJ_AngCtrl(int vK_s, int iNode_s, int jNode_s, bool isRectifier)
{
	int vRow, vCol;

	//����i
	vRow = iNode_s;
	vCol = Ydim + vK_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//����j
	vRow = jNode_s;
	vCol = Ydim + vK_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//����i
	vRow = Ydim + vK_s;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1 / pmcStaData[vK_s].nT;// -1/n

															  //����j
	vRow = Ydim + vK_s;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1 / pmcStaData[vK_s].nT;// +1/n

															  //����
	vRow = Ydim + vK_s;
	vCol = Ydim + vK_s;
	int X = 0;
	if (isRectifier)
		X = -(pmcStaData[vK_s].dx + pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	else
		X = +(pmcStaData[vK_s].dx - pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	J_Matrix[vRow*Jdim + vCol] = X;// -(dx+dr)/100*UdioN/IdN �� (dx-dr)/100*UdioN/IdN
}


//void CmcProfile::UpdateF_PdCtrl0(int vK, int iNode)
//{
//
//	int vRow;
//	double vPd, vU1, vU2, vId;
//
//	vU1 = X_Vect[iNode];
//	vU2 = 0;
//
//	//
//	vRow = Ydim + vK;
//	vId = dX_Vect[vRow];//x1=x0+dx
//
//	//
//	vPd = pmcStaData[vK].Pd; //�޿���
//
//	F_Vect[vRow] = (vPd - (vU1 - vU2)*vId);
//}
//
//void CmcProfile::UpdateF_UdCtrl0(int vK, int iNode)
//{
//
//	int vRow;
//	double vU1, vU2;
//	double vUd;
//
//	vU1 = X_Vect[iNode];
//	vU2 = 0;
//
//	//
//	vUd = pmcStaData[vK].Ud; //�޿���
//
//	vRow = Ydim + vK;
//	F_Vect[vRow] = (vUd - (vU1 - vU2));
//}
//
//void CmcProfile::UpdateF_AngCtrl0(int vK, int iNode)
//{
//
//	//�޿���
//	int vRow;
//
//	//
//	vRow = Ydim + vK;
//	//vFVect[vRow]=
//}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  UpdateJ_PdCtrl0��UpdateJ_AngCtrl0
// �Ķ���:    �޿���
// �Ķ�����:  ɾ��
// �Ķ�����:  1.�жϽӵط��ں�������
// �Ķ�ʱ��:  2017/04/18
//************************************
//void CmcProfile::UpdateJ_PdCtrl0(int vK, int iNode)
//{
//
//	//Ҫ�����Ƿ����Ե�ӵ�
//
//	int vRow, vCol;
//
//	//
//	vRow = iNode;
//	vCol = Ydim + vK;
//	J_Matrix[vRow*Jdim + vCol] = -1;
//
//
//	//
//	vRow = Ydim + vK;
//	vCol = iNode;
//	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[Ydim + vK];
//
//
//	//
//	vRow = Ydim + vK;
//	vCol = Ydim + vK;
//	J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode];
//}
//
//void CmcProfile::UpdateJ_UdCtrl0(int vK, int iNode)
//{
//
//	int vRow, vCol;
//
//	//
//	vRow = iNode;
//	vCol = Ydim + vK;
//	J_Matrix[vRow*Jdim + vCol] = -1;
//
//
//	//
//	vRow = Ydim + vK;
//	vCol = iNode;
//	J_Matrix[vRow*Jdim + vCol] = -1;
//
//
//	//
//}
//
//void CmcProfile::UpdateJ_AngCtrl0(int vK, int iNode)
//{
//
//	int vRow, vCol;
//
//	//
//	vRow = iNode;
//	vCol = Ydim + vK;
//	J_Matrix[vRow*Jdim + vCol] = -1;
//
//
//	//
//	vRow = Ydim + vK;
//	vCol = iNode;
//	//J_Matrix[vRow*Jdim + vCol] = -1/n;
//
//
//	//
//	vRow = Ydim + vK;
//	vCol = Ydim + vK;
//	//J_Matrix[vRow*Jdim + vCol] = -dX_Vect[iNode] + dX_Vect[jNode];
//
//	//�޿���
//}



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

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  InitX_Y
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.������Ӳ�Ӧ����ÿ��ȡ�����ʱ�����裬��ԭ�ȵ�srand(time(0));�Ƶ�CmcProfile�ֻ��ѭ������Calǰ����һ�������趨
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcProfile::InitX_Y(int vNode, double vUnode)
{
	//�޿���2014-4-15
	//����������ֵ
	X_Vect[vNode] = vUnode + (rand() % 3000) / 100.0 - 15;

}
void CmcProfile::InitX_I(int vK, double vId)
{
	//�޿���2014-4-15
	int vRow = Ydim + vK;
	//����������ֵ
	X_Vect[vRow] = vId + (rand() % 200) / 100.0 - 1;

}
void CmcProfile::UpdateConvertor_DC(int vK, bool isRectifier)
{
	double vUd, vId, vAngle;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	if (isRectifier)
		pmcStaData[vK].Udio = (vUd / nT + UT + (dx + dr) / 100 * vId / Id_N *Udio_N) / cos(vAngle);
	else
		pmcStaData[vK].Udio = (vUd / nT - UT + (dx - dr) / 100 * vId / Id_N *Udio_N) / cos(vAngle);
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - vAngle;
	pmcStaData[vK].Uv = M_PI / 3 / sqrt(2.0)*pmcStaData[vK].Udio;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(vAngle + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * vAngle) - sin(2 * (vAngle + pmcStaData[vK].miu))) / (4 * (cos(vAngle) - cos(vAngle + pmcStaData[vK].miu)));

}
void CmcProfile::UpdateConvertor_AC(int vK, bool isRectifier)
{
	double vUv, vId, vAngle;
	vUv = pmcStaData[vK].Uv;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*vUv;
	if (isRectifier)
		pmcStaData[vK].Ud = nT*(pmcStaData[vK].Udio*cos(vAngle) - UT - (dx + dr) / 100 * vId / Id_N*Udio_N);
	else
		pmcStaData[vK].Ud = nT*(pmcStaData[vK].Udio*cos(vAngle) + UT - (dx - dr) / 100 * vId / Id_N*Udio_N);
	pmcStaData[vK].Pd = pmcStaData[vK].Ud*vId;
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - vAngle;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(vAngle + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * vAngle) - sin(2 * (vAngle + pmcStaData[vK].miu))) / (4 * (cos(vAngle) - cos(vAngle + pmcStaData[vK].miu)));

}
void CmcProfile::UpdateConvertor_Port(int vK, bool isRectifier)
{
	double vUd, vId, vUv;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vUv = pmcStaData[vK].Uv;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*vUv;
	if (isRectifier)
		pmcStaData[vK].alphaOrgamma = acos((vUd / nT + UT + (dx + dr) / 100 * vId / Id_N*Udio_N) / pmcStaData[vK].Udio);
	else
		pmcStaData[vK].alphaOrgamma = acos((vUd / nT - UT + (dx - dr) / 100 * vId / Id_N*Udio_N) / pmcStaData[vK].Udio);
	pmcStaData[vK].miu = acos(cos(pmcStaData[vK].alphaOrgamma) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - pmcStaData[vK].alphaOrgamma;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * pmcStaData[vK].alphaOrgamma) - sin(2 * (pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu))) / (4 * (cos(pmcStaData[vK].alphaOrgamma) - cos(pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu)));

}

void CmcProfile::UpdateXf2_l(int vK)
{
	double vUl, vTC;
	vUl = pmcStaData[vK].Uac;
	vTC = pmcStaData[vK].TC;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Uv = vUl / (Nnom*(1 + vTC*deltaK / 100));
}
void CmcProfile::UpdateXf2_v(int vK)
{
	double vUv, vTC;
	vUv = pmcStaData[vK].Uv;
	vTC = pmcStaData[vK].TC;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Uac = vUv * (Nnom*(1 + vTC*deltaK / 100));
}
void CmcProfile::UpdateXf2_Port(int vK)
{
	double vUv, vUl;
	vUl = pmcStaData[vK].Uac;
	vUv = pmcStaData[vK].Uv;
	double TC, deltaK;
	TC = pmcStaData[vK].TC;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Nnom = vUl / vUv / (1 + TC*deltaK / 100);

}
void CmcProfile::UpdateXf2_UpShift(int vK)
{
	double vUl;
	vUl = pmcStaData[vK].Uac;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].TC += 1;
	pmcStaData[vK].Uv = vUl / (Nnom*(1 + pmcStaData[vK].TC*deltaK / 100));
}
void CmcProfile::UpdateXf2_DownShift(int vK)
{
	double vUl;
	vUl = pmcStaData[vK].Uac;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].TC -= 1;
	pmcStaData[vK].Uv = vUl / (Nnom*(1 + pmcStaData[vK].TC*deltaK / 100));
}

void CmcProfile::UpdateACSide(int vK)
{
	pmcStaData[vK].Qf_max = pmcStaData[vK].Qconv + pmcStaData[vK].QacOutMax;
	pmcStaData[vK].Qf_min = pmcStaData[vK].Qconv - pmcStaData[vK].QacInMax;
}

void CmcProfile::CalStation()
{	
	for (int i = 0; i < kDim; i++)
	{
		//pmcStaData[i]
	}
}