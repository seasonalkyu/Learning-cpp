#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{
	}

	template<typename TT>
		// TT는 doSoemthing() 에서만 적용되는 파라미터이다
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	a_int.doSomething<float>(123.4);
		// doSomething이라는 함수는 float TT에 대해서 instantiation이 되어있는 것이다.
		// 그런데 double인 123.4를 넣어서 truncation이 된다
	a_int.doSomething(123.4);
	a_int.doSomething('a');
		// 파라미터로 구분할 수 있다면 <float>이 필요없다


	A<char> a_char('A');
	a_char.print();

	// < > 로 구분
	a_char.doSomething<int>(3.4);

	// 파라미터로 구분
	a_char.doSomething(1);
		// m_value를 integer형식으로 출력하기 위함
	a_char.doSomething(int());
		// m_value를 integer 형식으로 출력하기 위함
	a_char.doSomething(char());
	return 0;
}