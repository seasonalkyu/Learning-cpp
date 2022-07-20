#include <iostream>
#include <string>
using namespace std;

class IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);
}

/*
* 인터페이스 클래스: 내부의 함수가 모두 pure virtual function
* 
* 위의 예시에서 IErrorLog를 상속한 FileErrorLog와 ConsoleErrorLog에서
* 자동으로 생성된 디폴트 소멸자로 오버라이딩하고 있다
* 
* IErrorLog 클래스를 인자로 받으면 reportError가 있음을 
* 알고 있으므로 doSomething메소드처럼 구현할 수 있다 
*/
