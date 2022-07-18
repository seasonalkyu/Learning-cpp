#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main()
{
	using namespace std;

	//// Composition Relationship

	//Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof. Hong"));
	//lec1.registerStudent(Student("JJ", 0));
	//lec1.registerStudent(Student("DD", 1));
	//lec1.registerStudent(Student("VV", 2));

	//Lecture lec2("Introduction to Computer Programming");
	//lec2.assignTeacher(Teacher("Prof. GOO"));
	//lec2.registerStudent(Student("JJ", 0));
	//lec2.registerStudent(Student("DD", 1));


	// TODO: implement Aggregation Relationship
	Student std1("JJ", 0);
	// Student *std1 = new Student("JJ",0);
	Student std2("DD", 1);
	Student std3("Violet", 2);

	Teacher teacher1("Prof. H");
	Teacher teacher2("Prof. G");


	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);

	Lecture lec2("Introduction to Computer Programming");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1);
	lec2.registerStudent(&std2);
	// test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		//event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	return 0;
}




// 구성(composition) 관계에서는 lec1에서 수정하더라도 lec2에서 lec1과 중복되는 학생의 변화가 없다
// lrvh
// 
// aggregation 관계에서는 lec1의 std1 정보가 수정되면 lec2 의 std1 정보도 수정된다.
// aggregation 관계를 구현하기 위해 lec1과 lec2는 Student의 주소를 저장 하도록 함

// std1, std2, std3, teacher1, teacher2는 main 함수의 local variable이므로 실행이 끝나면 사라진다
// 만약 다른 곳에서도 써야한다면 동적 할당으로 구현한다

// 분산 처리할 때는 메모리를 공유하지 않기 때문에 affegation 관계로 구현할 수 없다