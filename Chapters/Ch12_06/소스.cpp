#include <iostream>

using namespace std;

class Base
{
public:
	//FunctionPointer *_vptr;
	virtual void fun1() {};
	virtual void fun2() {};
};

class Der : public Base
{
public:
	//FunctionPointer *_vptr;
		// ��� ����
	virtual void fun1() {};
	//void fun3() {};
};

int main()
{
	cout << sizeof(Base) << endl;
		// 8 ���
	cout << sizeof(Der) << endl;
		// 8 ���

	// virtual�� �������� �ʾҴٸ� 1 �� ��µȴ�
}

/*
* �����Ϸ� ���������� virtual function�� ����Ǹ� ���� ���ε��� �ϴ� ���� �ƴ϶�
* ���� ���ε��� ǥ�� �ݵ� ���� ���ε��� �Ѵ�
* 
* virtual function�� �����Ű�� virtual function table�� ���� ã�´�
* ���̺��� �ش�Ǵ� �Լ� �����͸� ã���� ����Ű�� �ִ� �Լ��� ã�ư���
* 
* �ڽ�Ŭ�������� fun1()�� �������̵�Ǿ��ִ�. ���� ���� ���̺��� ã�ư���
* �� ���� fun1()�� ã�Ƽ� �����Ų��
* fun2()�� �����Ű�� ���̺��� �θ� Ŭ������ fun2()�� ã�Ƴ��� �����Ų��
* 
*/