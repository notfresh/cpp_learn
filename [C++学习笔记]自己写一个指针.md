# 如何自己实现一个智能指针？

智能指针的实现，比较有难度，也是面试高频问题。C++语言中有5种至少的智能指针，那么怎么模仿自己设计一个简易的指针呢？



## 目录

- [背景](#背景)
- [正文](#正文)
- [链接](#链接)
- [征求互动](#征求互动)
- [参考](#参考)

## 背景

最近有在阅读《Effective C++》以及一些其他C++相关的书，推荐《Effective C++》。



## 正文

### 难点

理清需求。我们要模仿智能指针，需要做的几件事，第一，可以自动释放堆内存中的对象，第二，可以支持一些常用的操作，比如 * 运算符，->运算符，赋值运算符，拷贝构造函数。



### 具体实现



以下是我参考别人思路实现的代码：

> 先声明，为了仅作演示，所有的方法都用类内定义的Inline方式。

```c++
#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T>
class SmartPrt{
public:
    SmartPrt(T* p=0) {
        m_refCount = new int(1);// 我们假设这个传入的指针一定是刚刚分配的堆内存的值，如果传入一个已有的指针，那么应该报错，因为可能会重复释放
        m_p = p;
    };

    SmartPrt(const SmartPrt& sp){
        m_p = sp.m_p; // 指向同一个内存位置
        m_refCount = sp.m_refCount;
        ++*m_refCount; // 引用数加1
    }

    SmartPrt& operator=(SmartPrt& p){
        decr();
        ++*p.m_refCount;
        m_p = p.m_p;
        m_refCount = p.m_refCount;
        return *this;
    }

    T* operator->(){
        if(m_p) return m_p;
        throw runtime_error("null pointer1");
    };

    T& operator*(){
        if(m_p)
            return *m_p;
        throw runtime_error("null pointer2");
    }

    ~SmartPrt(){
        decr();
        cout << "deconstructor" << endl;
    }

    int getRefCount(){
        return *m_refCount;
    }
private:
    T* m_p;
    int* m_refCount; // 这个指针

    void decr(){
        (*m_refCount)--;
        if((*m_refCount) == 0){
            cout << " free" << endl;
            delete m_p;
            delete m_refCount;

        }
    }
};
```



测试代码如下：

```c++
class Test{
public:
    Test(){name = "";};

    Test(string& i) {
        name = i;
    }

    Test(string i) {
        name = i;
    }

    Test(char* i) {
        name = i;
    }

    ~Test(){}

    void showName(){
        cout << name << endl;
    }
    string& getName(){
        return name;
    }

private:
    string name;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    SmartPrt<Test> p1(new Test("abcd"));
    p1->showName();
    SmartPrt<Test> p2(p1);
    *p2 = Test("defg");

    cout << p1->getName() << endl;
    cout <<"@1:" << p1.getRefCount() << endl;

    SmartPrt<Test> p3 (new Test("xxx"));
    p3 = p2;
    cout <<"@2:" << p1.getRefCount() << endl;
    return 0;
}
```



输出结果如下：

```
Hello, World!
abcd
defg
@1:2
 free // 这个free是释放p3原本指向的对象，这个很关键，也很费解
@2:3 
deconstructor
deconstructor
 free
deconstructor
```



### 实现过程中遇到的几个难点：

1. *运算符的重载。它只是模拟语言内置的解除指针命令，所以返回一个对象就可以了，我这里纠结了很久。
2. ->运算符的重载。它这里只是返回一个指向实体的指针，如果后面有一个方法，编译器会自动用这个指针去调用相应的方法，这里非常的费解。需要认真阅读 《C++ primer plus》相关的章节阅读->重载符的功效。
3. 拷贝构造方法可以直接访问私有属性，这个也是花了很久才想明白。





## 链接





## 征求互动

如果你觉得读完有帮助，请点个赞。

如果你觉得读完有打动你，欢迎和我留言互动。

如果你觉得我哪里写的不好，请留下你的看法。

如果觉得有改进的地方，也请不吝赐教。

如果你喜欢我的公众号，请点个关注。



## 参考

C++查看数据类型

https://blog.csdn.net/zhangzhi2ma/article/details/82463203

重载箭头运算符->

https://blog.csdn.net/gettogetto/article/details/53119893