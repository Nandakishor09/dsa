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

//this logic is wrong......
//debugging is needed......
void recoverTree(Node* root) {
    if(root == NULL)
        return;
    if(root->left != NULL && root->left->data < root->data){
        recoverTree(root->left);
    }else{
        if(root->left != NULL){
            int temp = root->left->data;
            root->left->data = root->data;
            root->data = temp;
            return;
        }else{
            return;
        }
    }
    if(root->right != NULL && root->right->data > root->data){
        recoverTree(root->right);
    }else{
        if(root->right != NULL){
            int temp = root->right->data;
            root->right->data = root->data;
            root->data = temp;
            return;
        }else{
            return;
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,6};
    Node *root = new Node(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    recoverTree(root);

    return 0;

}