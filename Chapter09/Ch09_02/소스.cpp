#include <iostream>
using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	// friend 전역 함수
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z ;

		return out;
	}
};

int main()
{
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	cout << p1 << " " << p2 << endl;

	return 0;
}


// 첫 번째 파라미터가 ostream이므로 멤버 function으로 만들 수가 없다
// pt 객체가 Point 클래스 타입이라고 가정했을 때, pt + 3을 하려면 Point 안에 + 연산자 오버로딩 정의가 있어야한다.
// 즉, Poin의 멤버함수로서 + 연산자 오버로딩 정의가 있어야한다.

// 그런데 입출력 연산자 <<의 왼쪽 피연산자는 ostream클래스의 cout 객체이다.
// 따라서 <<를 멤버함수로서 오버로딩하려면 ostream클래스에서 멤버함수를 정의해야하지만
// ostream은 C++ 표준 클래스이므로 수정할 수 없다.