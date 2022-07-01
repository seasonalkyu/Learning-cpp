#include <iostream>
#include <string>

using namespace std;

int main()
{
	// syntax error
	
	// symentic errors 논리 오류
	// 내 의도와는 다른 기능의 코딩을 함
	int x;
	cin >> x;

	if (x >= 5)
		cout << "x is greater than 5" << endl;


	// violated assumption
	// 사용자가 내 의도와 다른 방식으로 이용함
	string hello = "Hello, my name is Jack";

	cout << "Input from 0 to " << hello.size() - 1 << endl;
	
	while (true)
	{
		int ix;
		cin >> ix;

		if (ix >= 0 && ix <= hello.size() - 1)
			cout << hello[ix] << endl;
		else
			cout << "Please try again" << endl;

	}
	return 0;
}

// 방어적 프로그래밍
// 오류를 컴파일러가 잡아낼 수 있는 코딩을 의도적으로 해야한다
