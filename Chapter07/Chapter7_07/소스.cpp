#include <iostream>
#include <string>

using namespace std;

void print(unsigned int value) {}
void print(float value) {}


int main()
{
	//print('a'); // ambiguous
	//print(0); // ambiguous
	//print(3.14159); // ambiguous
	
	print((unsigned int)'a');
	print(0u);
	print(3.14156f);
	return 0;
}

