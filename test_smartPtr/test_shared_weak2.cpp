#include <iostream>
#include <memory>
using namespace std;

class B;
class A
{
public:// 为了省去一些步骤这里 数据成员也声明为public
    // weak对pb的约束弱一点， weak是弱势的一方
    weak_ptr<B> pb;//不增加引用数量，好像儿子不关系爸爸，但是爸爸关系儿子，双方不对等

    void doSomthing()
    {
        shared_ptr<B> pp = pb.lock();
        if(pp)//通过lock()方法来判断它所管理的资源是否被释放
        {
            cout<<"sb use count:"<<pp.use_count()<<endl;
        }
    }

    ~A()
    {
        cout << "kill A\n";
    }

    void f1(){
        cout << 1111 << endl;
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

    void f2(){
        cout <<"f2 B\n";
    }
};

int main(int argc, char** argv)
{
    shared_ptr<A> sa(new A());
    shared_ptr<B> sb(new B());

    sa->pb=sb;
    sb->pa=sa;
    sa->f1();
    if(auto pp = sa->pb.lock()){
        pp->f2();
    }

    sa->doSomthing();
    cout<<"sb use count:"<<sb.use_count()<<endl; // 在外面检测引用数量
    return 0;
}