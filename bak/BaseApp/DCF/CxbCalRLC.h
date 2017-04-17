#pragma once

#include "CxbCalTwoDot.h"

class CxbCalRLC : public CxbCalTwoDot
{
public:
public:
	virtual void Add(CxbCalRLC * vItem);
	virtual void Remove(CxbCalRLC * vItem);

public:	
	

};


typedef vector<CxbCalRLC*> pVector_xbCalRLC;

typedef map<string, CxbCalRLC*> pMap_xbCalRLC;

typedef pair<string, CxbCalRLC*> pPair_xbCalRLC;

