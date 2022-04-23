#include <cstdlib>

class Enemy
{
public:
	int x, y;
	bool Enemycheck;
	Enemy()
	{
		x = rand() % 36 + 27;
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
