#pragma once


/**
 * ≥Ã–Ú≥ı ºªØ
 */
class CMyInitApp
{
protected:
	static void Clear();
	static void Release();

public:
	static void Init();
	static void Close();
	static void Exit();
	static bool New();
	static bool ReOpen();
	static bool ReNew();
	static bool Open();
	static bool Save();
	static bool SaveAs();
	static bool IsSave();
	static void Help(int vID);

protected:
	//
	CMyInitApp() {	};
	~CMyInitApp() {	};
	CMyInitApp(const CMyInitApp & vInstance) {	};

};

