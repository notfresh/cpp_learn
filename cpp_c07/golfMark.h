//
// Created by zxzx on 2020/12/7.
//

#ifndef ZZZ_GOLFMARK_H
#define ZZZ_GOLFMARK_H

#include <iostream>
using namespace std;
const int SIZE = 10;

int set_mark(int nums[], int size);
void display_mark(int nums[], int size);
void cal_mark(int nums[], int size);

void testGolfMark(){
    int size, golfMark[SIZE];
    size = set_mark(golfMark, SIZE);
    display_mark(golfMark, size);
    cal_mark(golfMark, size);
}

int set_mark(int nums[], int size){
    int i=0;
    int input;
    while(true){
        if(i==size) break;
        cout << "输入第" << i <<"个成绩, 输入-1停止" << endl;
        cin >> input;
        if(input == -1){
            for(; i<size; i++) nums[i] = 0;
            break;
        }
        nums[i++] = input;
    }
    return i;
}


void display_mark(int nums[], int size){
    for(int i=0;i<size;i++){
        cout << nums[i] << '\t';
    }
    cout << endl;
}

/***
 *
 * @param nums
 * @param size
 */
void cal_mark(int nums[], int size){
    double _sum = 0;
    for(int i=0;i<size;i++){
        _sum += nums[i];
    }
    cout << "average score is " <<  _sum/size << endl;
}

#endif //ZZZ_GOLFMARK_H
