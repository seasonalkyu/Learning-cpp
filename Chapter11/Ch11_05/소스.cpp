#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};


class Derived1 : public Base
{
public:
	Derived1()
	{
	m_public = 123;
		// ok
	m_protected = 456;
		// ok
	//m_private = 789;
		// error
	}
};

class Derived2 : protected Base
{
public:
	Derived2()
	{
		m_public = 123;
		// ok
		m_protected = 456;
		//Base::m_protected = 456;
		//this->m_protected = 456;
		// ok
		//m_private = 789;
		// error
		
	}
};

class Derived3 : private Base
{
public:
	Derived3()
	{
		m_public = 123;
		// ok
		m_protected = 456;
		//Base::m_protected = 456;
		//this->m_protected = 456;
		// ok
		//m_private = 789;
		// error

	}
};

class GrandChild : public Derived3
{
public:
	GrandChild()
	{
		//Derived3::m_public;
			// error
			// m_public은 derived3 안에서 private인 것처럼 접근지정자가 작동한다
		//Derived3::m_protected;
			// error
		//Derived3::m_private;
			// error
	}

};

int main()
{
	Base base;
	Derived1 d1;
	Derived2 d2;

	base.m_public = 123;
		// ok
	//base.m_protected = 456;
		// error
	//base.m_private = 789;
		// error

	d1.m_public = 123;
	// ok
	//d1.m_protected = 456;
	// error
	//d1.m_private = 789;
	// error

	//d2.m_public = 123;
	// error
	//d2.m_protected = 456;
	// error
	//d2.m_private = 789;
	// error
}

/*
* 상속과 접근 지정자
* 
* 
*/