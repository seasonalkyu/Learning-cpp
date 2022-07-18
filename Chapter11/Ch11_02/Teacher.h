#pragma once
#include "Person.h"

class Teacher : public Person
{
private:

public:
	Teacher(const std::string& name_in = "No Name", const int& intel_in = 0)
		: Person(name_in)
		// �θ��� ������ ȣ��
	{}

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Teacher & teacher)
	{
		out << teacher.getName();
			// const Teacher & teacher �̹Ƿ� getName() �Լ��� const�� ����Ǿ���Ѵ�
		return out;
	}
};