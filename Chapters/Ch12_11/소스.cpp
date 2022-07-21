#include <iostream>

class Base
{
public:
	Base() {}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}
	
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << '\n';

	Derived d;
	std::cout << d << '\n';

	Base& bref = d;
	std::cout << bref << '\n';

	return 0;
}

/*
* 유도 클래스에서 출력 연산자 사용하기
* 클래스의 friend함수는 멤버가 아니므로, 자식클래스에서 오버라이딩을 할 수 없다
* 따라서 virtual 함수를 하나 선언해서 friend 함수에서 이용한다
* friend 함수에서 const Base& 타입으로 인자를 받고, virtual로 함수를 선언했기 때문에 
* 자식함수에서 오버라이딩하는 것 처럼 이용할 수 있다
* 
* 
* Derived() {} 에서 print함수를 const로 선언한 이유는 
* 오버로딩된 << 연산자에서 인자를 Base& 객체로 받을 것이기 때문이다.
* 또한 Base 함수에서 print를 virtual로 선언했으므로 Base& bref = d; 를하더라도
* d의 << 연산자가 이용된다
*/