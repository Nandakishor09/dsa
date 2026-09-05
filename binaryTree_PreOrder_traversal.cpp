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

void preOrder(Node *root){
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<int> preOrder_iterative(Node *root){
    vector<int> preOrder;
    if(root == nullptr) 
        return preOrder;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node *node = st.top();
        st.pop();
        preOrder.push_back(node->data);

        if(node->right != nullptr)
            st.push(node->right);
        if(node->left != nullptr)
            st.push(node->left);

    }
    return preOrder;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int n = arr.size();

    Node *root = createTree(arr, 0, n);

    preOrder(root); cout<<endl;

    vector<int> tree = preOrder_iterative(root);

    for(int i = 0; i < tree.size(); i++){
        cout<<tree[i]<<" ";
    }

    return 0;

}