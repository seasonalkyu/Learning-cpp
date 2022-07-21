#pragma once
#include <assert.h> // for assert()
#include <iostream>

template<typename T, unsigned int T_SIZE>
	// T_SIZE�� ������Ÿ�ӿ� �����ž� �Ѵ�
class MyArray
{
private:
	//int m_length;
		// m_length�� ��ü�ϴ� T_SIZE�� �ִ�
	T*	m_data;
	// �Ǵ� T m_data[T_SIZE];

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
* explicit instantiation�� �Ѵٸ� MyArray.cpp ���Ͽ�
* template class MyArray<char, 1>;
* template class MyArray<char, 100>;
* ó�� ��� ��������ϹǷ� �����ϱ� ��ƴ�
* 
* ���� non type parameter�� ����� ����
* ������Ͽ� ����� ���Ǹ� ���°��� ���� �� �ִ�
*/