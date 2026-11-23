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

void inOrder(Node *root, int target, int &sum, int &positive, int &flag){
    if(root == NULL)
        return;
    sum += root->data;
    if(sum == target){
        if(root->left == NULL && root->right == NULL){
            flag = 1;
        }
        return;
    }
    if(sum > target)
        sum -= root->data;
    if(root->data > 0)
        positive++;
    inOrder(root->left, target, sum, positive, flag);
    inOrder(root->right, target, sum, positive, flag);
}

bool hasPathSum(Node* root, int targetSum) {
        
    int sum = 0, positive = 0, flag = 0;
    if(root == NULL)
        return false;
    inOrder(root, targetSum, sum, positive, flag);

    if(targetSum == 0 && positive != 0 && targetSum == sum)
        return false;
    else if(targetSum == sum && flag == 1)
        return true;
    
    return false;
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