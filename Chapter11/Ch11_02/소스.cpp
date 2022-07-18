#include "Student.h"
#include "Teacher.h"

int main()
{
	Student std("JJ");
	std.setName("JJ2");
	std.getName();
	std::cout << std.getName() << std::endl;


	Teacher teacher1("prof. H");
	teacher1.setName("prof. K");

	std::cout << teacher1.getName() << std::endl;
	return 0;

	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();

	Person person;
	person.setName("Mr. Incredible");
	person.getName();
	//person.study(); // error
	// person.teach(); // error
}


// Student "is-a" Person, Teacher "is-a" Person 처럼 공통적인 부분을 일반화시킨다