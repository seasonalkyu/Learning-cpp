
#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl;
		return this;  
	}
};



int main()
{
	A a;
	B b;
	
	A& ref = b;
	b.getThis()->print();
		// 클래스 B의 getThis가 실행된다.
		// B가 출력된다.

	ref.getThis()->print();
		// 클래스 B의 getThis가 실행된다
		// A 가 출력된다.
		// getThis가 B를 반환하지만 내부적으로 다시 A로 바꾸어 출력하기 때문

	cout << typeid(b.getThis()).name() << endl;
		// class B *
	cout << typeid(ref.getThis()).name() << endl;
		// class A *


}

