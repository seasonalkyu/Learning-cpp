#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:

	//void setItem(int index, int value)
	//{
	//	m_list[index] = value;
	//}

	//int getItem(int index)
	//{
	//	return m_list[index];
	//}

	//int* getList()
	//{
	//	return m_list;
	//}

	int & operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

};

int main()
{
	IntList* list = new IntList;
	//list[3]
		// �ǵ����� ���� ���
	(*list)[3] = 10;
		// �������� ���

	return 0;
}

// �����͸� �̿��� �� �Ǽ��� �����Ѵ�