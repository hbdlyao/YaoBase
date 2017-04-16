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

	string GetObjGUID();
	void SetObjGUID(string newVal);

	virtual void Clear();

protected:
	string objGUID;
	
	virtual void Init();

};

typedef vector<CObjBase*> pObjVector;

typedef map<string, CObjBase*> pObjMap;

typedef pair<string, CObjBase*> pObj_Pair;

