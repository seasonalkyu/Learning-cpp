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
	// 생성된 인스턴스가 영역을 벗어나서 소멸될 때 자동으로 실행된다
};

int main()
{
	while (true)
	{
		IntArray my_int_arr(10000);
		//delete[] my_int_arr.m_arr;
			// 프로그래머가 지울 수 없다
			// 또한 지울 수 있더라고 매번 지우려면 번거로울 것이다
			// 이럴 때 소멸자를 이용한다
	}


	return 0;
}

/*
* 위의 상황에서는 memory leak이 발생한다
* 소멸자를 이용해서 해결할 수 있다
* 그런데 그냥 vector는 이러한 메커니즘이 구현되어 있으므로 vector를 이용하면 해결된다
*/