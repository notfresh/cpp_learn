//
// Created by zxzx on 2021/1/7.
//

#ifndef CPP_LEARN_THREAD_POOL_H
#define CPP_LEARN_THREAD_POOL_H

#include <zxlib/threadsafe_queue.h>
# include "zxlib/print.h"
/**
	2021-01-07 23:58:09，今天我们来实现一个线程池。
	线程池最简单的就是实现方法呢，首先，它肯定是一个容器，保持固定数量的线程，然后这些线程不停的去任务队列里面拿任务
	如果有任务，就执行，如果没有任务了就等待
	以上思路，就是第一版的整体思路了，我们现在来实现它，并且拿它做一件有趣的事情。
 */

/**
 * Listing 9.1 Simple thread pool
 * 原始代码来自 CCIA
 *  */


class join_threads {
	std::vector<std::thread> &threads;
public:
	explicit join_threads(std::vector<std::thread> &threads_) :
			threads(threads_) {}

	~join_threads() { // 当这个对象最后被析构的时候，确保每个thread都被join了! 这个很关键
		for (unsigned long i = 0; i < threads.size(); ++i) {
			if (threads[i].joinable()) // 如果出现了异常
				threads[i].join();
		}
	}
};


class thread_pool
{
	std::atomic_bool done;
	// 难点在于如何保存一个函数，这是一个新特性，我们需要了解
	// void() 就是表示任何类型的函数声明都可以，不局限与某一种
	threadsafe_queue<std::function<void()> > work_queue;
	std::vector<std::thread> threads;
	/**
	 *
	The join_threads instance will ensure that all the threads have completed before the
	pool is destroyed. Note that the order of declaration of the members is important:
	both the done flag and the worker_queue must be declared before the threads vector,
	which must in turn be declared before the joiner. This ensures that the members are
	destroyed in the right order; you can’t destroy the queue safely until all the threads
	have stopped, for example.
	 * */
	join_threads joiner;
	void worker_thread()
	{
		while(!done)
		{
			std::function<void()> task;
			if(work_queue.try_pop(task))
			{
				task();
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}

public:
	thread_pool():
			done(false),joiner(threads)
	{
		unsigned const thread_count=std::thread::hardware_concurrency();
		print("线程数量：");
		print(thread_count);
		try
		{
			for(unsigned i=0;i<thread_count;++i)
			{
				threads.push_back(
						std::thread(&thread_pool::worker_thread,this));
			}
		}
		catch(...) // 如果有异常了， 就终止这个简陋的线程池。
		{
			done=true;
			throw;
		}
	}
	~thread_pool()
	{
		done=true;
	}
	template<typename FunctionType>
	void submit(FunctionType f)
	{
		work_queue.push(std::function<void()>(f)); //@函数指针
	}
};


#endif //CPP_LEARN_THREAD_POOL_H
