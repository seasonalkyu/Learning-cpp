#include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}

	~A()
	{
		cout << "Destructor A";
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "B: " << b << endl;
	}

	~B()
	{
		cout << "Destructor B";
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "C: " << c << endl;
	}

	~C()
	{
		cout << "Destructor C";
	}
};



int main()
{
	C c(1024, 3.14, 'a');
}

/*
* ��������� child Ŭ������ motherŬ������ ũ����� �����Ѵ�
* 
* �ڽ� Ŭ������ grand mother�� �����ڸ� ȣ���� �� ����
* 
* destructor�� C -> B -> A ������ ����ȴ�
*/