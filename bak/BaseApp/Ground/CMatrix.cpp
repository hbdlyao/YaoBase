///////////////////////////////////////////////////////////
//  CMatrix.cpp
//  Created on:      06-4��-2017 
//  Original author: ����
///////////////////////////////////////////////////////////
#include "iostream"
#include "string"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "CMatrix.h"
#include <cmath>  //��ѧ����

using namespace std;

//������õ������ݴ洢��box�У��γ�һ��������Matrix��
CMatrix box_mul;//������˵Ľ��
CMatrix box_inver;//�������Ľ��
CMatrix box_change;//����ת�õĽ��
CMatrix box_plus;//����ӵĽ��
CMatrix box_cut;//������Ľ��

CMatrix::CMatrix(const CMatrix &s)
{
	_mat.clear();
	col = s.col;
	row = s.row;
	_mat = s._mat;
}
CMatrix::CMatrix(unsigned int n)
{
	_mat.clear();
	this->col = n;
	this->row = n;
	_mat = vector<vector<CComplex>>(n, vector<CComplex>(n, 0));
}
CMatrix::CMatrix(unsigned int n,string &s)
{
	if (s != "eye")
		return;
	_mat.clear();
	this->col = n;
	this->row = n;
	_mat = vector<vector<CComplex>>(n, vector<CComplex>(n, 0));
	while (n--){
		_mat[n][n] = 1;
	} 
}
CMatrix::CMatrix(unsigned int m,unsigned int n)
{
	_mat.clear();
	this->col = n;
	this->row = m;
	_mat = vector<vector<CComplex>>(m, vector<CComplex>(n, 0));
}
void CMatrix::set_dim(unsigned int m, unsigned int n)
{
	_mat.clear();
	this->col = n;
	this->row = m;
	_mat = vector<vector<CComplex>>(m, vector<CComplex>(n, 0));
}
CMatrix::CMatrix(vector<vector<CComplex>> b)
{
	_mat.clear();
	_mat = b;
	col = b[0].size();
	row = b.size();
}
void CMatrix::set_dim(unsigned int n)
{
	//vector<double> vrow(n ,0);
	_mat.clear();
	this->col = n;
	this->row = n;
	_mat = vector<vector<CComplex>>(n, vector<CComplex>(n, 0));
}
void CMatrix::readMatrix(string fileName)
{
	ifstream ifile(fileName.c_str(), ios::in);/*����һ������������fileName��ָ�ļ���
											 �������Ϳ���ͨ��ifile>>***����ȡ1.txt�е�������*/
	double tmp;
	string line;
	vector<CComplex> row;//vector�������൱��һ������
	while (getline(ifile, line))
	{
		istringstream istr(line);
		while (istr >> tmp)
		{
			row.push_back(tmp);//��rowβ��������������
		}
		this->col = row.size();
		_mat.push_back(row);
		row.clear();
		istr.clear();
		line.clear();
	}
	this->row = _mat.size();//�����row����vector��������matrix�е�row
	ifile.close();
}
void CMatrix::showMatrix()
{
	cout << "����" << endl;
	//cout<<"row="<<row<<endl;
	//cout<<"col="<<col<<endl;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			cout << _mat[i][j] << " ";
		cout << endl;
	}
}
ostream& operator << (ostream& out, CMatrix & m)
{
	//out << "����" << endl;
	//cout<<"row="<<row<<endl;
	//cout<<"col="<<col<<endl;
	for (int i = 0; i<m.row; i++)
	{
		for (int j = 0; j<m.col; j++)
			out << m._mat[i][j] << " ";
		out << endl;
	}
	return out;
}
void CMatrix::writeMatrix(string str)
{
	ofstream os(str, ios::trunc);
	//ofstreamos("C:\\Users\\Administrator\\Desktop\\���ݾ���W.txt",ios::trunc);
	if (os)
	{
		for (int i = 0; i<row; ++i)
		{
			for (int j = 0; j<col; ++j)
				os << _mat[i][j] << " ";
			os << endl;
		}
	}
	else
		cerr << "�޷����ļ���" << endl;
}

CMatrix CMatrix::operator+(CMatrix &a)
{
	//CMatrix vtemp;
	//cout<<"����ĺͣ�"<<endl;
	vector<vector<CComplex>> b(row, vector<CComplex>(col, 0));
	if ((col != a.row)&&(row!=a.row))
	{
		cout << "erro:matrix plus dim not fit" << endl;
		system("pause");
		return 0;
	}
	//b = vector<vector<CComplex>>(row, vector<CComplex>(col, 0));
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			b[i][j] = _mat[i][j] + a._mat[i][j];
	}
	return CMatrix(b);
	/*box_plus.col = col; box_plus.row = row;//���������ú�
	box_plus._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{

			t.push_back(b[i][j]);
		}
		box_plus._mat.push_back(t);//��������_mat����
		t.clear();
	}
	return box_plus;*/
}
CMatrix CMatrix::operator-(CMatrix &a)
{
	//cout<<"����Ĳ"<<endl;
	vector<vector<CComplex>> b(row, vector<CComplex>(col, 0));
	//b = vector<vector<CComplex>>(row, vector<CComplex>(col, 0));
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			b[i][j] = _mat[i][j] - a._mat[i][j];
	}
	return CMatrix(b);
	/*box_cut.col = col; box_cut.row = row;//���������ú�
	box_cut._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{

			t.push_back(b[i][j]);
		}
		box_cut._mat.push_back(t);//��������_mat����
		t.clear();
	}
	return box_cut;*/
}
CMatrix CMatrix::operator*(CMatrix &a)      //������ʹ��
{
	//cout<<"������ˣ�"<<endl;
	vector<vector<CComplex>> b(row, vector<CComplex>(a.col, 0));
	//b = vector<vector<CComplex>>(row, vector<CComplex>(col,0));
	if (col != a.row)
	{
		cout << "erro:matrix multiple dim not fit" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<a.col; j++)
		{
			b[i][j] = 0;
			for (int k = 0; k<col; k++)
			{
				b[i][j] += _mat[i][k] * a._mat[k][j];
			}
		}

	}
	return CMatrix(b);
}
CMatrix CMatrix::operator *(CComplex &a)//��������������ġ�*������
{
	vector<vector<CComplex>> b(row, vector<CComplex>(col, 0));
	for (int i = 0; i<row; i++)
	{
		for (int k = 0; k<col; k++)
		{
			b[i][k] = _mat[i][k] * a;
		}
	}
	return CMatrix(b);
}
CMatrix CMatrix::operator *(double &a)//��������������ġ�*������
{
	vector<vector<CComplex>> b(row, vector<CComplex>(col, 0));
	for (int i = 0; i<row; i++)
	{
		for (int k = 0; k<col; k++)
		{
			b[i][k] = _mat[i][k] * a;
		}
	}
	return CMatrix(b);
}
CMatrix& CMatrix::operator=(CMatrix &a)
{
	row = a.row; col = a.col;
	_mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			t.push_back(a._mat[i][j]);
		}
		_mat.push_back(t);
		t.clear();
	}
	return *this;
}

void CMatrix::change()    //������ʹ��
{
	//cout<<"�����ת�ã�"<<endl;
	CComplex b[200][200];
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			b[j][i] = _mat[i][j];
	}

	box_change.col = row; box_change.row = col;//���������ú�
	box_change._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<col; i++)
	{
		for (int j = 0; j<row; j++)
		{

			t.push_back(b[i][j]);
		}
		box_change._mat.push_back(t);//��������_mat����
		t.clear();
	}
}
CMatrix CMatrix::inversion()    //������ʹ��
{
	//cout<<"������棺"<<endl;
	int i, j, k, M = this->col, N = 2 * this->col;
	vector<vector<CComplex>> b(M, vector<CComplex>(N,0));
	for (i = 0; i<M; i++)     //��ֵ
	{
		for (j = 0; j<M; j++)
			b[i][j] = _mat[i][j];
	}
	for (i = 0; i<M; i++)    //��չ
	for (j = M; j<N; j++)
	{
		if (i == (j - M))
			b[i][j] = 1;
		else
			b[i][j] = 0;
	}
	for (i = 0; i<M; i++)
	{
		if (b[i][i] == 0)
		{
			for (k = i; k<M; k++)
			{
				if (b[k][i] != 0)
				{
					for (int j = 0; j<N; j++)
					{
						CComplex temp;
						temp = b[i][j];
						b[i][j] = b[k][j];
						b[k][j] = temp;
					}
					break;
				}
			}
			if (k == M)
			{
				cout << "�þ��󲻿��棡\n";
				break;
			}
		}
		for (j = N - 1; j >= i; j--)
			b[i][j] /= b[i][i];

		for (k = 0; k<M; k++)
		{
			if (k != i)
			{
				CComplex temp = b[k][i];
				for (j = 0; j<N; j++)
					b[k][j] -= temp*b[i][j];
			}
		}
	}
	box_inver.col = col; box_inver.row = row;//���������ú�
	box_inver._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<M; i++)
	{
		for (int j = M; j<N; j++)
		{
			//cout<<b[i][j]<<endl;
			t.push_back(b[i][j]);
		}
		box_inver._mat.push_back(t);//��������_mat����
		t.clear();
	}
	return box_inver;
}

CMatrix CMatrix::pow(int n)
{
	if (n == 1)
		return *this;
	else if (n>1)
	{
		CMatrix vm = *this;
		for (int i = 0; i < n - 1; i++)
			vm = vm * *this;
		return vm;
	}
	else if (n == 0)
	{
		CMatrix vm = CMatrix(col);
		for (int i = 0; i < row; i++)
		{
			vm._mat[i][i] = 1;
		}
		return vm;
	}
	else
	{
		CMatrix vm = *this;
		for (int i = 0; i < n - 1; i++)
			vm = vm * *this;
		return vm.inversion();
	}
	return CMatrix(0);
}
CMatrix CMatrix::coladd(unsigned int i, unsigned int j)
{
	CMatrix b(row, col);
	b = *this;
	for (unsigned int m = 0; m < row; m++)
		b._mat[m][i] += b._mat[m][j];
	return b;
}
CMatrix CMatrix::rowadd(unsigned int i, unsigned int j)
{
	CMatrix b(row, col);
	b = *this;
	for (unsigned int m = 0; m < col; m++)
		b._mat[i][m] += b._mat[j][m];
	return b;
}
CMatrix CMatrix::delet(unsigned int i)
{
	CMatrix b(row, col);
	b = *this;
	b = b.deletrow(i);
	b = b.deletcol(i);
	return b;
}
CMatrix CMatrix::delet(unsigned int i, unsigned int j)
{
	CMatrix b(row, col);
	b = *this;
	b = b.deletrow(i);
	b = b.deletcol(j);
	return b;
}
CMatrix CMatrix::deletcol(unsigned int i)
{
	CMatrix b(row, col);
	b = *this;
	for (unsigned int m = 0; m < row; m++)
		b._mat[m].erase(b._mat[m].begin() + i);
	b.col--;
	return b;
}
CMatrix CMatrix::deletrow(unsigned int i)
{
	CMatrix b(row, col);
	b = *this;
	b._mat.erase(b._mat.begin() + i);
	b.row--;
	return b;
}
double CMatrix::norm1()
{
	double vsum=0, vtemp=0;
	for (unsigned int j = 0; j < row; j++)
	{
		vtemp = _mat[j][0].abs();
		for (unsigned int i = 1; i < col; i++)
		if (vtemp < _mat[j][i].abs())
			vtemp = _mat[j][i].abs();
		vsum += vtemp;
	}
	return vsum;
}
double CMatrix::norm2()
{
	double vsum = 0;
	for (unsigned int j = 0; j < row; j++)
	for (unsigned int i = 0; i < col; i++)
		vsum += _mat[j][i].abs2();
	return sqrt(vsum);
}
double CMatrix::normInf()
{
	double vsum = 0, vtemp = 0;
	for (unsigned int j = 0; j < col; j++)
	{
		vtemp = _mat[j][0].abs();
		for (unsigned int i = 1; i < row; i++)
		if (vtemp < _mat[j][i].abs())
			vtemp = _mat[j][i].abs();
		vsum += vtemp;
	}
	return vsum;
}