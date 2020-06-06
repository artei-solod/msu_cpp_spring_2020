#include <iostream>
#include <fstream>
#include <algorithm>  
#include <thread>
#include <mutex>
#include <chrono>

#pragma warning (disable : 4996)
class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
public:
	Timer()
		: start_(clock_t::now())
	{
	}

	~Timer()
	{
		const auto finish = clock_t::now();
		const auto us =
			std::chrono::duration_cast<microseconds>
			(finish - start_).count();
		std::cout << us << " us" << std::endl;
	}

private:
	const clock_t::time_point start_;
};
void separation(const char* , uint64_t );
void merge(const char* , uint64_t );
bool simpleMergeSort(const char*);