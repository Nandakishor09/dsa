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

//idk how this logic works. Still trying to understand the logic
//all thanks to striver....

Node *first, *previous, *middle, *last;
void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    if(previous != NULL && (root->data < previous->data)){
        if(first == NULL){
            first = previous;
            middle = root;
        }else{
            last = root;
        }
    }
    previous = root;
    inOrder(root->right);
}

void recoverTree(Node* root) {
    first = NULL;
    middle = NULL;
    last = NULL;
    previous = new Node(INT_MIN);
    inOrder(root);
    if(first && last){
        swap(first->data, last->data);
    }else if(first && middle){
        swap(first->data, middle->data);
    }
}

int main(){
    //Node *first, *prev, *middle, *last;
    vector<int> arr = {1,2,3,4,6};
    Node *root = new Node(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        createBST(root, arr[i]);
    }
    print(root);cout<<endl;

    recoverTree(root);

    return 0;

}