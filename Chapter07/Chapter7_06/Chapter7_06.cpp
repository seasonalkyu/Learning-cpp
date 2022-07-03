#include <iostream>

using namespace std;

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
}

// 간단한 기능의 함수는 호출하고 반환하는 과정이 실제 기능보다 리소스를 더 많이 차지할 수 있다.
// 이럴 때는 인라인 함수를 이용한다
// 보통 헤더 파일에 선언한다
// 컴파일러가 판단해서 적용한다.
// 요즘에는 컴파일러가 좋아져서 inline을 적어두지 않아도 알아서 판단하기도 한다