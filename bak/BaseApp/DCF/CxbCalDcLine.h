///////////////////////////////////////////////////////////
//  CxbCalDcLine.h
//  Implementation of the Class CxbCalDcLine
//  Created on:      05-4月-2017 18:32:32
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_)
#define EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_

#include "CxbCal_Leaf.h"

/**
 * 主回路 直流极线
 */
class CxbCalDcLine : public CxbCal_Leaf
{
public:
	virtual void StationSort(StationMap& vStaMap);
	virtual void NodeGround(NodeMap & vNodeMap) ;

protected:
	virtual void UpdateY();


};
#endif // !defined(EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_)
