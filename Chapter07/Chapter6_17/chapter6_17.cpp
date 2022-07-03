#include <iostream>
#include <limits>

using namespace std;

int main()
{
	const int c_fibonacci[] = { 0, 1, 10, 45, 91 };
	int fibonacci[] = { 0, 1, 10, 45, 91 };
	
	// for each�� ����
	for (int number : c_fibonacci)
		cout << number << " ";
	cout << endl;

	// fibonacci�� ������ �ٲٱ�, ������ �ٲ��� �ʴ´�.
	for (int number : fibonacci)
		number = 10;

	// reference�� �̿��ؼ� fibonacci�� ������ �ٲ� �� �ִ�.
	for (int& number : fibonacci)
		number = 10;

	// ������ ����� �� ���� ���ȴ�.
	for (auto& number : fibonacci)
		number = 10;

	// ������ �ٲٰ� ���� �ʴٸ� ������ ����� �̿��Ѵ�.
	for (const auto& number : fibonacci)
		cout << number;
		// ��� �迭���ٴ� �� ����� ���� �̿��Ѵ�.

	// ���� �Ҵ� �迭���� for each�� ����� �� ����.
	// vector���� ����� �� �ִ�.
}