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

// main �� ��ȣ �ȿ� �Ű������� �ִ� ��

// vs�� �͹̳κ��ٴ� native tool 2022�� �̿��Ѵ�
// �Ǵ� ������Ʈ�� ������ ���콺 -> �Ӽ� - ����� - ����μ��� �Է�
// boost library�� �̿��ϸ� ���ϴ�