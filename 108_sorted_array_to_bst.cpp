#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode *left, *right;
    TreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};


void *bst(TreeNode *root, TreeNode *newNode, TreeNode *prev){
    if(root == NULL){
        if(prev->left == NULL){
            prev->left = newNode;
        }else{
            prev->right = newNode;
        }
            return 0;
    }
    else if(newNode->val < root->val){
        bst(root->left, newNode, root);
        return 0;
    }
    else if(newNode->val > root->val){
        bst(root->right, newNode, root);
        return 0;
    }
    return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode *root = new TreeNode(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        TreeNode *newNode = new TreeNode(nums[i]);
        TreeNode *prev = nullptr;
        bst(root, newNode, prev);
    }

    return root;
}