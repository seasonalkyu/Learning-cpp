#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Friend
{
public: // access specifier ���� ������ (public, private, protected)
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

	// ���� �̸� �۸����
	// m_name �Ǵ� _name �Ǵ� name_
};




int main()
{
	vector<Friend> my_friends;
	my_friends.resize(2);

	for (auto& ele : my_friends)
		ele.print();
		// �Ʒ�ó�� �ڵ��ϴ� �ͺ��� �ξ� ����ϴ�
		//my_friends[0].print();
		//my_friends[1].print();
		// ����ϰ� �ڵ��ϸ� �Ǽ��� �پ���

}