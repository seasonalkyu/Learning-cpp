#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;

	int* array = new int[3]{ 1, 2, 3 };
	delete[] array;
		// 정적 배열은 크기가 컴파일 타임에서 결정되기 때문
		// 배열의 크기를 바꾸려면 두 가지 방법이 있다.
		// 1. 새로운 배열을 만들고 element를 복사해서 붙여넣는다.
		// 2. 기존 배열의 뒷 부분에 추가해서 붙일 수 있는지 OS에 물어보고 요청함 
}