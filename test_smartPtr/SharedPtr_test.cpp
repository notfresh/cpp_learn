#include <memory>
#include <iostream>
#include "SharedPtr.h"
using namespace std;

class Test{

public:
    Test(){name = "";};

    Test(char* i) {
        name = i;
    }

    void showName(){
        cout << name << endl;
    }

    string& getName(){
        return name;
    }

private:
    string name; // 不是堆上的对象，析构的时候会自动释放的！！
};


void test_ptr(){
    SharedPtr<Test> p1(new Test("abcd"));
    p1->showName();
    SharedPtr<Test> p2(p1);
    *p2 = Test("defg");
    p1->showName();
    cout <<"@1:" << p1.getRefCount() << endl;

    SharedPtr<Test> p3 (new Test("xxx"));
    p3 = p2;
    cout <<"@2:" << p1.getRefCount() << endl;
}

int main(){
    test_ptr();
}





