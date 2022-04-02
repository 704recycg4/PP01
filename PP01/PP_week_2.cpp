// 스랜다드 라이브러리
#include <iostream>
#include <stdio.h>
// #include 컴파일러야 포함시켜 <iostream>을 이라는 뜻
// 컴파일러에서 지정해 놓은 메인으로 시작

using namespace std;

#pragma region week2_1

/*
namespace normal
{
	void print(std::string str)
	{
		std::cout << str;
	}
}

namespace visual_novel
{
	void print(std::string str)
	{
		std::cout << "김태인 : "<< str;
	}
}

int main()
{
	visual_novel::print ( "평화롭고 아름다운 프로그래밍 패턴시간...?\n");
	return 0;
}*/
#pragma endregion
#pragma region week2_2
/*
class Player
{
public:
	Player() // 생성자
	{
		cout << "주인공 생성! 아 맑은 공기~" << endl;
	}
	~Player() // 소멸자
	{
		cout << "아... 왜 피가..." << endl;
	}
};
class Player2
{
public:
	Player2() // 생성자
	{
		cout << "주인공2 생성! 아 상쾌한 공기~" << endl;
	}
	~Player2() // 소멸자
	{
		cout << "아... 왜 피가 나오지? 앗....." << endl;
	}
};

int main()
{
	// heat stack
	Player2 pl2;

	Player* player = new Player();
	delete(player);
	// pl2 소멸

	return 0;
}*/
#pragma endregion
#pragma region week2_3
//bool is_game_running = false;
//
//class GameObject
//{
//public:
//	GameObject()
//	{
//		cout << "게임 오브젝트 생성\n";
//	}
//	virtual ~GameObject()
//	{
//		cout << "게임 오브젝트 소멸\n";
//	}
//
//	virtual void Start() {};
//	virtual void Update() {};
//};
//
//class Player : public GameObject
//{
//public:
//	int HP = 100;
//
//	Player()
//	{
//		cout << "김태인 오브젝트 생성!!!\n";
//	}
//
//	~Player() 
//	{
//		cout << "김태인 오브젝트 소멸!!!\n";
//	}
//
//	void Start()
//	{
//		cout << "김태인 HP : " << HP << "\n";
//
//	}
//	void Update()
//	{
//		cout << "김태인 오브젝트 업데이트!!!\n";
//	}
//};
//
//class Enemy : public GameObject
//{
//public:
//	int HP = 50;
//
//	Enemy()
//	{
//		cout << "복예찬 오브젝트 생성!!!\n";
//	}
//	~Enemy()
//	{
//		cout << "복예찬 오브젝트 소멸!!!\n";
//	}
//
//	void Start()
//	{
//		cout << "복예찬 HP : "<< HP<<"\n";
//	}
//	void Update()
//	{
//		cout << "복예찬 오브젝트 업데이트!!!\n";
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
//		p->Update();
//		e->Update();
//
//		cout << "입력해주세요 (1: 게임종료 , 2: 게임계속): ";
//
//		int input;
//		cin >> input;
//
//		if (input == 1)
//			is_game_running = false;
//	}
//
//	delete(p);
//	delete(e);
//
//	return 0;
//}
#pragma endregion