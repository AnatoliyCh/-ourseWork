#include <iostream>//�/��� �������
#include <fstream> //����� �������� �������
#include <cstdlib>
using namespace std;
//����
#include <string>


template<class tipeData> class binFile : public fstream
{
public://��������� ������ ��� ���������
	int Size = 1;//������ ������� ���������� (4byte)
	int realSize = NULL;//������� ���������� ���������� (4byte)
	int ptrBeginArr = (int)nullptr;//����� ������ ������� ���������� / ���������
	int ptrFile = NULL;//��������� �� ���� �����/������
	int counterPtr = NULL;//������� ������ ������ � ���� (byte)	
	tipeData buf;//��������� ������ �������

	//������
	char bufnameFile[30];//��� �����
public:
	binFile(const char *nameFile, bool createdFile): basic_fstream(nameFile, ios::in | ios::out | ios::binary | (createdFile?ios::trunc :0))//�������� �����
	{
		if (is_open())
		{
			if (createdFile)
			{
				write((char*)&Size, sizeof(int));//������ ������� ������� ���������� (4byte)
				write((char*)&realSize, sizeof(int));//������ �������� ���������� ���������� (4byte)
				ptrFile = tellg();//��������� �� ���� �����/������ ������ �� ����� ���������� �������� (g - ��. �� ������)
				counterPtr = sizeof(int) + sizeof(tipeData);//����� �� ������ ���� ����� ������		
				seekg(ptrFile + counterPtr, ios::beg);//�������� ��������� ������ �� 2*tipeData
				ptrBeginArr = tellg();//������ ����� ������ ������� ���������� (g - ��. �� ������)
				seekg(ptrFile, ios::beg);//��������� ����� ������ �� ������ ������ ������ ����������
				write((char*)&ptrBeginArr, sizeof(int));//���������� ����� ������ ������� ����������
				Size = realSize = ptrFile = counterPtr = ptrBeginArr = (int)nullptr;			
			}
			else
			{
				cout << endl << " ���� ������ " << endl;
				positionCounterPtr();
			}
			for (int i = 0; i < 30; i++) bufnameFile[i] = nameFile[i];
		}
		else
		{
			cout << " Error!! " << endl;
			system("pause");
			exit(1);
		}
	}
	~binFile()
	{
		Size = realSize = ptrFile = ptrBeginArr = (int)nullptr;
		//buf = (tipeData)nullptr;
		close();
	}
	fstream& operator << (tipeData &object)//����
	{		
		write((char*)&object, sizeof(tipeData));	
		return *this;
	}
	fstream& operator >> (tipeData &object)//�����
	{
		read((char*)&object, sizeof(tipeData));
		return *this;
	}
	void addVariable(tipeData object)//���������� � ������
	{
		seekp(ios::beg);//������ � ������ ����� (p - ��. �� ������)
		read((char*) &Size, sizeof(int));//��������� ������ �������
		read((char*) &realSize, sizeof(int));//��������� ������� ���������� ��.
		read((char*)&ptrBeginArr, sizeof(int));//����� ������ ������� ����������	
		ptrFile = tellp();//��������� �� ����� ������������ ����. ������
		int bufAddress;//�����
		if (realSize != Size)
		{
			realSize++;//��������� ���. ���-�� ���������
			seekg(4, ios::beg);//����� �������� ���������� ���������� (g - ��. �� ������)
			write((char*) &realSize, sizeof(int));//����������
			seekg(ptrFile + counterPtr, ios::beg);//��������� ������ ������ �� ����� ����������� ��������
			bufAddress = tellg();//���������� ����� �������� ��.
			*this << object;//���������� ������
			counterPtr += sizeof(tipeData);			
			seekg(0, ios::end);//������ � ����� ����� (g - ��. �� ������)
			write((char*)&bufAddress, sizeof(int));//���������� ��������� �� �������			
		}
		else incrementSize(object);//����������� ������������ ������ �������		
		Size = realSize = ptrFile = ptrBeginArr = bufAddress = (int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void remVariable()
	{
		seekp(4, ios::beg);//������ � ������ ����� (p - ��. �� ������)
		read((char*)&realSize, sizeof(int));//��������� ����c
		if (realSize > 0)
		{
			realSize--;
			seekp(4, ios::beg);//������ � ������ ����� (p - ��. �� ������)
			write((char*)&realSize, sizeof(int));//��������� ����c
			counterPtr -= sizeof(tipeData);
		}
		else
		{
			cout << endl << " ���� ���� " << endl << endl;
			system("pause");
		}
		Size = realSize = ptrFile = ptrBeginArr = (int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void reviewFile()
	{
		seekp(0,ios::beg);//������ � ������ �����
		read((char*)&Size, sizeof(int));//��������� ������ �������
		read((char*)&realSize, sizeof(int));//��������� ������� ���������� ��.
		read((char*)&ptrBeginArr, sizeof(int));//����� ������ ������� ����������
		cout << endl << " ������������ ������: " << Size << endl;
		cout << " ������� ������ : " << realSize << endl;
		//cout << " ������ ������� ���������� : " << ptrBeginArr << endl;
		seekp(ptrBeginArr, ios::beg);//������� � ������ ������ ����������
		cout << " ���� �������� : " << endl << endl;
		int bufAddress;//��������� ���������� ��� �������� ������ 
		for (int i = 0; i < realSize; i++)
		{			
			read((char*)&bufAddress, sizeof(int));//��������� ��. ������� (����� �������)
			ptrFile = tellp();//��������� �� ����� ������������ ����. ����������
			seekp(bufAddress, ios::beg);//������� �� ������ � ��������
			*this >> buf;//��������� �������
			cout << i+1 << "-> " << buf << endl;//�������� 
			seekp(ptrFile, ios::beg);//������� � ����. ��. �������
		}
		cout << endl << " ���� : " << bufnameFile << endl << endl;
		bufAddress = (int)nullptr;
	}
	void sortObject()
	{		
		int tBuf, tbBuf;
		tipeData bBuf;;		
		for (int i = realSize - 1; i >= 0; i--)
		{
			seekp(0, ios::beg);//������ � ������ �����
			read((char*)&Size, sizeof(int));//��������� ������ �������
			read((char*)&realSize, sizeof(int));//��������� ������� ���������� ��.
			read((char*)&ptrBeginArr, sizeof(int));//����� ������ ������� ����������
			seekp(ptrBeginArr, ios::beg);//������� � ������ ������ ����������
			for (int j = 0; j < i; j++)
			{
				read((char*)&tBuf, sizeof(int));//��������� ��. ������� (����� �������)
				ptrFile = tellp();//��������� �� ����� ������������ ����. ����������
				read((char*)&tbBuf, sizeof(int));//��������� ��. �������+1 (����� �������)					
				seekp(tBuf, ios::beg);//������� �� ������ � ��������
				*this >> buf;//��������� �������
				seekp(tbBuf, ios::beg);//������� �� ������ � ��������
				*this >> bBuf;//��������� �������
				if (buf > bBuf)
				{
					tipeData temp = buf;
					seekg(tBuf, ios::beg);//������� �� ������ � ��������
					*this << bBuf;
					seekg(tbBuf, ios::beg);//������� �� ������ � ��������
					*this << temp;
					//temp = (tipeData)nullptr;
				}
				seekp(ptrFile, ios::beg);//������� � ����. ��. �������
										 //������
				//bBuf = (tipeData)nullptr;
				//tBuf = tbBuf = (int)nullptr;
			}
		}	
		Size = realSize = ptrFile = ptrBeginArr = tBuf = tbBuf =(int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void update(int variable)
	{		
		seekp(0, ios::beg);//������ � ������ �����
		read((char*)&Size, sizeof(int));//��������� ������ �������
		read((char*)&realSize, sizeof(int));//��������� ������� ���������� ��.
		read((char*)&ptrBeginArr, sizeof(int));//����� ������ ������� ����������
		if (variable <= realSize  && variable > 0)
		{
			int bufAddress;//����� ������� (����� ����� �������� ������� ������)
			cout << endl << " ����� ������� :" << endl << endl << ">> ";
			cin >> buf;
			seekp(ptrBeginArr + (sizeof(int)*variable) - sizeof(int), ios::beg);//������� � ����. ������
			read((char*)&bufAddress, sizeof(int));//��������� ��. ������� (����� �������)
			seekg(bufAddress, ios::beg);//������� � ��. (g - ��. �� ������);
			*this << buf;//���������� ������
			//buf = (tipeData)nullptr;
			Size = realSize = ptrFile = ptrBeginArr = bufAddress = (int)nullptr;
		}
		else
		{
			cout << endl << " �� ����� �������� ��� ���������!! " << endl << endl;
			system("pause");
		}
		Size = realSize = ptrFile = ptrBeginArr = (int)nullptr;
	}
	void incrementSize(tipeData object)//����������� ������������ ������ �������
	{
		Size *= 2;//����������� ������ �� 2

		seekg(0,ios::beg);//������ � ������ ����� (g - ��. �� ������)
		write((char*)&Size, sizeof(int));//������ ������� ������� ���������� (4byte)

		seekp(ptrBeginArr, ios::beg);//������� � ������ ������ ����������
		int bufArrOld = tellp();//��������� �� ������ ������ ��.
		seekg(0, ios::end);//������� � ����� ����� (g - ��. �� ������)
		int bufArrNew = tellg();//������ ����� ������ ������ ������� ��. (g - ��. �� ������);
		int bufAddress;//����� ������� (����� ����� �������� ������� ������)
		ptrBeginArr = tellg();//����� ����� ������ ������� ����������
		for (int i = 0; i < realSize; i++)//ptrFile ����� ����� ���������� ��������� ������� � ������ ������� ����������
		{
			seekp(bufArrOld, ios::beg);//������� � ����. ��. ������� ������� ��.
			read((char*)&bufAddress, sizeof(int));//��������� ��. ������� (����� �������)					
			bufArrOld = tellp();//��������� �� ����� ������������ ����. ����������
			seekg(bufArrNew, ios::beg);//������� � ��. ������ ������� ���������� (g - ��. �� ������);
			write((char*)&bufAddress, sizeof(int));//���������� �������� ��. ������� (����� �������)
			bufArrNew = tellg();//������ ����� ������ ��. ������� ��. (g - ��. �� ������);
		}
		seekg(8, ios::beg);//������� �� ����� ������ ������� ��. (g - ��. �� ������)
		write((char*)&ptrBeginArr, sizeof(int));// ���������� ����� ����� ������ ������� ����������		
		addVariable(object);
		bufArrOld = bufArrNew = bufAddress = (int)nullptr;
	}
	void positionCounterPtr()//������������� �������
	{
		counterPtr = sizeof(int);
		seekp(-counterPtr, ios::end);//������ � ����� ����� (p - ��. �� ������)
		read((char*)&counterPtr, sizeof(int));//��������� �����		
		seekp(counterPtr + sizeof(tipeData), ios::beg);//������� �� ������
		counterPtr = tellp();
		counterPtr -= (sizeof(int) * 3);
	}
};
