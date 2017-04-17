#pragma once


#include "CmcDevTwoDot.h"



/**
 * ������
 */
class CmcDevConvertor : public CmcDevTwoDot
{

public:
	/**
	 * ������/�ضϽ�
	 */
	double GetAlhpa_gama();
	/**
	 * �������/�ضϽ�
	 */
	double GetAlpha_gamaN();
	/**
	 * ������/�ضϽ����ֵ
	 */
	double GetAngleMax();
	/**
	 * ������/�ضϽ���Сֵ
	 */
	double GetAngleMin();
	
	/**
	 * �������ֵ�����ٷ�������  drN=Urp
	 */
	double GetdrN();
	/**
	 * ����翹�ֵ�� dxN=(1/2)Ukp ���ٷ�������
	 */
	double GetdxN();
	/**
	 * ֱ������,������ó�
	 */
	double GetId();
	/**
	 * ��ѹ�뻻��վ���� ?
	 */
	double GetLengthToSide();
	/**
	 * ֱ������
	 */
	double GetPd();
	/**
	 * �ֱ������
	 */
	double GetPdN();
	/**
	 * ����վ�����޹���Сֵ
	 */
	double GetQmin();
	/**
	 * ֱ����ѹ
	 */
	double GetUd();
	/**
	 * �ֱ����ѹ
	 */
	double GetUdN();
	/**
	 * 6��������ͨѹ��
	 */
	double GetUT();
	/**
	 * ÿ��12������������
	 */
	int GetValvor12Count();
	/**
	 * ������/�ضϽ�
	 */
	void SetAlhpa_gama(double newVal);
	/**
	 * �������/�ضϽ�
	 */
	void SetAlpha_gamaN(double newVal);
	/**
	 * ������/�ضϽ����ֵ
	 */
	void SetAngleMax(double newVal);
	/**
	 * ������/�ضϽ���Сֵ
	 */
	void SetAngleMin(double newVal);
	
	/**
	 * �������ֵ
	 */
	void SetdrN(double newVal);
	/**
	 * �������ֵ�����ٷ�������  drN=Urp
	 */
	void SetdxN(double newVal);
	/**
	 * ֱ������,������ó�
	 */
	void SetId(double newVal);
	/**
	 * ��ѹ�뻻��վ���� ?
	 */
	void SetLengthToSide(double newVal);
	/**
	 * ֱ������
	 */
	void SetPd(double newVal);
	/**
	 * �ֱ������
	 */
	void SetPdN(double newVal);
	/**
	 * ����վ�����޹���Сֵ
	 */
	void SetQmin(double newVal);
	/**
	 * ֱ����ѹ
	 */
	void SetUd(double newVal);
	/**
	 * �ֱ����ѹ
	 */
	void SetUdN(double newVal);
	/**
	 * 6��������ͨѹ��
	 */
	void SetUT(double newVal);
	/**
	 * ÿ��12������������
	 */
	void SetValvor12Count(int newVal);
	double GetUdioN();
	void SetUdioN(double newVal);
	double GetUdio();
	void SetUdio(double newVal);
	/**
	 * �����ѹ
	 */
	double GetUv();
	/**
	 * �����ѹ
	 */
	void SetUv(double newVal);
	/**
	 * ������ѹ
	 */
	double GetUvN();
	/**
	 * ������ѹ
	 */
	void SetUvN(double newVal);
	/**
	 * ֱ������,������ó�
	 */
	double GetIdN();
	/**
	 * ֱ������,������ó�
	 */
	void SetIdN(double newVal);
	/**
	 * ���������ͣ�������䣩
	 */
	int GetStationType();
	/**
	 * ���������ͣ�������䣩
	 */
	void SetStationType(int newVal);
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	int GetStationCtrlType();
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	void SetStationCtrlType(int newVal);
	int GetIsGround();
	void SetIsGround(int newVal);
	double GetAngleRef();
	void SetAngleRef(double newVal);

protected:
	/**
	 * ������/�ضϽ�
	 */
	double Alhpa_gama;
	/**
	 * �������/�ضϽ�
	 */
	double Alpha_gamaN;
	/**
	 * ������/�ضϽ����ֵ
	 */
	double AngleMax;
	/**
	 * ������/�ضϽ���Сֵ
	 */
	double AngleMin;
	/**
	 * �������ֵ�����ٷ�������  drN=Urp
	 */
	double drN;
	/**
	 * ����翹�ֵ�� dxN=(1/2)Ukp ���ٷ�������
	 */
	double dxN;
	/**
	 * ֱ������,������ó�
	 */
	double Id;
	/**
	 * ��ѹ�뻻��վ���� ?
	 */
	double LengthToSide;
	/**
	 * ֱ������
	 */
	double Pd;
	/**
	 * �ֱ������
	 */
	double PdN;
	/**
	 * ����վ�����޹���Сֵ
	 */
	double Qmin;
	/**
	 * ֱ����ѹ
	 */
	double Ud;
	/**
	 * �ֱ����ѹ
	 */
	double UdN;
	/**
	 * 6��������ͨѹ��
	 */
	double UT;
	/**
	 * ÿ��12������������
	 */
	int Valvor12Count;
	double UdioN;
	double Udio;
	/**
	 * �����ѹ
	 */
	double Uv;
	/**
	 * ������ѹ
	 */
	double UvN;
	/**
	 * ֱ������,������ó�
	 */
	double IdN;
	/**
	 * ���������ͣ�������䣩
	 */
	int StationType;
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	int StationCtrlType;
	int IsGround;
	double AngleRef;

};
