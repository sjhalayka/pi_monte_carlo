#include <iostream>
#include <complex>
#include <random>
#include <ctime>
using namespace std;

int main(void)
{
	mt19937 generator(static_cast<long unsigned int>(time(0)));
	uniform_real_distribution<float> distribution(0, 1);

	const size_t total = 10000000;
	size_t within_radius = 0;

	for (size_t i = 0; i < total; i++)
	{
		complex<float> c(distribution(generator), distribution(generator));

		if (abs(c) < 1)
			within_radius++;
	}

	cout << 4 * float(within_radius) / float(total) << endl;

	return 0;
}