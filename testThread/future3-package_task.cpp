#include <zxlib/using_std.h>

int f1(){
	return 1;
}


void f2(){
	packaged_task<int()> task(f1);
	future<int> fu = task.get_future();
	thread t(move(task));
	t.join();
	print(fu.get());
}

int main() {
	f2();
}