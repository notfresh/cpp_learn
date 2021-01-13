//
// Created by zxzx on 2021/1/2.
//


#include <cstdarg>
#include <iostream>

using namespace std;
template <typename T>
void print(T arg){
    cout << arg ;
}

using namespace std;
template <typename T, typename... Ts> // @不定参数 @垃圾
void print(T t0, Ts ...t){
    print(t...);
}

int main(){
    print(1,2,3);
}
