#include <iostream>

#define NUM_STUDENTS 10000

using namespace std;

void doSomething(int scores[20])
{
	cout << scores[0] << endl;
}

int main()
{
	// ���� �迭 �̿�. runtime�� ũ�Ⱑ ������ �� ����.
	int students_scores1[NUM_STUDENTS];
	// c��Ÿ�� ����̴�. �������� �ʴ� �ڵ� ���
	// ���� ����ó�� ����� �̿��Ѵ�.
	const int num_students = 20;
	int students_scores2[num_students];
	doSomething(students_scores2);
	// �迭�� ���ڷ� �Ѱ��� �� �ִ�.

}