#include <iostream>

using namespace std;

int main()
{
	// case 1 const int* : const int 주소를 담을 수 있는 포인터 변수
	const int c_value1_1 = 5;
	int value1_2 = 6;
	//int* ptr1 = &c_value1_1;
		// error
		// int* ptr1은 심볼릭 상수를 가리킬 수 없다
	const int* ptr1 = &c_value1_1;
		// ok
	//*ptr1 = 6;
		// error
		// const int*로 dereferencing해서 수정할 수 없다.
	//c_value1_1 = 6;
		// error
		// 상수이므로 수정할 수 없다
	ptr1 = &value1_2;
		// ok
		// const int*는 int의 주소도 담을 수 있다.
		// 이럴 때는 ptr로 dereferencing해서 값을 수정할 수 없다.
		// 하지만 value1_2를 직접 수정할 수는 있다.
	

	// case 2 int* const : int 주소를 담을 수 있는 포인터 상수. 선언과 초기화가 같이 일어나야한다.
	int value2_1 = 5;
	int value2_2 = 6;
	int* const ptr = &value2_1;
	*ptr = 10;
		// ok
	//ptr = &value2_2;
		// int* pointer가 다른 것을 가리키도록 바꿀 수 없다

	// case 3 const int* const : 가리키는 변수와 포인터 변수 모두 상수인 경우
		
}