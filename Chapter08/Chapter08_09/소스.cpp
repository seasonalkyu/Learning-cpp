#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
	string m_value = "default";

	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}


	const string& getValue() const
	{
		cout << "const version" << endl;
		return m_value;
	}
	
};


int main()
{
	Something something;
	something.getValue() = 10;
	// non-const �� ȣ��ǰ� �ִ�
	// ���� �ٲ��� �� �ִ�.


	const Something something2;
	something2.getValue();
	// const reference�� ��ȯ�ǹǷ� ���� �ٲ��� �� ����

	return 0;
}


