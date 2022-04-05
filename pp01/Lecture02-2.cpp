#include <iostream>

using namespace std;

class Car
{
public:
	Car()
	{
		cout << "car�� �����մϴ�\n";
	}
	~Car()
	{
		cout << "car�� �Ҹ�˴ϴ�\n";
	}

	virtual void openWindow()
	{
		cout << "â���� ���ϴ�\n";
	}

	virtual void ChangeGear()
	{
		cout << "�� �����մϴ�\n";
	}
};

class Spark : public Car
{
public:
	Spark()
	{
		cout << "����ũ�� �����մϴ�\n";
	}
	~Spark()
	{
		cout << "����ũ�� �Ҹ�˴ϴ�\n";
	}

	void openWindow()
	{
		cout << "�������� â���� ���ϴ�\n";
	}

	void ChangeGear()
	{
		cout << "�������� �� �ٲߴϴ�\n";
	}
};

class Escalade : public Car
{
public:
	Escalade()
	{
		cout << "Escalade�� �����մϴ�\n";
	}
	~Escalade()
	{
		cout << "Escalade�� �Ҹ�˴ϴ�\n";
	}

	void openWindow()
	{
		cout << "�ڵ����� â���� ���ϴ�\n";
	}

	void ChangeGear()
	{
		cout << "�ڵ����� �� �ٲߴϴ�\n";
	}
};

//������ �Լ�
void main()
{	
	int carNum = 2;

	Car** c;
	c = new Car*[carNum];
	c[0] = new Spark();
	c[1] = new Escalade();

	for (size_t i = 0; i < 2; i++)
	{
		c[i]->openWindow();
		c[i]->ChangeGear();
		delete(c[i]);
	}
}