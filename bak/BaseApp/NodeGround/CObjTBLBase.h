#pragma once

#include "string"
#include "CObjBase.h"

using namespace std;

/**
 * ∂‘œÛ±Ì
 */
class CObjTBLBase
{
private:
	int ItemCount;

protected:
	virtual void Init();

public:
	CObjTBLBase();
	/**
	 * CObjTBLBase(CObjTBLBase & vTBL);
	 */
	virtual ~CObjTBLBase();

	virtual void Clear();

public:
	//
	virtual string TypeToName(int vType) =0;
	virtual string TypeToName();

	virtual int GetItemCount();
	virtual pObjMap GetItems();
	string GetTblName();
	void SetTblName(string newVal);
	int GetTblType();
	void SetTblType(int newVal);
	virtual pObjVector ItemVect();
	
protected:
	pObjMap ItemsMap;
	pObjVector ItemsVect;
	string tblName;
	int tblType;

	virtual void ItemAdd(string vID, CObjBase* vItem);
	virtual void ItemRemove(CObjBase* vItem);
	virtual void ItemRemove(int vItem);
	virtual void ItemRemove(string vName);
	
	virtual CObjBase * Item(int vIndex);
	virtual CObjBase * Item(string vName);



};
