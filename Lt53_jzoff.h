//
// Created by zxzx on 2020/11/17.
//

#ifndef ZZZ_LT53_JZOFF_H
#define ZZZ_LT53_JZOFF_H

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = searchLeftMost(nums, target);
        cout << p << endl;
        int p2 = searchLeftMost(nums, target) ;
        cout << p2 << endl;
        if(p==-1) return 0;
        return p2+1-p;
    }

    int searchLeftMost(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] < target) l = mid+1;
            else if (nums[mid] > target) r = mid;
            else {
                if(mid>0 && nums[mid-1]==target) r = mid;
                else return mid;
            }
        }
        return -1; // 不存在
    }

    int searchRightMost(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] < target) l = mid+1;
            else if (nums[mid] > target) r = mid;
            else {
                if(mid<r-1 && nums[mid+1]==target) l = mid+1;
                else return mid;
            }
        }
        return -1; // 不存在
    }
};

void test_lt53(){
    Solution s;
    vector<int> a{5,7,7,8,8, 10};
    int res = s.search(a, 8);
    cout << res << endl;
}
#endif //ZZZ_LT53_JZOFF_H
