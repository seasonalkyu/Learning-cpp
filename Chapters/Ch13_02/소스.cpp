#include "MyArray.h"

int main()
{
	//MyArray my_array(10);
		// error : ���ø� Ŭ������ ��ü�� ������ ���� <int>, <double>�� ���� �ڷ��� ������ ������ �� ����
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