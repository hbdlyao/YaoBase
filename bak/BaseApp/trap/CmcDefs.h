#pragma once


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  struct_mcData
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.struct_mcStation����Ϊstruct_mcData
//            2.������������ݳ�Ա
// �Ķ�ʱ��:  2017/04/12
//************************************
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  struct_mcStation
// �Ķ���:    �޿���
// �Ķ�����:  
// �Ķ�����:  1.struct_mcData����Ϊstruct_mcStation
//            2.ȡ��CaseId��Ա
// �Ķ�ʱ��:  2017/04/13
//************************************
struct struct_mcStationData
{
public:
	//������е�����
	string StationName;//վ��

	double PdPer;//����ˮƽ
	double Uac;//������ѹ
	double Uv;//�����ѹ
	double Udio;//�������ֱ����ѹ
	double Ud;//ֱ���˿ڵ�ѹ
	double UdL;//ֱ���˿ڶԵص�ѹ
	double Id;//ֱ������
	double Pd;//ֱ������
	double Pconv;//�������й�
	double Qconv;//�������޹�
	double TC;//��ѹ���ֽ�ͷ��λ
	double alphaOrgamma;//������/�ضϽ�
	double miu;//�����
	double Qf_max;//�˲����ṩ������޹�
	double Qf_min;//�˲����ṩ����С�޹�

				  //������Ҫ�õ��Ĳ���������HVDC�豸��
	int nValNum;//12����������
	int nPoleNum;//������˫���򵥼���
	double UT;//6�����ŵ�ѹ��
	double dr;//���Ի���ѹ��
	double dx;//���Ի���ѹ��
	double deltaK;//��ѹ��ÿ���ĵ�ѹ�ٷֱ�
	double QacInMax;//����ϵͳ�����յ�����޹�
	double QacOutMax;//����ϵͳ�ɷ���������޹�

					 //������Ҫ�õ��Ĳ���������HVDC�豸������ֵ
	double AngCtrl_Max;//�ֽ�ͷ�����л�����������/�ضϽǵ�����
	double AngCtrl_Min;//�ֽ�ͷ�����л�����������/�ضϽǵ�����
	double Tap_Max;//�ֽ�ͷ���λ
	double Tap_Min;//�ֽ�ͷ��С��λ
	double Ang_Min;//������������/�ضϽǵ���Сֵ
	double Uv_Max;//�����ѹ��������ֵ
	double Ud_Max;//ֱ����ѹ��������ֵ
				  //������Ҫ�õ��Ĳ������������
	double Nnom;//��ѹ������
};

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  struct_mcResultData
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.������֯�������
//            2.struct_mcStationData��struct_mcResultData�ָ�����
// �Ķ�ʱ��:  2017/04/13
//************************************
struct struct_mcResultData
{
public:
	string CaseId;
	string StationName;//վ��

	double PdPer;//����ˮƽ
	double Uac;//������ѹ
	double Uv;//�����ѹ
	double Uv_N;//�����ѹ�ֵ
	double Udio;//�������ֱ����ѹ
	double Udio_N;//�������ֱ����ѹ�ֵ
	double Ud;//ֱ���˿ڵ�ѹ
	double UdL;//ֱ���˿ڶԵص�ѹ
	double Id;//ֱ������
	double Pd;//ֱ������
	double Pconv;//�������й�
	double Qconv;//�������޹�
	double TC;//��ѹ���ֽ�ͷ��λ
	double alphaOrgamma;//������/�ضϽ�
	double miu;//�����
	double Qf_max;//�˲����ṩ������޹�
	double Qf_min;//�˲����ṩ����С�޹�

	double Nnom;//��ѹ������
};

typedef map<string, struct_mcResultData> mc_ResultMap;

/////////////////////////////////////////////////////////////

enum Enum_HvdcConvertorType
{
	Hvdc_Rectify = 0,
	Hvdc_Invertor = 1,

};


enum Enum_mcGroundType
{
	mc_Ground10 = 10,
	mc_Ground11 = 11,
	mc_Ground20 = 20,
	mc_Ground21 = 21

};

enum Enum_mcDeviceType
{
	mc_AcSys = 11,
	mc_AcF,
	mc_Xf2,
	mc_Convertor,
	mc_DcLine,
	mc_GroundLine,
	mc_MetalLine,
	mc_Ground

};




//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  Enum_mcUdLevel��Enum_mcRdLevel��Enum_mcUacLevel
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.���ڱ�ʶ����
// �Ķ�ʱ��:  2017/04/13
//************************************

enum Enum_mcUdLevel
{
	Ud_Full = 0,
	Ud_Per80,
	Ud_Per70,
	Ud_Custom
};
enum Enum_mcRdLevel
{
	Rd_High = 0,
	Rd_Low
};

enum Enum_mcUacLevel
{
	Uac_Max = 0,
	Uac_Norm,
	Uac_Min,
	Uac_ExMin
};


const int mc_GndTypeArr[] = { mc_Ground10 ,mc_Ground11 ,mc_Ground20 ,mc_Ground21 };
const int mc_RdLevelArr[] = { Rd_High ,Rd_Low };
const int mc_UdLevelArr[] = { Ud_Full ,Ud_Per80,Ud_Per70,Ud_Custom };
const int mc_UacLevelArr[] = { Uac_Max ,Uac_Norm,Uac_Min, Uac_ExMin};

//////////////2017-4-15////////////////
enum Enum_mcStationCtrlType
{
	StaCtrl_ConstantPd = 0,
	StaCtrl_ConstantUd,
	StaCtrl_ConstantId,
	StaCtrl_ConstantAngle,
	StaCtrl_TrackId
};

enum Enum_mcTransformerCtrlType
{
	xfCtrl_FixedAngle = 0,
	xfCtrl_ConstantUv

};
