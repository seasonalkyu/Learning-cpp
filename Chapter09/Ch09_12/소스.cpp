#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	// ���̰� �־����� �� �޸𸮸� �Ҵ��ϴ� ����� �ϵ��� ��
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	// initializer_list�� �����ڸ� ȣ���ϱ�
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size())
			// ���̸� �޾ƿ��� ����� ���� �����ڸ� �̿��ߴ�.
			// �ߺ��Ǵ� ����� �ϳ��� �ڵ常 �̿��ϴ� ���� ���� ����
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		// for (unsigned count = 0; cout <list.size(); ++count)
		//m_data[count] = list[count]; // error
			// for-each���� �̿��ؾ��Ѵ�
			// initializer list�� ���ȣ operator�� �������� �ʱ� ����
			// for-each���� ���������� initializer�� iterator�� ����ϴ� ����
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	// To-do
	// ���Կ����� �����ε��ϱ�

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};


int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int my_arr2[5] { 1,2,3,4,5 };
		// { 1,2, 3, 4, 5} �� initializer list
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };
	
	auto il = { 10,20,30 };
		// initializer_list�� include �ϸ� �������� {10,20,30}�� initializer_list���� �˾Ƽ� ã�Ƽ�
		// �ʱ�ȭ�Ѵ�

	IntArray int_array { 1,2,3,4,5 };
		// ���� ������ �ڷ����� initializer list�� �̿��ϸ� �۵����� �ʴ´�
	cout << int_array << endl;

	return 0;
}

// initializer_list �� �̿��ؼ� �����ڸ� ������ ����
// ���� �����ڸ� �����ε��ϴ� ���� ����