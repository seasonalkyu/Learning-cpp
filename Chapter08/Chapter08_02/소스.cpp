#include <iostream>
#include <string>
#include <vector>

using namespace std;


// public
class Date
{
public: // access specifier
	int m_month;
	int m_day;
	int m_year;
};


// private
class Date2
{
private: // access specifier
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	void setMointh(const int& month_input)
	{
		m_month = month_input;
	}

	const int& getDay()
	{
		return m_day;
	}
		// int getDay()도 가능

	void copyFrom(const Date2& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
		// original.m_month는 private이지만 같은 클래스의 다른 인스턴스의 private 멤버는 접근이 가능하다
};


int main()
{
	// public
	//Date today{ 8, 4, 2025 };
		// ok
	Date today;
	today.m_month = 8;
	today.m_day = 4;
	today.m_year = 2025;

	// private
	//Date2 today2{ 8, 4, 202 };
		// error
	Date2 today2;
	today2.setDate(8, 4, 2025);
	//cout << today2.m_month;
		//error
	cout << today2.getDay() << endl;

	Date2 copy;
	copy.copyFrom(today2);


	return 0;
}

/*
* access specifier
	* 3가지가 있다
		1. public
		2. private
			* 기본값이다. access specifier가 없다면 private이다.
		3. protected
* 오픈소스나 상업용 코드는 객체지향을 엄격히 지키는 것이 좋다
	* 프로그램이 크기 때문
* encapsulation을 하는 이유
	* 멤버의 이름을 바꿀 때 효과적이고 정확하다
*/