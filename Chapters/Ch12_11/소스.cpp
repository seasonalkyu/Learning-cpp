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

	virtual std::ostream& print(std::ostream& out) override
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
*/