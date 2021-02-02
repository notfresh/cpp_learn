//
// Created by zxzx on 2021/1/23.
//

#include <zxlib/TreeNode.h>

class Solution {
public:
	void flatten(TreeNode* root) { // 2,3,4
		preOrder(root, nullptr);
		int a = 1;
	}

	TreeNode* preOrder(TreeNode* root, TreeNode* pre){
		if(!root) return pre;
		if(pre){
			pre->left = nullptr;
			pre->right = root;
		}
		pre = preOrder(root->left,root);//2,1
		pre = preOrder(root->right, pre);
		return pre;
	}
};
#include <time.h>
#include <zxlib/using_std.h>
#include <stdio.h>

struct a{
	int b;
	char c;
};

int main(){
//	TreeNode *n1 = new TreeNode(1);
//	TreeNode *n2 = new TreeNode(2);
//	Solution().flatten(n1);
//	n1->left = n2;

	time_t t;
	t = time(NULL);

	int ii = time(&t);
	printf("ii = %d\n", ii);
	printf("%d\n" , sizeof(int));
	printf("%d\n" , sizeof(double));
	printf("%d\n" , sizeof(struct a));
}
