#pragma once
#include <assert.h> // for assert()
#include <iostream>

template<typename T, unsigned int T_SIZE>
	// T_SIZE가 컴파일타임에 결정돼야 한다
class MyArray
{
private:
	//int m_length;
		// m_length를 대체하는 T_SIZE가 있다
	T*	m_data;
	// 또는 T m_data[T_SIZE];

public:
	MyArray()
	{
		m_data = new T [T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
	}


	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};

/*
* explicit instantiation을 한다면 MyArray.cpp 파일에
* template class MyArray<char, 1>;
* template class MyArray<char, 100>;
* 처럼 모두 적어줘야하므로 구현하기 어렵다
* 
* 따라서 non type parameter를 사용할 때는
* 헤더파일에 멤버의 정의를 적는것이 편할 수 있다
*/