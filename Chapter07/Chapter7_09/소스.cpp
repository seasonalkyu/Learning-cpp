#include <iostream>
#include <array>
#include <functional>
using namespace std;

/*
void printNumbers(const array<int, 10>& my_array, bool print_even) 
{
	for (auto element : my_array)
	{
		if (print_even && element % 2 == 0) cout << element;
		if(!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}
*/
// �� �Լ��� �Լ� �����͸� �̿��ؼ� ����

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 != 0) return true;
	else return false;
}


//typedef bool(*check_fcn_t)(const int&);
	// ��� 1
using check_fcn_t = bool(*)(const int&);
	// ��� 2

void printNumbers(const array<int, 10>& my_array, bool (*check_fcn)(const int&) = isEven ) 
//void printNumbers(const array<int, 10>& my_array, check_fcn_t check_fcn = isEven ) 
//void printNumbers(const array<int, 10>& my_array, std::functional<bool<const int&)> check_fcn = isEven ) 
// �⺻���� ���� �� �ִ�
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true) cout << element;
	}
	cout << endl;
}

int main()
{
	std::array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	std::function<bool(const int&)> fcnptr = isEven;
	// ��� 3


	printNumbers(my_array);
	printNumbers(my_array, isOdd);
	//printNumbers(my_array, fcnptr);
	// fcnptr = isOdd;
	//printNumbers(my_array, fcnptr);
	

	return 0;
}



