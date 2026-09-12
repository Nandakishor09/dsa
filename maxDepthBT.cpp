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

Node* createTree() {
    int value;
    cin >> value;

    if(value == -1)
        return nullptr;

    Node* newNode = new Node(value);

    cout << "Enter left child of " << value << ": ";
    newNode->left = createTree();

    cout << "Enter right child of " << value << ": ";
    newNode->right = createTree();

    return newNode;
}

void print(Node *root){
    vector<vector<int>> ans;
    if(root == nullptr)
        return;
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
    
    for(int i = 0; i < ans.size(); i++){
        cout<<"Level "<<i<<": "<<endl;
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node *root = createTree();

    print(root);
    depth(root);

    return 0;
}