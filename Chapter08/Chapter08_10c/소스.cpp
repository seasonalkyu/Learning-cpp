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

// static constexpr ����� runtime�� ������ �� ���� ������time�� �ʱ�ȭ �Ǿ� �־���Ѵ�