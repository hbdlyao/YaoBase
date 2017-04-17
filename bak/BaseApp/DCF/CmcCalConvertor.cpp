///////////////////////////////////////////////////////////
//  CmcCalConvertor.cpp
//  Implementation of the Class CmcCalConvertor
//  Created on:      02-4月-2017 14:42:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalConvertor.h"

void CmcCalConvertor::CalConvertor()
{


}

void CmcCalConvertor::CalConvertorNormal()
{
	int vK = 0;
	int vType;
	double vX;

	CmcDevConvertor * vDev;

	//崔康生
	vK = StationIndex;
	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
		
	//
	vX = pmcProfile->pmcStaData[vK].Ud;
	vDev->SetUdN(vX);

	vX = pmcProfile->pmcStaData[vK].Id;
	vDev->SetIdN(vX);

	//
	vType = vDev->GetStationType();
	switch (vType)
	{
	case Hvdc_Rectify:
		pmcProfile->UpdateR_UN(vK);

		vX=pmcProfile->pmcStaDataN[vK].Udio ;
		vDev->SetUdioN(vX);

		vX=pmcProfile->pmcStaDataN[vK].Uv;
		vDev->SetUvN(vX);
	
		break;
		
	case Hvdc_Invertor:

		pmcProfile->UpdateI_UN(vK);

		vX = pmcProfile->pmcStaDataN[vK].Udio;
		vDev->SetUdioN(vX);

		vX = pmcProfile->pmcStaDataN[vK].Uv;
		vDev->SetUvN(vX);

		break;

	default:
		break;
		}//switch
	 
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Prepare
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.完成了函数功能(数据填充)
// 改动时间:  2017/04/14
//************************************
void CmcCalConvertor::Prepare()
{
	//崔康生2014-4-15

	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//参数
	pmcProfile->pmcStaData[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaData[vK].Ang_Min = vDev->GetAngleMin();

	if (vDev->GetUdN() > pmcProfile->pmcStaData[vK].Ud_Max)
		pmcProfile->pmcStaData[vK].Ud_Max = vDev->GetUdN();

	if (vDev->GetStationCtrlType() == StaCtrl_ConstantAngle)
		pmcProfile->pmcStaData[vK].alphaOrgamma = vDev->GetAngleRef(); 
	else
		pmcProfile->pmcStaData[vK].alphaOrgamma = vDev->GetAlpha_gamaN();

	//指令相关
	pmcProfile->pmcStaData[vK].PdPer = pmcProfile->pmcOrder->PdPer;
	pmcProfile->pmcStaData[vK].nValNum = pmcProfile->pmcOrder->nValNum;
	if (pmcProfile->pmcOrder->GroundType == mc_Ground20 || pmcProfile->pmcOrder->GroundType == mc_Ground21)
		pmcProfile->pmcStaData[vK].nPoleNum = 2;
	else
		pmcProfile->pmcStaData[vK].nPoleNum = 1;
	
	//指令相关(冗余)
	switch (pmcProfile->pmcOrder->UdLevel)
	{
	case  Ud_Per80:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.8;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.8;
		break;
	case  Ud_Per70:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.7;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.7;
		break;
	default:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN();
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN();
		break;
	}
	

	pmcProfile->pmcStaData[vK].Id = vDev->GetPdN() / vDev->GetUdN()*pmcProfile->pmcOrder->PdPer / 100.0;
	pmcProfile->pmcStaData[vK].Pd = vDev->GetPdN()*pmcProfile->pmcOrder->PdPer / 100.0;


}



void CmcCalConvertor::InitX()
{
	//崔康生2014-4-15

	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	pmcProfile->InitX_Y(vDev->GetNodeID(0), vDev->GetUdN());
	if (vDev->GetNodeID(1) != -1)
		pmcProfile->InitX_Y(vDev->GetNodeID(1), 0);
	pmcProfile->InitX_I(vK, 3);

}


void CmcCalConvertor::PrepareNormal() 
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//崔康生
	//Yao

	//额定值
	pmcProfile->pmcStaDataN[vK].nValNum = vDev->GetValvor12Count();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();

	pmcProfile->pmcStaDataN[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaDataN[vK].Pd = vDev->GetPdN();
	pmcProfile->pmcStaDataN[vK].Ud = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].Id = vDev->GetIdN();

	pmcProfile->pmcStaDataN[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaDataN[vK].dr = vDev->GetdrN();
	pmcProfile->pmcStaDataN[vK].dx = vDev->GetdxN();

	pmcProfile->pmcStaDataN[vK].alphaOrgamma = vDev->GetAlpha_gamaN();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = vDev->GetAngleMin();

}

void CmcCalConvertor::UpdateJ()
{
	int vK = 0;
	CmcDevConvertor * vDev;
	
	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);	
	switch (vDev->GetStationCtrlType())
	{
	case StaCtrl_ConstantId:
		//doUpdateJ_IdCtrl(vK,vDev);
		break;
	
	case StaCtrl_ConstantPd:
		doUpdateJ_PdCtrl(vK,vDev);			
		break;
	
	case StaCtrl_ConstantUd:
		doUpdateJ_UdCtrl(vK,vDev);
		break;
	
	case StaCtrl_ConstantAngle:
		doUpdateJ_AngCtrl(vK, vDev);
		break;

	case StaCtrl_TrackId:
		//doUpdateJ_AngCtrl(vK, vDev);
		break;


	default:
		break;
	}// switch
	
}


void CmcCalConvertor::doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode==-1) //不接地
		pmcProfile->UpdateJ_PdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_PdCtrl(vK, iNode, jNode);

}


void CmcCalConvertor::doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //接地
		pmcProfile->UpdateJ_UdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_UdCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //接地
		pmcProfile->UpdateJ_AngCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_AngCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::UpdateF_J()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	switch (vDev->GetStationCtrlType())
	{
	case StaCtrl_ConstantId:
		//doUpdateF_IdCtrl(vK,vDev);
		break;

	case StaCtrl_ConstantPd:
		doUpdateF_PdCtrl(vK, vDev);
		break;

	case StaCtrl_ConstantUd:
		doUpdateF_UdCtrl(vK, vDev);
		break;

	case StaCtrl_ConstantAngle:
		doUpdateF_AngCtrl(vK, vDev);
		break;

	case StaCtrl_TrackId:
		//doUpdateF_AngCtrl(vK, vDev);
		break;


	default:
		break;
	}// switch

}


void CmcCalConvertor::doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	

	if (jNode == -1) //接地
		pmcProfile->UpdateF_PdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_PdCtrl(vK, iNode, jNode);

}


void CmcCalConvertor::doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //接地
		pmcProfile->UpdateF_UdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_UdCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //接地
		pmcProfile->UpdateF_AngCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_AngCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::NodeGround(NodeMap & vNodeMap)
{
	bool vGround;
	string vName;
	CmcDevConvertor  * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	//双极
	vGround = pmcProfile->IsBiPole();
	if (vGround)
	{
		vName = vDev->GetNodeName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

	//金属回线
	vGround = pmcProfile->IsMetalLine();
	vGround = vGround && (vDev->GetIsGround() == 1);
	if (vGround)
	{
		vName = vDev->GetNodeName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

}


