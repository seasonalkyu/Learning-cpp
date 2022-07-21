#include <iostream>
#include "Storage.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
		return (x > y) ? x : y;
}

// specialization
// char Ÿ������ instantiation�� ���� �����Ѵ�.
// ��, argument�� char�� ���� ����ǵ��� ��
// �̷� ����� ���� ������ ������ Ÿ�ӿ� �̷������ϹǷ� if���� ����� �� ���� ����
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	// case 1
	//cout << getMax<int>(1, 2) << endl;
	cout << getMax(1, 2) << endl;
		// instantiation�� �ڵ����� ���ش�
		// ���������δ� getMax<int>(1,2)�� ����
	cout << getMax(1.0, 2.0) << endl;
		// ���������δ� cout << getMax<double>(1.0, 2.0) << endl;
	cout << getMax<double>(1, 2) << endl;

	// case 2
	cout << getMax('a', 'b') << endl;

	// case 3
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}

/*
* ������ Ÿ�ӿ� �̷������ϹǷ� if���� ����� �� ����
* ���� specialization�� ����Ѵ�
* specialization : �Ϲ�ȭ �� ���� Ư���� �Ϳ��� ����
* 
* Ư��ȭ�� �и��ϱ⺸�ٴ� ������Ͽ� �δ� ���� ����
*/