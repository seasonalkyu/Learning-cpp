#include <iostream>

using namespace std;


class First
{
public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};


class Second
{
	First fir;
public:
	Second() 
	{
		cout << "class Second constructor()" << endl;
	}
};

int main()
{

	Second sec;

	return 0;
}

/*
* class Second�� First�� �ν��Ͻ��� ����� �����ٰ� ����
* �̶� Second�� �ν��Ͻ��� �����ϸ� First�� �����ڰ� �ռ� ����ǰ� �� ���� Second�� �����ڰ� ����ȴ�
*/