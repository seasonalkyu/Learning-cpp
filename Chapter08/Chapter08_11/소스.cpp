#include <iostream>
using namespace std;

class Something
{
public:

	class _init
	{
	public:
		_init()
		{
			ps_value = 9999;
		}
	};

private:
	static int ps_value;
	int m_value;
	
	static _init s_initializer;
public:

	static int s_value;
	int getValue()
	{
		return s_value;
	}

	static int getpsValue()
	{
		//return this->ps_value;
			// error
		//m_value = 3;
			// error
			// static 함수에서는 this가 불가능하므로
		return ps_value;
	}

	int temp()
	{
		return this->ps_value + this->s_value;
			// return ps_value 와 같은 의미
	}
};

int Something::s_value = 1024;
int Something::ps_value = 1;
	// inner클래스로 초기화를 하면 필요 없다.
Something::_init Something::s_initializer;
	// inner 클래스를 이용해서 간접적으로 static 멤버 초기화

int main()
{
	cout << Something::getpsValue() << endl;

	Something s1;
	cout << s1.getValue() << endl;
	cout << s1.getpsValue() << endl;




	Something s2;
	//int (Something::*fptr1)() = &s1.temp;
		//error
	// non static member function
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;

	// static member function
	//int (Something:: * fptr2)() = &Something::getpsValue;
		// error
	int (*fptr2)() = &Something::getpsValue;
	cout << fptr2() << endl;

	return 0;

}



// static 멤버 변수는 생성자에서 초기화할 수 없다
// C++에서 생성자는 static일 수 없어서이다.
// inner 클래스를 이용하면 생성자를 이용해서 static 멤버를 초기화할 수 있다.