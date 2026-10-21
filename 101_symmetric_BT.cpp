#include <bits/stdc++.h>
using namespace std;

//logic 1 -- mine
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> tree;

    if (root == NULL)
        return tree;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                level.push_back(101);
                continue;
            }

            level.push_back(curr->val);

            q.push(curr->left);
            q.push(curr->right);
        }

        // Avoid adding levels containing only null nodes
        bool allNull = true;
        for (int x : level) {
            if (x != 101) {
                allNull = false;
                break;
            }
        }

        if (allNull)
            break;

        tree.push_back(level);
    }

    return tree;
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL)
        return true;

    vector<vector<int>> tree = levelOrder(root);

    for (int i = 0; i < tree.size(); i++) {
        int left = 0;
        int right = tree[i].size() - 1;

        while (left < right) {
            if (tree[i][left] != tree[i][right])
                return false;

            left++;
            right--;
        }
    }

    return true;
}

//logic 2 -- striver
bool helper(TreeNode *left, TreeNode *right){
    if(left == NULL || right == NULL)
        return left == right;
        
    if(left->val != right->val)
        return false;

    return helper(left->left, right->right) &&
            helper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root == NULL || helper(root->left, root->right);
}