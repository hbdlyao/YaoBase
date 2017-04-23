///////////////////////////////////////////////////////////
//  CmcProfile.cpp
//  Implementation of the Class CmcProfile
//  Created on:      10-4月-2017 0:54:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcProfile.h"
#include "time.h"
#include "CLU.h"
#include "CMatrix.h"

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

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  ResetMatrix
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.根据offsetDim重设矩阵维数
// 改动时间:  2017/04/20
//************************************
void CmcProfile::ResetMatrix(int vOffsetDim)
{
	Jdim = Ydim + vOffsetDim;
	//
	doInitMatrix();
}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doInitMatrix
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.以下内容转移到doInitData里
//					pmcStaData = new struct_mcStationData[StaDim];
//                  pmcStaDataN = new struct_mcStationData[StaDim];
//            2.矩阵置零从doInitData转移到本方法
// 改动时间:  2017/04/20
//************************************
void CmcProfile::doInitMatrix()
{
	delete[] J_Matrix;
	delete[] F_Vect;
	delete[] X_Vect;
	delete[] dX_Vect;
	//
	J_Matrix = new double[Jdim*Jdim];
	F_Vect = new double[Jdim];
	X_Vect = new double[Jdim];
	dX_Vect = new double[Jdim];


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
	//////////////////////////////////////////////////////
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doInitMatrix
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.以下从doInitMatrix内容转移到本方法
//					pmcStaData = new struct_mcStationData[StaDim];
//                  pmcStaDataN = new struct_mcStationData[StaDim];
// 改动时间:  2017/04/20
//************************************
void CmcProfile::doInitData()
{
	int i;
	//
	pmcStaData = new struct_mcStationData[StaDim];
	//
	pmcStaDataN = new struct_mcStationData[StaDim];
	//
	Ud_Max = 0;//++--
	URefStation = -1;//++--
	URefNode[0] = -1;//++--
	URefNode[1] = -1;//++--
	for (i = 0; i < StaDim; i++)
	{
		pmcStaData[i].alphaOrgamma = 0;
		pmcStaData[i].Ang_Min = 0;
		pmcStaData[i].AngCtrl_Max = 0;
		pmcStaData[i].AngCtrl_Min = 0;
		pmcStaData[i].ConvertorType = 0;
		pmcStaData[i].deltaK = 0;
		pmcStaData[i].dr = 0;
		pmcStaData[i].dx = 0;
		pmcStaData[i].Id = 0;
		pmcStaData[i].miu = 0;
		pmcStaData[i].Nnom = 0;
		pmcStaData[i].nPoleNum = 0;
		pmcStaData[i].nT = 0;
		pmcStaData[i].Pconv = 0;
		pmcStaData[i].Pd = 0;
		pmcStaData[i].PdPer = 0;
		pmcStaData[i].QacInMax = 0;
		pmcStaData[i].QacOutMax = 0;
		pmcStaData[i].Qconv = 0;
		pmcStaData[i].Qf_max = 0;
		pmcStaData[i].Qf_min = 0;
		pmcStaData[i].StationName = "";
		pmcStaData[i].Tap_Max = 0;
		pmcStaData[i].Tap_Min = 0;
		pmcStaData[i].TapCtrlType = 0;
		pmcStaData[i].TC = 0;
		pmcStaData[i].Uac = 0;
		pmcStaData[i].Ud = 0;
		pmcStaData[i].Udio = 0;
		pmcStaData[i].UdL = 0;
		pmcStaData[i].UT = 0;
		pmcStaData[i].Uv = 0;
		pmcStaData[i].Uv_Max = 0;

		pmcStaDataN[i].alphaOrgamma = 0;
		pmcStaDataN[i].Ang_Min = 0;
		pmcStaDataN[i].AngCtrl_Max = 0;
		pmcStaDataN[i].AngCtrl_Min = 0;
		pmcStaDataN[i].ConvertorType = 0;
		pmcStaDataN[i].deltaK = 0;
		pmcStaDataN[i].dr = 0;
		pmcStaDataN[i].dx = 0;
		pmcStaDataN[i].Id = 0;
		pmcStaDataN[i].miu = 0;
		pmcStaDataN[i].Nnom = 0;
		pmcStaDataN[i].nPoleNum = 0;
		pmcStaDataN[i].nT = 0;
		pmcStaDataN[i].Pconv = 0;
		pmcStaDataN[i].Pd = 0;
		pmcStaDataN[i].PdPer = 0;
		pmcStaDataN[i].QacInMax = 0;
		pmcStaDataN[i].QacOutMax = 0;
		pmcStaDataN[i].Qconv = 0;
		pmcStaDataN[i].Qf_max = 0;
		pmcStaDataN[i].Qf_min = 0;
		pmcStaDataN[i].StationName = "";
		pmcStaDataN[i].Tap_Max = 0;
		pmcStaDataN[i].Tap_Min = 0;
		pmcStaDataN[i].TapCtrlType = 0;
		pmcStaDataN[i].TC = 0;
		pmcStaDataN[i].Uac = 0;
		pmcStaDataN[i].Ud = 0;
		pmcStaDataN[i].Udio = 0;
		pmcStaDataN[i].UdL = 0;
		pmcStaDataN[i].UT = 0;
		pmcStaDataN[i].Uv = 0;
		pmcStaDataN[i].Uv_Max = 0;
	}

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  ResetData
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.删除矩阵置零的功能，每次调用ResetMatrix都会执行置零
// 改动时间:  2017/04/20
//************************************
void CmcProfile::ResetData()
{
	Ud_Max = 0;//++--
	URefStation = -1;//++--
	URefNode[0] = -1;//++--
	URefNode[1] = -1;//++--
	int i;
	//
	for (i = 0; i < StaDim; i++)
	{
		pmcStaData[i].alphaOrgamma = 0;
		pmcStaData[i].Ang_Min = 0;
		pmcStaData[i].AngCtrl_Max = 0;
		pmcStaData[i].AngCtrl_Min = 0;
		pmcStaData[i].ConvertorType = 0;
		pmcStaData[i].deltaK = 0;
		pmcStaData[i].dr = 0;
		pmcStaData[i].dx = 0;
		pmcStaData[i].Id = 0;
		pmcStaData[i].miu = 0;
		pmcStaData[i].Nnom = 0;
		pmcStaData[i].nPoleNum = 0;
		pmcStaData[i].nT = 0;
		pmcStaData[i].Pconv = 0;
		pmcStaData[i].Pd = 0;
		pmcStaData[i].PdPer = 0;
		pmcStaData[i].QacInMax = 0;
		pmcStaData[i].QacOutMax = 0;
		pmcStaData[i].Qconv = 0;
		pmcStaData[i].Qf_max = 0;
		pmcStaData[i].Qf_min = 0;
		pmcStaData[i].StationName = "";
		pmcStaData[i].Tap_Max = 0;
		pmcStaData[i].Tap_Min = 0;
		pmcStaData[i].TapCtrlType = 0;
		pmcStaData[i].TC = 0;
		pmcStaData[i].Uac = 0;
		pmcStaData[i].Ud = 0;
		pmcStaData[i].Udio = 0;
		pmcStaData[i].UdL = 0;
		pmcStaData[i].UT = 0;
		pmcStaData[i].Uv = 0;
		pmcStaData[i].Uv_Max = 0;
	}

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Init_XVect
// 改动者:    崔康生
// 改动类型:  删除
// 改动内容:  1.由InitX_Y和InitX_I连个函数完成
// 改动时间:  2017/04/20
//************************************
//void CmcProfile::Init_XVect()
//{
//
//	//给定迭代初值；
//
//	//崔康生
//	//Yao
//
//}


void CmcProfile::UpdateY0(int iNode, double vY)
{

	double vX;

	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
}


void CmcProfile::UpdateY(int iNode, int jNode, double vY) {

	double vX;

	//
	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
	//
	vX = J_Matrix[jNode*Jdim + jNode];
	J_Matrix[jNode*Jdim + jNode] = vX + vY;

	//
	vX = J_Matrix[iNode*Jdim + jNode];
	J_Matrix[iNode*Jdim + jNode] = vX - vY;
	J_Matrix[jNode*Jdim + iNode] = vX - vY;

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
// *南方电网主回路及谐波计算软件*
// 改动对象:  doSaveX
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.保存doSovleDcNet的计算结果
// 改动时间:  2017/04/20
//************************************
void CmcProfile::SaveX(int vOffset, int vK_s, int iNode_s, int jNode_s)
{
	double vUd, vId;
	vUd = 0;
	if (iNode_s != -1)
		vUd += +X_Vect[iNode_s];
	if (jNode_s != -1)
		vUd += -X_Vect[jNode_s];

	vId = 0;
	for (int i = 0; i < Ydim; i++)
		vId += J_Matrix[iNode_s*Jdim + i] * X_Vect[i];

	pmcStaData[vK_s].Ud = vUd;
	pmcStaData[vK_s].Id = vId;
}
void CmcProfile::UpdateX()
{
	for (int i = 0; i < Jdim; i++)
		X_Vect[i] = X_Vect[i] - dX_Vect[i];
}

void CmcProfile::Solve_dX()
{
	CMatrix J_inv = CMatrix(Jdim);
	for (int i = 0; i < Jdim; i++)
		for (int j = 0; j < Jdim; j++)
			J_inv._mat[i][j] = J_Matrix[i*Jdim + j];

	J_inv = J_inv.inversion();

	for (int i = 0; i < Jdim; i++)
	{
		dX_Vect[i] = 0;
		for (int j = 0; j < Jdim; j++)
			dX_Vect[i] += J_inv._mat[i][j].real() * F_Vect[j];
	}

}

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
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateF_PdCtrl至UpdateF_AngCtrl
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.增加参数vOffset
//			  2.有一部分F_Vect没有检查Nodei/j是否为-1，修正了该Bug
// 改动时间:  2017/04/20
//************************************
void CmcProfile::UpdateF_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	//Pd-U1Id+U2Id
	double vPd, vU1, vU2, vId;

	vPd = pmcStaData[vK_s].Pd;
	vU1 = X_Vect[iNode_s];
	vU2 = X_Vect[jNode_s];
	vId = X_Vect[Ydim + vOffset];

	vRow = Ydim + vOffset;
	F_Vect[vRow] = vPd;
	if (iNode_s != -1)
		F_Vect[vRow] += -vU1*vId;
	if (jNode_s != -1)
		F_Vect[vRow] += +vU2*vId;
}
void CmcProfile::UpdateF_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	//Ud-U1+U2
	double vUd, vU1, vU2;

	vUd = pmcStaData[vK_m].Ud;
	vU1 = X_Vect[iNode_m];
	vU2 = X_Vect[jNode_m];

	vRow = Ydim + vOffset;
	F_Vect[vRow] = vUd;
	if (iNode_m != -1)
		F_Vect[vRow] += -vU1;
	if (jNode_m != -1)
		F_Vect[vRow] += +vU2;
}
void CmcProfile::UpdateF_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier)
{
	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	//Udio*cos(alpha)-(U1-U2)/nT-UT-(dx+dr)/100*UdioN/IdN*Id
	//或Udio*cos(gamma)-(U1-U2)/nT+UT+(dx-dr)/100*UdioN/IdN*Id
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
	vId = X_Vect[Ydim + vOffset];

	vRow = Ydim + vOffset;
	if (isRectifier)
		F_Vect[vRow] = vUdio*cos(vangle) - vUT - (vdx + vdr) / 100 * vUdioN / vIdN*vId;
	else
		F_Vect[vRow] = vUdio*cos(vangle) + vUT + (vdx - vdr) / 100 * vUdioN / vIdN*vId;
	if (iNode_s != -1)
		F_Vect[vRow] += -vU1 / vnT;
	if (jNode_s != -1)
		F_Vect[vRow] += +vU2 / vnT;
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateJ_IdCtrl
// 改动者:    崔康生
// 改动类型:  删除
// 改动内容:  1.
// 改动时间:  2017/04/20
//************************************
//void CmcProfile::UpdateJ_IdCtrl(int vK_s, int  iNode_s, int  jNode_s)
//{
//	int vRow, vCol;
//
//	//右上i
//	vRow = iNode_s;
//	vCol = Ydim + vK_s;
//	if (iNode_s != -1)
//		J_Matrix[vRow*Jdim + vCol] = -1;// -1
//
//	//右上j
//	vRow = jNode_s;
//	vCol = Ydim + vK_s;
//	if (jNode_s != -1)
//		J_Matrix[vRow*Jdim + vCol] = +1;// +1
//}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateJ_PdCtrl至UpdateJ_AngCtrl
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.增加参数vOffset
// 改动时间:  2017/04/20
//************************************
void CmcProfile::UpdateJ_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s)
{
	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -X_Vect[Ydim + vOffset];// -Id[vK]

															 //左下j
	vRow = Ydim + vOffset;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +X_Vect[Ydim + vOffset];// +Id[vK]

															 //右下
	vRow = Ydim + vOffset;
	vCol = Ydim + vOffset;
	J_Matrix[vRow*Jdim + vCol] = 0;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += -X_Vect[iNode_s];
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += +X_Vect[jNode_s];
}
void CmcProfile::UpdateJ_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m) {

	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_m;
	if (iNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//左下j
	vRow = Ydim + vOffset;
	vCol = jNode_m;
	if (jNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1
}

void CmcProfile::UpdateJ_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, bool isRectifier)
{
	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

										//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

										//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1 / pmcStaData[vK_s].nT;// -1/n

															  //左下j
	vRow = Ydim + vOffset;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1 / pmcStaData[vK_s].nT;// +1/n

															  //右下
	vRow = Ydim + vOffset;
	vCol = Ydim + vOffset;
	double X = 0;
	if (isRectifier)
		X = -(pmcStaData[vK_s].dx + pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	else
		X = +(pmcStaData[vK_s].dx - pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	J_Matrix[vRow*Jdim + vCol] = X;// -(dx+dr)/100*UdioN/IdN 或 (dx-dr)/100*UdioN/IdN
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
	//给定迭代初值
	X_Vect[vNode] = vUnode + (rand() % 3000) / 100.0 - 15;

}
void CmcProfile::InitX_I(int vK, double vId)
{
	int vRow = Ydim + vK;
	//给定迭代初值
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

void CmcProfile::UpdateUdio()//++--
{
	for (int i = 0; i < StaDim; i++)
		UpdateUdio(i);
}
void CmcProfile::UpdateUdio(int vK)//++--
{
	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*pmcStaData[vK].Uv;
}
bool CmcProfile::IsTapUpAble(int vK)//++--
{
	if (pmcStaData[vK].TapCtrlType == xfCtrl_ConstantUv)
		return false;
	if (pmcStaData[vK].TC >= pmcStaData[vK].Tap_Max)
		return false;
	if (pmcStaData[vK].Uac / (pmcStaData[vK].Nnom*(1 + (pmcStaData[vK].TC + 1)*pmcStaData[vK].deltaK / 100))>pmcStaData[vK].Uv_Max)
		return false;
	return true;
}
bool CmcProfile::IsTapDownAble(int vK)//++--
{
	if (pmcStaData[vK].TapCtrlType == xfCtrl_ConstantUv)
		return false;
	if (pmcStaData[vK].TC <= pmcStaData[vK].Tap_Min)
		return false;
	if (pmcStaData[vK].Uac / (pmcStaData[vK].Nnom*(1 + (pmcStaData[vK].TC - 1)*pmcStaData[vK].deltaK / 100)) > pmcStaData[vK].Uv_Max)
		return false;
	return true;
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateConvertor_N
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.额定计算用
// 改动时间:  2017/04/20
//************************************
void CmcProfile::UpdateConvertor_N(int vK, bool isRectifier)
{
	double vUd, vId, vAngle;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	if (isRectifier)
		pmcStaData[vK].Udio = (vUd / nT + UT) / (cos(vAngle) - (dx + dr) / 100);
	else
		pmcStaData[vK].Udio = (vUd / nT - UT) / (cos(vAngle) - (dx - dr) / 100);
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * pmcStaData[vK].Udio / pmcStaData[vK].Udio) - vAngle;
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

void CmcProfile::UpdateXf2_N(int vK)//++--
{
	double vUv, vUl;
	vUl = pmcStaData[vK].Uac;
	vUv = pmcStaData[vK].Uv;
	double TC, deltaK;
	TC = pmcStaData[vK].TC;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Nnom = vUl / vUv / (1 + TC*deltaK / 100);

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
void CmcProfile::UpdateXf2_Port(int vK)//++--
{
	double vUv, vUl;
	vUl = pmcStaData[vK].Uac;
	vUv = pmcStaData[vK].Uv;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	if ((100 / deltaK*(vUl / Nnom / vUv - 1)) >= 0)
		pmcStaData[vK].TC = (int)(0.5 + (100 / deltaK*(vUl / Nnom / vUv - 1)));//“0.5+”：四舍五入
	else
		pmcStaData[vK].TC = (int)(-0.5 + (100 / deltaK*(vUl / Nnom / vUv - 1)));//“0.5+”：四舍五入
	UpdateXf2_l(vK);

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
