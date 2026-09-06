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

vector<vector<int>> levelOrder(Node *root){
    vector<vector<int>> ans;
    if(root == nullptr)
        return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            Node *node = q.front();
            q.pop();
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int n = arr.size();

    Node *root = createTree(arr, 0, n);

    vector<vector<int>> tree = levelOrder(root);

    for(int i = 0; i < tree.size(); i++){
        for(int j = 0; j < tree[i].size(); j++){
            cout<<"Level: "<<i + 1<<"--";
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}