class Node//узел списка (отец)
{
	public:
		Node *Next, *Prev;//Указатели на адреса следующего и предыдущего элементов списка
	public:
		virtual void PrintNode() = 0;
		virtual ~Node() {};
};
class NodeMatrix : public Node//узел списка (матрица к*к)
{
	public:
		Matrix *myMatrix; //наша матрица
	public:
		void PrintNode() override;
		virtual ~NodeMatrix() override;
};
class NodeRectangularMatrix : public Node//узел списка (матрица a*b)
{
	public:
		RectangularMatrix * myMatrix; //наша матрица
	public:
		void PrintNode() override;
		virtual ~NodeRectangularMatrix() override;
};
class NodeIdentityMatrix : public Node//узел списка (матрица 1*1)
{
public:
	IdentityMatrix * myMatrix; //наша матрица
public:
	void PrintNode() override;
	virtual ~NodeIdentityMatrix() override;
};
class QueueList
{
public:
	Node *Head, *Tail; //Указатели на адреса начала очереди и её конца
	int kol = 0;// количество эл
public:
	QueueList() :Head(NULL), Tail(NULL) {}; //Инициализируем адреса как пустые
	~QueueList(); //Деструктор
	void Add(int **, int, int); //Функция добавления элементов в кольцо
	void Remove(); //Функция удаления элементов из кольца
	void PrintList();//вывод листа
	void Search(int a);//поиск
};