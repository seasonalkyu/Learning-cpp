#include <iostream>
#include <vector>
#include <algorithm> // 시간을 잴 대상은 sort 알고리즘
#include <random> // random number 생성
#include <chrono> // 시간을 잴 때 사용하는 라이브러리

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	// Timer 인스턴스가 만들어지는 순간에 now() 해서 시각을 기록
	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		// elapsed()를 실행한 시각을 기록
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		// 인스턴스가 만들어진 시각과 elapsed()가 실행된 시각의 차를 초로 변환하여 출력
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };


	// 숫자 10개를 초기화
	vector<int> vec(10000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	// 초기화한 숫자를 random하게 섞어줌
	std::shuffle(begin(vec), end(vec), mersenne_engine);

	// 섞인 숫자를 출력
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	// 시간을 재기 시작함
	Timer timer;

	std::sort(begin(vec), end(vec));

	// 지나간 시간을 출력
	timer.elapsed();

	// 정렬된 숫자를 출력
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	return 0;
}

// debug 모드와 release 모드에서 실행시간이 많이 차이가 난다.
// 실제 배포 실행 시간을 잰다면 release모드에서 재야한다.
// 시간은 여러 번 재야 한다.