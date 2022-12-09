#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};

class Solution {
    public:
    int maxAncestorDiff(TreeNode* root, int mx = INT_MIN, int mn = INT_MAX) {
        if(!root){
            return (mx - mn);
        }
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        return max(maxAncestorDiff(root->left, mx, mn), maxAncestorDiff(root->right, mx, mn));
    }
};

TreeNode* CreateNode(int data)
{
    TreeNode* newNode = new TreeNode();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* InsertNode(TreeNode* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    queue<TreeNode*> q;
    q.push(root);
 
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

int main(){
    TreeNode* root1 = CreateNode(8);
    root1->left = CreateNode(3);
    root1->left->left = CreateNode(1);
    root1->left->right = CreateNode(6);
    root1->left->right->left = CreateNode(4);
    root1->left->right->right = CreateNode(7);
    root1->right = CreateNode(10);
    root1->right->right = CreateNode(14);
    root1->right->right->left = CreateNode(10);

    Solution ob;
    cout<<ob.maxAncestorDiff(root1);
}