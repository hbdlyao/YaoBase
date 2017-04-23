///////////////////////////////////////////////////////////
//  CMyInitApp.cpp
//  Implementation of the Class CMyInitApp
//  Created on:      25-3��-2017 17:19:15
//  Original author: Administrator
///////////////////////////////////////////////////////////
#include "CMyInitApp.h"

#include "CMyParams.h"
#include "gbHead_SysVar.h"


void CMyInitApp::Init()
{
	CMyParams::Init();
	CMyParams::Init();
	CMyVars::Init();

	//
	CMyMvcs::Init();

}

void CMyInitApp::Clear() {
	//�������(�Ӷ���)

	CMyVars::Clear();

	CMyMvcs::Clear();

}

void CMyInitApp::Release()
{
	//������ݱ�

	CMyVars::Release();
	CMyMvcs::Release();

}

void CMyInitApp::Close() {

	//
	Save();

	//
	Clear();

}


void CMyInitApp::Exit()
{
	//
	Save();

	//
	Release();

}
bool CMyInitApp::ReOpen()
{
	bool vOk = false;
	//�ر����й���
	Close();

	//��ʼ������
	//ReInit();

	//���´�ѡ������
	vOk = Open();

	return vOk;

}

bool CMyInitApp::ReNew()
{
	bool vOk = false;

	//�ر����й���
	Close();

	//��ʼ������
	//ReInit();

	//���´�ѡ������
	vOk = New();

	return vOk;

}

bool CMyInitApp::New() {

	bool vOk = true;
	return vOk;
	/*
	vOk=gbShowMvc.ShowNew();
	if vOk then
	begin
	gbcfg.IsEditing=true;
	end;

	Result=vOk;
	*/
}


bool CMyInitApp::Open() {

	bool vOk = true;

	//
	CMyMvcs::RwMvc.OnLoad();

	//
	return vOk;
	/*
	vOk=gbShowMvc.ShowOpen();//svag

	if vOk then
	begin
	vFile=gbCfg.PRJFile;
	//
	gbPRJMVC.OnLoad();
	//
	gbRw.OnLoad();

	gbCfg.IsExist=true;
	gbcfg.IsEditing=true;

	end;

	Result=vOk;
	*/
}


bool CMyInitApp::Save() {

	bool vOk = true;

	CMyMvcs::RwMvc.OnSave();

	return vOk;
	/*

	if gbCfg.IsExist then
	vOk=gbShowMvc.ShowSave()
	else
	vOk=gbShowMvc.ShowSaveAs();

	/////////////////////
	if vOk then
	begin
	vFile=gbCfg.PRJFile;
	if not FileExists(vFile) then
	NewPRJFile(vFile);

	//
	gbPrjMvc.OnSave();
	//
	//gbRw.OnSave();    //2013-4-3 by yao

	//
	gbCfg.IsExist=true;

	end;

	result=vOk;
	*/
}


bool CMyInitApp::SaveAs() {

	bool vOk = true;

	//
	CMyMvcs::RwMvc.OnSave();


	return vOk;
	/*
	vOk=gbShowMvc.ShowSaveAs();
	if vOk then
	begin
	vFile=gbCfg.PRJFile;
	if not FileExists(vFile) then
	NewPRJFile(vFile);
	//
	gbPrjMvc.OnSave(vFile);
	//
	gbRw.OnSave();

	end;

	result=vOk;
	*/
}


bool CMyInitApp::IsSave() {

	bool vOk = true;
	return vOk;
	/*
	if gbPrjMvc.IsEditing then
	begin
	vRes=msg_Question('��Ҫ�˳������Ƿ񱣴����ݣ�');//,'��ʾ',MB_DEFBUTTON1);

	case vRes of
	mrYes   :   gbCFG.IsContinue=true;
	mrNo     :  gbCFG.IsContinue=true;
	mrCancel :  gbCFG.IsContinue=false;
	end;

	end;//if

	//
	result=(vRes=mrYes);
	*/
}


void CMyInitApp::Help(int vID) {

	//vStr=gbcfg.helpPath+'Hvdc.hlp';
	//WinHelp(Application.MainForm.Handle,PChar(vStr),HELP_CONTEXT,vID);
}