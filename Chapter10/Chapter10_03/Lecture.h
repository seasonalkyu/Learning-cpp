#pragma once
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;

	// composition 관계
	//Teacher teacher;
	//std::vector<Student> students;

	// aggregation 관계
	// pointer 이용
	// 주소를 저장하도록 함
	Teacher * teacher;
	std::vector<Student*> students;
public:
	Lecture(const std::string& name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		//do NOT delete teacher
		// do NOT delete students
	}
	// 
	//void assignTeacher(const Teacher& const teacher_input)
	void assignTeacher(Teacher* const teacher_input)
		// pointer 용으로 수정
	{
		teacher = teacher_input;
	}

	//void assignTeacher(Teacher* const teacher_input)
	//{
	//	teacher = teacher_input;
	//}

	//void registerStudent(const Student& const student_input)
	void registerStudent(Student* const student_input)
		// pointer 용으로 수정
	{
		students.push_back(student_input);
	}

	//void registerStudent(Student* const student_input)
	//{
	//	students.push_back(student_input);
	//}

	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		//for (auto& element : students) // Note : 'auto element' doesn't work
		//	element.setIntel(element.getIntel() + 1);

		for(auto element : students) // auto element도 work 그리고 auto & element도 work
		 (*element).setIntel((*element).getIntel() + 1);
			// pointer 용으로 수정
		
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		//out << lecture.teacher << std::endl;
		//for (auto element : lecture.students)
		//	out << element << std::endl;

		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl;
			// pointer 용으로 수정
		return out;
	}

	
};