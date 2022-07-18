#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}


	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
	}
	// 멤버함수로 선언하는 법
	//bool operator < (const Cents& c2)
	//{
	//	return this->m_cents < c2.m_cents;
	//}
};

int main()
{
	vector<Cents> arr(20);

	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	// random 하게 섞는 코드
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(arr.begin(), arr.end(), g);

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;
	
	
	std::sort(begin(arr), end(arr));
		// 크기 비교를 하는 연산자를 오버로딩하지 않으면 error가 난다

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
	
}

// 크기 비교 연산자는 < 만 오버로딩할 수 있다