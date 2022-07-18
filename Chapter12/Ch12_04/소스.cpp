#include <iostream>
using namespace std;

class Base
{
public:
	//~Base()
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	//~Derived()
	~Derived() override
	//virtual ~Derived() override
		// �θ�Ŭ������ �Ҹ��ڿ� virtual�� �پ��ִٸ� override �� �� �ִ�
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}
};


int main()
{
	//Derived derived(5);
		// Derived�� �Ҹ��ڰ� ����� �Ŀ� base�� �Ҹ��ڰ� ����ȴ�

	// �������� �̿��ϴ� case
	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;
		// Base�� �Ҹ��ڰ� virtual�� �ƴ϶�� base�� �Ҹ��ڸ� ����ȴ�
		// ���� Derived�� �Ҹ��ڰ� ������� �ʾƼ� memory leak�� �����
		// Base�� �Ҹ��ڸ� virtual�� �����Ѵٸ� Derived�� �Ҹ��ڰ� ���� ����ǰ�
		// �� ������ Base�� �Ҹ��ڰ� ����ȴ�

	return 0;
}

/* 
* �ڽ� Ŭ������ �Ҹ��ڰ� ���� ����ǰ� �� ���� �θ� Ŭ������ �Ҹ��ڰ� ����ȴ�
* 
* ���� �Ҹ���
* delete base�� �ϸ� base�� ����� Ŭ������ �Ҹ��ڰ� ������� �ʴ� �������� �ִ�
* �̰��� �ذ��ϱ� ���ؼ� base�� �Ҹ��ڸ� virtual�� �����Ѵ�
*/