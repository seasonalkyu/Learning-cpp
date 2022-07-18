#include <iostream>
using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

}
/*
* 다중 상속: 다중 클래스로부터 상속을 받는다
* 상속받을 클래스의 생성자를 각각 만들어주어야한다
* 
* 상속받은 클래스들에 이름이 같은 클래스가 있다면 다음처엄 이용한다
* my_device.USBDevice::getID();
* 
* 다이아몬드 상속은 피해야한다
*/