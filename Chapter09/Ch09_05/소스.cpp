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
	// int�� ����/���� �������� ������ ���� ������ Ư���� �ǹ̴� ����
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

// ��� ���� �����ڿ� ���������ڴ� ���� ������ ���� �̷������.
// ���� ���̴� ���� ���� ��ü�� ��ȯ�ϴ°�, ������ �����θ� ��ȯ�ϴ°��� �����̴�.
// ���� ������ �����θ� ��ȯ�ϴ� ���� �����ڰ� �ӵ��� ���� ���̴�