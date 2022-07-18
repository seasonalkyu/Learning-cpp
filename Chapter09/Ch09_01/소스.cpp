#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// friend �����Լ�
	friend Cents operator + (const Cents& c1, const Cents& c2)
	{
		return Cents(c1.getCents() + c2.getCents());
	}
};

//Cents add(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	// ���� ���
	//Cents sum;
	//add(cents1, cents2);
	//cout << add(cents1, cents2).getCents() << endl;

	// ��� ������ �����ε�
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;

}

// �� �ν��Ͻ��� add�ϴ� �Լ��� ������� ���� �۾��� �ʿ��ϴ�
// ����
// ���׿����� ?: , ������::, sizeof, .(dot=member selection), .*(member pointer selection) �� �����ε��� �ȵȴ�
// �����ε��� �ϴ��� ������ �켱������ �ٲ� �� ����
// ^ �����ڴ� �켱������ �ſ� ����. ���� ���� �����ε��Ͽ� �̿��Ѵٸ� ��ȣ�� �μ� �̿��Ѵ�