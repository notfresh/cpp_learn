//
// Created by zxzx on 2020/12/8.
// 两个线程 轮换打印0，1
//

#include <iostream>
#include <thread>
using namespace std;

int number=0;

void printOdd(){
    while(true){        
        if(number>20) break; 
        if(number%2==1){
           cout << number << endl;
           number++;
        }
    }
}

void printEven(){
    while(true){   
        if(number>20) break;      
        if(number%2==0){
           cout << number << endl;
           number++;
        }
    }
}


int main(){
    thread t1(printEven);
    // thread t2(printOdd);
    t1.join();
    // t2.join();
}


