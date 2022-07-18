#include <iostream>
using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator () (int i) { return (m_counter += i); }
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

	return 0;
}

// 위와 같이 함수처럼 이용되는 것을 functer 라고 한다