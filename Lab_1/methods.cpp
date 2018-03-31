#include "Functions.h"
//лаб 1
Matrix::Matrix()//конструктор без параметра
{
	matrix = nullptr;
	kv = 0;
}
Matrix::Matrix(int **a, int k)//конструктор заполненой матрицы
{
	kv = k;
	matrix = new int*[kv];//строки
	for (int count = 0; count < kv; count++)matrix[count] = new int[kv];//столбики
	//указатели на память из main
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[i][j] = a[i][j];
		}
	}
}
Matrix::Matrix(const Matrix &my_matrix)//конструктор копирования 
{
	kv = my_matrix.kv;
	matrix = new int*[my_matrix.kv];//строки
	for (int count = 0; count < my_matrix.kv; count++)matrix[count] = new int[my_matrix.kv];//столбики
	//Копирование
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[i][j] = my_matrix.matrix[i][j];
		}
	}
}
Matrix::~Matrix()
{
	if (kv != 0) 
	{
		for (int count = 0; count < kv; count++)delete[]matrix[count];
		delete[]matrix;
	}
}
void Matrix::Transponir(const Matrix &my_matrix)//транспонирование матрицы
{
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[j][i] = my_matrix.matrix[i][j];
		}
	}
}
void Matrix::Determinant()//расчёт определителя
{
	int l = 0, Ldiagonal = 1, Rdiagonal = 1;
	if (kv == 1)
	{
		determ = matrix[0][0];
		cout << endl << " Определитель :  " << determ << endl << endl;
	}
		
	else if (kv == 2)
		{			
			for (int i = 0; i < kv; i++)//строки
			{
				Ldiagonal = Ldiagonal * matrix[i][i];
			}
			for (int i = kv - 1; i >= 0; i--)//строки
			{
				Rdiagonal = Rdiagonal * matrix[i][l];
				l++;
			}
			determ = Ldiagonal - Rdiagonal;
			cout << endl << " Определитель :  " << determ << endl << endl;
		}
	else
		{
		int w = 0;
			for (int i = 0; i < kv; i++)//строки
			{
				for (0; w < kv; w++)//столбики
				{
					determ = determ*(matrix[i][w] / matrix[i][i]);
				}
				w = i;
			}
			cout << endl;
			cout << endl << " Определитель :  " << determ << endl << endl;
		}	
}
void Matrix::Print(int Height, int Width)
{	
	if (Height == Width)
	{
		cout << endl;
		//вывод
		for (int i = 0; i < kv; i++)//строки
		{
			for (int j = 0; j < kv; j++)//столбики
			{
				cout << " " << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < Height; i++)//строки
		{
			for (int j = 0; j < Width; j++)//столбики
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
}
//лаб 2
Matrix Matrix::operator+(Matrix my_matrix)//оператор сложения, как метод класса 
{
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[i][j] = matrix[i][j] + my_matrix.matrix[i][j];
		}
	}
	return *this;
}
Matrix operator-(Matrix my_matrix, Matrix my_matrixCopy)//оператор вычитания друж.
{
	for (int i = 0; i < my_matrix.kv; i++)//строки
	{
		for (int j = 0; j < my_matrix.kv; j++)//столбики
		{
			my_matrix.matrix[i][j] = my_matrix.matrix[i][j] - my_matrixCopy.matrix[i][j];
		}
	}
	return my_matrix;
}
Matrix& Matrix::operator++()//инкремент префиксный
{	
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			++matrix[i][j];
		}
	}
	return *this;
}
Matrix Matrix::operator++(int)//инкремент постфиксный
{
	Matrix Old_matrix(*this);
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[i][j]++;
		}
	}
	return Old_matrix;
}
Matrix::operator int(){	return  kv;}
//лаб 3
//Ни функция вставки, ни функция извлечения не могут быть членами клас­са.
//Причина заключается в том, что если функция - оператор является членом класса, то левым операндом, неявно передаваемым с использованием указателя this,
//служит объект того класса, который осуществляет вызов функции - оператора.И нет способа изменить такой порядок.
//Вместе с тем при перегрузке оператора вставки левым аргументом является поток, а правым аргументом — объект класса.
ofstream& operator<<(ofstream& ofs, Matrix& my_matrix)
{
	for (int i = 0; i < my_matrix.kv; i++)//строки
	{
		for (int j = 0; j < my_matrix.kv; j++)//столбики
		{
			ofs << my_matrix.matrix[i][j]<< " ";
		}
		ofs << endl;
	}
	return ofs;
}
ifstream& operator>>(ifstream& ofs, Matrix& my_matrix)
{
	for (int i = 0; i < my_matrix.kv; i++)//строки
	{
		for (int j = 0; j < my_matrix.kv; j++)//столбики
		{
			ofs >> my_matrix.matrix[i][j];
		}
	}
	return ofs;
}
Matrix::Matrix(int k)//конструктор пустой матрицы
{
	kv = k;
	matrix = new int*[kv];//строки
	for (int count = 0; count < kv; count++)matrix[count] = new int[kv];//столбики
	//указатели на память из main
	for (int i = 0; i < kv; i++)//строки
	{
		for (int j = 0; j < kv; j++)//столбики
		{
			matrix[i][j] = 0;
		}
	}
}
//лаб 4
IdentityMatrix::IdentityMatrix(int **a, int k) : Matrix(a, k) {};//для единичной матрицы вызываем конструктор с пар.
//IdentityMatrix::~IdentityMatrix() {};
RectangularMatrix::RectangularMatrix() : Matrix() {};
RectangularMatrix::RectangularMatrix(int **a, int height, int width)
{
	Height = height;
	Width = width;
	matrix = new int*[height];//строки
	for (int count = 0; count < height; count++)matrix[count] = new int[width];//столбики
	//указатели на память из main
	for (int i = 0; i < height; i++)//строки
	{
		for (int j = 0; j < width; j++)//столбики
		{
			matrix[i][j] = a[i][j];
		}
	}
}
RectangularMatrix::RectangularMatrix(int **a, int k):Matrix(a, k) {};//если матр. кв. то выз. род. конст.
RectangularMatrix::~RectangularMatrix()
{
	if (Height != Width)
	{
		for (int count = 0; count < Height; count++)delete[]matrix[count];
		delete[]matrix;
	}
}

//лаб 5
void QueueList::Add(int **a, int Width, int Height)
{
	kol++;
	if (Width == Height)//квадратная
	{
		NodeMatrix *temp = new NodeMatrix;//Выделение памяти под новый элемент класса (вызов конструктора по умолчанию)
		temp->Next = NULL;  //Указываем, что изначально по следующему адресу пусто
		temp-> myMatrix = new Matrix(a, Width);//Записываем значение

		if (Head != NULL) //Если список не пуст
		{
			temp->Prev = Tail; //Указываем адрес на предыдущий элемент в соотв. поле
			Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
			Tail = temp; //Меняем адрес хвоста
		}
		else //Если список пустой
		{
			temp->Prev = NULL; //Предыдущий элемент указывает в пустоту
			Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
		}
	}
	if (Width != Height)//прямоугольная
	{		
		NodeRectangularMatrix *temp = new NodeRectangularMatrix;//Выделение памяти под новый элемент класса (вызов конструктора по умолчанию)
		temp->Next = NULL;  //Указываем, что изначально по следующему адресу пусто
		temp->myMatrix = new RectangularMatrix(a, Height, Width);//Записываем значение

		if (Head != NULL) //Если список не пуст
		{
			temp->Prev = Tail; //Указываем адрес на предыдущий элемент в соотв. поле
			Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
			Tail = temp; //Меняем адрес хвоста
		}
		else //Если список пустой
		{
			temp->Prev = NULL; //Предыдущий элемент указывает в пустоту
			Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
		}
	}
	//if (Width == 1 && Height == 1)//ед
	//{
	//	NodeIdentityMatrix *temp = new NodeIdentityMatrix;//Выделение памяти под новый элемент класса (вызов конструктора по умолчанию)
	//	temp->Next = NULL;  //Указываем, что изначально по следующему адресу пусто
	//	temp->myMatrix = new IdentityMatrix(a, Height);//Записываем значение
	//	if (Head != NULL) //Если список не пуст
	//	{
	//		temp->Prev = Tail; //Указываем адрес на предыдущий элемент в соотв. поле
	//		Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
	//		Tail = temp; //Меняем адрес хвоста
	//	}
	//	else //Если список пустой
	//	{
	//		temp->Prev = NULL; //Предыдущий элемент указывает в пустоту
	//		Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
	//	}
	//}
}
void QueueList::Remove()
{
	kol--;
	Tail = Head->Next; //Резервная копия адреса следующего звена списка
	Head->~Node();
	delete Head; //Очистка памяти от первого звена
	Head = Tail; //Смена адреса начала на адрес следующего элемента
}
void QueueList::PrintList()
{
	//ВЫВОДИМ СПИСОК ВП
	Node *temp = Head;
	//Временный указатель на адрес последнего элемента
	while (temp != NULL) //Пока не встретится пустое значение
	{
		temp->PrintNode(); //Выводить значение на экран
		temp = temp->Next; //Указываем, что нужен адрес предыдущего элемента
	}
	//ВЫВОДИМ СПИСОК НАЗ
	//temp = Tail; //Временно указываем на адрес первого элемента
	//while (temp != NULL) //Пока не встретим пустое значение
	//{
	//	cout << temp->value << " "; //Выводим каждое считанное значение на экран
	//	temp = temp->Prev; //Смена адреса на адрес следующего элемента
	//}
	//cout << "\n";
}
void QueueList::Search(int a)
{
	Node * temp = Head;
	for (int i = 0; i < a; i++)
	{		
		temp = temp->Next;	
		if (temp->Next == NULL)
		{
			i++;
			temp = Head;
		}
	}
	cout << " Ваше число :";
	cout << " -------------------------------" << endl;
	temp->PrintNode();
	cout << " -------------------------------" << endl;
}
QueueList::~QueueList() //Деструктор
{
	while (Head) //Пока по адресу на начало списка что-то есть
	{
		Tail = Head->Next; //Резервная копия адреса следующего звена списка	
		Head->~Node();
		delete Head; //Очистка памяти от первого звена
		Head = Tail; //Смена адреса начала на адрес следующего элемента
	}
}
void NodeMatrix::PrintNode()
{
	myMatrix->Print(0,0);
}
void NodeRectangularMatrix::PrintNode()
{
	myMatrix->Print(myMatrix->Height, myMatrix->Width);
}
void NodeIdentityMatrix::PrintNode()
{
	myMatrix->Print(0,0);
}
NodeMatrix::~NodeMatrix()
{
	myMatrix->~Matrix();
}
NodeRectangularMatrix::~NodeRectangularMatrix()
{
	myMatrix->~RectangularMatrix();
}
NodeIdentityMatrix::~NodeIdentityMatrix()
{
	myMatrix->~IdentityMatrix();
}
//6 лаб 
void Matrix::Iskl(int k)
{
	char *str = nullptr;
	try
	{
		if (k == 1)throw 1;
		if (k == 2)throw 2;
		str = new char[30];
		throw "exception";
		delete[] str;//не выполняется 
	}
	catch (int a)
	{
		if (a == 1)cout << "Хорошо!" << endl;
		if (a == 2)cout << "Слишком большая матрица!" << endl;
		return;
	}
	catch (...)
	{
		cout << "Плохо. Память" << endl;
		delete[] str;
		return;
	}
}