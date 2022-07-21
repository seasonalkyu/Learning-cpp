#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{
	}

	template<typename TT>
		// TT�� doSoemthing() ������ ����Ǵ� �Ķ�����̴�
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	a_int.doSomething<float>(123.4);
		// doSomething�̶�� �Լ��� float TT�� ���ؼ� instantiation�� �Ǿ��ִ� ���̴�.
		// �׷��� double�� 123.4�� �־ truncation�� �ȴ�
	a_int.doSomething(123.4);
	a_int.doSomething('a');
		// �Ķ���ͷ� ������ �� �ִٸ� <float>�� �ʿ����


	A<char> a_char('A');
	a_char.print();

	// < > �� ����
	a_char.doSomething<int>(3.4);

	// �Ķ���ͷ� ����
	a_char.doSomething(1);
		// m_value�� integer�������� ����ϱ� ����
	a_char.doSomething(int());
		// m_value�� integer �������� ����ϱ� ����
	a_char.doSomething(char());
	return 0;
}