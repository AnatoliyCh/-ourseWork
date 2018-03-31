#include <iostream>//в/выв консоль
#include <fstream> //класс файловых потоков
#include <cstdlib>
using namespace std;
//тест
#include <string>


template<class tipeData> class binFile : public fstream
{
public://временные данные для обработки
	int Size = 1;//размер массива указателей (4byte)
	int realSize = NULL;//текущее количество указателей (4byte)
	int ptrBeginArr = (int)nullptr;//адрес начала массива указателей / указатель
	int ptrFile = NULL;//указатель на байт ввода/вывода
	int counterPtr = NULL;//счетчик сдвига записи в файл (byte)	
	tipeData buf;//временный буффер объекта

	//просто
	char bufnameFile[30];//имя файла
public:
	binFile(const char *nameFile, bool createdFile): basic_fstream(nameFile, ios::in | ios::out | ios::binary | (createdFile?ios::trunc :0))//создание файла
	{
		if (is_open())
		{
			if (createdFile)
			{
				write((char*)&Size, sizeof(int));//запись размера массива указателей (4byte)
				write((char*)&realSize, sizeof(int));//запись текущего количества указателей (4byte)
				ptrFile = tellg();//указатель на байт ввода/вывода ставим на конец последнего элемента (g - ук. на запись)
				counterPtr = sizeof(int) + sizeof(tipeData);//сдвиг на размер двух типов данных		
				seekg(ptrFile + counterPtr, ios::beg);//сдвигаем указатель записи на 2*tipeData
				ptrBeginArr = tellg();//задаем адрес начала массива указателей (g - ук. на запись)
				seekg(ptrFile, ios::beg);//указатель ввода ставим на запись адреса начала указателей
				write((char*)&ptrBeginArr, sizeof(int));//записываем адрес начала массива указателей
				Size = realSize = ptrFile = counterPtr = ptrBeginArr = (int)nullptr;			
			}
			else
			{
				cout << endl << " Файл открыт " << endl;
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
	fstream& operator << (tipeData &object)//ввод
	{		
		write((char*)&object, sizeof(tipeData));	
		return *this;
	}
	fstream& operator >> (tipeData &object)//вывод
	{
		read((char*)&object, sizeof(tipeData));
		return *this;
	}
	void addVariable(tipeData object)//добавление в массив
	{
		seekp(ios::beg);//чтение с начала файла (p - ук. на чтение)
		read((char*) &Size, sizeof(int));//считываем размер массива
		read((char*) &realSize, sizeof(int));//считываем тукущее количество эл.
		read((char*)&ptrBeginArr, sizeof(int));//адрес начала массива указателей	
		ptrFile = tellp();//указатель на место произведения след. записи
		int bufAddress;//адрес
		if (realSize != Size)
		{
			realSize++;//увеличили тек. кол-во элементов
			seekg(4, ios::beg);//место текущего количества указателей (g - ук. на запись)
			write((char*) &realSize, sizeof(int));//записываем
			seekg(ptrFile + counterPtr, ios::beg);//указатель записи ставим на конец предыдущего элемента
			bufAddress = tellg();//запоминаем адрес будущего эл.
			*this << object;//записываем объект
			counterPtr += sizeof(tipeData);			
			seekg(0, ios::end);//запись в конец файла (g - ук. на запись)
			write((char*)&bufAddress, sizeof(int));//записываем указатель на элемент			
		}
		else incrementSize(object);//увеличиваем максимальный размер массива		
		Size = realSize = ptrFile = ptrBeginArr = bufAddress = (int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void remVariable()
	{
		seekp(4, ios::beg);//чтение с начала файла (p - ук. на чтение)
		read((char*)&realSize, sizeof(int));//считываем адреc
		if (realSize > 0)
		{
			realSize--;
			seekp(4, ios::beg);//чтение с начала файла (p - ук. на чтение)
			write((char*)&realSize, sizeof(int));//считываем адреc
			counterPtr -= sizeof(tipeData);
		}
		else
		{
			cout << endl << " Файл пуст " << endl << endl;
			system("pause");
		}
		Size = realSize = ptrFile = ptrBeginArr = (int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void reviewFile()
	{
		seekp(0,ios::beg);//чтение с начала файла
		read((char*)&Size, sizeof(int));//считываем размер массива
		read((char*)&realSize, sizeof(int));//считываем тукущее количество эл.
		read((char*)&ptrBeginArr, sizeof(int));//адрес начала массива указателей
		cout << endl << " Максимальный размер: " << Size << endl;
		cout << " Текущий размер : " << realSize << endl;
		//cout << " Начало массива указателей : " << ptrBeginArr << endl;
		seekp(ptrBeginArr, ios::beg);//переход к началу масива указателей
		cout << " Ваши элементы : " << endl << endl;
		int bufAddress;//временная переменная для хранения адреса 
		for (int i = 0; i < realSize; i++)
		{			
			read((char*)&bufAddress, sizeof(int));//считываем эл. массива (адрес объекта)
			ptrFile = tellp();//указатель на место произведения след. считывания
			seekp(bufAddress, ios::beg);//переход по адресу к элементу
			*this >> buf;//считываем элемент
			cout << i+1 << "-> " << buf << endl;//печатаем 
			seekp(ptrFile, ios::beg);//переход к след. эл. массива
		}
		cout << endl << " Файл : " << bufnameFile << endl << endl;
		bufAddress = (int)nullptr;
	}
	void sortObject()
	{		
		int tBuf, tbBuf;
		tipeData bBuf;;		
		for (int i = realSize - 1; i >= 0; i--)
		{
			seekp(0, ios::beg);//чтение с начала файла
			read((char*)&Size, sizeof(int));//считываем размер массива
			read((char*)&realSize, sizeof(int));//считываем тукущее количество эл.
			read((char*)&ptrBeginArr, sizeof(int));//адрес начала массива указателей
			seekp(ptrBeginArr, ios::beg);//переход к началу масива указателей
			for (int j = 0; j < i; j++)
			{
				read((char*)&tBuf, sizeof(int));//считываем эл. массива (адрес объекта)
				ptrFile = tellp();//указатель на место произведения след. считывания
				read((char*)&tbBuf, sizeof(int));//считываем эл. массива+1 (адрес объекта)					
				seekp(tBuf, ios::beg);//переход по адресу к элементу
				*this >> buf;//считываем элемент
				seekp(tbBuf, ios::beg);//переход по адресу к элементу
				*this >> bBuf;//считываем элемент
				if (buf > bBuf)
				{
					tipeData temp = buf;
					seekg(tBuf, ios::beg);//переход по адресу к элементу
					*this << bBuf;
					seekg(tbBuf, ios::beg);//переход по адресу к элементу
					*this << temp;
					//temp = (tipeData)nullptr;
				}
				seekp(ptrFile, ios::beg);//переход к след. эл. массива
										 //чистим
				//bBuf = (tipeData)nullptr;
				//tBuf = tbBuf = (int)nullptr;
			}
		}	
		Size = realSize = ptrFile = ptrBeginArr = tBuf = tbBuf =(int)nullptr;
		//buf = (tipeData)nullptr;
	}
	void update(int variable)
	{		
		seekp(0, ios::beg);//чтение с начала файла
		read((char*)&Size, sizeof(int));//считываем размер массива
		read((char*)&realSize, sizeof(int));//считываем тукущее количество эл.
		read((char*)&ptrBeginArr, sizeof(int));//адрес начала массива указателей
		if (variable <= realSize  && variable > 0)
		{
			int bufAddress;//адрес объекта (нужен чтобы временно хранить адреса)
			cout << endl << " Новый элемент :" << endl << endl << ">> ";
			cin >> buf;
			seekp(ptrBeginArr + (sizeof(int)*variable) - sizeof(int), ios::beg);//переход к нужн. адресу
			read((char*)&bufAddress, sizeof(int));//считываем эл. массива (адрес объекта)
			seekg(bufAddress, ios::beg);//переход к эл. (g - ук. на запись);
			*this << buf;//записываем объект
			//buf = (tipeData)nullptr;
			Size = realSize = ptrFile = ptrBeginArr = bufAddress = (int)nullptr;
		}
		else
		{
			cout << endl << " Вы ввели значение вне диапазона!! " << endl << endl;
			system("pause");
		}
		Size = realSize = ptrFile = ptrBeginArr = (int)nullptr;
	}
	void incrementSize(tipeData object)//увеличиваем максимальный размер массива
	{
		Size *= 2;//увеличиваем размер на 2

		seekg(0,ios::beg);//запись в начало файла (g - ук. на запись)
		write((char*)&Size, sizeof(int));//запись размера массива указателей (4byte)

		seekp(ptrBeginArr, ios::beg);//переход к началу масива указателей
		int bufArrOld = tellp();//указатель на старый массив ук.
		seekg(0, ios::end);//каретка в конец файла (g - ук. на запись)
		int bufArrNew = tellg();//задаем адрес начала нового массива ук. (g - ук. на запись);
		int bufAddress;//адрес объекта (нужен чтобы временно хранить адреса)
		ptrBeginArr = tellg();//новый адрес начала массива указателей
		for (int i = 0; i < realSize; i++)//ptrFile нужен чтобы запоминать положение коретки в старом массиве указателей
		{
			seekp(bufArrOld, ios::beg);//переход к след. эл. старого массива ук.
			read((char*)&bufAddress, sizeof(int));//считываем эл. массива (адрес объекта)					
			bufArrOld = tellp();//указатель на место произведения след. считывания
			seekg(bufArrNew, ios::beg);//переход к эл. нового массива указателей (g - ук. на запись);
			write((char*)&bufAddress, sizeof(int));//записываем считаный эл. массива (адрес объекта)
			bufArrNew = tellg();//задаем адрес нового эл. массива ук. (g - ук. на запись);
		}
		seekg(8, ios::beg);//каретка на адрес начала массива ук. (g - ук. на запись)
		write((char*)&ptrBeginArr, sizeof(int));// записываем новый адрес начала массива указателей		
		addVariable(object);
		bufArrOld = bufArrNew = bufAddress = (int)nullptr;
	}
	void positionCounterPtr()//устанавливаем счетчик
	{
		counterPtr = sizeof(int);
		seekp(-counterPtr, ios::end);//чтение с конца файла (p - ук. на чтение)
		read((char*)&counterPtr, sizeof(int));//считываем адрес		
		seekp(counterPtr + sizeof(tipeData), ios::beg);//переход по адресу
		counterPtr = tellp();
		counterPtr -= (sizeof(int) * 3);
	}
};
