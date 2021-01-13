//
// Created by zxzx on 2020/12/30.
//

class A{
    int a;

private:
    ~A(){}
};

int main(){
    A *a = new A(); // 通过
    // A a;// 编译失败！！
}

