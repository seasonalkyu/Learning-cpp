#include "MyArray.h"

int main()
{
	//MyArray my_array(10);
		// error : 템플릿 클래스의 객체를 생성할 때는 <int>, <double>과 같은 자료형 정보를 생략할 수 없다
	MyArray<double> my_array(10);
	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 0.5;
	my_array.print();

	MyArray<char> my_array(10);
	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 10;
	my_array.print();

	return 0;
}