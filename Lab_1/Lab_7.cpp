#include "Functions.h"

void Start7lab(int e)
{
	bool a = true;	

	cout << " ������� ������ �������: " << endl << endl << ">> ";
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
		system("cls");//������� ������
		while (a)
		{			
			cout << " [ 1 ] ��������" << endl;
			cout << " [ 2 ] �������" << endl;
			cout << " [ 3 ] Exit" << endl << endl << ">> ";
			cin >> e;
			if (e == 3)a = false;
			else if (e == 1)//����������
			{
				cout << " ������� ������� :" << endl << endl << ">> ";
				cin >> iList->SizeQueue[iList->currentSize];
				iList->Add(&(iList->SizeQueue[iList->currentSize]));
				system("cls");//������� ������
				iList->PrintList();
			}
			else if (e == 2)//��������
			{
				system("cls");//������� ������
				if (iList->maxCurrent != NULL)iList->Remove();
				else
				{
					cout << "��������� ���" << endl;
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