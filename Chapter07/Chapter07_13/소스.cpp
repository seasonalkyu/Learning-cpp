#include <iostream>
#include <string>

using namespace std;

int main()
{
	// syntax error
	
	// symentic errors �� ����
	// �� �ǵ��ʹ� �ٸ� ����� �ڵ��� ��
	int x;
	cin >> x;

	if (x >= 5)
		cout << "x is greater than 5" << endl;


	// violated assumption
	// ����ڰ� �� �ǵ��� �ٸ� ������� �̿���
	string hello = "Hello, my name is Jack";

	cout << "Input from 0 to " << hello.size() - 1 << endl;
	
	while (true)
	{
		int ix;
		cin >> ix;

		if (ix >= 0 && ix <= hello.size() - 1)
			cout << hello[ix] << endl;
		else
			cout << "Please try again" << endl;

	}
	return 0;
}

// ����� ���α׷���
// ������ �����Ϸ��� ��Ƴ� �� �ִ� �ڵ��� �ǵ������� �ؾ��Ѵ�
