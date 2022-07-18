class Base
{
public:

};

/*
* 컴파일러 내부적으로 virtual function이 선언되면 정적 바인딩을 하는 것이 아니라
* 동적 바인딩의 표를 반들어서 동적 바인딩을 한다
* 
* virtual function을 실행시키면 virtual function table을 먼저 찾는다
* 테이블에서 적절한 함수 포인터를 찾으면 가리키고 있는 함수를 찾아간다
*/