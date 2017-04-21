///////////////////////////////////////////////////////////
//  CMatrix.cpp
//  Created on:      06-4月-2017 
//  Original author: 马骏鹏
///////////////////////////////////////////////////////////
#include "iostream"
#include "string"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "CMatrix.h"
#include <cmath>  //数学计算

using namespace std;

//将运算得到的数据存储到box中，形成一个完整的Matrix量
CMatrix box_mul;//矩阵相乘的结果
CMatrix box_inver;//矩阵的逆的结果
CMatrix box_change;//矩阵转置的结果
CMatrix box_plus;//矩阵加的结果
CMatrix box_cut;//矩阵减的结果

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
	ifstream ifile(fileName.c_str(), ios::in);/*声明一个输入句柄，打开fileName所指文件。
											 接下来就可以通过ifile>>***来读取1.txt中的内容了*/
	double tmp;
	string line;
	vector<CComplex> row;//vector容器，相当于一个数组
	while (getline(ifile, line))
	{
		istringstream istr(line);
		while (istr >> tmp)
		{
			row.push_back(tmp);//在row尾部插入读入的数据
		}
		this->col = row.size();
		_mat.push_back(row);
		row.clear();
		istr.clear();
		line.clear();
	}
	this->row = _mat.size();//这里的row不是vector变量，是matrix中的row
	ifile.close();
}
void CMatrix::showMatrix()
{
	cout << "矩阵：" << endl;
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
	//out << "矩阵：" << endl;
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
	//ofstreamos("C:\\Users\\Administrator\\Desktop\\数据矩阵W.txt",ios::trunc);
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
		cerr << "无法打开文件！" << endl;
}

CMatrix CMatrix::operator+(CMatrix &a)
{
	//CMatrix vtemp;
	//cout<<"矩阵的和："<<endl;
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
	/*box_plus.col = col; box_plus.row = row;//行列数设置好
	box_plus._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{

			t.push_back(b[i][j]);
		}
		box_plus._mat.push_back(t);//数据输入_mat量中
		t.clear();
	}
	return box_plus;*/
}
CMatrix CMatrix::operator-(CMatrix &a)
{
	//cout<<"矩阵的差："<<endl;
	vector<vector<CComplex>> b(row, vector<CComplex>(col, 0));
	//b = vector<vector<CComplex>>(row, vector<CComplex>(col, 0));
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			b[i][j] = _mat[i][j] - a._mat[i][j];
	}
	return CMatrix(b);
	/*box_cut.col = col; box_cut.row = row;//行列数设置好
	box_cut._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{

			t.push_back(b[i][j]);
		}
		box_cut._mat.push_back(t);//数据输入_mat量中
		t.clear();
	}
	return box_cut;*/
}
CMatrix CMatrix::operator*(CMatrix &a)      //可连续使用
{
	//cout<<"矩阵相乘："<<endl;
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
CMatrix CMatrix::operator *(CComplex &a)//声明重载运算符的“*”函数
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
CMatrix CMatrix::operator *(double &a)//声明重载运算符的“*”函数
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

void CMatrix::change()    //可连续使用
{
	//cout<<"矩阵的转置："<<endl;
	CComplex b[200][200];
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
			b[j][i] = _mat[i][j];
	}

	box_change.col = row; box_change.row = col;//行列数设置好
	box_change._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<col; i++)
	{
		for (int j = 0; j<row; j++)
		{

			t.push_back(b[i][j]);
		}
		box_change._mat.push_back(t);//数据输入_mat量中
		t.clear();
	}
}
CMatrix CMatrix::inversion()    //可连续使用
{
	//cout<<"矩阵的逆："<<endl;
	int i, j, k, M = this->col, N = 2 * this->col;
	vector<vector<CComplex>> b(M, vector<CComplex>(N,0));
	for (i = 0; i<M; i++)     //赋值
	{
		for (j = 0; j<M; j++)
			b[i][j] = _mat[i][j];
	}
	for (i = 0; i<M; i++)    //扩展
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
				cout << "该矩阵不可逆！\n";
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
	box_inver.col = col; box_inver.row = row;//行列数设置好
	box_inver._mat.clear();
	vector<CComplex> t;
	for (int i = 0; i<M; i++)
	{
		for (int j = M; j<N; j++)
		{
			//cout<<b[i][j]<<endl;
			t.push_back(b[i][j]);
		}
		box_inver._mat.push_back(t);//数据输入_mat量中
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