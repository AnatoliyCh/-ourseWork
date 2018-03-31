
template<class T>class NodeList
{
public:
	T *value;
	NodeList<T> *next;
public:
	NodeList()//констр. без параметра
	{
		next = nullptr;
		value = NULL;
	}	
	~NodeList()
	{
		*value = NULL;
	}
	void PrintNode()//вывод узла
	{
		cout << " " << *value << endl;
	}	
};

template<class T>class List : public NodeList<T>
{
public:
	NodeList<T> *Head, *Tail;//ук. на голову и хвост
	int *SizeQueue;//указатель на динамический массив
	int Size, currentSize, maxCurrent;//максимальный размер, текущий номер, тек. кол. эл.
public:
	List(int *a, int e)//констр.
	{
		Head = nullptr, Tail = nullptr;
		SizeQueue = a;
		Size = e;
		currentSize = NULL;
		maxCurrent = NULL;
	}
	~List()//деструктор
	{
		while (Head) //Пока по адресу на начало списка что-то есть
		{
			Tail = Head->next; //Резервная копия адреса следующего звена списка	
			Head->~NodeList();
			delete Head; //Очистка памяти от первого звена
			Head = Tail; //Смена адреса начала на адрес следующего элемента
		}
	}
	void Add(T *a)//Функция добавления элементов в кольцо
	{
		NodeList<T> *temp = new NodeList<T>;//Выделение памяти под новый элемент класса (вызов конструктора по умолчанию)
		temp->value = a;//Записываем значение
		currentSize++;
		maxCurrent++;
		if (Head != nullptr) //Если список не пуст
		{
			Tail->next = temp; //Указываем адрес следующего за хвостом элемента
			Tail = temp; //Меняем адрес хвоста
		}
		else //Если список пустой
		{
			Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
		}
	}
	void Remove()//Функция удаления элементов из кольца
	{		
		Tail = Head->next; //Резервная копия адреса следующего звена списка	
		Head->~NodeList();
		delete Head; //Очистка памяти от первого звена
		Head = Tail; //Смена адреса начала на адрес следующего элемента
		maxCurrent--;
	}
	void Rreplacement()
	{

	}
	void PrintList()//вывод листа
	{
		//ВЫВОДИМ СПИСОК ВП
		NodeList<T> *temp = Head;
		int a = 0;
		//Временный указатель на адрес последнего элемента
		while (temp != nullptr ) //Пока не встретится пустое значение
		{			
			temp->PrintNode(); //Выводить значение на экран
			temp = temp->next; //Указываем, что нужен адрес предыдущего элемента
		}
		cout << endl;
	}
};