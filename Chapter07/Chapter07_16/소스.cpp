#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...)
{
	double sum = 0;

	va_list list;

	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // list를 int로 변환하는 것임

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;
		// ok but 1이 출력
	cout << findAverage(3, 1, 2, 3) << endl;
		// ok
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
		// ok
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl;
		// 이상한 숫자 출력

}

// 생략부호 Ellipsis
// 사용하기 어렵고 디버깅도 힘들다
