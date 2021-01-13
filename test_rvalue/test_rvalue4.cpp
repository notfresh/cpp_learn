//
// Created by zxzx on 2020/12/27.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename  T>
void process_value(T& i) {
    std::cout << "LValue processed: " << i << std::endl;
}

//template <typename T>
//void forward_value(const T& val) {
//    process_value(val);
//}

template <typename T>
void forward_value(T&& val) { // 合法！
    process_value(val);
}

void print(int &&i){
    cout << "left value " << endl;
    cout << i << endl;
}

//void print(int &&i){
//    cout << "right value " << endl;
//    cout << i << endl;
//}

int main() {
    int a = 0;
//    const int &b = 1;
//    forward_value(a); // int&
//    forward_value(b); // const int&
//    forward_value(2); // int&

//    print(a);
    forward_value(a); // int&
    forward_value('1'); // int&
}

