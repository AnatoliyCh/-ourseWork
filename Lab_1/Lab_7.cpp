#include "Functions.h"

void Start7lab(int e)
{
	bool a = true;	

	cout << " Введите размер очереди: " << endl << endl << ">> ";
	cin >> e;	
	int *Arr = new int[e];
	//float *ArrF = new float[e];

	List<int> *iList = new List<int>(Arr,e);
	//List<float> *fList = new List<float>(ArrF, e);

	cout << " [ 1 ] int" << endl;
	cout << " [ 2 ] float" << endl;
	cin >> e;
	
	if (e == 1)
	{
		system("cls");//очистка экрана
		while (a)
		{			
			cout << " [ 1 ] Добавить" << endl;
			cout << " [ 2 ] Удалить" << endl;
			cout << " [ 3 ] Exit" << endl << endl << ">> ";
			cin >> e;
			if (e == 3)a = false;
			else if (e == 1)//добавление
			{
				cout << " введите элемент :" << endl << endl << ">> ";
				cin >> iList->SizeQueue[iList->currentSize];
				iList->Add(&(iList->SizeQueue[iList->currentSize]));
				system("cls");//очистка экрана
				iList->PrintList();
			}
			else if (e == 2)//удаление
			{
				system("cls");//очистка экрана
				if (iList->maxCurrent != NULL)iList->Remove();
				else
				{
					cout << "Элементов нет" << endl;
				}				
				iList->PrintList();
			}	
		}
	}
	else if (e == 2)
	{
		
	}		

	delete[] Arr;
	delete iList;
}