
#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl;
		return this;  
	}
};



int main()
{
	A a;
	B b;
	
	A& ref = b;
	b.getThis()->print();
		// Ŭ���� B�� getThis�� ����ȴ�.
		// B�� ��µȴ�.

	ref.getThis()->print();
		// Ŭ���� B�� getThis�� ����ȴ�
		// A �� ��µȴ�.
		// getThis�� B�� ��ȯ������ ���������� �ٽ� A�� �ٲپ� ����ϱ� ����

	cout << typeid(b.getThis()).name() << endl;
		// class B *
	cout << typeid(ref.getThis()).name() << endl;
		// class A *


}

