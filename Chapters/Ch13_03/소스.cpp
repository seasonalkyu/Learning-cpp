#include "MyArray.h"

int main()
{

	//int i = 100;
	//MyArray<double, i> my_array; // std::array<double, 100>
		// error
		// 컴파일타임에 값이 결정되는 것이 들어가야한다
	MyArray<double, 100> my_array1; // std::array<double, 100>
		// ok
	const int i = 100;
	MyArray<double, i> my_array2; // std::array<double, 100>
		// ok



	for (int i = 0; i < my_array1.getLength(); ++i)
		my_array1[i] = i + 65;
	my_array1.print();
}

/*
* 자료형이 아닌 템플릿 매개변수
* 
* 13_02 강의에서는 
* std::vector<double> my_array; my_array.resize(100);
* MyArray<double> my_array(100);
* 처럼 메모리를 동적할당했다
* 
*/