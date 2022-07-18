#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value = 5)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm Base " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		cout << "This is Base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value = 7)
		: Base(value)
	{}

	void print()
	{
		cout << "I'm Derived " << endl;
		// print();
			// 재귀적인 호출
		// Base::print();
			// 부모의 print() 호출
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& d)
	{
		cout << static_cast<Base>(d);
			// Derived는 Base를 포함하고 있다
			// 따라서 casting이 가능하다
		cout << "This is Derived output" << endl;
		return out;
	}
};

int main()
{
	Base base;
	base.print();
	cout << base;

	Derived derived(7);
	derived.print();
	cout << derived;
}

/*
* 자식 클래스에 구현하려는 기능이 부모클래스의 것과 유사할 때는 상속받은 함수를 오버라이딩할 수 있다
* 이름이 같은 함수를 자식클래스에서 정의함
*/