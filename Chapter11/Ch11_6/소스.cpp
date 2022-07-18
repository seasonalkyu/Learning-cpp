#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{

	}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{}

	void setValue(int value)
	{
		Base::m_value = value;
		// do Something with the vbariables in Derived
	}
};

/*
* 예제 코드처럼 m_value만 이용하는 상황이라면 Base 클래스에 setValue()를 만드는 것이 맞다
* 하지만 Derived의 멤버를 이용한다면 base의 멤버를 protected로 선언한다
* 
* getValue 등의 함수를 이용해서 private 멤버를 가져온다면 성능의 문제가 생길 수 있다
* 또한 부모의 멤버를 많이 사용할 때는 private 보다는 protected일 때가 더 유용하다
*/