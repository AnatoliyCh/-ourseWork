#include "Header_Binary_Class.h"
using namespace std;

char* addName(char *);//���������� ����� ����� � ����������� ����

char Way[6] = "File/";//����
char Expansion[5] = ".dat";//����������

void main()
{
	int k;
	bool a = true, createdFile;
	char nameFile[30];//��� ����� � ��������� ���������� (�� 1byte)

	setlocale(LC_ALL, ".ACP");//���. ��.
	cout << endl << " ����:" << endl;
	cout << " [ 1 ] ������� ����." << endl;
	cout << " [ 2 ] ������ � ���������� �������." << endl << endl << ">> ";
	cin >> k;
	if (k == 1) createdFile = true;
	else if (k == 2) createdFile = false;

	system("cls");//������� �������
	cout << endl << " ������� ��� ����� :" << endl << endl << ">> ";
	cin >> nameFile;
	addName(nameFile);//���������� ����� ����� � ����������� ����

	system("cls");//������� �������
	cout << " ��� ������ : " << endl;
	//cout << " [ 0 ] string " << endl;
	cout << " [ 1 ] int " << endl;
	cout << " [ 2 ] char " << endl << endl << ">> ";
	cin >> k;
	if (k == 1)
	{
		binFile<int>myFile(nameFile, createdFile);//������ � ������

		int variable;
		while (a)
		{
			system("cls");//������� ������		
			myFile.reviewFile();
			cout << endl << " [ 1 ] �������� �������. " << endl;
			cout << " [ 2 ] ������� �������. " << endl;
			cout << " [ 3 ] ����������. " << endl;
			cout << " [ 4 ] �������� �������. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " ������� �������� :" << endl << endl << ">> ";
				cin >> variable;
				myFile.addVariable(variable);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//������� ������
				myFile.reviewFile();
				cout << endl << " ����� ��������: " << endl << endl << ">> ";
				cin >> k;				
				myFile.update(k);
			}			
		}
	}
	else if (k == 2)
	{
		binFile<char>myFile(nameFile, createdFile);//������ � ������

		char variable;
		while (a)
		{
			system("cls");//������� ������		
			myFile.reviewFile();
			cout << endl << " [ 1 ] �������� �������. " << endl;
			cout << " [ 2 ] ������� �������. " << endl;
			cout << " [ 3 ] ����������. " << endl;
			cout << " [ 4 ] �������� �������. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " ������� �������� :" << endl << endl << ">> ";
				cin >> variable;
				myFile.addVariable(variable);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//������� ������
				myFile.reviewFile();
				cout << endl << " ����� ��������: " << endl << endl << ">> ";
				cin >> k;				
				myFile.update(k);
			}
		}
	}
	else if (k == 0)
	{
		binFile<char>myFile(nameFile, createdFile);//������ � ������

		string variable;
		char Mass[100] = "\0";
		while (a)
		{
			system("cls");//������� ������		
			myFile.reviewFile();
			cout << endl << " [ 1 ] �������� �������. " << endl;
			cout << " [ 2 ] ������� �������. " << endl;
			cout << " [ 3 ] ����������. " << endl;
			cout << " [ 4 ] �������� �������. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " ������� �������� :" << endl << endl << ">> ";
				cin >> variable;
				strcpy_s(Mass, variable.c_str());
				for(int i = 0; i<variable.length(); i++)myFile.addVariable(Mass[i]);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//������� ������
				myFile.reviewFile();
				cout << endl << " ����� ��������: " << endl << endl << ">> ";
				cin >> k;
				myFile.update(k);
			}
		}
	}
	system("pause");
}

char* addName(char *nameFile)//���������� ����� �����
{	
	int nameSize = strlen(nameFile);
	char charBuf[19];//������
	for (int i = 0; i < nameSize; i++)charBuf[i] = nameFile[i];//�������� ��� � ������
	for (int i = 0; i < 5; i++)nameFile[i] = Way[i];//�������� ����
	for (int i = 5; i < 5 + nameSize; i++)nameFile[i] = charBuf[i - 5];//���������� �����	
	for (int i = 5 + nameSize; i < 5 + 4 + nameSize; i++)nameFile[i] = Expansion[i - nameSize - 5];//���������� ����������
	nameFile[5 + 4 + nameSize] = '\0';//����� ������
	return nameFile;
}

