#include "Functions.h"

int** EnterTheMatrix(int Width, int Height)
{
	int **one = new int *[Height];//массив указателей
	for (int count = 0; count < Height; count++) one[count] = new int[Width];

	cout << " Матрица : " << Height << "x" << Width << endl << " Заполните матрицу : " << endl << endl << ">> ";

	//ввод
	for (int i = 0; i < Height; i++)//строки
	{
		for (int j = 0; j < Width; j++)//столбики
		{
			cin >> one[i][j];
		}
	}
	return one;
}

void Start5lab(int k, int e)
{
	system("cls");//очистка экрана
	int Width = 0, Height = 0; //ширина и высота матрицы             
	QueueList * List = new QueueList();//создаём корень
	bool v = true;
	for (v;;)
	{ 
		cout << " [ 1 ] Ввести элемент" << endl;
		cout << " [ 2 ] Удалить элемент" << endl;
		cout << " [ 3 ] Найти №" << endl;
		cout << " [ 4 ] End" << endl << endl << ">> ";

		cin >> e;

		if (e == 4)break;
		else if (e == 1)
		{
			cout << " Введите размерность матрицы : ";
			cin >> Height >> Width;			
			List->Add(EnterTheMatrix(Width, Height), Width, Height);
		}
		else if (e == 2 && List->kol != 0)
		{
			List->Remove();
		}
		else if (e == 3)
		{
			int a;
			cout << " Введите номер : ";
			cin >> a;
			List->Search(a);
		}
		List->PrintList();
	}

	delete List;
}