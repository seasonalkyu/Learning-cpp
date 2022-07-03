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
        // reference 변수 선언 방법

    // int &c_ref = c_value;
        // error가 난다.
    const int& c_ref = c_value;
        // ok

    ref = 10;
        // *ptr = 10;

    cout << ref << endl;
        // 1 출력

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
        // 모두 같은 주소를 출력한다.
    func(value);
        // 마찬가지로 같은 주소를 출력한다.
}