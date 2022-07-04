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
* class Second는 First의 인스턴스를 멤버로 가진다고 하자
* 이때 Second의 인스턴스를 생성하면 First의 생성자가 먼서 실행되고 그 다음 Second의 생성자가 실행된다
*/