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
* �� �ڵ�� A -> B -> C ������ �����ڰ� ����ȴ�
*/