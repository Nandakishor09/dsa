#include <bits/stdc++.h>
using namespace std;

class Node{     
public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *createBST(Node *root, int val){
    if(root == nullptr){
        Node *newNode = new Node(val);
        return newNode;
    }
    else if(val < root->data){
        root->left = createBST(root->left, val);
    }
    else if(val > root->data){
        root->right = createBST(root->right, val);
    }
}

void print(Node *root){
    if(root == nullptr){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void inOrder(TreeNode *root, vector<int> &arr){
    if(root == NULL)
        return;
        
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> arr;
    inOrder(root, arr);
    return arr[k - 1];
}
