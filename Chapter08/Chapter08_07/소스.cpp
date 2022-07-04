#include <iostream>
using namespace std;

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// 일반적인 경우
	//void add(int value) { m_value += value; }
	//void sub(int value) { m_value -= value; }
	//void mult(int value) { m_value *= value; }

	// 연쇄 호출
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void print()
	{
		cout << m_value << endl;
	}
};
int main()
{
	// 일반적인 경우
	//Calc cal(10);
	//cal.sub(1);
	//cal.mult(2);
	//cal.print();
	// 연쇄 호출 Chaining member function
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();

	
}

// 연쇄호출은 C++에서는 실용성은 애매하다
