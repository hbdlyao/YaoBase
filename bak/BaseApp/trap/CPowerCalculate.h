///////////////////////////////////////////////////////////
//  CPowerCalculate.h
//  Implementation of the Class CPowerCalculate
//  Created on:      09-4ÔÂ-2017 21:38:17
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_A5F5F6CF_F079_4be6_982B_AB5F234025A2__INCLUDED_)
#define EA_A5F5F6CF_F079_4be6_982B_AB5F234025A2__INCLUDED_

#include <string>
#include <vector>
#include <map>

#include "gbHead_Def.h"
#include "CPowerGrid.h"
#include "CPowerProfile.h"

using namespace std;

class CPowerCalculate
{
public:
	int DevType;
	int DevIndex;
	int StationIndex;

	int SelfType;
	string SelfID;

	virtual void Init(CDeviceBase * vDev) ;

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);


public:
	virtual void Prepare();

	virtual void StationSort(StationMap& vStaMap);

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);

protected:
	CPowerProfile * pProfile;
	/**
	 * CPowerGrid * pGrid;
	 */
	CDeviceBase* pDevice;

};



typedef vector<CPowerCalculate*> pPowerCalVector;

typedef map<string, CPowerCalculate*> pPowerCalMap;
typedef pair<string, CPowerCalculate*> pPowerCal_Pair;

#endif // !defined(EA_A5F5F6CF_F079_4be6_982B_AB5F234025A2__INCLUDED_)
