#include <iostream>
#include <array>
using namespace std;

int main() 
{
	// std::array�� ���� �迭�� ��ü�� �� �ִ�.
	// std::array ����� �ʱ�ȭ
	std::array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
	my_arr = { 0, 1, 2, 3, 4 };
	my_arr = { 0, 1, 2, }; // ������ �� ���� 0���� ä���ش�.
		// �� ��, my_arr �� {0, 1, 2, 0, 0}���� �ʱ�ȭ�Ǿ� �ִ�.
	for (auto element : my_arr)
		cout << element << " ";
	cout << endl;

	// std::array ���� ����� ���
	cout << my_arr[0] << endl; // ok
	cout << my_arr.at(0) << endl; // ok

	cout << my_arr[10];   // ������ �ִ��� Ȯ������ �ʰ� �ٷ� �׼���
	cout << my_arr.at(10);// ������ �ִ��� Ȯ���ϰ� �׼���

	// element�� �� ������ �����ش�.
	my_arr.size();
	// �Ķ���ͷδ� ����ó�� �Ѱ��ش�.
	void printLength(array<int, 5> my_arr) { .., };
	// �� ����� array�� ����Ǵ� �����̹Ƿ� array�� ũ�ٸ� ����ϴ�.
	void printLength(array<int, 5>& my_arr); // 
	void printLength(const array<int, 5>& my_arr); // ������ array�� ������ �ʱ� �ٶ� ��
}