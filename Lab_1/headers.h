#include <iostream>
#include <fstream> //����� �������� �������
#include <cstdlib>
#include <time.h>


using namespace std;

class Matrix
{
public:
	int **matrix, kv, determ = 1;
	//������� = kv, determ = �����.
public:
	Matrix();//����������� ��� ���������� 
	Matrix(int **, int);//����������� ���������� �������
	Matrix(const Matrix &);//����������� �����������
	~Matrix();//����������
	void Print(int ,int );//����� �������
	void Transponir(const Matrix &);//���������������� �������
	void Determinant();//������ ������������
	//��� 2
	Matrix operator+(Matrix);//�������� ��� ����� ������
	friend Matrix operator-(Matrix, Matrix);//��������� ��� ����. �-�� 
	Matrix& operator++();//��������� ����������
	Matrix operator++(int);//��������� �����������
	operator int();
	//��� 3
	friend ofstream& operator<<(ofstream&, Matrix&);//��������� ����
	friend ifstream& operator>>(ifstream&, Matrix&);//��������� �����
	Matrix(int);	
	//��� 6
	void Iskl(int);//����� ��� ������������ ����	
};
//��� 4
class IdentityMatrix : public Matrix //����� ��� ������ � ���������� ��������� 
{
public:
	IdentityMatrix(int **, int);//����������� � ����������
	//~IdentityMatrix();//���������� ���. �����.
};
class RectangularMatrix : public Matrix //����� ��� ������ � �������������� ���������
{
public:
	float Height, Width;
public:
	RectangularMatrix();
	RectangularMatrix(int **, int, int);
	RectangularMatrix(int **, int);
	~RectangularMatrix();
};

