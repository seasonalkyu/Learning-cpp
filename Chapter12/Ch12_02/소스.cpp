#include <iostream>
using namespace std;

class A
{
public: 
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
	//virtual int print() { cout << " << endl; return 0; }
		// error
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	A& ref = c;
	ref.print();
		// A에 virtual키워드를 사용하면 C가 출력된다
	B& ref = c;
	ref.print();
		// C가 출력된다
		// B가 A를 출력받지 않았다면 B가 출력된다.
		// 즉, 최상위 클래스가 virtual로 함수를 선언했다면 하위의 모든 클래스는 virtual로 사용한다
		// 그래서 관습적으로 virtual로 선언한 함수는 하위 클래스에서도 오버라이딩한 함수를 virtual로 선언한다

}
/*
* 가상 함수와 다형성
* 
* D에서 오버라이딩할 때 리턴타입이 다르다면?
* A에서 선언된 print()와 차이가 있다며 에러가 난다
* 오버로딩을 할 때 리턴타입으로 함수를 구분할 수 없는 것처럼 오버라이딩에서도 리턴타입만 다른 것을 막아둔 것
* 
* virtual 키워드는 스택 방식으로 작동하는 것이 아니라 테이블에서 표를 보고 찾아가는 과정이 있어서 느리다
* 
*/
