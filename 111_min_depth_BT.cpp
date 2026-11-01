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

Node *findLeafs(Node *root, vector<Node*> &leafs){
    if(root->left == NULL && root->right == NULL){
        leafs.push_back(root);
        return root;
    }
    else if(root->left == NULL){
        root->right = findLeafs(root->right, leafs);
    }
    else if(root->right == NULL){
        root->left = findLeafs(root->left, leafs);
    }
    else{
        root->left = findLeafs(root->left, leafs);
        root->right = findLeafs(root->right, leafs);
    }

    return root;
}

/*void findHeight(Node *root, Node *l, int &height){
    if(root != NULL){
        if(root->data == l->data){
            height++;
            return;
        }
        else{
            height++;
            return findHeight(root->left, l, height);
            return findHeight(root->right, l, height);
        }
    }

}*/

int findHeight(Node *root, Node *l){
    if(root->data == l->data){
        return 1;
    }

    int le = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        le++;
        //vector<int> level;
        int size = q.size();
        Node *top = q.front();

        for(int i = 0; i < size; i++){
            Node *top = q.front();
            if(top->data == l->data){
                return le;
            }
            //level.push_back(top->data);
            q.pop();
            if(top->left != NULL){
                q.push(top->left);
            }
            if(top->right != NULL){
                q.push(top->right);
            }
        }
    }
}

void minDepth(Node* root) {
    vector<Node*> leafs;
    findLeafs(root, leafs);

    for(int i = 0; i < leafs.size(); i++){
        cout<<leafs[i]->data<<" ";
    }cout<<endl;

    int mini = 1000;
    for(int i = 0; i < leafs.size(); i++){
        int start = 0;
        start = findHeight(root, leafs[i]);
        cout<<start<<endl;
        if(start < mini){
            mini = start;
        }
    }
    cout<<mini<<endl;
}

int main(){
    Node *root = createBT();

    levelOrder(root); cout<<endl;

    minDepth(root);

    return 0;
}