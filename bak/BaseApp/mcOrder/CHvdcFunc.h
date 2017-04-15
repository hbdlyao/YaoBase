#pragma once



#include <string>
#include <vector>

using namespace std;

class CHvdcFunc
{
	CHvdcFunc() {};
	virtual ~CHvdcFunc() {};
	CHvdcFunc(const CHvdcFunc& vFunc) {};

public:

	static string mcTypeToName(int vType);
	static string xbTypeToName(int vType);
};
