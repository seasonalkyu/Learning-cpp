#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base " << endl;
	}
};

class Derived : public Base
{
protected:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}


	using Base::m_i;
		// m_i�� Derived���� public�� �ȴ�

private:
	using Base::print;
		// ��ӹ��� �Լ��� private�� �Ͽ� ������� ���ϰԲ� ���´�
		// ������ ()�� ������� �ʰ� �̸��� ������Ѵ�
	// void print() = delete;
};

int main()
{
	Derived derived(7);
	derived.m_i = 1024;
		// using Base::m_i�� ���ٸ� error
	//derived.print();
}

/*
* ��ӹ��� �Լ��� ������� ���ϵ��� ���ƹ����� ��
* 
* public: using Base::m_i; �� �ڽ� �Լ����� �����ϸ� �ڽ��Լ����� m_i�� public�� �ȴ�
* 
* �ڽ� Ŭ�������� �θ�Ŭ���� �Լ��� ������� �ʴ� ����� 2�����̴�
* ���1: private: using Base::print
* ���2: private: void print() = delete;
*/