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
    void helper(TreeNode *root, vector<int> &tmp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            tmp.push_back(root->val);
        }
        helper(root->left, tmp);
        helper(root->right, tmp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tmp1, tmp2;
        helper(root1, tmp1);
        helper(root2, tmp2);
        return tmp1 == tmp2;
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
    TreeNode* root1 = CreateNode(3);
    root1->left = CreateNode(5);
    root1->left->left = CreateNode(6);
    root1->left->right = CreateNode(2);
    root1->left->right->left = CreateNode(7);
    root1->left->right->right = CreateNode(4);
    root1->right = CreateNode(1);
    root1->right->left = CreateNode(9);
    root1->right->right = CreateNode(8);

    TreeNode* root2 = CreateNode(3);
    root2->left = CreateNode(5);
    root2->left->left = CreateNode(6);
    root2->left->right = CreateNode(7);
    root2->right = CreateNode(1);
    root2->right->left = CreateNode(4);
    root2->right->right = CreateNode(2);
    root2->right->right->left = CreateNode(9);
    root2->right->right->right = CreateNode(8);

    Solution ob;
    cout<<ob.leafSimilar(root1, root2);
}