#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count)
	{
		std::string argv_single = argv[count];

		if (count == 1)
		{
			int input_number = std::stoi(argv_single);
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;
	}
	return 0;
}

// main 의 괄호 안에 매개변수를 넣는 법

// vs의 터미널보다는 native tool 2022를 이용한다
// 또는 프로젝트에 오른쪽 마우스 -> 속성 - 디버깅 - 명령인수에 입력
// boost library를 이용하면 편하다