#include "MyArray.h"

int main()
{

	//int i = 100;
	//MyArray<double, i> my_array; // std::array<double, 100>
		// error
		// ������Ÿ�ӿ� ���� �����Ǵ� ���� �����Ѵ�
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
* �ڷ����� �ƴ� ���ø� �Ű�����
* 
* 13_02 ���ǿ����� 
* std::vector<double> my_array; my_array.resize(100);
* MyArray<double> my_array(100);
* ó�� �޸𸮸� �����Ҵ��ߴ�
* 
*/