#include "Functions.h"

void Start4lab(int k, int e)
{
	system("cls");//очистка экрана
	cout << " Введите размерность матрицы : ";
	int Width, Height; //ширина и высота матрицы
	cin >> Height >> Width;

	int **b = new int*[Height];//массив указателей
	for (int count = 0; count < Height; count++)b[count] = new int[Width];

	cout << " Матрица : " << Height << "x" << Width << endl << " Заполните матрицу : " << endl << endl << ">> ";

	//ввод
	for (int i = 0; i < Height; i++)//строки
	{
		for (int j = 0; j < Width; j++)//столбики
		{
			cin >> b[i][j];
		}
	}
	if (Height == 1 && Width == 1)
	{
		k = 1;
		IdentityMatrix * my_matrixIdentity = new IdentityMatrix(b, k);//создание указателя на переменную типа IdentityMatrix
		Matrix * my_matrixTransponir = new Matrix(k);//создаём пустую матрицу
		my_matrixIdentity->Print(0,0);
		my_matrixTransponir->Transponir(*my_matrixIdentity);
		my_matrixTransponir->Print(0,0);
		delete my_matrixIdentity;
	}
	else
	{
		if (Height != Width)
		{
			RectangularMatrix * my_matrixRectangular = new RectangularMatrix(b, Height, Width);
			my_matrixRectangular->Print(Height, Width);
			delete my_matrixRectangular;
		}
		else
		{
			RectangularMatrix * my_matrixRectangular = new RectangularMatrix(b, Height);
			my_matrixRectangular->Print(Height, Width);
			delete my_matrixRectangular;
		}
	}

	for (int count = 0; count < Height; count++)delete[]b[count];
	delete[]b;
}