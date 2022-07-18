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




// ����(composition) ���迡���� lec1���� �����ϴ��� lec2���� lec1�� �ߺ��Ǵ� �л��� ��ȭ�� ����
// lrvh
// 
// aggregation ���迡���� lec1�� std1 ������ �����Ǹ� lec2 �� std1 ������ �����ȴ�.
// aggregation ���踦 �����ϱ� ���� lec1�� lec2�� Student�� �ּҸ� ���� �ϵ��� ��

// std1, std2, std3, teacher1, teacher2�� main �Լ��� local variable�̹Ƿ� ������ ������ �������
// ���� �ٸ� �������� ����Ѵٸ� ���� �Ҵ����� �����Ѵ�

// �л� ó���� ���� �޸𸮸� �������� �ʱ� ������ affegation ����� ������ �� ����