//
// Created by zxzx on 2021/1/7.
//

#ifndef CPP_LEARN_THREAD_POOL2_H
#define CPP_LEARN_THREAD_POOL2_H

class tpool {
private:

public:
	class tjob {
	public:
		virtual void run() { cout << "tjob" << endl; };
	};
	queue<tjob*> job;//任务列表
	mutex mutex_global,job_mutex;
	condition_variable cv;
	thread *tlist;
	int num_running,n;//任务个数
	//bool if_init;
	tpool(int const &_n):n(_n) {
		//初始化线程池个数
		//if_init = false;
		num_running = 0;
		//job_mutex = new mutex[_n];
		tlist = new thread[_n];
		for (int i = 0; i < _n; i++) {
			tlist[i]=thread([this,i]() {//直接在这里用lambda表达式建立线程

				while (1) {
					unique_lock<mutex> lock(this->job_mutex);
					//while(this->if_init==false)
					this->cv.wait(lock, [this] {
						return !this->job.empty();
					});//等待阻塞线程，直到update中通知状态改变
					if (this->job.size() != 0)
					{
						this->mutex_global.lock();
						tjob* job = this->job.front(); this->job.pop();
						this->mutex_global.unlock();
						lock.unlock();
						this->num_running++;
						job->run();
						this->num_running--;
						cout << i<<"线程运行完毕,当前运行"<<this->num_running<<"/"<<this->n<<"任务，任务队列中还剩余"<<this->job.size()<<"个任务未处理" << endl;

						//this->if_init = false;
					}
					//delete this->job_mutex;
				}
			});

		}
	}
	tpool() {
		int _n = this->core_num();
		this->n = _n;
		//初始化线程池个数
		//if_init = false;
		num_running = 0;
		//job_mutex = new mutex[_n];
		tlist = new thread[_n]; // zx:这是一个数组啊，怎么保证有序的控制线程出入呢？
		for (int i = 0; i < _n; i++) {
			tlist[i] = thread([this, i]() {//直接在这里用lambda表达式建立线程，zx:真够长的啊
				while (1) {
					unique_lock<mutex> lock(this->job_mutex);
					//while(this->if_init==false)
					this->cv.wait(lock, [this] {
						return !this->job.empty();
					});//等待阻塞线程，直到update中通知状态改变
					if (this->job.size() != 0) //zx:解锁之后
					{
						this->mutex_global.lock(); // zx:弹出一个任务
						tjob* job = this->job.front();
						this->job.pop();
						lock.unlock();
						this->num_running++; //zx:这个恐怕也要锁住的
						this->mutex_global.unlock();
						job->run();
						this->mutex_global.lock();
						this->num_running--;
						this->mutex_global.unlock();
						cout << i << "线程运行完毕,当前运行" << this->num_running << "/" << this->n << "任务，任务队列中还剩余" << this->job.size() << "个任务未处理" << endl;

						//this->if_init = false;
					}
					//delete this->job_mutex;
				}
			});

		}
	}

	/**
	 * pool.addTask(*new job2(1000)); 用户入口
	 *
	 * */
	void addTask(tjob& job) {
		//cout << "添加任务" << endl;
		this->job.push(&job); // 任务加到队列里去了
		this->update();
	}

	void update() { // zx:随机唤醒一个线程，因为在这个condition上面阻塞了N个线程啊！！
		//更新线程状态
		this->cv.notify_one();
	}
	unsigned int core_num(){
		return std::thread::hardware_concurrency();
	}

};


#endif //CPP_LEARN_THREAD_POOL2_H
