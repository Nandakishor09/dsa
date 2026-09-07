#include <bits./stdc++.h>
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

void inOrder(Node *root){
    if(root == nullptr)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

vector<int> inOrder_iterative(Node *root){

    vector<int> ans;
    stack<Node*> st;
    Node *node = root;

    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int n = arr.size();

    Node *root = createTree(arr, 0, n);

    inOrder(root); cout<<endl;

    vector<int> tree = inOrder_iterative(root);
    for(int i = 0; i < tree.size(); i++){
        cout<<tree[i]<<" ";
    }
    return 0;

}