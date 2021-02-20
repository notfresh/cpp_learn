//
// Created by zxzx on 2021/1/23.
//

#include <zxlib/TreeNode.h>
#include <map>
#include <time.h>
#include <zxlib/using_std.h>
#include <stdio.h>


class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int ret = 0;
		map<int, int> memo{{0,1}};
		int sum = 0;
		for(int num: nums){
			sum += num;
			ret += memo.count(sum-k);
			memo[sum] += 1;
		}
		return ret;
	}
};

int main(){
	vector<int> num{1,-1, 0};
	int k = 0;
	int z = Solution().subarraySum(num, k);
	cout << z << endl;
}
