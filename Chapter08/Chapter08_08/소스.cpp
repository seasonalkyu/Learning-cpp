#include "Calc.h"
using namespace std;


int main()
{
	// 일반적인 경우
	//Calc cal(10);
	//cal.sub(1);
	//cal.mult(2);
	//cal.print();
	// 연쇄 호출 Chaining member function
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();
	Calc(20).add(10).sub(1).mult(2).print();


}

// 연쇄호출은 C++에서는 실용성은 애매하다