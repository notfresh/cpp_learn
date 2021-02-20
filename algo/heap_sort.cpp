//
// Created by zxzx on 2021/1/11.
//
#include <vector>
#include <zxlib/print.h>
using namespace std;

void adjust_down(vector<int>& arr, int from, int to){
	int tmp = arr[from];
	int i = from * 2 + 1;
	while(i < to){
		if(i+1 < to && arr[i+1] > arr[i] ) i++;
		if( tmp >= arr[i] ) break;
		else{
			arr[from] = arr[i];
			from = i;
			i = i*2 + 1;
		}
	}
	arr[from] = tmp;
}

void build_heap(vector<int>& arr){
	int len = arr.size();
	for(int i=len/2-1;i>-1;i--){
		adjust_down(arr, i, len);
	}
}

void heapSort(vector<int>& arr){
	build_heap(arr);
	int len = arr.size();
	int tmp;
	for(int i=len-1; i>-1; i--){ // 这个错误让我一时半会找不到，看来找bug需要技巧
		tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		adjust_down(arr, 0, i);
	}
}

class Solution {
public:
	int rob(vector<int>& nums) {
		int sz = nums.size();
		if(sz == 0) return 0;
		vector<int> dp(sz);
		for(int i=0; i<sz; i++){
			if(i==0){
				dp[i] = nums[i];
			}
			else if(i==1){
 				dp[i] == nums[i];
			}
			else{
				dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
			}
		}
		return dp[sz-1];
	}
};

void test_rob(){
	vector<int> nums = {1,1};
	int t = Solution().rob(nums);
	cout << t << endl;
}

int main(){
//	vector<int> arr{1,2,3,4,6,10,8};
//	heapSort(arr);
//	print(arr);
	test_rob();
}
