#include "Functions.h"

void Start3lab(int k, int e, Matrix *my_matrix)
{	
	cout << " [ 1 ] Записать матрицу в txt" << endl;
	cout << " [ 2 ] Записать матрицу в bat" << endl << endl << ">> ";
	cin >> e;

	Matrix * my_matrixFile = new Matrix(k);//создаём пустую матрицу
	if (e == 1)//работа с txt
	{
		ofstream fileTXT("Matrix.txt", ios::out);//создание и записть в файл.txt
		if (!fileTXT)
		{
			cerr << "Error: создания/записи файла " << endl;
			exit(1);
		}
		else
		{			
			fileTXT << *my_matrix;
			fileTXT << my_matrix->kv;//размер матрицы
			fileTXT.close();//закрытие потока
			cout << " Вывод файла txt Yes[1] / No[2] " << endl << endl << ">> ";
			cin >> e;
			if (e == 1)
			{
				ifstream fileTXT("Matrix.txt", ios::in);//открываем для чтения из файла.txt
				fileTXT >> *my_matrixFile;//матрица
				fileTXT >> my_matrixFile->kv;//размер матрицы
				my_matrixFile->Print(0, 0);
				fileTXT.close();//закрытие потока
			}
		}
	}
	else if (e == 2)//работа с bat
	{
		ofstream fileDAT("Matrix.dat");//создание и записть в файл.dat
		if (!fileDAT) {
			cerr << "Error: создания/записи файла " << endl;
			exit(1);
		}
		else
		{
			int k = my_matrix->kv;//Размер матрицы
			fileDAT.write((char*)&(*my_matrix), sizeof(Matrix));
			fileDAT.write((char*)&(k), sizeof(int));
			fileDAT.close();
			cout << " Вывод файла bat Yes[3] / No[4] " << endl << endl << ">> ";
			cin >> e;
			if (e == 3)
			{ 
				ifstream fileDAT("Matrix.dat");//открываем для чтения из файла.dat
				fileDAT.read((char*)&(*my_matrixFile), sizeof(Matrix));
				fileDAT.close();
				my_matrixFile->Print(0, 0);
			}
		}
	}
	if (e != 3)delete my_matrixFile;
}