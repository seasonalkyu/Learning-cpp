#include "Calc.h"
using namespace std;


int main()
{
	// �Ϲ����� ���
	//Calc cal(10);
	//cal.sub(1);
	//cal.mult(2);
	//cal.print();
	// ���� ȣ�� Chaining member function
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();
	Calc(20).add(10).sub(1).mult(2).print();


}

// ����ȣ���� C++������ �ǿ뼺�� �ָ��ϴ�