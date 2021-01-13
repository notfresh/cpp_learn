//
// Created by zxzx on 2020/12/31.
//

#include <iostream>
#include <memory>
using namespace std;

class B;
class A
{
public:// 为了省去一些步骤这里 数据成员也声明为public
    shared_ptr<B> pb;

    ~A()
    {
        cout << "kill A\n";
    }
};

class B
{
public:
    shared_ptr<A> pa;
    ~B()
    {
        cout <<"kill B\n";
    }
};

int main(int argc, char** argv)
{
    shared_ptr<A> sa(new A());
    shared_ptr<B> sb(new B());
    if(sa && sb)
    {
        sa->pb=sb;
        sb->pa=sa;
    }
    cout<<"sa use count:"<<sa.use_count()<<endl;
    cout<<"sa use count:"<<sb.use_count()<<endl;
    return 0;
}

