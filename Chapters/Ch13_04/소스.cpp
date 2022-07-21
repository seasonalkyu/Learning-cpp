#include <iostream>
#include "Storage.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
		return (x > y) ? x : y;
}

// specialization
// char 타입으로 instantiation될 때만 적용한다.
// 즉, argument가 char일 때만 적용되도록 함
// 이런 방법을 쓰는 이유는 컴파일 타임에 이뤄져야하므로 if문을 사용할 수 없기 때문
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	// case 1
	//cout << getMax<int>(1, 2) << endl;
	cout << getMax(1, 2) << endl;
		// instantiation을 자동으로 해준다
		// 내부적으로는 getMax<int>(1,2)와 같다
	cout << getMax(1.0, 2.0) << endl;
		// 내부적으로는 cout << getMax<double>(1.0, 2.0) << endl;
	cout << getMax<double>(1, 2) << endl;

	// case 2
	cout << getMax('a', 'b') << endl;

	// case 3
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}

/*
* 컴파일 타임에 이뤄져야하므로 if문을 사용할 수 없다
* 따라서 specialization을 사용한다
* specialization : 일반화 한 것을 특수한 것에만 적용
* 
* 특수화는 분리하기보다는 헤더파일에 두는 것이 좋다
*/