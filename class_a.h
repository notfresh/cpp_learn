//
// Created by zxzx on 2020/9/5.
//

#ifndef CPP_LEARN_CLASS_A_H
#define CPP_LEARN_CLASS_A_H
class A2{
public:
    int a;

    A2(int b):a(b){
    }
    A2(){}

    A2 operator+(const A2 & a2){
        A2 a3;
        a3.a = this->a + a2.a;
        return a3;
    }
    bool operator==(const A2 & a2){
        if (a == a2.a) return true;
        return false;
    }
};
#endif //CPP_LEARN_CLASS_A_H
