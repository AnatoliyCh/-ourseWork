#include "Header_Binary_Class.h"
using namespace std;

char* addName(char *);//приведение имени файла к нормальному виду

char Way[6] = "File/";//путь
char Expansion[5] = ".dat";//расширение

void main()
{
	int k;
	bool a = true, createdFile;
	char nameFile[30];//имя файла и временная переменная (по 1byte)

	setlocale(LC_ALL, ".ACP");//рус. яз.
	cout << endl << " Меню:" << endl;
	cout << " [ 1 ] Создать файл." << endl;
	cout << " [ 2 ] Работа с созданными файлами." << endl << endl << ">> ";
	cin >> k;
	if (k == 1) createdFile = true;
	else if (k == 2) createdFile = false;

	system("cls");//очистка консоли
	cout << endl << " Введите имя файла :" << endl << endl << ">> ";
	cin >> nameFile;
	addName(nameFile);//приведение имени файла к нормальному виду

	system("cls");//очистка консоли
	cout << " Тип данных : " << endl;
	//cout << " [ 0 ] string " << endl;
	cout << " [ 1 ] int " << endl;
	cout << " [ 2 ] char " << endl << endl << ">> ";
	cin >> k;
	if (k == 1)
	{
		binFile<int>myFile(nameFile, createdFile);//работа с файлом

		int variable;
		while (a)
		{
			system("cls");//очистка экрана		
			myFile.reviewFile();
			cout << endl << " [ 1 ] Добавить элемент. " << endl;
			cout << " [ 2 ] Удалить элемент. " << endl;
			cout << " [ 3 ] Сортировка. " << endl;
			cout << " [ 4 ] Обновить элемент. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " Введите значение :" << endl << endl << ">> ";
				cin >> variable;
				myFile.addVariable(variable);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//очистка экрана
				myFile.reviewFile();
				cout << endl << " Номер элемента: " << endl << endl << ">> ";
				cin >> k;				
				myFile.update(k);
			}			
		}
	}
	else if (k == 2)
	{
		binFile<char>myFile(nameFile, createdFile);//работа с файлом

		char variable;
		while (a)
		{
			system("cls");//очистка экрана		
			myFile.reviewFile();
			cout << endl << " [ 1 ] Добавить элемент. " << endl;
			cout << " [ 2 ] Удалить элемент. " << endl;
			cout << " [ 3 ] Сортировка. " << endl;
			cout << " [ 4 ] Обновить элемент. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " Введите значение :" << endl << endl << ">> ";
				cin >> variable;
				myFile.addVariable(variable);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//очистка экрана
				myFile.reviewFile();
				cout << endl << " Номер элемента: " << endl << endl << ">> ";
				cin >> k;				
				myFile.update(k);
			}
		}
	}
	else if (k == 0)
	{
		binFile<char>myFile(nameFile, createdFile);//работа с файлом

		string variable;
		char Mass[100] = "\0";
		while (a)
		{
			system("cls");//очистка экрана		
			myFile.reviewFile();
			cout << endl << " [ 1 ] Добавить элемент. " << endl;
			cout << " [ 2 ] Удалить элемент. " << endl;
			cout << " [ 3 ] Сортировка. " << endl;
			cout << " [ 4 ] Обновить элемент. " << endl;
			cout << " [ 5 ] Exit" << endl << endl << ">> ";
			cin >> k;

			if (k == 5) a = false;
			else if (k == 1)
			{
				cout << endl << " Введите значение :" << endl << endl << ">> ";
				cin >> variable;
				strcpy_s(Mass, variable.c_str());
				for(int i = 0; i<variable.length(); i++)myFile.addVariable(Mass[i]);
			}
			else if (k == 2)myFile.remVariable();
			else if (k == 3)myFile.sortObject();
			else if (k == 4)
			{
				system("cls");//очистка экрана
				myFile.reviewFile();
				cout << endl << " Номер элемента: " << endl << endl << ">> ";
				cin >> k;
				myFile.update(k);
			}
		}
	}
	system("pause");
}

char* addName(char *nameFile)//обработчик имени файла
{	
	int nameSize = strlen(nameFile);
	char charBuf[19];//буффер
	for (int i = 0; i < nameSize; i++)charBuf[i] = nameFile[i];//копируем имя в буффер
	for (int i = 0; i < 5; i++)nameFile[i] = Way[i];//указание пути
	for (int i = 5; i < 5 + nameSize; i++)nameFile[i] = charBuf[i - 5];//добавление имени	
	for (int i = 5 + nameSize; i < 5 + 4 + nameSize; i++)nameFile[i] = Expansion[i - nameSize - 5];//добавления расширения
	nameFile[5 + 4 + nameSize] = '\0';//конец строки
	return nameFile;
}

