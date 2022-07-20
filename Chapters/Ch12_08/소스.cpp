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
	// virtual Ű���带 �̿��ϸ� �������� �ȴ�.
	// ���� ����� �ϸ� �Ҿƹ��� Ŭ������ �����ڴ� ���� Ŭ�������� ȣ��ȴ�
	// �θ��� �θ�� �ڽŵ��� �θ��� �Ҿƹ��� �����ڸ� ȣ������ �ʵ��� ó���� ��
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
			// PoweredDevice�� �����ڵ� ȣ���Ѵ�
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

		powered device�� �����ڰ� �ѹ��� ȣ��ȴ�
	*/
}

