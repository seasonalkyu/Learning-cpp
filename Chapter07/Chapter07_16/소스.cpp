#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...)
{
	double sum = 0;

	va_list list;

	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // list�� int�� ��ȯ�ϴ� ����

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;
		// ok but 1�� ���
	cout << findAverage(3, 1, 2, 3) << endl;
		// ok
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
		// ok
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl;
		// �̻��� ���� ���

}

// ������ȣ Ellipsis
// ����ϱ� ��ư� ����뵵 �����
