//
// Created by zxzx on 2020/8/30.
//

class A{
public:
    int a;
    A operator+(const A & a2){
        A a3;
        a3.a = this->a + a2.a;
        return a3;
    }
};