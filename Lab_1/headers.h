#include <iostream>
#include <fstream> //класс файловых потоков
#include <cstdlib>
#include <time.h>


using namespace std;

class Matrix
{
public:
	int **matrix, kv, determ = 1;
	//порядок = kv, determ = опред.
public:
	Matrix();//конструктор без параметров 
	Matrix(int **, int);//конструктор заполненой матрицы
	Matrix(const Matrix &);//конструктор копирования
	~Matrix();//деструктор
	void Print(int ,int );//вывод матрицы
	void Transponir(const Matrix &);//транспонирование матрицы
	void Determinant();//расчет определителя
	//лаб 2
	Matrix operator+(Matrix);//сложение как метод класса
	friend Matrix operator-(Matrix, Matrix);//вычитание как друж. ф-ия 
	Matrix& operator++();//инкремент префиксный
	Matrix operator++(int);//инкремент постфиксный
	operator int();
	//лаб 3
	friend ofstream& operator<<(ofstream&, Matrix&);//потоковый ввод
	friend ifstream& operator>>(ifstream&, Matrix&);//потоковый вывод
	Matrix(int);	
	//лаб 6
	void Iskl(int);//метод для демонстрации искл	
};
//лаб 4
class IdentityMatrix : public Matrix //класс для работы с единичными матрицами 
{
public:
	IdentityMatrix(int **, int);//конструктор с параметром
	//~IdentityMatrix();//вызывается род. дестр.
};
class RectangularMatrix : public Matrix //класс для работы с прямоугольными матрицами
{
public:
	float Height, Width;
public:
	RectangularMatrix();
	RectangularMatrix(int **, int, int);
	RectangularMatrix(int **, int);
	~RectangularMatrix();
};

