#pragma once
#include "iostream"
#include "string"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include<sstream>        //istringstream必须包含这个头文件
#include "CComplex.h"

using namespace std;

class CMatrix
{
public:
	CMatrix(){};
	CMatrix(const CMatrix &s);
	CMatrix(vector<vector<CComplex>> b);
	CMatrix(unsigned int n);
	CMatrix(unsigned int m,unsigned int n);
	CMatrix(unsigned int n,string &s);
	void set_dim(unsigned int n);
	void set_dim(unsigned int m, unsigned int n);
	void readMatrix(string fileName);
	void showMatrix();
	void writeMatrix(string str);
	double norm1();//求矩阵的逆矩阵
	double norm2();//求矩阵的逆矩阵
	double normInf();//求矩阵的逆矩阵
	CMatrix inversion();//求矩阵的逆矩阵
	CMatrix pow(int n);//求矩阵的幂
	CMatrix coladd(unsigned int i, unsigned int j);//
	CMatrix rowadd(unsigned int i, unsigned int j);//
	CMatrix delet(unsigned int i);//
	CMatrix delet(unsigned int i, unsigned int j);//
	CMatrix deletcol(unsigned int i);//
	CMatrix deletrow(unsigned int i);//
	void change();//求矩阵的转置
	CMatrix operator +(CMatrix &a);//声明重载运算符的“+”函数
	CMatrix operator -(CMatrix &a);//声明重载运算符的“-”函数
	CMatrix operator *(CMatrix &a);//声明重载运算符的“*”函数
	CMatrix& operator =(CMatrix &a);//声明重载运算符的“=”赋值函数
	CMatrix operator *(CComplex &a);//声明重载运算符的“*”函数
	CMatrix operator *(double &a);//声明重载运算符的“*”函数

	vector<vector<CComplex>> _mat;
	int row;
	int col;

	friend ostream& operator << (ostream& out, CMatrix & m);
};
