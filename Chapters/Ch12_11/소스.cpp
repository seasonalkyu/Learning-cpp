#include <iostream>

class Base
{
public:
	Base() {}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}
	
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << '\n';

	Derived d;
	std::cout << d << '\n';

	Base& bref = d;
	std::cout << bref << '\n';

	return 0;
}

/*
* ���� Ŭ�������� ��� ������ ����ϱ�
* Ŭ������ friend�Լ��� ����� �ƴϹǷ�, �ڽ�Ŭ�������� �������̵��� �� �� ����
* ���� virtual �Լ��� �ϳ� �����ؼ� friend �Լ����� �̿��Ѵ�
* friend �Լ����� const Base& Ÿ������ ���ڸ� �ް�, virtual�� �Լ��� �����߱� ������ 
* �ڽ��Լ����� �������̵��ϴ� �� ó�� �̿��� �� �ִ�
* 
* 
* Derived() {} ���� print�Լ��� const�� ������ ������ 
* �����ε��� << �����ڿ��� ���ڸ� Base& ��ü�� ���� ���̱� �����̴�.
* ���� Base �Լ����� print�� virtual�� ���������Ƿ� Base& bref = d; ���ϴ���
* d�� << �����ڰ� �̿�ȴ�
*/