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

Node *findLastRight(Node *root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}

Node *helper(Node *root){
    if(root->left == NULL){
        return root->right;
    }else if(root->right == NULL){
        return root->left;
    }
    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node *deleteNode(Node *root, int key){
    if(root == nullptr)
        return root;
    if(root->data == key){
        root = helper(root);
        return root;    
    }
    Node *temp = root;
    while(root != nullptr){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }else{
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
    }
    return temp;
}

int main(){
    vector<int> arr = {1,2,3,4,6};
    Node *root = new Node(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    root = deleteNode(root, 4);
    print(root);cout<<endl;

    return 0;
}