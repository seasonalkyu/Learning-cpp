#include <iostream>

using namespace std;

int main()
{
	int length;
	cin >> length;

	int* array = new int[3]{ 1, 2, 3 };
	delete[] array;
		// ���� �迭�� ũ�Ⱑ ������ Ÿ�ӿ��� �����Ǳ� ����
		// �迭�� ũ�⸦ �ٲٷ��� �� ���� ����� �ִ�.
		// 1. ���ο� �迭�� ����� element�� �����ؼ� �ٿ��ִ´�.
		// 2. ���� �迭�� �� �κп� �߰��ؼ� ���� �� �ִ��� OS�� ����� ��û�� 
}