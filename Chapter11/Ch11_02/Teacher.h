#pragma once
#include "Person.h"

class Teacher : public Person
{
private:

public:
	Teacher(const std::string& name_in = "No Name", const int& intel_in = 0)
		: Person(name_in)
		// 부모의 생성자 호출
	{}

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Teacher & teacher)
	{
		out << teacher.getName();
			// const Teacher & teacher 이므로 getName() 함수는 const로 선언되어야한다
		return out;
	}
};