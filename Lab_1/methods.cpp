#include "Functions.h"
//��� 1
Matrix::Matrix()//����������� ��� ���������
{
	matrix = nullptr;
	kv = 0;
}
Matrix::Matrix(int **a, int k)//����������� ���������� �������
{
	kv = k;
	matrix = new int*[kv];//������
	for (int count = 0; count < kv; count++)matrix[count] = new int[kv];//��������
	//��������� �� ������ �� main
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			matrix[i][j] = a[i][j];
		}
	}
}
Matrix::Matrix(const Matrix &my_matrix)//����������� ����������� 
{
	kv = my_matrix.kv;
	matrix = new int*[my_matrix.kv];//������
	for (int count = 0; count < my_matrix.kv; count++)matrix[count] = new int[my_matrix.kv];//��������
	//�����������
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
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
void Matrix::Transponir(const Matrix &my_matrix)//���������������� �������
{
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			matrix[j][i] = my_matrix.matrix[i][j];
		}
	}
}
void Matrix::Determinant()//������ ������������
{
	int l = 0, Ldiagonal = 1, Rdiagonal = 1;
	if (kv == 1)
	{
		determ = matrix[0][0];
		cout << endl << " ������������ :  " << determ << endl << endl;
	}
		
	else if (kv == 2)
		{			
			for (int i = 0; i < kv; i++)//������
			{
				Ldiagonal = Ldiagonal * matrix[i][i];
			}
			for (int i = kv - 1; i >= 0; i--)//������
			{
				Rdiagonal = Rdiagonal * matrix[i][l];
				l++;
			}
			determ = Ldiagonal - Rdiagonal;
			cout << endl << " ������������ :  " << determ << endl << endl;
		}
	else
		{
		int w = 0;
			for (int i = 0; i < kv; i++)//������
			{
				for (0; w < kv; w++)//��������
				{
					determ = determ*(matrix[i][w] / matrix[i][i]);
				}
				w = i;
			}
			cout << endl;
			cout << endl << " ������������ :  " << determ << endl << endl;
		}	
}
void Matrix::Print(int Height, int Width)
{	
	if (Height == Width)
	{
		cout << endl;
		//�����
		for (int i = 0; i < kv; i++)//������
		{
			for (int j = 0; j < kv; j++)//��������
			{
				cout << " " << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < Height; i++)//������
		{
			for (int j = 0; j < Width; j++)//��������
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
}
//��� 2
Matrix Matrix::operator+(Matrix my_matrix)//�������� ��������, ��� ����� ������ 
{
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			matrix[i][j] = matrix[i][j] + my_matrix.matrix[i][j];
		}
	}
	return *this;
}
Matrix operator-(Matrix my_matrix, Matrix my_matrixCopy)//�������� ��������� ����.
{
	for (int i = 0; i < my_matrix.kv; i++)//������
	{
		for (int j = 0; j < my_matrix.kv; j++)//��������
		{
			my_matrix.matrix[i][j] = my_matrix.matrix[i][j] - my_matrixCopy.matrix[i][j];
		}
	}
	return my_matrix;
}
Matrix& Matrix::operator++()//��������� ����������
{	
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			++matrix[i][j];
		}
	}
	return *this;
}
Matrix Matrix::operator++(int)//��������� �����������
{
	Matrix Old_matrix(*this);
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			matrix[i][j]++;
		}
	}
	return Old_matrix;
}
Matrix::operator int(){	return  kv;}
//��� 3
//�� ������� �������, �� ������� ���������� �� ����� ���� ������� ������.
//������� ����������� � ���, ��� ���� ������� - �������� �������� ������ ������, �� ����� ���������, ������ ������������ � �������������� ��������� this,
//������ ������ ���� ������, ������� ������������ ����� ������� - ���������.� ��� ������� �������� ����� �������.
//������ � ��� ��� ���������� ��������� ������� ����� ���������� �������� �����, � ������ ���������� � ������ ������.
ofstream& operator<<(ofstream& ofs, Matrix& my_matrix)
{
	for (int i = 0; i < my_matrix.kv; i++)//������
	{
		for (int j = 0; j < my_matrix.kv; j++)//��������
		{
			ofs << my_matrix.matrix[i][j]<< " ";
		}
		ofs << endl;
	}
	return ofs;
}
ifstream& operator>>(ifstream& ofs, Matrix& my_matrix)
{
	for (int i = 0; i < my_matrix.kv; i++)//������
	{
		for (int j = 0; j < my_matrix.kv; j++)//��������
		{
			ofs >> my_matrix.matrix[i][j];
		}
	}
	return ofs;
}
Matrix::Matrix(int k)//����������� ������ �������
{
	kv = k;
	matrix = new int*[kv];//������
	for (int count = 0; count < kv; count++)matrix[count] = new int[kv];//��������
	//��������� �� ������ �� main
	for (int i = 0; i < kv; i++)//������
	{
		for (int j = 0; j < kv; j++)//��������
		{
			matrix[i][j] = 0;
		}
	}
}
//��� 4
IdentityMatrix::IdentityMatrix(int **a, int k) : Matrix(a, k) {};//��� ��������� ������� �������� ����������� � ���.
//IdentityMatrix::~IdentityMatrix() {};
RectangularMatrix::RectangularMatrix() : Matrix() {};
RectangularMatrix::RectangularMatrix(int **a, int height, int width)
{
	Height = height;
	Width = width;
	matrix = new int*[height];//������
	for (int count = 0; count < height; count++)matrix[count] = new int[width];//��������
	//��������� �� ������ �� main
	for (int i = 0; i < height; i++)//������
	{
		for (int j = 0; j < width; j++)//��������
		{
			matrix[i][j] = a[i][j];
		}
	}
}
RectangularMatrix::RectangularMatrix(int **a, int k):Matrix(a, k) {};//���� ����. ��. �� ���. ���. �����.
RectangularMatrix::~RectangularMatrix()
{
	if (Height != Width)
	{
		for (int count = 0; count < Height; count++)delete[]matrix[count];
		delete[]matrix;
	}
}

//��� 5
void QueueList::Add(int **a, int Width, int Height)
{
	kol++;
	if (Width == Height)//����������
	{
		NodeMatrix *temp = new NodeMatrix;//��������� ������ ��� ����� ������� ������ (����� ������������ �� ���������)
		temp->Next = NULL;  //���������, ��� ���������� �� ���������� ������ �����
		temp-> myMatrix = new Matrix(a, Width);//���������� ��������

		if (Head != NULL) //���� ������ �� ����
		{
			temp->Prev = Tail; //��������� ����� �� ���������� ������� � �����. ����
			Tail->Next = temp; //��������� ����� ���������� �� ������� ��������
			Tail = temp; //������ ����� ������
		}
		else //���� ������ ������
		{
			temp->Prev = NULL; //���������� ������� ��������� � �������
			Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
		}
	}
	if (Width != Height)//�������������
	{		
		NodeRectangularMatrix *temp = new NodeRectangularMatrix;//��������� ������ ��� ����� ������� ������ (����� ������������ �� ���������)
		temp->Next = NULL;  //���������, ��� ���������� �� ���������� ������ �����
		temp->myMatrix = new RectangularMatrix(a, Height, Width);//���������� ��������

		if (Head != NULL) //���� ������ �� ����
		{
			temp->Prev = Tail; //��������� ����� �� ���������� ������� � �����. ����
			Tail->Next = temp; //��������� ����� ���������� �� ������� ��������
			Tail = temp; //������ ����� ������
		}
		else //���� ������ ������
		{
			temp->Prev = NULL; //���������� ������� ��������� � �������
			Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
		}
	}
	//if (Width == 1 && Height == 1)//��
	//{
	//	NodeIdentityMatrix *temp = new NodeIdentityMatrix;//��������� ������ ��� ����� ������� ������ (����� ������������ �� ���������)
	//	temp->Next = NULL;  //���������, ��� ���������� �� ���������� ������ �����
	//	temp->myMatrix = new IdentityMatrix(a, Height);//���������� ��������
	//	if (Head != NULL) //���� ������ �� ����
	//	{
	//		temp->Prev = Tail; //��������� ����� �� ���������� ������� � �����. ����
	//		Tail->Next = temp; //��������� ����� ���������� �� ������� ��������
	//		Tail = temp; //������ ����� ������
	//	}
	//	else //���� ������ ������
	//	{
	//		temp->Prev = NULL; //���������� ������� ��������� � �������
	//		Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
	//	}
	//}
}
void QueueList::Remove()
{
	kol--;
	Tail = Head->Next; //��������� ����� ������ ���������� ����� ������
	Head->~Node();
	delete Head; //������� ������ �� ������� �����
	Head = Tail; //����� ������ ������ �� ����� ���������� ��������
}
void QueueList::PrintList()
{
	//������� ������ ��
	Node *temp = Head;
	//��������� ��������� �� ����� ���������� ��������
	while (temp != NULL) //���� �� ���������� ������ ��������
	{
		temp->PrintNode(); //�������� �������� �� �����
		temp = temp->Next; //���������, ��� ����� ����� ����������� ��������
	}
	//������� ������ ���
	//temp = Tail; //�������� ��������� �� ����� ������� ��������
	//while (temp != NULL) //���� �� �������� ������ ��������
	//{
	//	cout << temp->value << " "; //������� ������ ��������� �������� �� �����
	//	temp = temp->Prev; //����� ������ �� ����� ���������� ��������
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
	cout << " ���� ����� :";
	cout << " -------------------------------" << endl;
	temp->PrintNode();
	cout << " -------------------------------" << endl;
}
QueueList::~QueueList() //����������
{
	while (Head) //���� �� ������ �� ������ ������ ���-�� ����
	{
		Tail = Head->Next; //��������� ����� ������ ���������� ����� ������	
		Head->~Node();
		delete Head; //������� ������ �� ������� �����
		Head = Tail; //����� ������ ������ �� ����� ���������� ��������
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
//6 ��� 
void Matrix::Iskl(int k)
{
	char *str = nullptr;
	try
	{
		if (k == 1)throw 1;
		if (k == 2)throw 2;
		str = new char[30];
		throw "exception";
		delete[] str;//�� ����������� 
	}
	catch (int a)
	{
		if (a == 1)cout << "������!" << endl;
		if (a == 2)cout << "������� ������� �������!" << endl;
		return;
	}
	catch (...)
	{
		cout << "�����. ������" << endl;
		delete[] str;
		return;
	}
}