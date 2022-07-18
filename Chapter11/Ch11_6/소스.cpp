#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{

	}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{}

	void setValue(int value)
	{
		Base::m_value = value;
		// do Something with the vbariables in Derived
	}
};

/*
* ���� �ڵ�ó�� m_value�� �̿��ϴ� ��Ȳ�̶�� Base Ŭ������ setValue()�� ����� ���� �´�
* ������ Derived�� ����� �̿��Ѵٸ� base�� ����� protected�� �����Ѵ�
* 
* getValue ���� �Լ��� �̿��ؼ� private ����� �����´ٸ� ������ ������ ���� �� �ִ�
* ���� �θ��� ����� ���� ����� ���� private ���ٴ� protected�� ���� �� �����ϴ�
*/