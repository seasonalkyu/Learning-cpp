#include <iostream>
using namespace std;

class Base
{
public:
	//~Base()
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	//~Derived()
	~Derived() override
	//virtual ~Derived() override
		// 부모클래스의 소멸자에 virtual이 붙어있다면 override 할 수 있다
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}
};


int main()
{
	//Derived derived(5);
		// Derived의 소멸자가 실행된 후에 base의 소멸자가 실행된다

	// 다형성을 이용하는 case
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;
		// Base의 소멸자가 virtual이 아니라면 base의 소멸자만 실행된다
		// 따라서 Derived의 소멸자가 실행되지 않아서 memory leak이 생긴다
		// Base의 소멸자를 virtual로 선언한다면 Derived의 소멸자가 먼저 실행되고
		// 그 다음에 Base의 소멸자가 실행된다

	return 0;
}

/* 
* 자식 클래스의 소멸자가 먼저 실행되고 그 다음 부모 클래스의 소멸자가 실행된다
* 
* 가상 소멸자
* delete base를 하면 base를 상속한 클래스의 소멸자가 실행되지 않는 문제점이 있다
* 이것을 해결하기 위해서 base의 소멸자를 virtual로 선언한다
*/