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
	// 길이가 주어졌을 때 메모리를 할당하는 기능을 하도록 함
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	// initializer_list로 생성자를 호출하기
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size())
			// 길이를 받아오는 기능을 위의 생성자를 이용했다.
			// 중복되는 기능은 하나의 코드만 이용하는 것이 좋기 때문
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		// for (unsigned count = 0; cout <list.size(); ++count)
		//m_data[count] = list[count]; // error
			// for-each문을 이용해야한다
			// initializer list는 대괄호 operator를 제공하지 않기 때문
			// for-each문은 내부적으로 initializer의 iterator를 사용하는 구조
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	// To-do
	// 대입연산자 오버로딩하기

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
		// { 1,2, 3, 4, 5} 가 initializer list
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };
	
	auto il = { 10,20,30 };
		// initializer_list은 include 하면 오른쪽의 {10,20,30}이 initializer_list임을 알아서 찾아서
		// 초기화한다

	IntArray int_array { 1,2,3,4,5 };
		// 직접 정의한 자료형에 initializer list를 이용하면 작동하지 않는다
	cout << int_array << endl;

	return 0;
}

// initializer_list 를 이용해서 생성자를 구현할 때는
// 대입 연산자를 오버로딩하는 것이 좋다