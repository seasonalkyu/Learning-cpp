#include <iostream>
#include <vector>
#include <algorithm> // �ð��� �� ����� sort �˰���
#include <random> // random number ����
#include <chrono> // �ð��� �� �� ����ϴ� ���̺귯��

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	// Timer �ν��Ͻ��� ��������� ������ now() �ؼ� �ð��� ���
	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		// elapsed()�� ������ �ð��� ���
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		// �ν��Ͻ��� ������� �ð��� elapsed()�� ����� �ð��� ���� �ʷ� ��ȯ�Ͽ� ���
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };


	// ���� 10���� �ʱ�ȭ
	vector<int> vec(10000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	// �ʱ�ȭ�� ���ڸ� random�ϰ� ������
	std::shuffle(begin(vec), end(vec), mersenne_engine);

	// ���� ���ڸ� ���
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	// �ð��� ��� ������
	Timer timer;

	std::sort(begin(vec), end(vec));

	// ������ �ð��� ���
	timer.elapsed();

	// ���ĵ� ���ڸ� ���
	for (auto& e : vec) cout << e << " ";
	cout << endl;

	return 0;
}

// debug ���� release ��忡�� ����ð��� ���� ���̰� ����.
// ���� ���� ���� �ð��� ��ٸ� release��忡�� ����Ѵ�.
// �ð��� ���� �� ��� �Ѵ�.