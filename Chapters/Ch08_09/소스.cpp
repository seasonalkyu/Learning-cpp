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


	//string& getValue() const
		// error : ���۷����� ��ȯ�ϸ� ���� �ٲ� �� �����Ƿ�
		// const�� ������ ������ ���۷����� ��ȯ�ϰ� �ʹٸ�, const reference�� ��ȯ�Ѵ�.
	const string& getValue() const
	{
		cout << "const version" << endl;
		return m_value;
	}

};


int main()
{
	Something something1;
	something1.getValue();
		// non-const 
	something1.getValue() = 10;
	// ���� �ٲٷ��� �õ��ϱ� ������ non-const �� ȣ��ȴ�
	// ���� �ٲ��� �� �ִ�.


	const Something something2;
	something2.getValue();
	// const reference�� ��ȯ�ǹǷ� ���� �ٲ��� �� ����

	const Something& sref1 = something1;
	const Something& sref2 = something2;

	sref1.getValue();
		// ok
	//sref1.getValue() = 3;
		//error : const����� ȣ��ȴ�
	sref2.getValue();
		// const����� ȣ��ȴ�
		
	return 0;
}