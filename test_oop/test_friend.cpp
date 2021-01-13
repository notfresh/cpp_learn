//
// Created by zxzx on 2020/12/30.
//

template <typename T>
class Parent{
    friend T;
private:
    Parent(){}; // 核心原理是, 友元可以调用类的私有方法,友元方法和you元类都可以.
};

// 这里说明,必须是 virtual, 这里会直接去调用祖先类的构造方法，和爸爸做朋友
// 如果不是virtual的，那么 MyFinal 的子类就会先去调用 MyFinal 的构造方法， 然后 MyFinal 会去调用它的父类的构造方法，
// 因为是父子关系，就可以直接编译通过，从而无法实现不可继承！！
class MyFinal: public virtual Parent<MyFinal>{
public:
    MyFinal(){}
    MyFinal(MyFinal &copy){}
};

class Grandson: public MyFinal{ // 直接去调用祖先的构造方法！！
};



int main(){
    MyFinal f;
    // Grandson s; // 构造函数默认是public的, 编译不通过
}