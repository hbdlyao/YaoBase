#pragma once

#include <vector>
#include <map>

using namespace std;

/**
 * 对象基类
 */
class CObjBase
{

public:
	CObjBase();
	virtual ~CObjBase();

	virtual void Clear();

	unsigned long GetObjGUID();
	void SetObjGUID(unsigned long newVal);

protected:
	unsigned long objGUID;
	
	virtual void Init();

};

typedef vector<CObjBase*> pObjVector;

typedef map<string, CObjBase*> pObjMap;

typedef pair<string, CObjBase*> pObj_Pair;

