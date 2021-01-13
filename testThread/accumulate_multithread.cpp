//
// Created by zxzx on 2021/1/9.
//

#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

// @并行求和 @accumulate
template<typename Iterator, typename T>
struct accumulate_block {
	void operator()(Iterator first, Iterator last, T &result) {
		result = std::accumulate(first, last, result);
	}
};


template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
	long const length = std::distance(first, last);
	if (!length)
		return init;

	long const min_per_thread = 25;
	long const max_threads =
			(length + min_per_thread - 1) / min_per_thread;

	long const hardware_threads =
			std::thread::hardware_concurrency();

	long const num_threads =
			std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

	long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);

	Iterator block_start = first;
	for (long i = 0; i < (num_threads - 1); ++i) {  // @难点，这段循环
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread( //启动很多个线程
				accumulate_block<Iterator, T>(), // @难点1：生成线程，去执行
				block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}
	accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);
	std::for_each(threads.begin(), threads.end(),
				  std::mem_fn(&std::thread::join)); // mem_fn member function,调用每个对象的member function
	return std::accumulate(results.begin(), results.end(), init);
}


void test_parallel_accumte(){
	std::vector<int> vi;
	for (int i = 0; i < 1000000; ++i) {
		vi.push_back(i);
	}
	int sum = parallel_accumulate(vi.begin(), vi.end(), 0);
	std::cout << "sum=" << sum << std::endl;
}

void test_common_accumte(){
	std::vector<int> vi;
	for (long i = 0; i < 1000000; ++i) {
		vi.push_back(i);
	}
	long sum = std::accumulate(vi.begin(), vi.end(), 0);
	std::cout << "sum=" << sum << std::endl;
}

#include "zxlib/time_wrap.h"

int main() {
	time_wrap(test_parallel_accumte);
	time_wrap(test_common_accumte);
}
