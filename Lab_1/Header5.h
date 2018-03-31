class Node//���� ������ (����)
{
	public:
		Node *Next, *Prev;//��������� �� ������ ���������� � ����������� ��������� ������
	public:
		virtual void PrintNode() = 0;
		virtual ~Node() {};
};
class NodeMatrix : public Node//���� ������ (������� �*�)
{
	public:
		Matrix *myMatrix; //���� �������
	public:
		void PrintNode() override;
		virtual ~NodeMatrix() override;
};
class NodeRectangularMatrix : public Node//���� ������ (������� a*b)
{
	public:
		RectangularMatrix * myMatrix; //���� �������
	public:
		void PrintNode() override;
		virtual ~NodeRectangularMatrix() override;
};
class NodeIdentityMatrix : public Node//���� ������ (������� 1*1)
{
public:
	IdentityMatrix * myMatrix; //���� �������
public:
	void PrintNode() override;
	virtual ~NodeIdentityMatrix() override;
};
class QueueList
{
public:
	Node *Head, *Tail; //��������� �� ������ ������ ������� � � �����
	int kol = 0;// ���������� ��
public:
	QueueList() :Head(NULL), Tail(NULL) {}; //�������������� ������ ��� ������
	~QueueList(); //����������
	void Add(int **, int, int); //������� ���������� ��������� � ������
	void Remove(); //������� �������� ��������� �� ������
	void PrintList();//����� �����
	void Search(int a);//�����
};