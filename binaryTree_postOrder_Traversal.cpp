#include <bits./stdc++.h>
using namespace std;

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

Node* createTree(vector<int> &arr, int i, int n){
    if(i >= n)
        return nullptr;

    Node *root = new Node(arr[i]);

    root->left = createTree(arr, 2 * i + 1, n);
    root->right = createTree(arr, 2 * i + 2, n);

    return root;
}

void postOrder(Node *root){
    if(root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int n = arr.size();

    Node *root = createTree(arr, 0, n);

    postOrder(root);

    return 0;

}