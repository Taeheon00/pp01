class Enemy
{
public:
	int x, y;
	bool Enemycheck;
	Enemy()
	{
		x = 50;
		y = 7;
		Enemycheck = false;
	}
	~Enemy()
	{

	}

	void enemymove()
	{
		x -= 1;
	}

};
