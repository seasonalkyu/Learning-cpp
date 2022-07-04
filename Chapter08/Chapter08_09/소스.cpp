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
	// non-const 가 호출되고 있다
	// 값을 바꿔줄 수 있다.


	const Something something2;
	something2.getValue();
	// const reference가 반환되므로 값을 바꿔줄 수 없다

	return 0;
}


