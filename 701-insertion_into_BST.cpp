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

TreeNode *createBST(TreeNode *root, int val){
    if(root == nullptr){
        TreeNode *newNode = new TreeNode(val);
        return newNode;
    }
    else if(val < root->value){
        root->left = createBST(root->left, val);
    }
    else if(val > root->value){
        root->right = createBST(root->right, val);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr){
        TreeNode *newNode = new TreeNode(val);
        return newNode;
    }
    else if(val < root->value){
        root->left = insertIntoBST(root->left, val);
    }
    else if(val > root->value){
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void print(TreeNode *root){
    if(root == nullptr){
        return;
    }
    print(root->left);
    cout<<root->value<<" ";
    print(root->right);
}

int main(){
    vector<int> arr = {1,2,3,4,6};
    TreeNode *root = new TreeNode(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    root = insertIntoBST(root, 7);
    print(root); cout<<endl;

    return 0;
}