//
// Created by zxzx on 2020/12/10.
//

#ifndef CPP_LEARN_TESTALGO_H
#define CPP_LEARN_TESTALGO_H

#include <vector>
#include <set>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // 1,2,3
        string ret;
        serialize(root, ret);
        return ret;
    }

    void serialize(TreeNode* p, string& pipe){//$1,$2,$null,$null
        if(!p){
            pipe.push_back('#'); //
            return;
        }
        pipe.push_back(p->val+'0');//$+1,$+2,$+#,$+#,$+3,#+
        serialize(p->left, pipe);
        serialize(p->right, pipe);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { //1,2,#,#,3,#,#
        TreeNode *root=NULL;
        int i=0;
        deserialize(data, i, root);
        return root;
    }

    void deserialize(string& data, int& i, TreeNode*& p){ //$i=0 $i=1,$i=2,$i=3,$i=4
        if(i>=data.size()) return;
        if(data[i]=='#') return; //$i=3
        p = new TreeNode(data[i]-'0');//$ 1
        deserialize(data, ++i, p->left);//
        deserialize(data, ++i, p->right);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


void testAlgo(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    a->left = b;
    a->right = c;
    string ret = Codec().serialize(a);
    cout << ret << endl;
    TreeNode* p = Codec().deserialize(ret);
    cout << p << endl;
}

#endif //CPP_LEARN_TESTALGO_H
