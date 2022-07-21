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
		// Ŭ������ ���ڷ� ���� �� �ִ�
		// ���� ���� �ڷ����� ���� �� �ִ�
	return 0;
}

/*
* ���ø� instantiation : �����Ϸ��� �Լ�(Ŭ����) Ʋ(Template)���κ��� ���� �Լ�(Ŭ����)�� ������ ���� 
* �ν��Ͻ��ʹ� �ٸ���. �ν��Ͻ��� ��ü�� ������ �޸𸮿� �����ϴ� ��
*/