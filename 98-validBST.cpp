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

bool helper(Node *root, long long int minVal, long long int maxVal){
    if(root == NULL)
        return true;
    if(root->data >= maxVal || root->data <= minVal)
        return false;
    return helper(root->left, minVal, root->data) &&
         helper(root->right, root->data, maxVal);
}

bool isValidBST(Node* root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    vector<int> arr = {1,2,3,4,6};
    Node *root = new Node(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    cout<<isValidBST(root)<<endl;

    return 0;
}