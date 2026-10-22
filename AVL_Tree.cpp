#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int x) {
        val = x;
        left = right = nullptr;
        height = 1;
    }
};

// Get the height of a node
int getHeight(Node* root) {
    if (root == nullptr)
        return 0;

    return root->height;
}

// Calculate balance factor
int getBalance(Node* root) {
    if (root == nullptr)
        return 0;

    return getHeight(root->left)
         - getHeight(root->right);
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert a value into the AVL tree
Node* insert(Node* root, int key) {

    // 1. Normal BST insertion
    if (root == nullptr)
        return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root;  // Ignore duplicates

    // 2. Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Find balance factor
    int balance = getBalance(root);

    // 4. Handle the four cases

    // LL case
    if (balance > 1 && key < root->left->val)
        return rightRotate(root);

    // RR case
    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    // LR case
    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case
    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Display the tree sideways
void display(Node* root, int space = 0) {
    if (root == nullptr)
        return;

    space += 5;

    display(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->val << "\n";

    display(root->left, space);
}

int main() {
    Node* root = nullptr;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nInorder traversal: ";
    inorder(root);

    cout << "\n\nAVL tree:";
    display(root);

    return 0;
}
