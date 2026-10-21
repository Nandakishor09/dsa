#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *right;
    Node *left;

    Node(int value){
        data = value;
        right = NULL;
        left = NULL;
    }
};

Node *createBT(){
    int num = 0;
    cout<<"Enter number: ";
    cin>>num;

    if(num == -1) 
        return NULL;

    Node *newNode = new Node(num);

    cout<<"Left of "<<num<<" -- ";
    newNode->left = createBT();
    
    cout<<"Right of "<<num<<" -- ";
    newNode->right = createBT();

    return newNode;
}

void print(Node *root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(){
    Node *root = createBT();
    print(root);

    return 0;
}