#include "Functions.h"

int** EnterTheMatrix(int Width, int Height)
{
	int **one = new int *[Height];//������ ����������
	for (int count = 0; count < Height; count++) one[count] = new int[Width];

	cout << " ������� : " << Height << "x" << Width << endl << " ��������� ������� : " << endl << endl << ">> ";

	//����
	for (int i = 0; i < Height; i++)//������
	{
		for (int j = 0; j < Width; j++)//��������
		{
			cin >> one[i][j];
		}
	}
	return one;
}

void Start5lab(int k, int e)
{
	system("cls");//������� ������
	int Width = 0, Height = 0; //������ � ������ �������             
	QueueList * List = new QueueList();//������ ������
	bool v = true;
	for (v;;)
	{ 
		cout << " [ 1 ] ������ �������" << endl;
		cout << " [ 2 ] ������� �������" << endl;
		cout << " [ 3 ] ����� �" << endl;
		cout << " [ 4 ] End" << endl << endl << ">> ";

		cin >> e;

		if (e == 4)break;
		else if (e == 1)
		{
			cout << " ������� ����������� ������� : ";
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
			cout << " ������� ����� : ";
			cin >> a;
			List->Search(a);
		}
		List->PrintList();
	}

	delete List;
}