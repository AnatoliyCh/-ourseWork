#include "Functions.h"

void Start3lab(int k, int e, Matrix *my_matrix)
{	
	cout << " [ 1 ] �������� ������� � txt" << endl;
	cout << " [ 2 ] �������� ������� � bat" << endl << endl << ">> ";
	cin >> e;

	Matrix * my_matrixFile = new Matrix(k);//������ ������ �������
	if (e == 1)//������ � txt
	{
		ofstream fileTXT("Matrix.txt", ios::out);//�������� � ������� � ����.txt
		if (!fileTXT)
		{
			cerr << "Error: ��������/������ ����� " << endl;
			exit(1);
		}
		else
		{			
			fileTXT << *my_matrix;
			fileTXT << my_matrix->kv;//������ �������
			fileTXT.close();//�������� ������
			cout << " ����� ����� txt Yes[1] / No[2] " << endl << endl << ">> ";
			cin >> e;
			if (e == 1)
			{
				ifstream fileTXT("Matrix.txt", ios::in);//��������� ��� ������ �� �����.txt
				fileTXT >> *my_matrixFile;//�������
				fileTXT >> my_matrixFile->kv;//������ �������
				my_matrixFile->Print(0, 0);
				fileTXT.close();//�������� ������
			}
		}
	}
	else if (e == 2)//������ � bat
	{
		ofstream fileDAT("Matrix.dat");//�������� � ������� � ����.dat
		if (!fileDAT) {
			cerr << "Error: ��������/������ ����� " << endl;
			exit(1);
		}
		else
		{
			int k = my_matrix->kv;//������ �������
			fileDAT.write((char*)&(*my_matrix), sizeof(Matrix));
			fileDAT.write((char*)&(k), sizeof(int));
			fileDAT.close();
			cout << " ����� ����� bat Yes[3] / No[4] " << endl << endl << ">> ";
			cin >> e;
			if (e == 3)
			{ 
				ifstream fileDAT("Matrix.dat");//��������� ��� ������ �� �����.dat
				fileDAT.read((char*)&(*my_matrixFile), sizeof(Matrix));
				fileDAT.close();
				my_matrixFile->Print(0, 0);
			}
		}
	}
	if (e != 3)delete my_matrixFile;
}