#include <iostream>

#define NUM_STUDENTS 10000

using namespace std;

void doSomething(int scores[20])
{
	cout << scores[0] << endl;
}

int main()
{
	// 정적 배열 이용. runtime에 크기가 결정될 수 없다.
	int students_scores1[NUM_STUDENTS];
	// c스타일 방식이다. 권장하지 않는 코딩 방식
	// 차라리 다음처럼 상수를 이용한다.
	const int num_students = 20;
	int students_scores2[num_students];
	doSomething(students_scores2);
	// 배열을 인자로 넘겨줄 수 있다.

}