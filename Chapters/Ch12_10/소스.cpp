#include <iostream>
#include <string>
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

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main()
{
	Derived1 d;
	Base* basePtr = &d;

	auto* base_to_d = static_cast<Derived2*>(basePtr);
	
		// dynamic_cast는 실패하면 nullptr을 반환한다

	if (base_to_d != nullptr)
		base_to_d->print();
	else
		cout << "Failed" << endl;
	cout << base_to_d;
	return 0;
}

/*

*/