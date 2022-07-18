#include <iostream>

using namespace std;

class A
{

public:
	A()
	{
		cout << "A Con" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B Con" << endl;
	}
};


class C : public B
{
public:
	C()
	{
		cout << "C Con" << endl;
	}
};
int main()
{
	C c;

}

/*
* 위 코드는 A -> B -> C 순으로 생성자가 실행된다
*/