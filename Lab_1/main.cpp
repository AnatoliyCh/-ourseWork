#include "Functions.h"

void main()
{
	system("cls");//очистка экрана
	setlocale(LC_ALL, ".ACP");//рус. яз.
	int k, e;
	cout << " Введите размерность матрицы : ";
	/// 6 лаб. работа
	/*try	{*/
		cin >> k;

		/*if ((int)k != k)throw k;
		if (k<0)throw (char)k;*/
	/*}
	catch (float k)
	{
		cout << endl << "Размерность матрицы должна быть целой!" << endl;
		system("pause");
		return;
	}
	catch (char k)
	{
		cout << endl << "Размерность матрицы должна быть целой, вы ввели букву!" << endl;
		system("pause");
		return;
	}*/
	/// 6 лаб. работа
	if (k == 0)//для нулевой матрицы
	{
		Matrix Nullmatrix;
		Nullmatrix.Print(0, 0);
	}
	cout << " Матрица : " << k << "x" << k << endl << " Заполните матрицу : " << endl << endl << ">> ";
	int **a = new int*[k];//массив указателей
	for (int count = 0; count < k; count++)a[count] = new int[k];
	//ввод
	for (int i = 0; i < k; i++)//строки
	{
		for (int j = 0; j < k; j++)//столбики
		{
			cin >> a[i][j];
		}
	}
	cout << endl << " Ваша матрица : " << endl;
	Matrix * my_matrix = new Matrix(a, k);//создание указателя на переменную типа Matrix
	my_matrix->Print(0, 0);//вывод
	Matrix * my_matrixTransponir = new Matrix(*my_matrix);

	cout << " [ 1 ] Лабораторная 1" << endl;
	cout << " [ 2 ] Лабораторная 2" << endl;
	cout << " [ 3 ] Лабораторная 3" << endl;
	cout << " [ 4 ] Лабораторная 4" << endl;
	cout << " [ 5 ] Лабораторная 5" << endl;
	cout << " [ 6 ] Лабораторная 6" << endl;
	cout << " [ 7 ] Лабораторная 7" << endl << endl << ">> ";
	cin >> e;

	if (e == 1)
	{
		cout << " Транспонировать матрицу? Yes[1] / No[2] " << endl << endl << ">> ";

		cin >> e;
		if (e == 1)
		{
			my_matrixTransponir->Transponir(*my_matrix);//транспонирование
			my_matrixTransponir->Print(0, 0);//вывод
		}

		cout << " [ 1 ] Найти определитель введённой матрицы" << endl;
		cout << " [ 2 ] Найти определитель транспонированной матрицы" << endl << endl << ">> ";

		cin >> e;
		if (e == 1)my_matrix->Determinant();//определитель
		else if (e == 2)my_matrixTransponir->Determinant();//определитель
	}
	else if (e == 2) Start2lab(k, e, my_matrix, my_matrixTransponir);//лаба 2
	else if (e == 3) Start3lab(k, e, my_matrix);//лаба 3
	else if (e == 4) Start4lab(k, e);//лаба 4
	else if (e == 5) Start5lab(k, e);//лаба 5
	else if (e == 6) my_matrix->Iskl(my_matrix->kv);//лаба 6
	else if (e == 7) Start7lab(e);//лаба 7

	delete my_matrix;
	delete my_matrixTransponir;
	for (int count = 0; count < k; count++)delete[]a[count];
	delete[]a;		
	
	system("pause");
}