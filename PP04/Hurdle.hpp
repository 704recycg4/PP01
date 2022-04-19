#pragma once
#pragma once
class Hurdle
{
public:
	int x, y;
	Hurdle()
	{
		x = 30;
		y = 7;
	}
	~Hurdle()
	{

	}

	void isHurdleSpawn(int radomY)
	{
		y = radomY;
	}

};