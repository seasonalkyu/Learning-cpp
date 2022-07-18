#include <cassert>
#include <iostream>
using namespace std;

class MyString
{
	//private:
public:
	char* m_data = nullptr;
	unsigned m_length = 0;

public:
	MyString(const char* source = "")
	{
		// 문자열이 비었는지 확인
		assert(source);

		// 문자열의 길이(null 포함)
		m_length = (int)std::strlen(source) + 1;

		// 동적할당으로 배열을 만든다
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];
		m_data[m_length - 1] = '\0';
	}

	// 복사 생성자
	// 깊은 복사를 하고 있다
	MyString(const MyString& source)
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
		// m_data = 0;
			// 이 방식은 예전의 문법이다. nullptr이 최신 문법
	}

	MyString& operator = (const MyString& source)
	{
	//// shallow copy
	//	this->m_data = source.m_data;
	//	this->m_length = source.m_length;
		// default copy constructor의 형태
	cout << "Assignment operator " << endl;

	if (this == &source) // prevent self-assignment
		return *this;
		// 스스로를 스스로의 인스턴스에 대입하는 것은 컴파일러입장에서는 곤란한 일이다
		// 따라서 위 코드를 예방한 것

	// 가지고 있던 메모리를 지워버림
	delete[] m_data;

	m_length = source.m_length;

	// source가 nullptr이 아니라면 다시 메모리를 할당받아서 복사
	if (source.m_data != nullptr)
	{
		m_data = new char[m_length];
		for (int i = 0; i < m_length; ++i)
			m_data[i] = source.m_data[i];
	}
	else
		m_data = nullptr;

	return *this;
}

	// memory leak를 해결하기위해서 반드시 필요
	~MyString()
	{
		delete[] m_data;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");

	MyString str1 = hello;
		// assignment 연산자가 있지만 copy constructor가 호출된다
		// MyString str1(hello); 로 코딩하는 것이 의미를 파악하기에 더 좋을 것이다
	MyString str2;
		// 생성자가 호출된
	str2 = hello;
		// assignment operator 가 호출
	str2 = hello;
}


// shalow copy를 막기 위해서는 복사 생성자를 만드는 것이 가장 좋지만
// MyString(const MyString &source = delete; 하여 막아버리는 방법도 있다