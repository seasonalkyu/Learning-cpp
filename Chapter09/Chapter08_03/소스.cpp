#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		// !Cents(...) 에서 ...가 0이면 true return 나머지에서 false return
		return (m_cents == 0) ? true : false;
	}
};

int main()
{

	// 단항 연산자 오버로딩
	Cents cents1(6);
	Cents cents2(0);

	auto temp = !cents1;

	cout << !cents1 << " " << !cents2 << " " << temp << endl;
	// cout은 false 는 0, true는 1로 출력됨

	return 0;
}