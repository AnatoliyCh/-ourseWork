#include "Functions.h"

void main()
{
	system("cls");//������� ������
	setlocale(LC_ALL, ".ACP");//���. ��.
	int k, e;
	cout << " ������� ����������� ������� : ";
	/// 6 ���. ������
	/*try	{*/
		cin >> k;

		/*if ((int)k != k)throw k;
		if (k<0)throw (char)k;*/
	/*}
	catch (float k)
	{
		cout << endl << "����������� ������� ������ ���� �����!" << endl;
		system("pause");
		return;
	}
	catch (char k)
	{
		cout << endl << "����������� ������� ������ ���� �����, �� ����� �����!" << endl;
		system("pause");
		return;
	}*/
	/// 6 ���. ������
	if (k == 0)//��� ������� �������
	{
		Matrix Nullmatrix;
		Nullmatrix.Print(0, 0);
	}
	cout << " ������� : " << k << "x" << k << endl << " ��������� ������� : " << endl << endl << ">> ";
	int **a = new int*[k];//������ ����������
	for (int count = 0; count < k; count++)a[count] = new int[k];
	//����
	for (int i = 0; i < k; i++)//������
	{
		for (int j = 0; j < k; j++)//��������
		{
			cin >> a[i][j];
		}
	}
	cout << endl << " ���� ������� : " << endl;
	Matrix * my_matrix = new Matrix(a, k);//�������� ��������� �� ���������� ���� Matrix
	my_matrix->Print(0, 0);//�����
	Matrix * my_matrixTransponir = new Matrix(*my_matrix);

	cout << " [ 1 ] ������������ 1" << endl;
	cout << " [ 2 ] ������������ 2" << endl;
	cout << " [ 3 ] ������������ 3" << endl;
	cout << " [ 4 ] ������������ 4" << endl;
	cout << " [ 5 ] ������������ 5" << endl;
	cout << " [ 6 ] ������������ 6" << endl;
	cout << " [ 7 ] ������������ 7" << endl << endl << ">> ";
	cin >> e;

	if (e == 1)
	{
		cout << " ��������������� �������? Yes[1] / No[2] " << endl << endl << ">> ";

		cin >> e;
		if (e == 1)
		{
			my_matrixTransponir->Transponir(*my_matrix);//����������������
			my_matrixTransponir->Print(0, 0);//�����
		}

		cout << " [ 1 ] ����� ������������ �������� �������" << endl;
		cout << " [ 2 ] ����� ������������ ����������������� �������" << endl << endl << ">> ";

		cin >> e;
		if (e == 1)my_matrix->Determinant();//������������
		else if (e == 2)my_matrixTransponir->Determinant();//������������
	}
	else if (e == 2) Start2lab(k, e, my_matrix, my_matrixTransponir);//���� 2
	else if (e == 3) Start3lab(k, e, my_matrix);//���� 3
	else if (e == 4) Start4lab(k, e);//���� 4
	else if (e == 5) Start5lab(k, e);//���� 5
	else if (e == 6) my_matrix->Iskl(my_matrix->kv);//���� 6
	else if (e == 7) Start7lab(e);//���� 7

	delete my_matrix;
	delete my_matrixTransponir;
	for (int count = 0; count < k; count++)delete[]a[count];
	delete[]a;		
	
	system("pause");
}