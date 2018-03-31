
template<class T>class NodeList
{
public:
	T *value;
	NodeList<T> *next;
public:
	NodeList()//������. ��� ���������
	{
		next = nullptr;
		value = NULL;
	}	
	~NodeList()
	{
		*value = NULL;
	}
	void PrintNode()//����� ����
	{
		cout << " " << *value << endl;
	}	
};

template<class T>class List : public NodeList<T>
{
public:
	NodeList<T> *Head, *Tail;//��. �� ������ � �����
	int *SizeQueue;//��������� �� ������������ ������
	int Size, currentSize, maxCurrent;//������������ ������, ������� �����, ���. ���. ��.
public:
	List(int *a, int e)//������.
	{
		Head = nullptr, Tail = nullptr;
		SizeQueue = a;
		Size = e;
		currentSize = NULL;
		maxCurrent = NULL;
	}
	~List()//����������
	{
		while (Head) //���� �� ������ �� ������ ������ ���-�� ����
		{
			Tail = Head->next; //��������� ����� ������ ���������� ����� ������	
			Head->~NodeList();
			delete Head; //������� ������ �� ������� �����
			Head = Tail; //����� ������ ������ �� ����� ���������� ��������
		}
	}
	void Add(T *a)//������� ���������� ��������� � ������
	{
		NodeList<T> *temp = new NodeList<T>;//��������� ������ ��� ����� ������� ������ (����� ������������ �� ���������)
		temp->value = a;//���������� ��������
		currentSize++;
		maxCurrent++;
		if (Head != nullptr) //���� ������ �� ����
		{
			Tail->next = temp; //��������� ����� ���������� �� ������� ��������
			Tail = temp; //������ ����� ������
		}
		else //���� ������ ������
		{
			Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
		}
	}
	void Remove()//������� �������� ��������� �� ������
	{		
		Tail = Head->next; //��������� ����� ������ ���������� ����� ������	
		Head->~NodeList();
		delete Head; //������� ������ �� ������� �����
		Head = Tail; //����� ������ ������ �� ����� ���������� ��������
		maxCurrent--;
	}
	void Rreplacement()
	{

	}
	void PrintList()//����� �����
	{
		//������� ������ ��
		NodeList<T> *temp = Head;
		int a = 0;
		//��������� ��������� �� ����� ���������� ��������
		while (temp != nullptr ) //���� �� ���������� ������ ��������
		{			
			temp->PrintNode(); //�������� �������� �� �����
			temp = temp->next; //���������, ��� ����� ����� ����������� ��������
		}
		cout << endl;
	}
};