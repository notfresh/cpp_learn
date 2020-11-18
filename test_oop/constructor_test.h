//
// Created by zxzx on 2020/11/14.
//

#ifndef ZZZ_CONSTRUCTOR_TEST_H
#define ZZZ_CONSTRUCTOR_TEST_H
class Person{
public:
    Person():age(10){}
    Person(int age1):age(age1){}
private:
    int age;
};

void test_constructor(){
    Person p1(10);
//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
//Person p2();

//2.2 显式法
    Person p2 = Person(10);
    Person p3 = Person(p2);
//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

//2.3 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);


Person p6(p4);
//Person p7();
}



#endif //ZZZ_CONSTRUCTOR_TEST_H
