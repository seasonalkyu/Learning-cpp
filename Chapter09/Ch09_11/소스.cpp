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
		// ���ڿ��� ������� Ȯ��
		assert(source);

		// ���ڿ��� ����(null ����)
		m_length = (int)std::strlen(source) + 1;

		// �����Ҵ����� �迭�� �����
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];
		m_data[m_length - 1] = '\0';
	}

	// ���� ������
	// ���� ���縦 �ϰ� �ִ�
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
			// �� ����� ������ �����̴�. nullptr�� �ֽ� ����
	}

	MyString& operator = (const MyString& source)
	{
	//// shallow copy
	//	this->m_data = source.m_data;
	//	this->m_length = source.m_length;
		// default copy constructor�� ����
	cout << "Assignment operator " << endl;

	if (this == &source) // prevent self-assignment
		return *this;
		// �����θ� �������� �ν��Ͻ��� �����ϴ� ���� �����Ϸ����忡���� ����� ���̴�
		// ���� �� �ڵ带 ������ ��

	// ������ �ִ� �޸𸮸� ��������
	delete[] m_data;

	m_length = source.m_length;

	// source�� nullptr�� �ƴ϶�� �ٽ� �޸𸮸� �Ҵ�޾Ƽ� ����
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

	// memory leak�� �ذ��ϱ����ؼ� �ݵ�� �ʿ�
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
		// assignment �����ڰ� ������ copy constructor�� ȣ��ȴ�
		// MyString str1(hello); �� �ڵ��ϴ� ���� �ǹ̸� �ľ��ϱ⿡ �� ���� ���̴�
	MyString str2;
		// �����ڰ� ȣ���
	str2 = hello;
		// assignment operator �� ȣ��
	str2 = hello;
}


// shalow copy�� ���� ���ؼ��� ���� �����ڸ� ����� ���� ���� ������
// MyString(const MyString &source = delete; �Ͽ� ���ƹ����� ����� �ִ�