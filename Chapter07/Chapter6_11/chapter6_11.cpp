#include <iostream>

using namespace std;

int main()
{
	// int array[1000000];
		// error�� ����.
		// �������� �迭�� �Ҵ��ϸ� stack ������ ����Ǵµ� stack������ ũ�Ⱑ �۴�.

	int* ptr1 = new int;
	int* ptr2 = new int{ 7 };
		// new�� �̿��ؼ� os�κ��� �޸𸮸� �Ҵ���� �� �ִ�.

	int* ptr3 = new (std::nothrow)int{ 7 };
		// ���� �޸𸮸� �Ҵ���� ���ؼ� ������ �� ���� �ִ�.
		// ���� ó������ �ڼ��� ����.
		// Ȥ�� ����ó�� �̿��� ���� �ִ�.
	if (ptr1 != nullptr)
	{
		*ptr1 = 8;
	}

	delete ptr1;
	delete ptr2;
	delete ptr3;
		// ���� �Ҵ���� �޸𸮴� ��ȯ�ؾ��Ѵ�.
}