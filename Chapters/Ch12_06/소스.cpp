#include <iostream>

using namespace std;

class Base
{
public:
	//FunctionPointer *_vptr;
	virtual void fun1() {};
	virtual void fun2() {};
};

class Der : public Base
{
public:
	//FunctionPointer *_vptr;
		// 상속 받음
	virtual void fun1() {};
	//void fun3() {};
};

int main()
{
	cout << sizeof(Base) << endl;
		// 8 출력
	cout << sizeof(Der) << endl;
		// 8 출력

	// virtual로 선언하지 않았다면 1 이 출력된다
}

/*
* 컴파일러 내부적으로 virtual function이 선언되면 정적 바인딩을 하는 것이 아니라
* 동적 바인딩의 표를 반들어서 동적 바인딩을 한다
* 
* virtual function을 실행시키면 virtual function table을 먼저 찾는다
* 테이블에서 해당되는 함수 포인터를 찾으면 가리키고 있는 함수를 찾아간다
* 
* 자식클래스에서 fun1()은 오버라이드되어있다. 따라서 먼저 테이블을 찾아가고
* 그 다음 fun1()을 찾아서 실행시킨다
* fun2()를 실행시키면 테이블에서 부모 클래스의 fun2()를 찾아내서 실행시킨다
* 
*/