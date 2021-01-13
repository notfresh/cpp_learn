//
// Created by zxzx on 2020/11/29.
//


#include <vector>
#include <iostream>
using namespace std;

int minPositive(vector<int>& numbers){
    int _min = 0, _max = 0;
    for(int num:numbers){
        if(num>0){
            _min = min(_min, num);
            _max = max(_max, num);
        }
    }
    if(_min == 1) return _max+1;
    return _min - 1 ;
}

void testMinPositive(){
    vector<int> a = {1,2,3,4,6};
    int n =  minPositive(a);
    cout << n << endl;
}


#endif //ZZZ_ALGOMINPOSITIVE2_H



