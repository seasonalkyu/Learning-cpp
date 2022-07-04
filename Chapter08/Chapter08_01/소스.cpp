#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Friend
{
public: // access specifier 접근 지정자 (public, private, protected)
	string m_name;
	string address;
	int age;
	double height;
	double weight;
	void print()
	{
		cout << m_name << " " << address << " " << age <<
			" " << height << " " << weight << endl;
	}

	// 변수 이름 작명법은
	// m_name 또는 _name 또는 name_
};




int main()
{
	vector<Friend> my_friends;
	my_friends.resize(2);

	for (auto& ele : my_friends)
		ele.print();
		// 아래처럼 코딩하는 것보다 훨씬 깔끔하다
		//my_friends[0].print();
		//my_friends[1].print();
		// 깔끔하게 코딩하면 실수가 줄어든다

}