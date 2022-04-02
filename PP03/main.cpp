#include <iostream>
using namespace std;

class A
{
public:
	virtual void dynamic_print()
	{
		cout << "다이나미크 데헤\n";
	}

	void static_print()
	{
		cout << " 데헤\n";
	}

};

class B :public A
{
public:
	void dynamic_print()
	{
		cout << "다이나미크 헤헿\n";
	}

	void static_print() // overiding
	{
		cout << "헤헿\n";
	}

	void static_print(int a)
	{
		cout << a << "헤헿\n";
	}
};

void main()
{
	A* tempA;
	B* tempB = new B();
	tempA = tempB;
	tempA->static_print(); //바인딩된 함수
	tempB->static_print();

	tempA->dynamic_print(); 
	tempB->dynamic_print();
}