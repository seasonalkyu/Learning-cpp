#include <iostream>
#include "my_constants4_02.h"

using namespace std;



void doSomething();

int main()
{
	cout << "In main.cpp file " << constants4_02::pi << " " << &constants4_02::pi << endl;
	doSomething();
	return 0;
}