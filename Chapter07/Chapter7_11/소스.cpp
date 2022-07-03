#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> v{ 1, 2, 3 };
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl << endl;

	v.resize(10);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl << endl;


	v.resize(2);
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl << endl;
	//cout << v[2] << endl;
		// error
	//cout << v.at(2) << endl;
		// error

	int* ptr = v.data();
	cout << ptr[2] << endl << endl;
	//	3 출력

	std::vector<int> v2{ 1, 2, 3 };
	v2.reserve(1024);
	// capacity를 늘린다
	// reserve를 해두면 실행하는 속도의 차이가 크다
	for (auto& e : v2)
		cout << e << " ";
	cout << endl;
	cout << v2.size() << " " << v2.capacity() << endl << endl;

	return 0;
}