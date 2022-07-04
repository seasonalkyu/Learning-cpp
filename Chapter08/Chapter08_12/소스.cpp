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

// 1.class B�� class A�� �����ϰ� ������ �˾ƾ���
// 2.class A�� B�� doSomething�̶�� �Լ��� �����ϰ� ������ �˾�����
// 3.class B�� doSomething �Լ��� class A�� m_value�� �������� �˾ƾ� ��