#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left, *right;
    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* createTree(){
    int val;
    cin>>val;

    if(val == -1){
        return nullptr;
    }
    Node *root = new Node(val);
    cout<<"Enter left of: "<<val<<endl;
    root->left = createTree();

    cout<<"Enter right of: "<<val<<endl;
    root->right = createTree();

    return root;

}

void print(Node *root){
    if(root == nullptr)
        return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

Node *insertNode(Node *root, int insertVal){
    if(root == nullptr){
        return new Node(insertVal);
    }
    if(root->val == insertVal){
        return root;
    }
    if(insertVal < root->val){
        root->left = insertNode(root->left, insertVal);
    }
    else if(insertVal > root->val){
        root->right = insertNode(root->right, insertVal);
    }
    return root;
}

int main(){
    Node *root = createTree();
    print(root); cout<<endl;

    root = insertNode(root, 15);
    print(root);

    return 0;
}


