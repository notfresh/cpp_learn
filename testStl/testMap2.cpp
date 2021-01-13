//
// Created by zxzx on 2020/10/11.
//


#include <list>
#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void map_test4(){
    map<string, int> map_;
    map_.insert(make_pair("abc", 1));
    map_.insert(make_pair("abcd", 1));
    for(auto iter=map_.begin();iter!=map_.end();iter++){
        cout << iter->first << ":" << iter->second << endl;
    }
}

void map_test5(){
    map<string, int> map_{{"abc", 1}, {"abcde",2}, {"feg",3}};

    for(auto iter=map_.begin();iter!=map_.end();iter++){
        cout << iter->first << ":" << iter->second << endl;
    }
}

class Name
{
public:
    size_t hash() const { return std::hash<std::string>()(first+second); }
    bool operator==(const Name& name) const { return first == name.first && second== name.second; }
private:
    string first;
    string second;
};
class Hash_Name {
public:
    size_t operator()(const Name& name) const { return name.hash(); }
};


void map_test6(){
    unordered_map<int,Name> people
    {
//            {1,{"Ann", "Ounce"}},
//            {2,{"Bill", "Bao"}}
        }
        ;
}

int main(){
    map_test6();
}


