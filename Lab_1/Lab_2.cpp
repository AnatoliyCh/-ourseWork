#include "Functions.h"

void Start2lab(int k, int e, Matrix *my_matrix, Matrix *my_matrixTransponir)
{
	cout << " [ 1 ] ������� �������" << endl;
	cout << " [ 2 ] ������� �������" << endl;
	cout << " [ 3 ] �������� ������� = �������++" << endl;
	cout << " [ 4 ] �������� ������� = ++�������" << endl << endl << ">> ";

	cin >> e;
	switch (e)
	{
	case 1:
		((*my_matrix) + (*my_matrixTransponir)).Print(0, 0);//�������� �������(�-��) ������		
		break;
	case 2:
		(*my_matrix - *my_matrixTransponir).Print(0, 0);//��������� ������������� �-��
		break;
	case 3:
		((*my_matrix)++).Print(0, 0);//��������� �����������
		break;
	case 4:
		(++*my_matrix).Print(0, 0);//��������� ����������
		break;
	}

	cout << " ��������� ������� � int? Yes[1] / No[2] " << endl << endl << ">> ";

	cin >> e;
	if (e == 1)
	{
		cout << (int)(*my_matrix) << endl;
	}
}