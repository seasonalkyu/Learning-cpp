#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base & b)

/*
* ��ü �߸��� reference_wrapper
*
* ��ü�߸�:
* �θ��� ��ü�� �ڽ��� ��ü�� ������ �����ϸ�
* �ڽ�Ŭ�������� �ִ� �������� ��� �߷��� �����������!
*/