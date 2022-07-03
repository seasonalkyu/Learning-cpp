#include <iostream>

using namespace std;

int main()
{
	// int array[1000000];
		// error가 난다.
		// 정적으로 배열을 할당하면 stack 영역에 저장되는데 stack영역은 크기가 작다.

	int* ptr1 = new int;
	int* ptr2 = new int{ 7 };
		// new를 이용해서 os로부터 메모리를 할당받을 수 있다.

	int* ptr3 = new (std::nothrow)int{ 7 };
		// 가끔 메모리를 할당받지 못해서 에러가 날 때가 있다.
		// 예외 처리에서 자세히 배운다.
		// 혹은 다음처럼 이용할 수도 있다.
	if (ptr1 != nullptr)
	{
		*ptr1 = 8;
	}

	delete ptr1;
	delete ptr2;
	delete ptr3;
		// 직접 할당받은 메모리는 반환해야한다.
}