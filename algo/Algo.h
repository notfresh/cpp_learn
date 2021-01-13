//
// Created by zxzx on 2020/12/14.
//

#ifndef CPP_LEARN_ALGO_H
#define CPP_LEARN_ALGO_H

#include <vector>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node *head=NULL, *pre=NULL;
public:
    Node* treeToDoublyList(Node* root) {
        visit(root);
        return head;
    }

    void visit(Node *root){
        if(!root) return;
        visit(root->left);
        if(!head && root->left == NULL) head = root;  // 设置头结点
        if(pre){
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        visit(root->right);
    }
};


void test_algo(){
    Solution s;
    Node *p1 = new Node(1);
    Node *p2 = new Node(2);
    Node *p3 = new Node(3);
    p1->left = p2;
    p1->right = p3;
    Node *p = s.treeToDoublyList(p1);
    cout << endl;
}

#endif //CPP_LEARN_ALGO_H
