//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool is_game_running = false;
//
//class GameObject
//{
//public:
//	GameObject()
//	{
//		cout << "���� ������Ʈ ����!\n";
//	}
//	virtual ~GameObject()
//	{
//		cout << "���� ������Ʈ �Ҹ�!\n";
//	}
//
//	virtual void Start()
//	{
//		cout << "���� ������Ʈ ��ŸƮ!\n";
//	}
//	virtual void Update()
//	{
//		cout << "���� ������Ʈ ������Ʈ!\n";
//	}
//};
//
//class Player : public GameObject
//{
//public:
//	int HP = 100;
//	Player()
//	{
//		cout << "������ ����!\n";
//	}
//	~Player()
//	{
//		cout << "������ �Ҹ�!\n";
//	}
//	void Start()
//	{
//		cout << "�������� HP��" << HP << "�Դϴ�!\n";
//	}
//	void Update()
//	{
//		cout << "������ ������Ʈ!\n";
//	}
//};
//
//class Enemy :  public GameObject
//{
//public:
//	int HP = 100;
//	Enemy()
//	{
//		cout << "�� ����!\n";
//	}
//	~Enemy()
//	{
//		cout << "�� �Ҹ�!\n";
//	}
//	void Start()
//	{
//		cout << "���� HP��" << HP << "�Դϴ�!\n";
//	}
//	void Update()
//	{
//		cout << "�� ������Ʈ!\n";
//	}
//};
//
//int main()
//{
//	is_game_running = true;
//
//	GameObject* p = new Player();
//	GameObject* e = new Enemy();
//
//	p->Start();
//	e->Start();
//
//	while (is_game_running)
//	{
//		p->Start();
//		e->Start();
//		cout << "�Է����ּ��� (1:���� ����, 2: ���� ���): ";
//		int input;
//		cin >> input;
//		if (input == 1)
//			is_game_running = false;
//	}
//
//	delete(p);
//	delete(e);
//
//	return 0;
//}