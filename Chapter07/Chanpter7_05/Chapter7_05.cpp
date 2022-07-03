#include <iostream>
#include <array>

using namespace std;

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

int main()
{
	std::array<int, 100> my_array;
	my_array[30] = 10;

	get(my_array, 30) = 1024;

	cout << my_array[30] << endl;

	return 0;
}