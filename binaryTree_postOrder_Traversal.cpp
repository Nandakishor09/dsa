
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

vector<int> postOrder_Iterative(Node *root){
    vector<int> postOrder;
    if(root == NULL) return postOrder;

    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->right != nullptr)
            s1.push(root->left);
        if(root->left != nullptr)
            s1.push(root->right);
    }

    while(!s2.empty()){
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }

    return postOrder;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int n = arr.size();

    Node *root = createTree(arr, 0, n);

    postOrder(root); cout<<endl;

    vector<int> tree = postOrder_Iterative(root);
    for(int i = 0; i < tree.size(); i++){
        cout<<tree[i]<<" ";
    }

    return 0;

}