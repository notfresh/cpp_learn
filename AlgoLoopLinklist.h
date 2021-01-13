//
// Created by zxzx on 2020/11/29.
//

#ifndef ZZZ_ALGOLOOPLINKLIST_H
#define ZZZ_ALGOLOOPLINKLIST_H


#include <vector>
#include <iostream>
using namespace std;


struct Node{
    struct Node *next;
    int val;
    Node(int _v):val(_v){}
 };

class LoopList{
public:
    struct Node *head;
    struct Node *tail;

    LoopList(){
        head = new Node(0);
        tail = head;
        tail->next = head;
    }

    bool empty(){
        return tail == head;
    }

    bool full(){
        return tail->next == head;
    }

    // 1,2
    void en_que(int v){
        tail->val = v;
        if(full()){
            Node *tmp = new Node(0);
            tmp->next = head;
            tail->next = tmp;
        }
        tail = tail->next;
    }

    int exit_que(){
        if(empty()) return -1;
        int tmp = head->val;
        head = head->next;
        return tmp;
    }
};

void testLoopLinklist(){
    LoopList que;
    que.en_que(3);
    int t2 = que.exit_que();
    cout << t2 << endl;

    que.en_que(4);
    int t = que.exit_que();
    cout << t << endl;


//    cout << t2 << endl;
}
#endif //ZZZ_ALGOLOOPLINKLIST_H
