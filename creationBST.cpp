#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *left, *right;
    Node(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *createBST(Node *root, int val){
    if(root == nullptr){
        Node *newNode = new Node(val);
        return newNode;
    }
    else if(val < root->value){
        root->left = createBST(root->left, val);
    }
    else if(val > root->value){
        root->right = createBST(root->right, val);
    }
}

void print(Node *root){
    if(root == nullptr){
        return;
    }
    print(root->left);
    cout<<root->value<<" ";
    print(root->right);
}
int main(){
    vector<int> arr = {1,2,3,4,6};
    Node *root = new Node(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    return 0;
}
