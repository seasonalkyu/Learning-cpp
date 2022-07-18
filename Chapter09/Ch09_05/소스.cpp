#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}

	// prifix
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	// postfix
	// int는 전위/후위 연산자의 구분을 위한 것으로 특별한 의미는 없다
	Digit operator ++ (int)
	{
		Digit temp(m_digit);
		++(*this);
		return temp;
	}
};

int main()
{


	return 0;
}

// 사실 전위 연산자와 후위연산자는 값의 증감이 즉이 이루어진다.
// 둘의 차이는 증감 전의 객체를 반환하는가, 증감한 스스로를 반환하는가의 차이이다.
// 따라서 증감한 스스로를 반환하는 전위 연산자가 속도가 빠를 것이다