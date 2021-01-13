//
// Created by zxzx on 2020/12/12.
//

#include <iostream>
using namespace std;

void swap(int &i, int &j){
    int tmp = i;
    i = j;
    j = tmp;
}

void swap(int *arr, int i, int j){
    int tmp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = tmp;
}

void bubleSort(int *arr, int len){ // 3,2,5,1:4
    for(int i=len-1;i>-1; i--){ // 3,2,1, 0
        for(int j=0;j<i;j++){ // <3, 2: 0,1,2 :  0,1, 0
            if( arr[j] > arr[j+1]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void test_buble(){
    int arr[4] = {3,2,5,1};
    bubleSort(arr, 4);
    for(int num: arr){
        cout << num <<  endl;
    }
}


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

public:
//    Node* treeToDoublyList(Node* root) {
//        if(root == NULL) return NULL;
//        vector<Node*> res = lrro(root);
//        return res[0];
//    }
//
//    vector<Node*> lrro(Node *root){
//        if(!root || (!root->left && !root->right)){
//            vector<Node*> res{root, root};
//            return res;
//        }
//        vector<Node*> l_res= lrro(root->left);
//        vector<Node*> r_res= lrro(root->right);
//        Node *first = NULL, *last= NULL;
//
//        if(l_res[0] == NULL){
//            first = root;
//        }else{
//            first = l_res[0];
//            l_res[1]->right = root;
//            root->left = l_res[1];
//        }
//
//        if(r_res[0] == NULL){
//            last = root;
//        }else{
//            last = r_res[1];
//            r_res[0]->left = root;
//            root->right = r_res[0];
//        }
//        vector<Node*> res{first, last};
//        return res;
//    }

    int majorityElement(vector<int>& nums) { // 1,2,2
        int res = nums[0], cnt = 1;
        int i = 1;
        while(i < nums.size()){
            if(res == nums[i] && cnt > 0){
                cnt++;
            }else if(res != nums[i]){
                cnt--;
            }else if(cnt == 0){
                res = nums[i];
                cnt = 1;
            }
            i++;
        }
        return res;
    }
};


void test_tree2ls(){
//    Node * p = new Node(1);
//    Node * pl = new Node(2);
//    Node * pr = new Node(3);
//    p->left = pl;
//    p->right = pr;
//    Node * p2 = Solution().treeToDoublyList(p);
}
#endif //CPP_LEARN_BUBLESORT_H


