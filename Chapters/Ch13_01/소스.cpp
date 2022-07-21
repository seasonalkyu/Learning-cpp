#include <iostream>
#include "Cents.h"

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


int main()
{

	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(4.13, 1.592) << std::endl;
	std::cout << getMax(1.0f, 3.4f) << std::endl;
	std::cout << getMax('a', 'f') << std::endl;

	std::cout << getMax(Cents(5), Cents(9)) << std::endl;
		// 클래스를 인자로 받을 수 있다
		// 유저 정의 자료형도 받을 수 있다
	return 0;
}

/*
* 템플릿 instantiation : 컴파일러가 함수(클래스) 틀(Template)으로부터 실제 함수(클래스)를 만들어내는 과정 
* 인스턴스와는 다르다. 인스턴스는 객체가 실제로 메모리에 존재하는 것
*/