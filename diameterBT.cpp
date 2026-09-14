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

int depth(Node *root, int &diameter){
    if(root == nullptr)
        return 0;
    int lh = depth(root->left, diameter);
    int rh = depth(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node* root) {
    int ans = 0;
    ans = depth(root, ans);
    return ans;
}

int main(){
    Node *root = createTree();
    print(root); cout<<endl;

    cout<<"Diameter of Binary Tree: "<<diameterOfBinaryTree(root)<<endl; 

    return 0;
}