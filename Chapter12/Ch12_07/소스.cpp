#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	// pure virtual function ����
	virtual void speak() const = 0;
	/*void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	*/
	// body�� ���ش� 
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main()
{
	//Animal animal("my animal");
		// error�� ����

	return 0;
}

/*
* ���� ���� �Լ�: 
*	�ٵ� ����. ���� �ݵ�� �ڽ� Ŭ�������� �������̵��ؾ��Ѵ�
* �߻� �⺻ Ŭ����:
*	���� ���� �Լ��� ������ �� Ŭ����
* �������̽� Ŭ����
*	���� ���� �Լ��θ� ������ Ŭ����
*/