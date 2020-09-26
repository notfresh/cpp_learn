#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int number = 0;
mutex locker;

void f1(string name, int tell){
    while (true) {
        locker.lock();
        if (number > 9) {
            locker.unlock();
            break;
        }
        if (number % 2 == tell) {
            cout << name << ":" << number << endl;
            number++;
        }
        locker.unlock();
    }
}

int main() {
    cout << "Hello, World!" << endl;
    thread t1(f1, "thread1", 1);
    thread t2(f1, "thread2", 0);
    t1.join();
    t2.join();
    cout << "Hello, World! over" << endl;

    return 0;
}



