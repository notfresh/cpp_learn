//
// Created by zxzx on 2021/2/3.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int x0;
	int y0;
	vector<vector<int>> path;

	void print_path(int x, int y){
		x0 = x;
		y0 = y;
		go(0, 0);
	}

	void print_full_path(){
		for(auto item: path){
			cout << item[0] << "," << item[1]  << "\t";
		}
		cout << endl;
	}

	void go(int x, int y){
		if(x == x0 && y == y0){
			print_full_path(); //打印路径
			return;
		}

		if(x > x0 || y > y0){
			return;
		}
		vector<int> tmp;

		tmp = {x+1, y};
		path.push_back(tmp);
		go(x+1, y);
		path.pop_back();

		tmp = {x, y+1};
		path.push_back(tmp);
		go(x, y+1);
		path.pop_back();
	}

};



int main(){
//	cout << 1 << endl;
	Solution().print_path(2,2);
}