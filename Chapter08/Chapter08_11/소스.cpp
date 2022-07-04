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
			// static �Լ������� this�� �Ұ����ϹǷ�
		return ps_value;
	}

	int temp()
	{
		return this->ps_value + this->s_value;
			// return ps_value �� ���� �ǹ�
	}
};

int Something::s_value = 1024;
int Something::ps_value = 1;
	// innerŬ������ �ʱ�ȭ�� �ϸ� �ʿ� ����.
Something::_init Something::s_initializer;
	// inner Ŭ������ �̿��ؼ� ���������� static ��� �ʱ�ȭ

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



// static ��� ������ �����ڿ��� �ʱ�ȭ�� �� ����
// C++���� �����ڴ� static�� �� ����̴�.
// inner Ŭ������ �̿��ϸ� �����ڸ� �̿��ؼ� static ����� �ʱ�ȭ�� �� �ִ�.