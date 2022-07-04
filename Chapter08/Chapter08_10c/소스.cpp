#include <iostream>
using namespace std;

class Something
{
public:
	static constexpr int s_value = 1;
};

//int Something::s_value = 1;
	// error

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;

	Something st1;
	Something st2;

	//st1.s_value = 2;
		// error 
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;

	//Something::s_value = 1024;
		// error

	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}

// static constexpr 멤버는 runtime에 결정될 수 없고 컴파일time에 초기화 되어 있어야한다