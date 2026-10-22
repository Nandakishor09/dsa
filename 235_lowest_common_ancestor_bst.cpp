#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int value){
        val = value;
        right = nullptr;
        left = nullptr;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)
        return root;
        
    TreeNode *curr = root;
    if(curr->val > p->val && curr->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(curr->val < p->val && curr->val< q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

void levelOrder(TreeNode *root){
    queue<TreeNode*> q;
    if(root == NULL)
        return;
    q.push(root);
    int l = 1;

    while(!q.empty()){
        vector<int> level;
        int len = q.size();

        for(int i = 0; i < len; i++){
            TreeNode *curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        cout<<"Level "<<l<<": ";
        for(int i = 0; i < level.size(); i++){
            cout<<level[i]<<" ";
        }
        l++;
        cout<<endl;
    }
}

TreeNode *createBst(TreeNode *root, int data){
    if(root == NULL){
        TreeNode *newNode = new TreeNode(data);
        return newNode;
    }

    if(root->val > data)
        root->left = createBst(root->left, data);
    else
        root->right =createBst(root->right, data);

    return root;
}

int main(){
    int n = 0;

    cout<<"Enter no of elements in bst: ";
    cin>>n;

    TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter no: ";
        cin >> num;

        root = createBst(root, num);
    }

    levelOrder(root);

    return 0;
}

