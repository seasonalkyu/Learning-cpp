#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;

public:
	Mother(const int& i_in)
		: m_i(i_in)
	{
		std::cout << "Mother constructor" << std::endl;
	}
	void setValue(const int& value)
	{
		m_i = value;
	}

	int getValue() {
		return m_i;
	}
};

class Child : public Mother
{
private:
	double m_d;
	
public:
	Child(const int& i_in, const double& d_in)
		// Mother�� default �����ڸ� ȣ���Ѵ�
		// ���� Mother�� default �����ڰ� ���� ��Ȳ�̶�� error�� ���Ƿ�
		// Mother�� �ٸ� �����ڸ� �̿��ؾ��Ѵ�
		: Mother(i_in), m_d(d_in)
	{
		//Mother::setValue(i_in);
		//m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		//m_i = i_in;
			// error
		Mother::setValue(i_in);
			// �θ��� setValue
		setValue(d_in);
			// �ڽ��� setValue
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};


int main()
{
	Mother mother(1);
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 128);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	child.Mother::setValue(1024);
	child.setValue(128);
}

// ���
/*
* Child Ŭ������ �������� initialization list���� Mother class�� �����ڸ� �̿��� �� �ִ�
*/