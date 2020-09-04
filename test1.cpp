//
// Created by zxzx on 2020/9/3.
//

#include <iostream>
using namespace std;

void func(const int &a)
{
    cout << "func (const int &a) 调用 " << endl;
}
void func(int &a)
{
    cout << "func (int &a) 调用 " << endl;
}



bool isFlowerN(int n){

    int a = n % 10;
    int b = (n-a) % 100 / 10;
    int c = (n-a-b*10) % 1000 / 100;
    if((a*a*a+b*b*b+c*c*c) == n){
        return true;
    }
    return false;
};

void findNum(){
    using namespace std;
    for(int i=0;i<=999;i++){
        if(isFlowerN(i)){
            cout << i << endl;
        }
    }
};