#include <iostream>
using namespace std;

class A
{
public: 
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
	//virtual int print() { cout << " << endl; return 0; }
		// error
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	A& ref = c;
	ref.print();
		// A�� virtualŰ���带 ����ϸ� C�� ��µȴ�
	B& ref = c;
	ref.print();
		// C�� ��µȴ�
		// B�� A�� ��¹��� �ʾҴٸ� B�� ��µȴ�.
		// ��, �ֻ��� Ŭ������ virtual�� �Լ��� �����ߴٸ� ������ ��� Ŭ������ virtual�� ����Ѵ�
		// �׷��� ���������� virtual�� ������ �Լ��� ���� Ŭ���������� �������̵��� �Լ��� virtual�� �����Ѵ�

}
/*
* ���� �Լ��� ������
* 
* D���� �������̵��� �� ����Ÿ���� �ٸ��ٸ�?
* A���� ����� print()�� ���̰� �ִٸ� ������ ����
* �����ε��� �� �� ����Ÿ������ �Լ��� ������ �� ���� ��ó�� �������̵������� ����Ÿ�Ը� �ٸ� ���� ���Ƶ� ��
* 
* virtual Ű����� ���� ������� �۵��ϴ� ���� �ƴ϶� ���̺��� ǥ�� ���� ã�ư��� ������ �־ ������
* 
*/
