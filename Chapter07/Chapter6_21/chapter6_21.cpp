#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> array;
		// std::array<int, 5> array; �� �ٸ��� ����� �ݵ�� ���� �ʾƵ� �ȴ�
	std::vector<int> array2 = { 1, 2, 3, 4, 5 };
	cout << array2.size() << endl;

	std::vector<int> array3 = { 1, 2, 3, };
	cout << array3.size() << endl;

	std::vector<int> array4 { 1, 2, 3, };
	cout << array4.size() << endl;

	for (auto& itr : array2)
		cout << itr << " ";
	cout << endl;

	cout << array2[1] << endl;
	cout << array2.at(1) << endl;
	array2.resize(10);

	// int *my_arr = new int[5]; 
	// delete[] my_arr;
	// ���� �迭�� delete�� �����������
	// vector�� delete�� �� �ʿ䰡 ����
}