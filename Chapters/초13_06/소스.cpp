#include <iostream>
using namespace std;

// 자료형이 아닌 템플릿 매개변수를 이용함
template <class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	void print()
		// T와 size가 class template이므로 제공된다
	{
		for (int count = 0; count < size; ++count)
			std::cout << (*this)[count] << ' ';
		std::cout << endl;
	}
};

template <class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

// 클래스 템플릿을 상속받은 클래스의 specialization
template <int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	void print()
		// T와 size가 class template이므로 제공된다
	{
		for (int count = 0; count < size; ++count)
			std::cout << (*this)[count];
		std::cout << endl;
	}
};

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.print();

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';

	strcpy_s(char14.getArray(), 14, "Hello, World");
	//strcpy_s((char*)&char14[0], 14 * sizeof(char), "Hello, World");

	char14.print();
}

/*
* 클래스 멤버를 직접 specialization하기는 어렵기 때문에 상속구조를 이용한다
*
* 
*/