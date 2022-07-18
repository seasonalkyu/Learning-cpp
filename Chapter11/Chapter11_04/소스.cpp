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
* 결론적으로 child 클래스는 mother클래스의 크기까지 포함한다
* 
* 자식 클래스가 grand mother의 생성자를 호출할 수 없다
* 
* destructor는 C -> B -> A 순서로 실행된다
*/