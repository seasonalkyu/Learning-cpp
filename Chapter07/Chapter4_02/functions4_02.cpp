#include <iostream>
#include "my_constants4_02.h"

extern int a;

void doSomething()
{
	using namespace std;

	cout << "In functions.cpp " << constants4_02::pi << " " << & constants4_02::pi << endl;
}