//
// Created by zxzx on 2021/1/2.
//


#include <cstdarg>
#include <iostream>

 using namespace std;
int sum(int count, ...);

int main()
{
    int nS = sum(4,1,2,3,4);

    cout << nS << endl;
    return 0;
}

int sum(int count, ...)
{
    int _sum,arg ;
    va_list arg_ptr;
    _sum = 0;
    va_start(arg_ptr,count); // 初始化
    for(int i=0; i < count; ++i)
    {
        arg = va_arg(arg_ptr,int); // 每次前进一个单位长度
        _sum += arg;
    }
    va_end(arg_ptr); // 释放
    return _sum;
}