#include <iostream>
#include <thread>
#include <map>
using namespace std;

void f1(){
    cout << "f1" << endl;
}
void f2(int x){
    cout << "f2" << "," << x << endl;
}


int main() {
    cout << "Hello, World!" << endl;
    thread t1(f1);
    thread  t2(f2,10);
    t2.join();
    t1.join();

    cout << "Hello, World! over" << endl;

    return 0;
}



