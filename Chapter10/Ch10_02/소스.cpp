#include "Monster.h"
using namespace std;

int main()
{
	Monster mon1("Sanson", Position2D(0, 0));

	cout << mon1 << endl;
	//while (1) // game loop
	{
		// event
		mon1.moveTo(Position2D(1,1));
		cout << mon1 << endl;
	}
	return 0;
}

// 중복인 코드를 두지 않는 이유는 변경이 생겼을 때 모두 찾아서 바꾸는 것이 어렵기 때문이다
// 출력에 endl이 붙는 것은 클래스에는 두지 않고 main에서만 하는 것이 일반적이다

// mon1의 m_location은 m_name을 포함한 다른 정보를 알 필요가 없다
// 따라서 Monster 와 Position2D는 구성관계이다(composition 관계)

// Position2D는 Monster의 subclass이다
// Monster 클래스의 moveTo 메소드에 있는 
// m_location.set() 메소드의 내부는 Monster 클래스가 모르는 것이 좋다.

// 중요한 점: 구성 관계에서 부품인 클래스는 다른 클래스에도 속할 수 있는가?
// 부품인 클래스는 다른 클래스에서 재활용할 수 있지만, Monster의 m_location 멤버는
// 다른 클래스와 전혀 관련이 없다. 이러한 점을 잘 구분해야한다