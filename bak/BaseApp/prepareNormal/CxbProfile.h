#pragma once

#include "CMatrix.h"
#include "CPowerMath.h"


#include "CxbHvdcGrid.h"
#include "CxbResult.h"
#include "CxbOrder.h"

#include "CPowerProfile.h"


class CxbProfile : public CPowerProfile
{
public:
	//
	~CxbProfile();

	virtual void Init();
	virtual void Clear();
	virtual void Release();

protected:
	virtual void doInit();
	virtual void doClear();

public:
	string Flag_Case="DFBFH22";

	int Flag_DCFOver;

	CxbOrder* pxbOrder;

	int xbHOrder=1;

	double xbFreq=50;

	//Âí¿¥Åô
	int StationNum=1;

	CMatrix * Ymatrix;
	CMatrix * Ivect;
	CMatrix * Uvect;
	
public:

	
	double Omega();

	virtual void InitMatrix(int vN);

	virtual void Solve();

	void UpdateYLine(int * pNode, CMatrix vY);

	virtual void UpdateI(int iNode, double vIr, double vIm);

	virtual void UpdateI(int iNode, int jNode, double vIr, double vIm);


};

