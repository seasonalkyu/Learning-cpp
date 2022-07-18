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
		// Mother의 default 생성자를 호출한다
		// 따라서 Mother에 default 생성자가 없는 상황이라면 error가 나므로
		// Mother의 다른 생성자를 이용해야한다
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
			// 부모의 setValue
		setValue(d_in);
			// 자신의 setValue
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

// 상속
/*
* Child 클래스의 생성자의 initialization list에서 Mother class의 생성자를 이용할 수 있다
*/