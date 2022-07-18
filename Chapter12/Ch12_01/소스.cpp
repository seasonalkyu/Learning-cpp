#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const
	//void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak();
		// dog class이지만 부모클래스인 Animal로 인식하고 작동

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3") };
	Dog dogs[] = { Dog("dog1"), Dog("Dog2") };

	for (int i = 0; i < 3; ++i)
		cats[i].speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	Animal* my_animals[] = { &cats[0], &cats[1], &cats[3], &dogs[0], &dogs[1] };
	for (int i = 0; i < 5; ++i)
		my_animals[i]->speak();


	return 0;
}


/*
* 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?
* => 다형성과 관련된 질문
* 
* 부모의 함수에 virtual 키워드를 넣으면 부모 클래스의 포인터를 이용해서 자식 클래스를 가리키더라도
* 부모 클래스의 함수가 아닌 자식 클래스의 오버로딩된 함수를 이용한다.
* 이러한 성질을 다형성이라고 한다
*/