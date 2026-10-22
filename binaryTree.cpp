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

void preOrder(Node *root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if(root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(Node *root){
    if(root == NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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

void sumMaxBT(Node *root, int &s, int &maxi){
    if(root == NULL)
        return;

    s += root->data;
    maxi = max(maxi, root->data);

    sumMaxBT(root->left, s, maxi);
    sumMaxBT(root->right, s, maxi);
}

void countLeafNodes(Node *root, int &leafs){
    if(root->left == NULL && root->right == NULL){
        leafs++;
        return;
    }

    if(root->left != NULL)
        countLeafNodes(root->left, leafs);
    if(root->right != NULL)
        countLeafNodes(root->right, leafs);
}

int height(Node *root){
    if(root == NULL)
        return 0;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return 1 + max(leftheight, rightheight);
}

void noOfNodesInEachLevel(Node *root){
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
        cout<<"No of nodes in level "<<l<<": "<<level.size();
        l++;
        cout<<endl;
    }
}

void mirrorImage(Node *root){
    if(root == NULL)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

int main(){
    Node *root = createBT();

    //preOrder(root); cout<<endl;
    //inOrder(root); cout<<endl;
    //postOrder(root); cout<<endl;

    //int s = 0;
    //int maxi = 0;
    //sumMaxBT(root, s, maxi);
    //cout<<"Sum and Max value of binary tree: ";
    //cout<<s<<" "<<maxi<<endl;

    levelOrder(root); cout<<endl;

    //int leafs = 0;
    //countLeafNodes(root, leafs);
    //cout<<"No of Leaf Nodes: "<<leafs<<endl;

    //cout<<"Height of BT: "<<height(root)<<endl;

    //noOfNodesInEachLevel(root); cout<<endl;

    mirrorImage(root); 

    levelOrder(root); cout<<endl;

    return 0;
}