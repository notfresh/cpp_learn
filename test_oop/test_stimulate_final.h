//
// Created by zxzx on 2020/12/18.
//

#ifndef CPP_LEARN_TEST_STIMULATE_FINAL_H
#define CPP_LEARN_TEST_STIMULATE_FINAL_H

// 模拟实现一个无法继承的类
template <typename T>
class Parent{
    friend T;
private:
    Parent(){};
    Parent(Parent &){};

};
class MyFinal: public virtual Parent<MyFinal>{
public:
    MyFinal(){}
    MyFinal(MyFinal &copy){}
};

class Grandson: public MyFinal{
};
void test_my_final(){
    MyFinal f;
    Grandson s;
}

#endif //CPP_LEARN_TEST_STIMULATE_FINAL_H
