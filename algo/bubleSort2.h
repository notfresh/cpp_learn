//
// Created by zxzx on 2020/12/17.
//


#include <iostream>
using namespace std;

void swap(int& i, int& j){
    i = i + j;
    j = i - j;
    i = i - j;
}

bool greater_(int i, int j){
    return i > j;
}

bool little_(int i, int j){
    return i < j;
}

void bubleSort2(int arr[], int len, bool (*f)(int ,int)){ // 这里会被编译器当做指针，声明数组是没有意义的!
    for(int i=1;i<len;i++){
        for(int j=0;j<len-i;j++){
            if(f(arr[j],arr[j+1])) swap(arr[j], arr[j+1]);
        }
    }
}

template <typename T>
void print_arr(T* p, int len){
    for(int i=0;i<len;i++){
        cout << *(p+i) << '\t';
    }
    cout << endl;
}

void test_bubleSort2(){
    int arr[4]{1,4,5,2};
    bubleSort2(arr,4, greater_);
    print_arr(arr,4);
    bubleSort2(arr,4, little_);
    print_arr(arr,4);

}

