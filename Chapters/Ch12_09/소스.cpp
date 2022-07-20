#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b) 
{
	b.print();
}

void doSomething2(Base b)
{
	b.print();
}

int main()
{
	Base b;
	Derived d;

	std::vector<std::reference_wrapper<Base>> my_vec;
		// std::vector<Base&> my_vec ó�� �۵��Ѵ�
	//my_vec.push_back(&b);
	//my_vec.push_back(&d);
		// error
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& ele : my_vec)
		ele.get().print();
			// ele.print()�� error
			// ele.get()�� ���ؼ� ���ε� ������ �����´�.

	return 0;
}
/*
*
*/