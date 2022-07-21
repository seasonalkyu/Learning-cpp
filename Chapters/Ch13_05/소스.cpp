#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A
{
public:
	A(const T& input)
	{}

	void dosomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

// char type에만 특별한 행동을 하도록 함
template<>
class A<char>
{
public:
	A(const char & temp)
	{}

	void dosomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	// Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);
	for (int count = 0; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';
	
	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;

	//Define a Storage8 for bool
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);
	for (int count = 0; count < 8; ++count)
		std::cout << boolStorage.get(count) << '\n';

}

/*
* 클래스 템플릿 특수화
* 거의 클래스를 새로 구현하는 형태이다.
*/