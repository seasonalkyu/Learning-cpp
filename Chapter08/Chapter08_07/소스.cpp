#include <iostream>
using namespace std;

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	// �Ϲ����� ���
	//void add(int value) { m_value += value; }
	//void sub(int value) { m_value -= value; }
	//void mult(int value) { m_value *= value; }

	// ���� ȣ��
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	void print()
	{
		cout << m_value << endl;
	}
};
int main()
{
	// �Ϲ����� ���
	//Calc cal(10);
	//cal.sub(1);
	//cal.mult(2);
	//cal.print();
	// ���� ȣ�� Chaining member function
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();

	
}

// ����ȣ���� C++������ �ǿ뼺�� �ָ��ϴ�
