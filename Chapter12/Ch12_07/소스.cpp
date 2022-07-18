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

	// pure virtual function 선언
	virtual void speak() const = 0;
	/*void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
	*/
	// body를 없앤다 
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
		// error가 난다

	return 0;
}

/*
* 순수 가상 함수: 
*	바디가 없다. 따라서 반드시 자식 클래스에서 오버라이드해야한다
* 추상 기본 클래스:
*	순수 가상 함수가 포함이 된 클래스
* 인터페이스 클래스
*	순수 가상 함수로만 구성된 클래스
*/