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

// �ߺ��� �ڵ带 ���� �ʴ� ������ ������ ������ �� ��� ã�Ƽ� �ٲٴ� ���� ��Ʊ� �����̴�
// ��¿� endl�� �ٴ� ���� Ŭ�������� ���� �ʰ� main������ �ϴ� ���� �Ϲ����̴�

// mon1�� m_location�� m_name�� ������ �ٸ� ������ �� �ʿ䰡 ����
// ���� Monster �� Position2D�� ���������̴�(composition ����)

// Position2D�� Monster�� subclass�̴�
// Monster Ŭ������ moveTo �޼ҵ忡 �ִ� 
// m_location.set() �޼ҵ��� ���δ� Monster Ŭ������ �𸣴� ���� ����.

// �߿��� ��: ���� ���迡�� ��ǰ�� Ŭ������ �ٸ� Ŭ�������� ���� �� �ִ°�?
// ��ǰ�� Ŭ������ �ٸ� Ŭ�������� ��Ȱ���� �� ������, Monster�� m_location �����
// �ٸ� Ŭ������ ���� ������ ����. �̷��� ���� �� �����ؾ��Ѵ�