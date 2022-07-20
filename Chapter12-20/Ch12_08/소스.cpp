#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice: " << power << '\n';
	}
};

class Scanner : virtual public PoweredDevice
	// virtual 키워드를 이용하면 가상상속이 된다.
	// 가상 상속을 하면 할아버지 클래스의 생성자는 손자 클래스에서 호출된다
	// 두명의 부모는 자신들의 부모인 할아버지 생성자를 호출하지 않도록 처리가 됨
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << '\n';
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power),
		PoweredDevice(power)
			// PoweredDevice의 생성자도 호출한다
	{
	}
};

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	/*
	* 
		PoweredDevice: 3
		Scanner: 1
		Printer: 2
		0000003ED77DF668
		0000003ED77DF668

		powered device의 생성자가 한번만 호출된다
	*/
}

