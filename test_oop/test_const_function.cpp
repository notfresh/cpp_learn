//
// Created by zxzx on 2021/1/1.
//
#include <iostream>
class A{
public:
    int size() const{
        return 1;
    }
    int size(){
        return 2;
    }
};

int main(){
    A a;
    std::cout << a.size();
}