//
// Created by zxzx on 2020/11/18.
//


#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void test_vector(){
    vector<int> vctr;
}

void test_vector2(){
    int a = int(-1); // 默认是0
    cout << a<< endl;
}

void test_erase(){
    vector<int> arr{1,2,3,4,5,6};
    for(vector<int>::iterator it=arr.begin();it!=arr.end();it++){
        if(*it!=3) cout << *it << endl;
        if(*it==3){
            arr.erase(it);
            it--; // 数据前移，务必--；
        }
    }
}

void test_read_data(){
    vector<int> arr;
    ifstream in("/Users/zxzx/projects/cpp_learn/testStl/data.txt");
    if(!in){
        cout << "infile_error" << endl;
        return ;
    }
    int tmp = 0;
    while(!in.eof()){
        in >> tmp;
        arr.push_back(tmp);
    }
    in.close();
    sort(arr.begin(), arr.end());
    for(int c: arr){
        cout << c << '\t' ;
    }
    ofstream out("/Users/zxzx/projects/cpp_learn/testStl/data3.txt"); // 没有的话就会自己创建！！
    if(!out){
        cout << "out file_error" << endl;
        return;
    }
    for(int c: arr){
        out << c << '\t';
    }
    out.close();
    cout << endl;
}



