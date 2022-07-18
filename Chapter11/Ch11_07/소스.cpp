#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value = 5)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm Base " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		cout << "This is Base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value = 7)
		: Base(value)
	{}

	void print()
	{
		cout << "I'm Derived " << endl;
		// print();
			// ������� ȣ��
		// Base::print();
			// �θ��� print() ȣ��
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& d)
	{
		cout << static_cast<Base>(d);
			// Derived�� Base�� �����ϰ� �ִ�
			// ���� casting�� �����ϴ�
		cout << "This is Derived output" << endl;
		return out;
	}
};

int main()
{
	Base base;
	base.print();
	cout << base;

	Derived derived(7);
	derived.print();
	cout << derived;
}

/*
* �ڽ� Ŭ������ �����Ϸ��� ����� �θ�Ŭ������ �Ͱ� ������ ���� ��ӹ��� �Լ��� �������̵��� �� �ִ�
* �̸��� ���� �Լ��� �ڽ�Ŭ�������� ������
*/