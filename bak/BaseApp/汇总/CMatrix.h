#pragma once
#include "iostream"
#include "string"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include<sstream>        //istringstream����������ͷ�ļ�
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
	double norm1();//�����������
	double norm2();//�����������
	double normInf();//�����������
	CMatrix inversion();//�����������
	CMatrix pow(int n);//��������
	CMatrix coladd(unsigned int i, unsigned int j);//
	CMatrix rowadd(unsigned int i, unsigned int j);//
	CMatrix delet(unsigned int i);//
	CMatrix delet(unsigned int i, unsigned int j);//
	CMatrix deletcol(unsigned int i);//
	CMatrix deletrow(unsigned int i);//
	void change();//������ת��
	CMatrix operator +(CMatrix &a);//��������������ġ�+������
	CMatrix operator -(CMatrix &a);//��������������ġ�-������
	CMatrix operator *(CMatrix &a);//��������������ġ�*������
	CMatrix& operator =(CMatrix &a);//��������������ġ�=����ֵ����
	CMatrix operator *(CComplex &a);//��������������ġ�*������
	CMatrix operator *(double &a);//��������������ġ�*������

	vector<vector<CComplex>> _mat;
	int row;
	int col;

	friend ostream& operator << (ostream& out, CMatrix & m);
};
