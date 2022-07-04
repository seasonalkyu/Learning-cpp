#include <iostream>


class Fruit
{
public:
	enum class FruitType
	{
		APPLE, BANANA, CHERRY,
	};
private:
	FruitType m_type;

public:
	Fruit(FruitType type) : m_type(type)
	{}

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		std::cout << "Apple" << std::endl;
	}
}


// 클래스 안에만 어떤 자료형을 선언할 수 있다
// 여러 클래스가 같이 사용하는 자료형은 클래스 밖에 선언하는 것이 좋지만
// 특정클래스만 사용한다면 클래스 내부에 선언한다