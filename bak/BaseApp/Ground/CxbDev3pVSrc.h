///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.h
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4��-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
#define EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_

#include "CxbDevTwoDot.h"
#include "gbHead_Def.h"
#include "CxbU3PData.h"

/**
* ��������ѹԴ
*/
class CxbDev3pVSrc : public CxbDevTwoDot
{

protected:
	//����DataMap[ConMethod+PowLevel]
	pxbU3PData_Map DataMap;

	//PowPreMap[Condition]=pxbU3PData_Map, pxbU3PData_Map[PowPre]=CxbU3PData
	//pxbU3PPowPre_Map PowPreMap;

	//
	struct_xbU3PData  pU3pData;

public:
	virtual void Prepare_hRLC();
	virtual void Init();

public:

	//������
	//virtual void PrepareData(string vCondition, string vPowPre);
	virtual void PrepareData(string vCondition);

	double hUre(int vhOrder);
	double hUim(int vhOrder);

	double hIre(int vhOrder);
	double hIim(int vhOrder);

	double hYg(int vhOrder);
	double hYb(int vhOrder);

	double Get_hUrms(int vhOrder);
	void   Set_hUrms(int vhOrder,double vX);

	double Get_hAngle(int vhOrder);
	void   Set_hAngle(int vhOrder, double vX);

	double Get_hYL(int vhOrder);
	void   Set_hYL(int vhOrder, double vX);
};

#endif // !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)