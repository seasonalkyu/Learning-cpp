#include <iostream>

using namespace std;

void func(int& value)
{
    cout << &value << endl;
    value = 1000;
}

int main()
{
    int value = 1;
    const int c_value = 9;
    int* ptr = &value;
    int& ref = value;
        // reference ���� ���� ���

    // int &c_ref = c_value;
        // error�� ����.
    const int& c_ref = c_value;
        // ok

    ref = 10;
        // *ptr = 10;

    cout << ref << endl;
        // 1 ���

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
        // ��� ���� �ּҸ� ����Ѵ�.
    func(value);
        // ���������� ���� �ּҸ� ����Ѵ�.
}