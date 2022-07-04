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
		// int getDay()�� ����

	void copyFrom(const Date2& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
		// original.m_month�� private������ ���� Ŭ������ �ٸ� �ν��Ͻ��� private ����� ������ �����ϴ�
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
	* 3������ �ִ�
		1. public
		2. private
			* �⺻���̴�. access specifier�� ���ٸ� private�̴�.
		3. protected
* ���¼ҽ��� ����� �ڵ�� ��ü������ ������ ��Ű�� ���� ����
	* ���α׷��� ũ�� ����
* encapsulation�� �ϴ� ����
	* ����� �̸��� �ٲ� �� ȿ�����̰� ��Ȯ�ϴ�
*/