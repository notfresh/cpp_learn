//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTGENERICSORT_H
#define CPP_LEARN_TESTGENERICSORT_H

#include <iostream>
using namespace std;

template<class T>
bool asc(T& a, T&b){
    return a < b;
}

template<class T>
void bubleSort(T* arr, int length, bool (*comparator)(T& a, T&b)=asc){
    for(int i=length-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(comparator(arr[j+1], arr[j])){
                T tmp;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}



template<class T>
bool desc(T& a, T&b){
    return a > b;
}

void generic_sort_f1(){
    int a[10] = {1,2,3,4};
    bubleSort(a, 10);
    for(int i=0;i<10;i++){
        cout <<  a[i] <<endl;
    }
}


#endif //CPP_LEARN_TESTGENERICSORT_H
