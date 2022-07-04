#include <iostream>
using namespace std;

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "Constructor " << endl;
	}

	int size() { return m_length;  }

	~IntArray()
	{
		if(m_arr != nullptr)
			delete[] m_arr;
	}
	// ������ �ν��Ͻ��� ������ ����� �Ҹ�� �� �ڵ����� ����ȴ�
};

int main()
{
	while (true)
	{
		IntArray my_int_arr(10000);
		//delete[] my_int_arr.m_arr;
			// ���α׷��Ӱ� ���� �� ����
			// ���� ���� �� �ִ���� �Ź� ������� ���ŷο� ���̴�
			// �̷� �� �Ҹ��ڸ� �̿��Ѵ�
	}


	return 0;
}

/*
* ���� ��Ȳ������ memory leak�� �߻��Ѵ�
* �Ҹ��ڸ� �̿��ؼ� �ذ��� �� �ִ�
* �׷��� �׳� vector�� �̷��� ��Ŀ������ �����Ǿ� �����Ƿ� vector�� �̿��ϸ� �ذ�ȴ�
*/