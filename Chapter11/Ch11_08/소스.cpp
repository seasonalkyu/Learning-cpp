#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base " << endl;
	}
};

class Derived : public Base
{
protected:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}


	using Base::m_i;
		// m_i가 Derived에서 public이 된다

private:
	using Base::print;
		// 상속받은 함수를 private로 하여 사용하지 못하게끔 막는다
		// 문법상 ()를 사용하지 않고 이름만 적어야한다
	// void print() = delete;
};

int main()
{
	Derived derived(7);
	derived.m_i = 1024;
		// using Base::m_i가 없다면 error
	//derived.print();
}

/*
* 상속받은 함수를 사용하지 못하도록 막아버리는 것
* 
* public: using Base::m_i; 를 자식 함수에서 선언하면 자식함수에서 m_i는 public이 된다
* 
* 자식 클래스에서 부모클래스 함수를 사용하지 않는 방법은 2가지이다
* 방법1: private: using Base::print
* 방법2: private: void print() = delete;
*/