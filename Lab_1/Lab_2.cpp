#include "Functions.h"

void Start2lab(int k, int e, Matrix *my_matrix, Matrix *my_matrixTransponir)
{
	cout << " [ 1 ] Сложить матрицы" << endl;
	cout << " [ 2 ] Вычесть матрицы" << endl;
	cout << " [ 3 ] Введённая матрица = матрица++" << endl;
	cout << " [ 4 ] Введённая матрица = ++матрица" << endl << endl << ">> ";

	cin >> e;
	switch (e)
	{
	case 1:
		((*my_matrix) + (*my_matrixTransponir)).Print(0, 0);//сложение методом(ф-ей) класса		
		break;
	case 2:
		(*my_matrix - *my_matrixTransponir).Print(0, 0);//вычитание дружественной ф-ей
		break;
	case 3:
		((*my_matrix)++).Print(0, 0);//инкремент постфиксный
		break;
	case 4:
		(++*my_matrix).Print(0, 0);//инкремент префиксный
		break;
	}

	cout << " Перевести матрицу к int? Yes[1] / No[2] " << endl << endl << ">> ";

	cin >> e;
	if (e == 1)
	{
		cout << (int)(*my_matrix) << endl;
	}
}