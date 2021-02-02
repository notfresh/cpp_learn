//
// Created by zxzx on 2020/10/11.
//


#include <list>
#include <map>
#include <iostream>
using namespace std;

// 测试insert方法
void map_f1(){
    map<int, int> m;
    typedef  map<int, int>::iterator map_iter;
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(2,1));
    m.insert(pair<int,int>(3,1));
    m.erase(m.begin()++);
    m.erase(3);
    for(map_iter it=m.begin();it != m.end(); it++){
        cout << it->first << "," << it->second << endl;
    }
}

void map_test2(){
    map<int, map<int, int> > memo;
    map<int, int> tmp = memo[2];
    cout << tmp[1] << endl;
    cout << memo[2][1] << endl;
    memo[2][3] = 5;
    cout << memo[2][3] << endl;
}

void map_test3(){
    map<int, int> a;
}

////////////////////////////////////////////
class NUM{
public:
    NUM(int n):num(n){}
    NUM():num(0){} // 没有无参构造，作为pair中的元素，就会报错！！
    friend ostream& operator << (ostream& out, NUM &n){
        out << n.num ; // no endl, in case of unexpected
        return out;
    }

    friend bool operator<(const NUM& self, const NUM& other){
    	return self.num < other.num;
    }

private:
    int num;
};


// test map[] and insert(make_pair())
void map_test4(){
    map<int, NUM> map1_;
    map1_.insert(make_pair(4, NUM(3)));
    cout << map1_[4] << endl;
    cout << map1_[1] << endl;
    cout << map1_.size() << endl;
}

#include <zxlib/print.h>
void test_my_class_key(){
	map<NUM, int> m;
	m[NUM(0)] = 3;
	m[NUM(0)] = 2;
//	for(auto iter=m.begin();iter!=m.end();iter++){
//		print(iter->first, iter->second);
//	}
	print(1,2,3);
	print(NUM(0), NUM(1));
}

int main(){
//    map_test4();
	test_my_class_key();
}


