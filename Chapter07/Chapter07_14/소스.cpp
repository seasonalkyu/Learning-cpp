#include <iostream>
#include <cassert>
#include <array>

using namespace std;


int main()
{
	const int x = 10;

	assert(x == 5);

	static_assert(x == 5, "x should be 5");
}