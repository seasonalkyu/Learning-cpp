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

	// friend 전역함수
	friend Cents operator + (const Cents& c1, const Cents& c2)
	{
		return Cents(c1.getCents() + c2.getCents());
	}
};

//Cents add(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	// 힘든 방법
	//Cents sum;
	//add(cents1, cents2);
	//cout << add(cents1, cents2).getCents() << endl;

	// 산술 연산자 오버로딩
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;

}

// 두 인스턴스를 add하는 함수를 만드려면 많은 작업이 필요하다
// 주의
// 삼항연산자 ?: , 스코프::, sizeof, .(dot=member selection), .*(member pointer selection) 은 오버로딩이 안된다
// 오버로딩을 하더라도 연산자 우선순위는 바꿀 수 없다
// ^ 연산자는 우선순위가 매우 낮다. 따라서 굳이 오버로딩하여 이용한다면 괄호로 싸서 이용한다