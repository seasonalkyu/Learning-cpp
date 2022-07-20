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
* 객체 잘림과 reference_wrapper
*
* 객체잘림:
* 부모의 객체에 자식의 객체를 강제로 대입하면
* 자식클래스에만 있는 정보들은 모두 잘려서 사라져버린다!
*/