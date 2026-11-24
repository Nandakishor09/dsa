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

void levelOrder(Node *root){
    queue<Node*> q;
    if(root == NULL)
        return;
    q.push(root);
    int l = 1;

    while(!q.empty()){
        vector<int> level;
        int len = q.size();

        for(int i = 0; i < len; i++){
            Node *curr = q.front();
            q.pop();
            level.push_back(curr->data);
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

// dont work....
/*void inOrder(TreeNode *root, int target, int &sum, int &positive, int &flag){
    if(root == NULL)
        return;
    if(root->val > 0)
        positive++;
    if(root->val == target){
        if(root->left == NULL && root->right == NULL){
            flag = 0;
        }
        return;
    }
        
    sum += root->val;
    if(sum == target){
        if(root->left == NULL && root->right == NULL){
            flag = 1;
        }
        else if(root->left != NULL && root->left->val == 0){
            root = root->left;
            while(true){
                if(root->left == NULL && root->right == NULL){
                    flag = 1;
                    return;
                }
                else if(root->left->val == 0){
                    root = root->left;
                }
                else if(root->right->val == 0){
                    root = root->right;
                }
            }
        }
        else if(root->right != NULL && root->right->val == 0){
            root = root->right; 
            while(true){
                if(root->left == NULL && root->right == NULL){
                    flag = 1;
                    return;
                }
                else if(root->left->val == 0){
                    root = root->left;
                }
                else if(root->right->val == 0){
                    root = root->right;
                }
            }
        }
        return;
    }
    if(sum > target && target > 0)
        sum -= root->val;
    else if(target < 0 && target > sum)
        sum -= root->val;
    
    inOrder(root->left, target, sum, positive, flag);
    inOrder(root->right, target, sum, positive, flag);
}
bool hasPathSum(TreeNode* root, int targetSum) {
    
    int sum = 0, positive = 0, flag = 0;
    if(root == NULL)
        return false;
    if(root->val == targetSum && root->left == NULL && root->right == NULL)
        return true;

    inOrder(root, targetSum, sum, positive, flag);

    if(targetSum == 0 && positive != 0 && targetSum == sum)
        return false;
    else if(targetSum == sum && flag == 1)
        return true;
    return false;
}*/

bool hasPathSum(Node* root, int targetSum) {
    if(root == NULL)
        return false;

    targetSum -= root->data;

    if(root->left == NULL && root->right == NULL)
        return targetSum == 0;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main(){
    Node *root = createBT();
    levelOrder(root);

    if(hasPathSum(root, 1)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}