#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = -1)
		:m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction)
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "copy constructor called" << endl;
	}




	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main()
{
	Fraction result = doSomething();

	cout << result << endl;
	cout << &result << endl;

	return 0;
}

// 반환이 되면 temp라는 return value는 유지될 필요가 없기 때문에
// release 모드에서는 copy constructor를 실행시키지 않는다
// 이것을 반환값 최적화라고 한다
// 위 코드는 debug 모드에서는 temp와 result의 주소가 다르다
// 하지만 release 모드에서는 주소가 같다. 즉 같은 객체를 이용하는 것