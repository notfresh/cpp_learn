//
// Created by zxzx on 2020/12/9.
//

#include <iostream>
using namespace std;

double cal(int a ){ //
    return static_cast<double>(a);
}

int max(int x, int y); //求最大数
int min(int x, int y); //求最小数
int add(int x, int y); //求和
void process(int i, int j, int (*p)(int a, int b)); //@函数指针 @指针函数


int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

int add(int x, int y)
{
    return x + y;
}

// 函数指针比较特殊，它不像 int i，它的类型就是一个函数指针，而它直接给出的就是自己的声明，这就是函数指针
void process(int i, int j, int (*p)(int, int)) // @函数指针 @函数指针参数
{
    cout<<p(i, j)<<endl;
}


int main(){
    double (*pf)(int);
    pf = cal;
    cout << (*pf)(1) << endl;
    cout << pf(1) << endl;
    int a = 2, b = 3;
    process(a, b, max);
}


