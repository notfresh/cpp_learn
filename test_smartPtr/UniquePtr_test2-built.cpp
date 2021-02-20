#include <memory>
#include <iostream>

#include <zxlib/test_class.h>
#include <zxlib/print.h>

using namespace std;


void test_ptr(){
    unique_ptr<SimpleClass> p1(new SimpleClass("a"));
    p1->f1();
    p1.reset(new SimpleClass("b"));
    p1->f1();
}

void test_ptr2(){
    unique_ptr<SimpleClass> p1(new SimpleClass("a"));
    unique_ptr<SimpleClass> p2(new SimpleClass("b"));
    p2 = move(p1);
    p2->f1();
    p1->f1();
    print("abc");
}

void test_ptr3(){
    unique_ptr<SimpleClass> p1;
    p1 = unique_ptr<SimpleClass>(new SimpleClass);
    print("abc");
}

template <typename T>
struct node{
    shared_ptr<T> data;
    unique_ptr<node> next;    // 之所以把next设计成 unique_ptr,是为了让其自动释放data 
}; 

// 测试链式释放, 释放一个头, 所有的结点都被释放,这就是智能指针的爆炸效果!!! 
void test_chain_release(){

    shared_ptr<SimpleClass> p1(new SimpleClass("a"));
    shared_ptr<SimpleClass> p2(new SimpleClass("b"));
    shared_ptr<SimpleClass> p3(new SimpleClass("c"));
    
    using node1 = node<SimpleClass>;
    unique_ptr<node1> n1 = unique_ptr<node1>(new node1()); // 这他妈是人能写出来的玩意?
    unique_ptr<node1> n2 = unique_ptr<node1>(new node1());;
    unique_ptr<node1> n3 = unique_ptr<node1>(new node1());;
    
    n3->data = p3;
    n2->data = p2;    
    n2->next = move(n3);

    n1->data = p1; // 首先, 它是空的, 不能直接复制
    n1->next = move(n2);
    n1.release(); // 不会释放, 在mac系统上, 好像并没有调用析构函数, 但是也许内存是被回收了, 直接回收
    // n1.reset( new node1() )  ;
    print(2222);
}

int main(){
    // test_ptr3();
    test_chain_release();
}
