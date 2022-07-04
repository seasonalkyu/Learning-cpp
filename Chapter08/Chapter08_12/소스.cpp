#include <iostream>

using namespace std;

class A;
	// forward Declaration
	// 1
class B
{
private:
	int m_value = 2;

public:
	void doSomething(A& a);
};
	// 2

class A
{
private:
	int m_value = 1;

	friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}
	// 3

int main()
{
	A a;
	B b;
	
	b.doSomething(a);

	return 0;
}

// 1.class B는 class A가 존재하고 있음을 알아야함
// 2.class A는 B에 doSomething이라는 함수가 존재하고 있음을 알아햐함
// 3.class B의 doSomething 함수는 class A에 m_value가 존재함을 알아야 함