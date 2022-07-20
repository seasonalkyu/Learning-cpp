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
		// error : 레퍼런스를 반환하면 값이 바뀔 수 있으므로
		// const로 선언한 멤버라면 레퍼런스를 반환하고 싶다면, const reference를 반환한다.
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
	// 값을 바꾸려고 시도하기 때문에 non-const 가 호출된다
	// 값을 바꿔줄 수 있다.


	const Something something2;
	something2.getValue();
	// const reference가 반환되므로 값을 바꿔줄 수 없다

	const Something& sref1 = something1;
	const Something& sref2 = something2;

	sref1.getValue();
		// ok
	//sref1.getValue() = 3;
		//error : const멤버가 호출된다
	sref2.getValue();
		// const멤버가 호출된다
		
	return 0;
}