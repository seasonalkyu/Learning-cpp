#include <iostream>

using namespace std;

int main()
{
	// case 1 const int* : const int �ּҸ� ���� �� �ִ� ������ ����
	const int c_value1_1 = 5;
	int value1_2 = 6;
	//int* ptr1 = &c_value1_1;
		// error
		// int* ptr1�� �ɺ��� ����� ����ų �� ����
	const int* ptr1 = &c_value1_1;
		// ok
	//*ptr1 = 6;
		// error
		// const int*�� dereferencing�ؼ� ������ �� ����.
	//c_value1_1 = 6;
		// error
		// ����̹Ƿ� ������ �� ����
	ptr1 = &value1_2;
		// ok
		// const int*�� int�� �ּҵ� ���� �� �ִ�.
		// �̷� ���� ptr�� dereferencing�ؼ� ���� ������ �� ����.
		// ������ value1_2�� ���� ������ ���� �ִ�.
	

	// case 2 int* const : int �ּҸ� ���� �� �ִ� ������ ���. ����� �ʱ�ȭ�� ���� �Ͼ���Ѵ�.
	int value2_1 = 5;
	int value2_2 = 6;
	int* const ptr = &value2_1;
	*ptr = 10;
		// ok
	//ptr = &value2_2;
		// int* pointer�� �ٸ� ���� ����Ű���� �ٲ� �� ����

	// case 3 const int* const : ����Ű�� ������ ������ ���� ��� ����� ���
		
}